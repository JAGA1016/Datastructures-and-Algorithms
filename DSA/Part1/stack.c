#include <stdio.h>
#include <stdlib.h>
  int i=0;
  struct node        // each node have some element and the address of next node
  {
    int item;
    struct node*next;
  };
  struct node*head=NULL; //declaring head as a global pointer variable 
  /*this function checks whether the stack is empty or not*/
void IsEmpty()
{
   if(head==NULL)
  {
      printf("Empty\n");
      return;
  }
   else
  { 
      printf("Non Empty\n");
  }
}
  /*this function takes the input of type integer and adds that integer into the stack*/
   void Push(int num)
   {    
        struct node *newptr=NULL,*lastptr=NULL;
        newptr=(struct node*)malloc(sizeof(struct node)); //dynamically creating a new node 
         if(newptr!=NULL)
        {
           newptr->item=num;//storing the the value of entered integer in the newly created node
            if(i==0)
           {
               newptr->item=num; 
               newptr->next=NULL;
               head=newptr;
               i++;
           }
            else
           {  newptr->item=num;
              newptr->next=head; // linking the newly added node
              head=newptr;       //bringing head again to the starting 
           }
        }
         else
        {
           printf("Push Failure\n");
        }
      
   }
   
   /*this function deletes the top element of the stack and displays that element*/ 
   void Pop()  
   {  int x;
        if(head!=NULL)
       {  struct node*temptr;
          temptr=head;
          printf("%d\n",temptr->item); //printing the element going to delete
          head=head->next;             // moving head to the next node
          temptr->next=NULL;           
          free(temptr);               //deleting the node
         
       }
        else
       {
          printf("Pop Failure\n");
       }
   }   
   /*this function just displays the top element of the stack*/
   void Top()
   {   
       if(head!=NULL)
      {
         printf("%d\n",head->item);
      }
       else
      {
        printf("Top Failure\n");
      }      
   } 
   /*this function dispalas all elements in the stack*/
   void Display()
   {    struct node*curptr=NULL;
        curptr=head;
        if(head!=NULL)
       {
            while(curptr!=NULL)
           {
              printf("%d\n",curptr->item);
              curptr=curptr->next;
              
           }        
      }
       else
      {
        printf("Empty List\n");
      }
   }
  
  
int main()
{    
       
    while(1)      // infinite loop
   {
        int choice=0,num=0;
        scanf("%d",&choice); // choice from the user
        if(choice==1)
        {
        	scanf("%d",&num);  //  taking an element from the user for choice =1 
        }
        switch(choice)      // calling the functions based on the user's choice
       {
          case 0: IsEmpty();
                  break;
          case 1: Push(num);
                  break;
          case 2: Pop();
                  break;
          case 3: Top();
                  break;
          case 4: Display();
                  break;
          case 5: return 0;
       }
   
   }
   return 0;
}
