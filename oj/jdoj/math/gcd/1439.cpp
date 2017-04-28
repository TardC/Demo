#include <stdio.h>

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);

            long long num[m];
            for (int j = 0; j < m; j++)
                scanf("%lld", &num[j]);

            long long ans = num[0];
            for (int k = 1; k < m; k++) {
                long long tmp = gcd(ans, num[k]);
                ans = ans*num[k]/tmp;
            }

            printf("%lld\n", ans);
        }
    }

    return 0;
}
