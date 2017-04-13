#include <stdio.h>
#define MAX 10

int main()
{
    int a[MAX][MAX];
    int b[MAX][MAX];
    int c[MAX][MAX];
    int m, n;

    while (scanf("%d", &m) != EOF) {
        if (m == 0)
            break;

        scanf("%d", &n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        int total = 0;
        for (int i = 0; i < m; i++) {
            int flag = 1;
            for (int j = 0; j < n; j++) {
                if (c[i][j] != 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                total++;
        }
        for (int i = 0; i < n; i++) {
            int flag = 1;
            for (int j = 0; j < m; j++) {
                if (c[j][i] != 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                total++;
        }
        printf("%d\n", total);
    }

    return 0;
}
