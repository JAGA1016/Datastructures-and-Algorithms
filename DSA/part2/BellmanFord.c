#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int flag,count=0;
typedef struct node//this structure  is for stack node
{
    int item;
    struct node *next;
}Node;
typedef struct vertex //this structure is for the storing the statuses of all vertices ,like its distance from the source,its predecessor and its visiting status
{
    int dist;
    int pred;
    int visit;
}vtx;
typedef struct Edge // for storing the edge and its weight
{
    int a;
    int b;
    int weight;
}edge;
Node*head=NULL;//this is the stack pointer used for pointing to the top of stack 
//this function takes a new element and pushes into the stack
void Push (int num)
{
	Node *newnode;
	//dynamically allot a newnode
	newnode=(Node*) malloc (sizeof(Node));
	//linking newnode at top of stack
	newnode->item=num;
	newnode->next=head;
	head=newnode;
}
//this function prints the top element and deletes that element from the stack 
void Pop()  
{  
    int x;
    if(head!=NULL)
    {  
        Node*temptr;
        temptr=head;
        if(count!=1)
        {
            printf("%d ",temptr->item); //printing the element going to delete
        }
        else
        {
            printf("%d\n",temptr->item);  
        }
        head=head->next;             // moving head to the next node
        temptr->next=NULL;           
        free(temptr);               //deleting the node
     
    }
    else
    {
        printf("Pop Failure\n");
    }
}
//this function returns the pointer pointing to top element of the stack
Node* IsEmpty()
{
    return head;
}
//this function returns the top element of the stack
int Top()
{   
    if(head!=NULL)
    {
        return head->item;
    }
} 
//this function takes  source
void Bellman_ford(Node*a,vtx *status,edge*E,int v,int e) 
{   
    int m,u;//m is for storing 
    for(int j=1;j<=v;j++)
    {
        flag=0;
        for(int i=1;i<=e;i++)
        {   
            if(status[E[i].b].dist >(status[E[i].a].dist + E[i].weight))
            {  
                if (j==v)//finding the vertex which distance is updating first in vth iteration 
                {
                    m=E[i].b;//storing that vertex in m  
                    count++;
                    flag=1;
                    break;
                }
                status[E[i].b].dist =(status[E[i].a].dist + E[i].weight);//updating the distances if we find better distance
                status[E[i].b].pred = E[i].a;// storing its predecessor
                flag=1;
            }
        
        } 
        if(flag==0) //if flag is zero means no distances are updated so we can stop edge relaxation
        {
            break;
        }  
    }
    if (flag==0) //here if flag is zero means all distances are set
    {   //printing the distances and predecessors of each vertex
        for(int i=1;i<=v;i++)
        {  
            if(status[i].dist!=100000)
            {
                printf("%d %d\n",status[i].dist,status[i].pred);
            }    
            else
            { 
                printf("Unreachable\n");
            }
        }
    }
    else //if flag is not zero then there exits a negative edge cycle
    {   
        while(status[m].visit<=1)
        {
            status[m].visit++;// just increasing the visit statuses of all vertices present in the negative edge cycle 
            if(status[m].visit!=2)//if that vertex is visited only once push that vertex into the stack
            {   
                Push(m);
                count++;
            }
            else
            {
                u=m;//storing the first vertex which got visited twice
                break;
            }
           m=status[m].pred;
        }
        //printing all the vertices in the cycle
        while(head!=NULL)
        { 
            if(Top()!=u)
            {
                Pop();
                count--;
            }
            else
            {
                Pop();
                break;
            }
        }     
         
    }
}
int main()
{   
    int v;//no of vertices
    int e;
    scanf("%d%d",&v,&e);
    Node a[v];//declaring array of node structures
    vtx status[v];
    edge E[e];
    
     for(int k=1;k<=v;k++)
  	{   
	    a[k].next=NULL;     //making the next of each node=NULL 
	    status[k].visit=0;
	    status[k].pred=-1;
	    status[k].dist=100000;
	}
    
    //taking input of the graph
    for(int i=1;i<=e;i++)
    {   
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        E[i].a=x;
        E[i].b=y;
        E[i].weight=w;
    }
    int source;//source vertex
    scanf("%d",&source);
    status[source].dist=0;//making the distance of source vertex as 0
    Bellman_ford(a,status,E,v,e);//calling bellman_ford function for finding shortest path to all vertices from source
    return 0;
}