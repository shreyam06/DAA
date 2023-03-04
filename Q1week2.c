#include <stdio.h>
#define n 10
int binarSearch(int a[], int num, int key)
{
    int l = 0, mid;
    int r = num - 1, count = 0;
    while (l <= r)
    {
        count++;
        mid = (l + r) / 2;
        // printf("%d",l);
        if (key == a[mid])
        {
            printf("%d  ", count);
            return mid;
        }
        else if (key < a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    int a[n], key;
    printf("enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the value of data to be searched");
    scanf("%d", &key);
    int value = binarSearch(a, n, key);
    if (value == -1)
        printf("Not present");
    else
    {
        printf("Present\n");
        int dup = 0;
        for (int i = value; i < n; i++)
        {
            if (a[i] == key)
                dup++;
        }
        printf("Total no. of duplicate keys's are %d", dup);
    }
}
