#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int num[1000];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }

        if (n == 1) {
            printf("%d\n", num[0]);
            printf("-1\n");
        } else {
            sort(num, num + n);
            printf("%d\n", num[n-1]);
            for (int i = 0; i < n - 2; i++) {
                printf("%d ", num[i]);
            }
            printf("%d", num[n-2]);
            printf("\n");
        }
    }

    return 0;
}
