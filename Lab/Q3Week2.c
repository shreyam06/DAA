#include <stdio.h>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int test_case;
    scanf("%d", &test_case);
    while (test_case)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int k;
        scanf("%d", &k);
        int count = 0;
        int mid;
        qsort(arr, n, sizeof(int), cmpfunc);
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n)
            {
                int diff = arr[j] - arr[i];
                if (diff == k)
                {
                    count++;
                    break;
                }
                else if (diff < k)
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        printf("pairs are : %d", count);
        test_case--;
    }
}
