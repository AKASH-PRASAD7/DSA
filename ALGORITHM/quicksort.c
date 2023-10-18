#include <stdio.h>
int pivotpos(int a[], int low, int size)
{
    int p = a[low], temp;
    int i = low + 1, j = size ;

    do
    {
        while (p >= a[i])
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
int quicksort(int a[], int low, int size)
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
        printf("%d", a[i]);
        printf(" ");
    }
}
int main()
{
    int a[] = {2, 3, 1, 56, 0, 78, 4, 3, 22};
    int s = sizeof(a) / sizeof(int);
    quicksort(a, 0, s-1);
    show(a, s);

    return 0;
}