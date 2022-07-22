#include <stdio.h>
int depth=0; // gobal variable for counting the depth of recursion
int binary_search(int *a,int left,int right,int item )
/*a is the base adress of the array in which searching of an item to be done,
  assume left<=right
  item is the searching element  in the array 
  this function returns -1 if item is not present in the array
  if item present in the array then the return value will be index of that element in the array
  */
{
 int mid;
  // base case of recursive function
  if(left==right)// means if array has only 1 element
  {
    if(a[left]==item)
    {
      return left;
    }
    
    else
    {
      return -1;
    }
  }
  
  else // array has more than 1 element
  {
     mid=(left+right)/2;
     
     if(a[mid]==item)
     {
       return mid;
     }
     
     else if(item>a[mid] && right>mid) // searching the item in right subarray
     { 
        depth++;
        return binary_search(a,mid+1,right,item);
       
     }
     
     else if(item<a[mid] && left < mid) // seraching the item in left subarray
     {
        depth++;
        return binary_search(a,left,mid-1,item);
     }
     else 
     {
        return -1;
     }
  }
}



int main()
{ 
    int n,X,loc;// n is the size of array,Xis the item,loc is the return value of binary_search function
    scanf("%d",&n);
    int A[n];// array for storing integer elements
  
    for(int i=0;i<n;i++)
   {
     scanf("%d",&A[i]);
   }
   
   scanf("%d",&X);
   depth++;
   loc= binary_search(A, 0 ,n-1,X);
   printf("%d\n",depth);
   printf("%d\n",loc);
   return 0;
}