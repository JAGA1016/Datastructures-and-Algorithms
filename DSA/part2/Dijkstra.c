#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
//structer for the node of adjacency list
typedef struct node
{
    int item;
    int weight;
    struct node *next;
}Node;
// structure for storing the distance and its vertex in heap
typedef struct Hnode
{
    int s;
    int vertex;
}hnode;
//this is for storing the each vertex statuses like its predecessor,its distance,visited or not
typedef struct vertex
{
   int dist;
   int pred;
   int visit;
}vtx;

Node *head = NULL;   
//this function is for swaping elements in the heap
void swap(hnode*x,hnode*y)
{
    hnode temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

void minheapify(hnode *H, int i,int n,int*index);// declaring the function minheapify
//printing the heap
void printheap(hnode*H,int n)
{
    for( int i=0;i<n;i++)
    {
       printf("i %d %d %d\n",i,H[i].vertex,H[i].s);
    } 
}
//this function shifts up the the elment in the tree if its parent greater than its value
void shiftup(hnode *H, int i,int*index)
{
  while(i>0 && H[i].s <= H[(i-1)/2].s)  
  {
      swap(&H[i],&H[(i-1)/2]);
      index[H[i].vertex]=i;
      index[H[(i-1)/2].vertex]=(i-1)/2;
      i=(i-1)/2;
  }
  return;
}
//this function decrease the value of node to new value 
 void decreasekey(hnode*H,int i,int new,int*index)
{
 if(H[i].s <=new)        //if the value node is less than the new value just return
  { 
     printf("Operation Fail\n");
     return; 
  }
  else
  {
    H[i].s=new;  // otherwise shift up it
    shiftup(H,i,index);
  }
}
void insert(hnode*H, hnode x,int*n,int*index)
{
  (*n)++; //increasing the size of arry
  H[(*n)-1]=x; //store the new element in the last position of the tree  
  shiftup(H,(*n)-1,index);//and shift up it recurssively
}
hnode extractmin(hnode*H,int* n,int *index)  //this function deletes the min value in the heap 
{   hnode temp;
    temp=H[0];  //store the minvalue in the temp
    H[0]=H[(*n)-1];//copy the last value in heap to root position
    index[H[(*n)-1].vertex]=0;
    (*n)--;        //decraese the size of the array
    minheapify(H,0,*n,index); //call minheapify
    return temp;
}

//assupstion in this function is left subtree and right subtree of that node are already heaps

void minheapify(hnode*H,int i,int n,int *index)
{
  int smallest=i; //let smallest is equal to the position at which we are calling minheapify
  if (i >= (n)/2) //leaf node
  {
    return;
  }
 
  if(H[2*i+1].s <H[i].s) //if left child is less that its parent
 {
     smallest=2*i+1;//smallest=left
 }
  if((2*i+2)<=(n-1) && H[2*i+2].s < H[smallest].s) //comparing right child with smallest (its brother , its parent)
 {
    smallest=2*i+2;  //smallest=right
 }
 if(H[smallest].s==H[i].s)
 {
     return;
 }
 if(smallest != i)  // smallest is not the parent 
 {
     swap(&H[i],&H[smallest]); //swap it with H[i]
     index[H[i].vertex]=i;
     index[H[smallest].vertex]=smallest;
     minheapify(H,smallest,n,index); // call minheapify for restoring the property of heap
 }
}

 void buildheap(hnode*H,int n,int *index)
{
  int relevant_index=(n-1)/2;   // last non leafnode
  for(int i=relevant_index;i>=0;i--) // going to all non leaf nodes and calling minheapify
  {
      minheapify(H,i,n,index);
  }
}
void weighted_Edge( Node*p,int i, int j,int w)  //p is the starting address of array of array of structures
  {  
        Node *newptr=NULL,*temp=NULL;
        newptr=(Node*)malloc(sizeof(Node)); //dynamically creating newptr  of type struct node*
            if(newptr!=NULL) //if allocation is success
            {     
                newptr->item=j; //storing the neighbour of i
                newptr->weight = w;
                newptr->next = NULL;
                head=&p[i];
                temp=head;
             while(temp->next!=NULL)//finding the end of the linked list
            {       
                temp=temp->next;
            }
            temp->next=newptr;//and linking the newnode at the end of the linked list
        }
  }
  //this function takes inputs as source vertex,starting address of adjacency list,starting address of heap and starting address of array of structures containing statuses of all vertices,no of vertices,index array for storing indices of vertices in heap 
void Dijkstra(int source,Node*a,hnode*H,vtx*status,int v,int*index)
{     
        int V=v;
        int count=v;
      while(count)
      {  
         hnode temp= extractmin(H,&v,index);// taking out the vertex with min distance from the source from heap 
         count--;

         status[temp.vertex].visit=1;
         head = &a[temp.vertex];
        if (head->next == NULL) 
        {
            continue;
        }
        else
        {  // doing edge relaxation for the neighbouring vertices if better shortest distance found from the source
            while (head->next != NULL)  
            {
                head= head->next;
                if(status[head->item].visit != 1)
                {   int loc= index[head->item];
                    if(((status[temp.vertex].dist)+ (head->weight)) < (H[loc].s))
                    {   
                        int new_distance=((status[temp.vertex].dist)+ (head->weight));
                        decreasekey(H,loc,new_distance,index); //updating the distance if we find better short distances than its previous distance
                        status[head->item].dist = new_distance;//storing the new_distance and its predecessor of the vertex
                        status[head->item].pred=  temp.vertex;
                    }
                }
                
            }
            
        }
      } //printing the shortest distances of all vertices and their predecessors 
       for(int k = 1; k <=V; k++)
      {     
            if(status[k].dist!=100000)
            {
                printf("%d %d\n",status[k].dist,status[k].pred);
            }
            else
            {
                printf("Unreachable\n");
            }
      }

  }
int main()
{   
    int v;//no of vertices
    scanf("%d",&v);
    Node a[v];//declaring array of node structures
    vtx status[v];
    
    for(int k=1;k<=v;k++)
  	{   
	    a[k].next=NULL;     //making the next of each node=NULL 
	    
	}
	for(int k=1;k<=v;k++)
	{
	    status[k].visit=0;
	    status[k].pred=-1;
	    status[k].dist=100000;
	}
	
    
    //taking input of the graph
    int i=1;
    while(i<=v)
    {   
        while(1)
        {   int x,w;
            scanf("%d",&x);
            if(x==-1)
            {
                break;
            }
            scanf("%d",&w);
            weighted_Edge(a,i,x,w);
        }
        i++;
    }
    int source;
    hnode H[v];
    int index[v+1];
    scanf("%d",&source);
    //taking the input of vertices and their distances into the heap
    //initialising all distances of vertices as 100000 except source vertex  
    for(int i=0;i<v;i++)
    {
        if((i+1)==source)
        {
            H[i].s= 0;
            H[i].vertex=i+1;
        }
        else
        {
            H[i].s= 100000;
            H[i].vertex=i+1;
        }
    }
    //storing the indices of all vertices in index array 
    for(int i=0;i<=v-1;i++)
    {
        index[i+1]=i;
    }
    buildheap(H,v,index); //calling build heap fuction
    status[source].dist=0;// making source distance as 0
    Dijkstra(source,a,H,status,v,index);//calling dijkstra function
    return 0;

 }