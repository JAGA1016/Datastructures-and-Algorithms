#include<stdio.h>
#include<stdlib.h>
  struct node
  {
    int item;                  // each node have some element and the address of next node and address of the previous node
    struct node*next;
    struct node*prev;
  };
int main()
{   struct node*newptr=NULL,*lastptr=NULL,*head=NULL,*curptr=NULL,*last=NULL;
    int n,x;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
   {
       newptr=(struct node*)malloc(sizeof(struct node)); //dynamically allocating nodes of size struct node

        if(newptr!=NULL)
       { 
           scanf("%d",&x); 
           newptr->item=x;//storing the the value of entered integer in the newly created node
           newptr->next=NULL;
           
           if(i==0)
           { 
             head=newptr; // starting address of 1st node storing in head 
             lastptr=head;
             newptr->prev=NULL;
           }
           else
           {
             lastptr->next=newptr; //linking previous node and new node
             newptr->prev=lastptr;
             lastptr=newptr;    //storing the address of new pointer inthe previous pointer for next link
                          
           }
           
       }

       else // if malloc returns null pointer then error in allocating memory
      {
          printf("alloc failed\n");
         
      }
  }     
   last=newptr;
   curptr=head;                 //printing elements from first to last before removing end nodes
   while(curptr!=NULL) 
     { 
         printf("%d\n",(*curptr).item);
         curptr=(curptr)->next; 

     }
   curptr=last;              //printing elements from last to first before removing end nodes
   while(curptr!=NULL)
     { 
         printf("%d\n",(*curptr).item);
         curptr=(curptr)->prev; 

     }
     struct node*temptr;//deleting the first node of double link list
          temptr=head;
          head=head->next; 
          temptr->next=NULL; //breaking the link
          head->prev=NULL;
          free(temptr);
     struct node*tempptr;       //deleting the last node
          tempptr=last;         //storing the last pointer in tempptr pointer
          last=last->prev;      //moving the last to a node just before last node 
          last->next=NULL;     // breaking the link
          tempptr->prev=NULL;
          free(tempptr);   //freeing the tempptr
  
   curptr=head;            //printing elements from first to last after removing end nodes
   while(curptr!=NULL) 
     { 
         printf("%d\n",(*curptr).item);
         curptr=(curptr)->next; 

     }
   curptr=last;           //printing elements from last to first after removing end nodes
   while(curptr!=NULL)
     { 
         printf("%d\n",(*curptr).item);
         curptr=(curptr)->prev; 

     }
     return 0;
}
  
  