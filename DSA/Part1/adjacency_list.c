#include<stdio.h>
#include<stdlib.h>
struct node
  {
    int item;            //each node have some element and the address of next node
    struct node*next;
  };
   struct node*head=NULL;
   //this function forms an edge between two vertices of the graph
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
  
      for (int k = 0; k < v; k++)
    {
        head = &a[k];
        if (head->next == NULL) 
        {
            printf("Nil\n");//if the vertex has no neighbours print Nil
        }
        else
        {
            while (head->next != NULL)  //printing the neighbours of ecah vertex in the specified format
            {
                head= head->next;
                printf("%d", head->item);
                if (head->next != NULL)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
        return 0;
}
  

