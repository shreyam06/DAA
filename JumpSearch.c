#include <stdio.h>
#include <math.h>
#define n 10
int main()
{
    int key, count = 0;
    int a[n];
    printf("enter the array element\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the key");
    scanf("%d", &key);
    int start = 0, end = sqrt(n);
    while (a[end] < key)
    {
        start = end;
        end += sqrt(n);
        if (end > n - 1)
        {
            end = n - 1;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            printf("present \t");
            break;
        }
        count++;
    }
    count += 1;
    if (count > n)
    {
        printf("Not present");
    }
    else
        printf("%d", count - 1);
}
