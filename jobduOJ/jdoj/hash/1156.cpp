#include <stdio.h>
#define MAX 201

int main()
{
    int reader[MAX];
    int book[MAX];
    int n, m, tmp;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < MAX; i++) {
            book[i] = 0;
        }
//        for (int i= 0; i < MAX; i++) {
//            reader[i] = 0;
//        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &reader[i]);
            tmp = reader[i];
            book[tmp]++;
        }

        for (int i = 0; i < n; i++) {
            tmp = reader[i];
            if (book[tmp] > 1)
                printf("%d\n", book[tmp] - 1);
            else if (book[tmp] == 1)
                printf("BeiJu\n");
        }
    }

    return 0;
}
