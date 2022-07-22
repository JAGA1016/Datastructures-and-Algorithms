#include<stdio.h>
// this function keep on shifting elements that are greater than element stored in temp variable and finally copies value in temp toa[index] 
void insertion (int n, int* a) 
{
    int temp, index = n-1;
    temp = a[n-1];
    for (int i = n-2; i >= 0; i--)
    {
       if (temp < a[i])
        {
            a[i+1] = a[i];
            index = i;
        }
        else
        {
            break;
        }
      

    }
    a[index] = temp;
}
//this function calls it's self until n=1 and after that it calls insertion function
void insertion_sort (int n, int* a)
{
    if (n > 1)
    {
        insertion_sort (n-1, a);// calling insertion_sort function
        insertion (n, a);// calling insertion function
    }
}

int main()
{
    int n;// declaration of size of array
    
    scanf ("%d", &n); //read and store array size
    int A[n]; // declaring array of size n
    
    for (int i = 0; i < n; i++) //read and store elements into the array 
    {
        scanf ("%d", &A[i]); 
    }
    
    insertion_sort(n, A);// calling insertion_sort function
    for (int i = 0; i < n; i++) // display all elements of sorted array
    {
        printf ("%d\n", A[i]);
    }
    return 0;
}