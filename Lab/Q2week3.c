#include <stdio.h>
#define n 8
int main()
{
    int a[n],t, comparisons = 0, swaps = 0;
    printf("enter the array elements");                     
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n-1; i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
                comparisons++;
        }
        if(min != i){
            t=a[min];
            a[min]=a[i];
            a[i]=t;
            swaps++;
        }
    }
    printf("sorted array is:- ");
    for (int k = 0; k < n; k++)
        printf("%d  ", a[k]);
    printf("\nTotal no of comparisons are:- %d\nTotal no. of swaps are:- %d", comparisons, swaps);
}
