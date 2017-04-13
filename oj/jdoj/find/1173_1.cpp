#include <stdio.h>
#include <algorithm>
#define MAX 80

using namespace std;

int main()
{
    int n, m, flag;
    int a[MAX], b[MAX];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        sort(a, a + n);

        for (int i = 0; i < m; i++) {
            flag = 0;
            int s = 0;
            int e = n - 1;
            while (e >= s) {
                int mid = (s + e) / 2;
               if (b[i] == a[mid]) {
                    flag = 1;
                    break;
               } else if (b[i] > a[mid]) {
                    s = mid + 1;
               } else {
                    e = mid - 1;
               }
            }
            if (flag == 1){
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}
