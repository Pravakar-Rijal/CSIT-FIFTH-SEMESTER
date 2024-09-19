#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main()
{
    int arr[] = {24, 35, 12, 1, 6, 8, 55 , 22, 88, 48};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The originally inserted array is:{ ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        printf(" }");
printf("\n");
    bubbleSort(arr, n);

    printf("\nThe element after sorting the array is:{ ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
printf(" }");
    return 0;
}

