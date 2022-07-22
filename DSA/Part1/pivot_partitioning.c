#include <stdio.h>

/* x and y are two pointer variables and the swap function  exchange the their values*/
void swap(int *x,int *y)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=temp;
 }

int main()
{
   int n,k,r=0;
   scanf("%d",&n);
 
   int a[n];
   for(int i=0; i<n ;i++)
  {
 
    scanf("%d",&a[i]);
  }

   scanf("%d",&k);
   
   for(int i=0;i<n;i++) // counting the number of elements less than element with a[k]
   {
        if(a[i]<a[k])
        {
          r++;
        }
   
   }
   swap(&a[k],&a[r]);
   
   int i=0,j= (r+1); 
   
   while(i<r && j<n) 
   {
       while(j<n &&a[i]<a[r]) 
       {
     
            i++;
       }
       
       while(j<n && a[j]>=a[r]) 
       {
       
            j++;
       }
       
       if(i<r && j<n)
       {
         swap(&a[i],&a[j]);
         i++;
         j++;
       }
   }
   
   for(int i=0;i<n ;i++)
   {
      printf("%d\n",a[i]);
   }
   return 0;
}