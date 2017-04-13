#include <stdio.h>
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
int day_of_month[13][2] = {
    0, 0,
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31
};

int main()
{
    int y, m, d;
    int ans = 0;

    while (scanf("%d %d %d", &y, &m, &d) != EOF) {
        for (int i = 1; i < m; i++) {
            ans += day_of_month[i][ISYEAP(y)];
        }
        ans += d;
        printf("%d\n", ans);
        ans = 0;
    }

    return 0;
}
