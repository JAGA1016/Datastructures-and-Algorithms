#include<stdio.h>
#include<stdlib.h>
  struct node
 {
    int item;           // each node have one integer and the address of next node
    struct node*next; 
 };
  /*this function takes the inputs starting address of link list and size of the linked list in which we are going to sort
    and this fuction calls itself recursively upto size*/
  void insertion_sort(struct node *first,int size)
  {
     if(size==0) //base case
    {
        return;
    }
     insertion_sort(first,size-1); //recursive case
     for(int i=0;i<(size-1);i++) // variable size is size of linked list in which we have to do sorting
    {    int temp;
         struct node *p,*q; // p and q used for inerchange the values of nodes if previous node >next node
                            // else move pointers to next poistion
         p= first;
         q= first->next;
         for(int j=0;j<(size-1);j++)
        {
      
            if( (p->item)>(q->item) )//if previous node value>next node value interchange the values
            {
               temp=p->item;
               p->item=q->item;
               q->item=temp;
               break;
            }
            else                  //else move p,q pointers to next position
            {
               p=p->next;          
               if(q->next != NULL)
               {
                q=q->next;
               }
            }
        }
    }
  }
  
  
  int main()
{    
    int n,x;
    struct node*newptr=NULL,*lastptr=NULL,*head=NULL,*curptr=NULL;
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
           }
           else
           {
             lastptr->next=newptr; //linking previous node and new node
             lastptr=newptr; //storing the address of new pointer inthe previous pointer for next link
           }
       }

       else // if malloc returns null pointer then error in allocating memory
      {
          printf("alloc failed\n");
         
      }
  }     curptr=head;
        insertion_sort(head,n); 
        while(curptr!=NULL) // printing all the elements of the linked list
       {   
           printf("%d\n",curptr->item);
           curptr=curptr->next;
       }
     return 0;
}
       