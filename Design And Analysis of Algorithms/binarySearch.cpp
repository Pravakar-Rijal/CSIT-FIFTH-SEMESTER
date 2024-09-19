#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == element)
            return mid;
        else if (arr[mid] > element)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
	int a;
    int arr[] = {1, 8, 15, 20, 35, 56, 88,99};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element, index;

    printf("Enter the element to search in an sorted array:\t");
    scanf("%d", &element);

    index = binarySearch(arr, size, element);

    if (index != -1)
        printf("\nElement %d found at the index %d.\n", element,index);
    else
        printf("\nElement %d not found in the sorted array.\n", element);

    return 0;
}
