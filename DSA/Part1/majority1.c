#include <stdio.h>
int main()
{
   int n;
   scanf("%d",&n);
   int a[n],freq;
   // read and store elements in an array
     for(int i=0; i<n; i++)
  {
      scanf("%d",&a[i]);
   }
   // finding majority element
    for(int i=0; i<n ; i++)
   {  
       freq=0;
   
      for(int j=0 ;j<n; j++)
    {
       if(a[i]==a[j])
     {
       freq++;
     }
    }
    if(freq>n/2)
     {
     printf("%d\n",a[i]);
     return 0;
     }
   }
  printf("No Majority\n");
}