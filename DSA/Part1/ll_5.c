#include<stdio.h>
struct node
{
  int a;           // each node have some element and the address of next node
  struct node*next; 
};
 int main()
 {   
     int x, i=0;
     struct node x1,x2,x3,x4,x5,p,q;//creating nodes of structure type
     struct node*curptr=NULL; //intialising all pointers to null
     struct node*head=NULL;
     x1.next=NULL;
     x2.next=NULL;
     x3.next=NULL;
     x4.next=NULL;
     x5.next=NULL;
     head = &x1;   //head of type struct node pointer stores the address offirst node 
     curptr=head;  //assing head to the current pointer
     x1.next=&x2;
     x2.next=&x3;
     x3.next=&x4;
     x4.next=&x5;
      while(curptr!=NULL)  //read and store integers
     { 
         scanf("%d",&(*curptr).a);
         curptr=curptr->next; 

     }
      curptr=head;
     while(curptr!=NULL) //printing 5 integers
     { 
         printf("%d\n",(*curptr).a);
         curptr=(curptr)->next; 

     }
     
      scanf("%d",&x);//reading a new integer
     curptr=head;
      while(curptr!=NULL) //if there is a first  element greater than x from starting of linked list,then insert a  node q before that element
      {                      // and store x in that node
          if(((*curptr).a)>x)
          { 
            if(curptr==head)
            {
              q.next=&x1;
              q.a=x;
              head=&q;
              break;
            }
            else
            {
              (*(curptr-1)).next=&q;
              q.next=&(*(curptr));
              q.a=x;
              break;
            }
          }
          else // else move the current pointer to
          {
             curptr=curptr->next;
          }
      }
   
      if(curptr==NULL) // if current pointer reaches null means there is no elment greater than x,then insert a node p at the end and store 
                       //the x in that node
      {
        x5.next=&p;
        p.a=x;
        p.next=NULL;    
      }
       curptr=head;
       while(curptr!=NULL) // print all the elements after inserting a new integer
     { 
         printf("%d\n",(*curptr).a);
         curptr=(curptr)->next; 

     }
      
      
      return 0;
 }