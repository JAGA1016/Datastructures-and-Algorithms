#include <stdio.h>
int main()
{
   int n;
   scanf("%d",&n);
   int a[n],freq,curr_element;
   
     for(int i=0; i<n; i++)
   {
      scanf("%d",&a[i]);
   }
     freq=0;
     //finding the element which repeated maximum number of times 
     for(int i=0;i<n;i++)
   {
       if(freq==0)
      {
        freq=1;
        curr_element=a[i];
        
      }
       else if(a[i]==curr_element)
      {
         freq++;
        }
       
         else
        {
          freq--;
        }
      
       
  }  //checking whether the current element is the majority element or not
     freq=0;
     
     for(int i=0 ;i<n;i++)
     {
        if(curr_element==a[i])
       {
         freq++;
       
       }
     }
     
      if(freq>n/2)
     {
      printf("%d",curr_element);
      
     }
     
     else
     {
       printf("No Majority\n");
     }
  return 0;
  
 }