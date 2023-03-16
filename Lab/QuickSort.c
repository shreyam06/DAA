#include <stdio.h>
#define n 8
int partition (int a[],int l,int h)
{
    int i=l-1,t;
    int piv=a[h];
    for(int j=l;j<=h-1;j++){
        if(a[j]<piv){
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[h];
    a[h]=t;
    return i+1;
}
void quicksort (int a[],int l,int h)
{
    if(l<h)
    {
        int piv_index=partition(a,l,h);
        quicksort(a,l,piv_index-1);
        quicksort(a,piv_index+1,h);
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
    int a[n];
    printf("enter the array elements");
    for (int i = 0; i < n; i++)  
        scanf("%d", &a[i]); 
    quicksort(a,0,n-1);
    printf("sorted array is:- ");
    printArr(a, n);  
    /*for(int i=0;i<n;i++)
    {
       if(a[i]==a[i+1]){
            printf("YES");
            count++;
            break;
       }
    }
    if(count=0)
        printf("NO");
        */
}
