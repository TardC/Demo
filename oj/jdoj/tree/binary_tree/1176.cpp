#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        int tree[n+1];
        int d;

        for (int i = 1; i <= n; i++)
            scanf("%d", &tree[i]);
        scanf("%d", &d);

        if (d == 1)
            printf("%d\n", tree[1]);
        else if (d > 1) {
            int left = pow(2, d-1);
            int right = 2*pow(2, d-1) - 1;

            if (n >= right) {
                for (int i = left; i <= right; i++) {
                    if (i == left)
                        printf("%d", tree[i]);
                    else
                        printf(" %d", tree[i]);
                }
                printf("\n");
            } else {
                for (int i = left; i <= n; i++) {
                    if (i == left)
                        printf("%d", tree[i]);
                    else
                        printf(" %d", tree[i]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
