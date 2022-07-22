#include<stdio.h>
#include <stdlib.h>
int flag=0;//this is for  identifying whether the given directed graph id Dag or not
//structer for the node of adjacency list
typedef struct node
{
    int item;
    struct node*next;
}Node;
//this stucture is for entry,exit,visit status of all vertices and also predecessor of each vertex 
typedef struct Vertex
{
     int visit;
     int entry;
     int exit;
     int pred;
}vtx;
Node*head=NULL,*head1=NULL;//head1 is the head pointer of stack
int clock=0;// counting the vertices between entry and exit 
void Push(int num);//declaration of function push
// this function takes the base address of array of nodes ,and two vertices and forms an edge between them(i--->j) 
void Edge( Node*p,int i, int j)  //p is the starting address of array of array of structures
  {  
        Node *newptr=NULL,*temp=NULL;
        newptr=(Node*)malloc(sizeof(Node)); //dynamically creating newptr  of type struct node*
         if(newptr!=NULL) //if allocation is success
         {     
              newptr->item=j; //storing the neighbour of i 
              newptr->next=NULL;                                              
              head=&p[i];
              temp=head;
             while(temp->next!=NULL)//finding the end of the linked list
            {       
               temp=temp->next;
            }
            temp->next=newptr;//and linking the newnode at the end of the linked list
           
        }
  }
  //this function performs dfs explore on vertex i
  void DFS_explore( Node *p,int i,vtx *status)
 {  Node*temp=NULL;
    status[i].visit=1; //when we come to that vertex we marking it as visited
    status[i].entry=clock; // taking entry time status of vertex
     clock++;
     head=&p[i];
     temp=head;
      while(temp->next!=NULL) 
     {
            if((status[temp->next->item].visit)==0) //if any neighbour of that vertex is not visited
           {
              status[temp->next->item].pred=i;
              DFS_explore(p,temp->next->item,status);//exploring at the non visited neighbour
           }
             temp=temp->next;
     }
      status[i].exit=clock; // storing the exit time of that vertex
      Push(i);//pushing each vertex into stack while exiting 
      clock++;
  }
  //this function check the visiting status of each vertex of graph calls the DFS_explore function if that vertex is not visited
  void DFS(Node *p,int v,vtx*status)
  {
    for(int i=1;i<=v;i++)
    {
      if(status[i].visit==0)                //exploring at the vertex if it is not visited
      { 
        DFS_explore(p,i,status);
      }
    }   
  }
  //this function takes base address of array of nodes , base address of array of statuses of vertices,no. of vertices as input
  //checks the back edge condition for all edges in the graph
  void back_edge(Node *a,int v, vtx *status)
  {
      for(int i=1;i<=v;i++)
      {
          Node*temp=&a[i];
          while(temp->next!=NULL)
          {
              int r=temp->next->item;
              if(status[r].entry<status[i].entry && status[i].exit<status[r].exit)//checking the back edge condition
              {
                  if (flag==0)
                  {   
                      printf("Not a DAG\n"); //if atleast one back edge exits then print NOT a Dag
                      flag=1; //here making flag value 1 to avoid repeated printing of not a dag
                  }
                  printf("%d %d %d %d\n",status[r].entry,status[i].entry,status[i].exit,status[r].exit);
              }
              temp=temp->next;
          }
      }
  }
  //Push function of stack 
 void Push(int num) 
{
	Node *newnode;
	//dynamically allot a newnode
	newnode=(Node *) malloc (sizeof(Node));
	//linking newnode at top of stack
	newnode->item=num;
	newnode->next=head1;
	head1=newnode;
}
//this function checks whether stack is empty or not
Node* IsEmpty()
{
   return head1;
}
//this function returns tpo element of the stack
void Top()
{   
   if(head1!=NULL)
  {
     printf("%d\n",head1->item);
  }
   else
  {
    printf("Top Failure\n");
  }      
} 
//this function deletes the top element of the stack
void Pop()  
{   
    if(head1!=NULL)
   {  Node*temptr;
      temptr=head1;
      head1=head1->next;             // moving head to the next node
      temptr->next=NULL;           
      free(temptr);               //deleting the node
   }
    else
   {
      printf("Pop Failure\n");
   }
}   
int main()
{   
    int v;//no of vertices
    scanf("%d",&v);
    Node a[v];//declaring array of node structures
    vtx status[v];//declaring array of status structures
     for(int k=1;k<=v;k++)
  	{
	    a[k].next=NULL;     //making the next of each node=NULL 
	}
    //taking input of the graph
    int i=1;
    while(i<=v)
    {   
        while(1)
        {   int x;
            scanf("%d",&x);
            if(x==-1)
            {
                break;
            }
            Edge(a,i,x);
        }
        i++;
    }

    for(int i=1;i<=v;i++)
    {  
        status[i].visit=0; //initialising all the visit status of all the vertices as 0
        status[i].entry=-1;//and entry and exit time as -1
        status[i].exit=-1;
        status[i].pred=-1;//predecessor of all vertices as -1
    }    
    int q;
    scanf("%d" , &q);
    DFS_explore(a,q,status);
    DFS(a,v,status);// calling DFS to explore the graph and get the statuses of all vertices
    for(int i=1; i<=v;i++)
    {                                        
        printf("%d %d %d\n",status[i].entry,status[i].exit,status[i].pred);//printing entry time exit time and predecessor of each vertex 
    }
    back_edge(a,v,status);
    if(flag==0)//if flag is 0 then it does not enter into if condition in back edge function so it is dag
    {
        printf("DAG\n"); 
        while(IsEmpty()!=NULL) //print the topological oder of vertices means decreasing order of exit time of all vertices 
        {
           Top();
           Pop();
        }
    }
  return 0;
 }
