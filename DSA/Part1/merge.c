#include <stdio.h>
/*  this function take starting address of array,first and last indices as inputs and divides the array into two sub arraysand           
recursively sort the left and right sub arrays and merge them in the new array B ,in the  increasing order and copy them back to
 orginal array*/
  void merge_sort(int*A,int first,int last)
 {
      if(first==last) // if the array has single element
     {
       return;
     }
      int B[last-first+1];      //declaring a new array of size same as original array
      int mid =(first +last)/2;  
     
      merge_sort(A,first,mid); //recursive sorting the left and right sub arrays
      merge_sort(A,mid+1,last);  
     
 
      int i=first,j=mid+1,k=0;// i,j are the starting indices of left and right sub arrays respectively
      while(i<=(mid)&& j<=last)
    {
          if(A[i]<=A[j])        // comparing the two elements from the staring of two subarrays and copying the small element to array B 
         {
           B[k]=A[i];
           k++;
           i++;
         
         }
          else if(A[i]>A[j])
         {
           B[k]=A[j];
           k++;
           j++;
      
         }
       
     }
    
       if(i<=(mid)) // if we find any element remaining in any of the sub array ,copy them to array B directly in the same order
      {
           while(i<=mid)
         {
            B[k]=A[i];
            k++;
            i++;
         }
      }
       else if(j<=(last))
      {
           while(j<=last)
          {
             B[k]=A[j];
             k++;
             j++;
          }
      }
      
       for(i=0;i<=last-first;i++) // finaly copying all the elements in array B back to array A
      {
         A[first+i]=B[i];
      }
 }
int main()
{
     int n,i;
     scanf("%d",&n);
     int A[n];
     for(i=0;i<n;i++)
   {
       scanf("%d",&A[i]);
   }
     int first=0,last=(n-1);
     merge_sort(A,first,last);
     for(i=0;i<n;i++)
     {
      printf("%d\n",A[i]);
     }
     
    return 0;
}
