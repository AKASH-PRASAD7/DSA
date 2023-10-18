#include<iostream>
#include <stdio.h>
using namespace std;
int pivotpos(int a[], int low, int size)
{
    int p = a[low], temp;
    int i = low + 1, j = size ;

    do
    {
        while (a[i] <= p)
        {
            i++;
        }
        while (a[j] > p)//a[j]>= p i wrong
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
void quicksort(int a[], int low, int size)
{

    int pivotindex;
    if (low < size)
    {
        pivotindex = pivotpos(a, low, size);
        quicksort(a, low, pivotindex - 1);
        quicksort(a, pivotindex + 1, size);
    }
}

void show(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int a[] = {2, 3, 1,  0, 8, 4, 3, 2};
    int s = sizeof(a) / sizeof(int);
    show(a, 9);
    quicksort(a, 0, s-1);
    show(a, 9);

    return 0;
}