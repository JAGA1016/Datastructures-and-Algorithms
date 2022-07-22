#include<stdio.h>
  struct node
 {
    int item;           // each node have some element and the address of next node
    struct node*next; 
 };
  /*this function takes the inputs starting address of link list and size of the linked list in which we are going to sort
    and this fuction calls itself recursively upto size*/
  void insertion_sort(struct node *first,int size)
  {
     int k=0,temp=0;
     if(size==0)//base case
    {
        return;
    }
     insertion_sort(first,size-1); //recursive case
     for(int i=0;i<(size-1);i++)
    {
         struct node *p,*q;
         p= first;                             // p and q used for inerchange the values of nodes if previous node >next node
         q= first->next;                       // else move pointers to next poistion
        
         for(int j=0;j<(size-1);j++)
        {
      
            if( (p->item)>(q->item) )//if previous node value>next node value interchange the values
            {
               temp=p->item;
               p->item=q->item;
               q->item=temp;
               break;
            }
            else                     // else move pointers to next poistion
            {
               p=p->next;
               if(q->next != NULL)
               {
                  q=q->next;
               }
            }
        }
    }
  
     struct node *first1;
     /*declaring another pointer of type of struct node (first1) and initialising it to starting address of firstnode ,for printing the   numbers upto sorted list*/
     first1 = first;
     while(k<size)
    {   
         printf("%d\n",first1->item);
         first1=first1->next;
         k++;
    }
   
  }
  int main()
 {
     struct node x1,x2,x3,x4,x5;//creating nodes of structure type
     struct node*curptr=NULL;   //intialising all pointers to null
     struct node*head=NULL;
     x1.next=NULL;
     x2.next=NULL;
     x3.next=NULL;
     x4.next=NULL;
     x5.next=NULL;
     head = &x1; 
     curptr=head;             
     x1.next=&x2;
     x2.next=&x3;
     x3.next=&x4;
     x4.next=&x5;
      while(curptr!=NULL)  //read and store integers in linked list
     { 
         scanf("%d",&(*curptr).item);
         curptr=curptr->next; 
     }
     curptr=head;
    
     insertion_sort(head,5);// calling the function insertion sort
     return 0;
 }     
     
       