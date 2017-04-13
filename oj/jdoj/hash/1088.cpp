#include <stdio.h>
#define MAX 10001

int main()
{
    int r[MAX];
    int l, m, s, e;

    while (scanf("%d%d", &l, &m) != EOF) {
        for (int i = 0; i < MAX; i++)
            r[i] = 0;

        for (int i = 0; i <= l; i++) {
            r[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &s, &e);
            for (int j = s; j <= e; j++)
                r[j] = 0;
        }
        int ans = 0;
        for (int i = 0; i <= l; i++)
            if (r[i] == 1)
                ans += 1;
        printf("%d\n", ans);
    }

    return 0;
}
