#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, m;

    while (scanf("%d %d", &m, &n) != EOF && m != 0 && n != 0) {
        int count, left, right;

        count = 0;
        left = right = m;
        int deep_m = (int)(log(m)/log(2) + 1);
        int deep_n = (int)(log(n)/log(2) + 1);
        int deep_diff = deep_n - deep_m;

        count += (int)pow(2, deep_diff) - 1;

        for (int i = 1; i <= deep_diff; i++) {
            left = 2 * left;
            right  = 2 * right + 1;
        }

        if (right <= n)
            count += right - left + 1;
        else if (left <= n)
            count += n - left + 1;

        printf("%d\n", count);
    }

    return 0;
}
