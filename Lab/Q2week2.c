#include <stdio.h>
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
        int key, a, b, k, flag = 0;
        int count;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int sum = arr[i] + arr[j];
                int start = j + 1, end = n - 1, mid;
                while (start <= end)
                {
                    mid = (start + end) / 2;
                    if (arr[mid] == sum)
                    {
                        flag = 1;
                        break;
                    }
                    else if (arr[mid] < sum)
                    {
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
                if (flag == 1)
                    {
                        printf("sequence are : %d %d %d", i, j, mid);
                        break;
                    }
            }
            if (flag == 1)
                break;
        }
        if (flag != 1)
        {
            printf("no sequence");
        }
        test_case--;
    }
}
