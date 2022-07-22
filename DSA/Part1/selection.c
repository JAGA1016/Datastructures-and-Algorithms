#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, max_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the maximum element in unsorted array
		j=0;
		max_idx = j;
		for (j = 0; j < n-(i); j++)
		{
		      if (arr[j] > arr[max_idx])
		     {
			max_idx = j;
		     }
		}
		// Swap the found maximum element with the last element
		swap(&arr[max_idx], &arr[n-(i+1)]);
	}
}



int main()
{
	int n ;
	scanf("%d",&n);
	int A[n];
	
	for(int i=0 ;i<n ;i++)
	{
	   scanf("%d",&A[i]);
	}
	
	selectionSort(A, n);
	for(int i=0 ;i<n ;i++)
	{
	   printf("%d\n",A[i]);
	}
	
	return 0;
}
