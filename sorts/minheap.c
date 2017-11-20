#include<stdio.h>
int least;
void minheap(int arr[], int n, int i)
{
int t;
    least = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
        if (l < n && arr[l] < arr[least])
        least = l;
        if (r < n && arr[r] < arr[least])
        least = r;
        if (least != i)
    {   t=arr[i];
        arr[i]= arr[least];
        arr[least]=t;
        minheap(arr, n, least);
    }
}

void heapSort(int arr[], int n)
{int i,t;
       for (i = n / 2 - 1; i >= 0; i--)
        minheap(arr, n, i);
         for ( i=n-1; i>=0; i--)
    {
        t=arr[i];
        arr[i]= arr[0];
        arr[0]=t;

            minheap(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
   int i;
    for (i=0; i<n; i++)
         printf("%d ",arr[i]);
   printf("\n");
}

int main()
{
int n,i;
printf("enter size of array: ");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
heapSort(arr, n);
printArray(arr, n);
}

