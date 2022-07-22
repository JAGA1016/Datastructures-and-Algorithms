#include<stdio.h>

int pivot_partition (int* arr, int left, int right, int pivot_index)
/*declaration of pivot_partition function to partition elements with respect to pivot index
by taking parameters as array address [integer pointer type] and indices of left-most and right-most 
elements of the part of the array that is required to be sorted and pivot_index[integer type]*/
{
    int r=0,temp, i, j; //declaration of required variables
    for ( i = left; i <= right; i++)
    {
        if (arr[i] < arr[pivot_index]) //comparing all the elements of the array with the pivot value
        {
            r++;
            /*the variable r stands for number of elements whose value is strictly less than pivot element
            we incriment r by 1 if arr[i]<arr[pivot_index] {that is, whenever we find an element less than pivot value}*/
        }
    }
    temp = arr[left+r]; //swaping of arr[left+r] and arr[pivot_index] values so that now arr[left+r] contains the pivot value
    arr[left+r] = arr[pivot_index];
    arr[pivot_index] = temp;
    i = left; //initialising i to left and j to left+r+1
    j = left+r+1;
    while (i<(left+r) && j<=right) //going through the loop while i<left+r and j<=right
    {
        while (i<(left+r) && arr[i]<arr[left+r])
        {
            i++; // incrimenting i by 1 if arr[i]<pivot value and i<left+r
        }
        while (j<=right && arr[j]>=arr[left+r])
        {
            j++; //incrimenting j by 1 if arr[j]>=pivot value and j<=right
        }
        if (i<(left+r) && j<=right)
        {
            temp = arr[i]; //swaping arr[i] and arr[j] values if i<left+r and j<=right
            arr[i] = arr[j]; 
            arr[j] = temp;
            i++; //incrimenting both i and j by 1 after swaping
            j++;
        }
    }
    return (left+r); //returning the value of index of first occurence of pivot value after partitioning
}

void quick_sort (int* arr, int left, int right)
/*declaration of quick_sort function of void type to sort elements of an array A in increasing order, 
by taking parameters as array address [integer pointer type] and indices of left-most and right-most 
elements of the part of the array that is required to be sorted [integer type]*/
{
    if (right > left)
    {
        int pi = pivot_partition (arr, left, right, left+1); 
        /*calling pivot_partition function to partition elements with respect to pivot index of 1
        and storing the value of index of first occurence of pivot value after partitioning in variable pi*/
        quick_sort (arr, left, pi-1); //recursively calling quick_sort function to sort part of array that is left to iof
        quick_sort (arr, pi+1, right); //recursively calling quick_sort function to sort part of array that is right to iof
    }
}

int main()
{
    int n;
    
    scanf ("%d", &n);
    int a[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &a[i]);
    }
   
    quick_sort (a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf ("%d\n", a[i]);
    }
    return 0;
}