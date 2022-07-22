#include<stdio.h>
#include<stdlib.h>
struct node
  {
    int item;            //each node have some element and the address of next node
    struct node*next;
  };
   struct node*head=NULL;
   int clock=0;// counting the vertices betwwwn entry and exit 
   //this function is used to create an edge
  void Edge(struct node *p,int i, int j)  //p is the statting address of array of array of structures
  {  
        struct node *newptr=NULL,*temp=NULL;
        newptr=(struct node*)malloc(sizeof(struct node)); //dynamicaly creating newptr  of tye struct node*
         if(newptr!=NULL) //if allocation is success
        {     newptr->item=j; //storing the neighbour of i 
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
  void DFS_explore(struct node *p,int i,int *visited,int *entry,int *exit)
 {  struct node*temp=NULL;
    visited[i]=1; //when we come to that vertex we marking it as visited
    entry[i]=clock; // taking entry time status of vertex
    clock++;
        
     head=&p[i];
     temp=head;
      while(temp->next!=NULL) 
     {
            if((visited[temp->next->item])==0) //if any neighbour of that vertex is not visted
           {
             DFS_explore(p,temp->next->item,visited,entry,exit);//exploring at the non visited neighbour
           }
             temp=temp->next;
     }
      exit[i]=clock; // storing the exit time of that vertex
      clock++;
     
  }
  //this function check the visiting status of each vertex of graph calls the DFS_explore function if that vertex is not visited
  void DFS(struct node *p,int v,int *visited,int *entry,int *exit)
  {
    for(int i=0;i<v;i++)
    {
      if(visited[i]==0)                //exploring at the vertex if it is not visited
      {
        DFS_explore(p,i,visited,entry,exit);
      }
    }   
  }
  
 int main()
{
  int v,e,i,j; //v - no of vertices, e-no of edges,
  scanf("%d%d",&v,&e); 
  struct node a[v]; //declarting array of nodes
  
     for(int k=0;k<v;k++)
  	{
	    a[k].next=NULL;     //making the next of each node=NULL 
	}
  
  for(int k=0;k<e;k++)
  {  
        scanf("%d %d", &i, &j);
        Edge(a,i,j); //calling edge function for creating a edge
        Edge(a,j,i);// undirected graph so called two times
  }
    
    int visited[v],pred[v],entry[v],exit[v]; //declaring arrays for storing the status of each vertex of graph
    for(int i=0;i<v;i++)
    {  
       visited[i]=0;//initialising all vertices as unvisited
       entry[i]=-1;//intially entry and exit status of all vertices  are -1;
       exit[i]=-1;
    }
    int q;
    scanf("%d" , &q);
    DFS_explore(a,q,visited,entry,exit);
     DFS(a,v,visited,entry,exit);// calling DFS to explore the graph and get the statuses of all vertices
     for(int i=0; i< v;i++)
     {                                        //printing the entry and exit time of each vertex
        printf("%d %d\n",entry[i],exit[i]);
     }

  return 0;
 }
