#include<stdio.h>
#include <stdlib.h>
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
  //this function performs dfs explore on vertex i of reversegraph
  void DFS_explore1( Node *p,int i,vtx *status)
 {  
     Node*temp=NULL;
     printf("%d",i);
    status[i].visit=1; //when we come to that vertex we marking it as visited
    status[i].entry=clock; // taking entry time status of vertex
     clock++;
     head=&p[i];
     temp=head;
      while(temp->next!=NULL) 
     {
            if((status[temp->next->item].visit)==0) //if any neighbour of that vertex is not visited
           {  printf(" ");
              status[temp->next->item].pred=i;
              DFS_explore1(p,temp->next->item,status);//exploring at the non visited neighbour
           }
             temp=temp->next;
     }
      status[i].exit=clock; // storing the exit time of that vertex
      clock++;
  }
  //this function check the visiting status of each vertex of graph calls the DFS_explore function if that vertex is not visited
  void DFS(Node *p,int v,vtx*status)
  {
    for(int i=1;i<=v;i++)
    {
      if(status[i].visit==0)             //exploring at the vertex if it is not visited
      { 
        DFS_explore(p,i,status);
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
//this function returns top element of the stack
int Top()
{   
   if(head1!=NULL)
  {
     return head1->item;
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
{   int v;
    scanf("%d",&v);
    Node a[v],c[v];
    vtx status[v];
     for(int k=1;k<=v;k++)
  	{
        a[k].next=NULL;     //making the next of each node=NULL
        c[k].next=NULL; 
	}
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
    //reversing the graph
    for (int k = 1; k <= v; k++)
    {
            Node*temp1,temp2;
            temp1=&a[k];
            while (temp1->next != NULL)  
            {   
                int s=temp1->next->item;
                Edge(c,s,k);//forming reverse graph by reversing the edges
                temp1= temp1->next;
            }
    }
    //printing the reverse graph
    for (int k = 1; k <=v; k++)
    {
        head = &c[k];
        if (head->next == NULL) 
        {
            printf("-1\n");//if the vertex has no neighbors print -1
        }
        else
        {
            while (head->next != NULL)  //printing the neighbors of each vertex in the specified format
            {
                head= head->next;
                printf("%d ", head->item);
            }
            printf("-1\n");
        }
    }
    //making all the visit status of all vertices as 0
    for(int i=1;i<=v;i++)
    {  
        status[i].visit=0;
    }
    //again calling Dfs_explore for reverse graph in the order order of stack elements
     while(IsEmpty()!=NULL)
    { 
      if(status[Top()].visit==0)                //exploring at the vertex of stack if it is not visited
      { 
        DFS_explore1(c,Top(),status);
        printf("\n");
      }
       Pop();//deleting the top element of stack after calling DFS_explore 
    }   
  return 0;
}
