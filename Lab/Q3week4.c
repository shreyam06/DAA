#include <stdio.h>
#define n 10
int partition(int a[], int l, int h)
{
    int i = l - 1, t;
    int piv = a[h];
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < piv)
        {
            i++;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[i + 1];
    a[i + 1] = a[h];
    a[h] = t;
    return i + 1;
}
void quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int piv_index = partition(a, l, h);
        quicksort(a, l, piv_index - 1);
        quicksort(a, piv_index + 1, h);
    }
}
void printArr(int a[], int m)
{
    int i;
    for (i = 0; i < m; i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[n],k;
    printf("Enter the array elements");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    printf("sorted array is:- ");
    printArr(a, n);
    printf("\nEnter the value of k\n");
    scanf("%d",&k);
    int choice;
    printf("Enter the choice 1:- kth smallest number \n2:-kth largest number");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Kth smallest element is %d",a[k-1]);
        break;
        case 2:
        printf("kth largest number is %d",a[n-k-1]);
        break;
    }
}
