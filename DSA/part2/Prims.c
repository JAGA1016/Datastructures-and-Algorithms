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
// structure for storing the cost and its vertex in heap
typedef struct Hnode
{
    int s;
    int vertex;
}hnode;
//this is for storing the each vertex statuses like its predecessor,its cost
typedef struct vertex
{  
    int cost;
    int prev;
}vtx;
//structure for storing the edges of mst
typedef struct edges
{
    int u;
    int v;
    int w;
}mst_edges;
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
    while(i>0 && H[i].s < H[(i-1)/2].s)  
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
    shiftup(H,(*n)-1,index);//and shift up it reccursively
}
hnode extractmin(hnode*H,int* n,int *index)  //this function deletes the min value in the heap 
{   
    hnode temp;
    temp=H[0];  //store the minvalue in the temp
    H[0]=H[(*n)-1];//copy the last value in heap to root position
    index[H[(*n)-1].vertex]=0;
    (*n)--;        //decrease the size of the array
    minheapify(H,0,*n,index); //call minheapify
    return temp;
}

//assumption in this function is left subtree and right subtree of that node are already heaps
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
void prims(int source,Node*a,hnode*H,vtx*status,int v,int*index)
{       
    //initialising all distances of vertices as 100000 except source vertex  
    for(int i=0;i<v;i++)
    {
        if((i+1)==source)
        {
            H[i].s= 0; //cost of source vertex as 0
            H[i].vertex=i+1;
        }
        else
        {
            H[i].s= 100000;
            H[i].vertex=i+1;
        }
    }
    //storing the indices of all vertices from the heap in index array 
    for(int i=0;i<=v-1;i++)
    {   
        index[i+1]=i;
    }
    head=&a[source];
    while (head->next != NULL)  //setting the pred value as source for the source neighbors
    {                           //cost as edge weight
        head = head->next;
        int x=index[head->item];
        status[head->item].prev=source;
        status[head->item].cost=head->weight;
        H[x].s=head->weight;
    }
    buildheap(H,v,index); //calling build heap fuction
    status[source].cost=0;// making source distance as 0
    mst_edges mst[v];//declaring array edges with weight for forming an mst
    hnode temp1=extractmin(H,&v,index);//removing the source vertex from the heap
    int count=v,i=1;
    while(count)
    {  
        hnode temp= extractmin(H,&v,index);// taking out the vertex with min cost from heap 
        count--;                              //mst_edge
        mst[i].u = status[temp.vertex].prev;  //  w
                                              //u--->v
        mst[i].v = temp.vertex;
        mst[i].w = status[temp.vertex].cost;
        i++;
        head = &a[temp.vertex];
        if (head->next == NULL) //checking whether the vertex have the neighbors or not
        {
            continue;
        }
        else
        {  
            while (head->next != NULL)  
            {
                head= head->next;
                int loc= index[head->item]; //getting the index value of the neighbor vertex
                if(status[head->item].cost > head->weight) //comparing the cost of neighbour vertex with the edge weight
                {                                         //if the cost is >edge weight
                    status[head->item].prev=temp.vertex; //updating the prev and cost values
                    status[head->item].cost=head->weight;
                    decreasekey(H, loc, head->weight, index);
                }
            }
        }
    
    } 
    //printing the mst
    for(int k=1;k<=i-1;k++)
    {
        printf("%d %d %d\n",mst[k].u,mst[k].v,mst[k].w);
    }
}
int main()
{   
    int v;//no of vertices
    scanf("%d",&v);
    Node a[v+1];//declaring array of node structures
    vtx status[v];
    
    for(int k=1;k<=v;k++)
  	{   
	    a[k].next=NULL;     //making the next of each node=NULL 
	}
	for(int k=1;k<=v;k++)
	{
	    status[k].prev=-1;
	    status[k].cost=100000;
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
    prims(source,a,H,status,v,index);
    return 0;
 }