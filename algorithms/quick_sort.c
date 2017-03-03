#include <stdio.h>
void quick_sort(int left, int right);
int book[101], n;

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
        scanf("%d", &book[i]);
    quick_sort(1, n);

    for (i=1; i<=n; i++)
        printf("%d ", book[i]);

    getchar();getchar();
    return 0;
}

void quick_sort(int left, int right)
{
    int i, j, t, temp;

    if (left > right)
        return ;

    temp = book[left];  // temp´æ´¢»ù×¼Öµ
    i = left;
    j = right;
    while (i != j)
    {
        while (book[j]>=temp && i<j)
            j--;
        while (book[i]<=temp && i<j)
            i++;
        if (i < j)
        {
            t = book[i];
            book[i] = book[j];
            book[j] = t;
        }
    }
    book[left] = book[i];
    book[i] = temp;
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);

    return ;
}
