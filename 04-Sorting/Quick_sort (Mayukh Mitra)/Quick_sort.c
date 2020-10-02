#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int c = 0;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// p = low, r = high
// partition algorithm
int sedgewick_partition(int *arr, int p, int r)
{
    int i, j;
    i = p;
    j = r + 1;
    int random = p + rand()%(p - r);
    swap(&arr[p], &arr[random]);
    int pivot = arr[p]; 
    while (i < j)
    {
        do
        {
            j--;
        } while (++c && arr[j] > pivot);
        do
        {
            i++;
        } while (++c && arr[i] < pivot);
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[p]);
    return j;
}
int sedgewick_quick_sort(int *arr, int p, int r)
{
    int q;
    if (p < r)
    {
        q = sedgewick_partition(arr, p, r);
        sedgewick_quick_sort(arr, p, q - 1);
        sedgewick_quick_sort(arr, q + 1, r);
    }
}

int main(void)
{
    int i, *arr, ch, n;
    printf("\nenter size of array : ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 10 + 1; // generating random elemnet for array..
    }

    printf("The elements of the array is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    sedgewick_quick_sort(arr, 0, n - 1);

    printf("The sorted array is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}

// end code
// contributor -> mayukh mitra.