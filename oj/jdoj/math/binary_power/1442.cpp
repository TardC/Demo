#include <stdio.h>
#include <math.h>
#define M 200907

long long power(long long a, long long b)
{
    long long ans = 1;

    while (b != 0) {
        if (b % 2 == 1)
            ans = (ans * a) % M;

        a = (a * a) % M;
        b /= 2;
    }

    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        long long num[3];
        long long k;
        for (int j = 0; j < 3; j++)
            scanf("%lld", &num[j]);
        scanf("%lld", &k);

        int ans;
        if (num[2] - num[1] == num[1] - num[0]) {  // 等差数列
            long long d = num[1] - num[0];
            ans = (num[0]%M + (((k - 1)%M)*(d%M))) % M;
        } else if (num[2] / num[1] == num[1] / num[0]) {  // 等比数列
            long long q = num[1] / num[0];
            ans = ((num[0]%M) * (power(q, k-1)%M)) % M;
        }
        printf("%d\n", ans);
    }

    return 0;
}
