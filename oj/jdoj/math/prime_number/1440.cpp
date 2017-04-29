#include <stdio.h>
#include <math.h>

bool judge(int x)
{
    if (x == 2)
        return true;

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

    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;

        int cnt = 0;
        int tmp = n / 2;

        for (int i = 2; i <= tmp; i++) {
            if (judge(i) && judge(n-i))
                cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}
