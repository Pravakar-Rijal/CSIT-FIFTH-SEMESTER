#include <stdio.h>
void insertion_sort(int a[],int n)
{
   int i,key;
   for(int j=1;j<n;j++)
   {
       key=a[j];
       i=j-1;
       while(i>=0&&a[i]>key)
     {
             a[i+1]=a[i];
             i--;
     }
     a[i+1]=key;
   }
}

int main() {
    int arr[5]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    for(int i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
