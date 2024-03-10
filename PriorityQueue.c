//Maximum priority queue using MAX Heap


#include <stdio.h>
#define MAX 10  
int h[MAX], n = 0;
void heapify()
{
    int i, j, heap, k, v;
    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = h[k];
        heap = 0;
        while (!heap && 2 * k <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if (h[j] < h[j + 1])
                {
                    j = j + 1;
                }
            }
            if (v >= h[j])
                heap = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}


void insertpq(int ele)
{
    if (n >= MAX)
    {
        printf("\nOverflow bhai!");
        return;
    }
    n++;
    h[n] = ele;
    heapify();
}

void deletepq()
{
    if (n == 0)
    {
        printf("\n Underflow bhai!");
        return;
    }
    int temp = h[n];
    h[n] = h[1];
    h[1] = temp;
    printf("\n Deleted %d", h[n]);
    n--;
    heapify();

}

void display()
{

    if (n == 0)
    {
        printf("\nPQueue is empty");
        return;
    }
    printf("\n PQueue contents: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", h[i]);
    }
}
int main()
{
    int choice, ele;
    while (1)
    {
        printf("\n Pqueue: 1.Insert, 2.Delete, 3.Display");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element: ");
            scanf("%d", &ele);
            insertpq(ele);
            display();
            break;

        case 2:
            deletepq();
            display();
            break;

        case 3:
            display();

        default:
            return 0;
        }
    }

    return 0;
}