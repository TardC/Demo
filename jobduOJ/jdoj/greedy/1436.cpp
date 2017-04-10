#include <stdio.h>
#include <algorithm>
#define MAX 600

using namespace std;

int main()
{
    int l, n;
    int block[MAX];

    while (scanf("%d%d", &l, &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &block[i]);
        }

        sort(block, block + n);

        int ans = 0;
        int tmp = 0;
        int flag = 0;

        for (int i = n - 1; i >= 0; i--) {
            tmp += block[i];
            ans++;
            if (tmp >= l) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("%d\n", ans);
        } else if (flag == 0) {
            printf("impossible\n");
        }
    }

    return 0;
}
