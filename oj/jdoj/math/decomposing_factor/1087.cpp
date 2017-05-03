#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;

        long long num[n];
        for (int i = 0; i < n; i++)
            scanf("%lld", &num[i]);

        long long ans[n];
        memset(ans, 0, sizeof(ans)); // long long ans[n] = {0};
        for (int i = 0; i < n; i++) {
            if (num[i] == 1) {
                ans[i] = 1;
                continue;
            }

            long long bound = (long long)sqrt(num[i]) + 1;
            for (long long j = 1; j < bound; j++) {
                if (num[i] % j == 0) {
                    if (j == num[i] / j)
                        ans[i] += 1;
                    else
                        ans[i] += 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
            printf("%lld\n", ans[i]);
    }

    return 0;
}
