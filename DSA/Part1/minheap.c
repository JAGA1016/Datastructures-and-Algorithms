#include<stdio.h>
void minheapify(int *H, int i,int n);// declaring the function minheapify
//this function swaps two integers
void swap(int*x,int*y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  return;
}

//printing the heap
void printheap(int*H,int n)
{
  for( int i=0;i<n;i++)
    {
       printf("%d\n",H[i]);
    } 

}
//this function shifts up the the elment in the tree if its parent greater than its value
void shiftup(int *H, int i)
{
  while(i>0 && H[i]<=H[(i-1)/2])  
  {
      swap(&H[i],&H[(i-1)/2]);
      i=(i-1)/2;
  }
  return;
}
//this function decrease the value of node to new value 
 void decreasekey(int*H,int i,int new)
{
  
 if(H[i]<=new)        //if the value node is less than the new value just return
  { 
     printf("Operation Fail\n");
     return; 
  }
  else
  {
    H[i]=new;  // otherwise shift up it
    shiftup(H,i);
  }
}
void insert(int*H,int x,int*n)
{
  (*n)++; //increasing the size of arry
  H[(*n)-1]=x; //store the new element in the last position of the tree  
  shiftup(H,(*n)-1);//and shift up it recurssively
}
int extractmin(int*H,int* n)  //this function deletes the min value in the heap 
{  int temp;
    temp=H[0];  //store the minvalue in the temp
    H[0]=H[(*n)-1];//copy the last value in heap to root position
    (*n)--;        //decraese the size of the array
    minheapify(H,0,*n); //call minheapify
    return temp;
}
 //this function deletes the element of the heap at a particular position
 int delete(int*H,int i,int*n)
 { 
   int temp;          
   temp=H[i];  //store the value into temp
  H[i]=H[(*n)-1]; //copy the last element in the heap to that position a
  (*n)--;         //decrease the size of array
  minheapify(H,i,*n);//call min heapaify
  return temp;
  
 }

//assupstion in this function is left subtree and right subtree of that node are already heaps

void minheapify(int*H,int i,int n)
{
  int smallest=i; //let smallest is equal to the position at which we are calling minheapify
  if (i >= (n)/2) //leaf node
  {
    return;
  }
 
  if(H[2*i+1]<H[i]) //if left child is less that its parent
 {
     smallest=2*i+1;//smallest=left
 }
  if((2*i+2)<=(n-1) && H[2*i+2]<H[smallest]) //comparing right child with smallest (its brother , its parent)
 {
    smallest=2*i+2;  //smallest=right
 }
 if(H[smallest]==H[i])
 {
     return;
 }
 if(smallest != i)  // smallest is not the parent 
 {
     swap(&H[i],&H[smallest]); //swap it with H[i]
     minheapify(H,smallest,n); // call minheapify for restoring the property of heap
 }
}
void findmin(int*H)  //thus function prints the smallest element in the heap
{
    printf("%d\n",H[0]);
}
 void buildheap(int*H,int n)
{
  int relevant_index=(n-1)/2;   // last non leafnode
  for(int i=relevant_index;i>=0;i--) // going to all non leaf nodes and calling minheapify
  {
      minheapify(H,i,n);
  }
}
int main()
{
    int x,i,n;
    scanf("%d",&n);  
    int H[n];
    for( i=0;i<n;i++)
    {
       scanf("%d",&H[i]);
    }
    buildheap(H,n); //calling build heap fuction
    while(1)
    {
     int choice=0;
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
               scanf("%d", &x);
               insert(H, x,&n);
               break;
      case 2:
              scanf("%d", &i);
              if(n<i)
             {
               printf("Operation Fail\n");
             }
             else
             {
               delete (H, i,&n);
             }
             break;
      case 3:  
                findmin(H);
               extractmin(H,&n);
               break;
      case 4:
              printheap(H,n);
              break;
      case 5:
                  scanf("%d", &i);
                  scanf("%d", &x);
                  if(n<i)
                 {
                    printf("Operation Fail\n");
                 }
                 else
                 {
                    decreasekey(H, i,x);
                 } 
                 break;
      case 6:
                 findmin(H);
                 break;

      case 7:
                return 0;
                

      }
    }
    
}
