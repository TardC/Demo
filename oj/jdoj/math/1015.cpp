#include <stdio.h>

int main(void)
{
    int a, b, k;

    while (scanf("%d %d %d", &a, &b, &k) != EOF && a != 0 && b != 0) {
        int a_plus_b = a + b;
        int tmp1 = 0, tmp2 = 0;

        for (int i = 0, rank = 1; i < k; i++) {
            tmp1 += (a % 10) * rank;
            tmp2 += (b % 10) * rank;
            a /= 10;
            b /= 10;
            rank *= 10;
        }

        if (tmp1 == tmp2)
            printf("-1\n");
        else
            printf("%d\n", a_plus_b);
    }

    return 0;
}
