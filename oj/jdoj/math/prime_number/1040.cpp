#include <stdio.h>
#include <math.h>

int prime[10001];

bool judge(int x)
{
    if (x % 2 == 0)
        return false;

    int bound = (int)sqrt(x) + 1;
    for (int i = 3; i < bound; i += 2) {
        if (x % i == 0)
            return false;
    }

    return true;
}

int main(void)
{
    int n;

    int k = 1;
    for (int i = 2; ; i++) {
        if (i == 2) {
            prime[k] = 2;
            k++;
            continue;
        }

        if (judge(i)) {
            prime[k] = i;
            k++;
        }

        if (k > 10000)
            break;
    }

    while (scanf("%d", &n) != EOF)
        printf("%d\n", prime[n]);

    return 0;
}
