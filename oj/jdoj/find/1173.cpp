#include <stdio.h>
#define MAX 100

int main()
{
    int n, m, flag;
    int a[MAX], b[MAX];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < m; i++) {
            flag = 0;
            for (int j = 0; j < n; j++) {
                if (b[i] == a[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
