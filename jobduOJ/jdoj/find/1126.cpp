#include <stdio.h>
#define MAX 80

int main()
{
    int n, k, num[MAX], flag;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        flag = 0;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &num[j]);
        }

        for (int l = 0; l < k; l++) {
            if (l == 0) {
                if (num[l] != num[l+1]) {
                    printf("%d", l);
                    flag = 1;
                }
            } else if (l == k - 1) {
                if (num[l] != num[l-1]) {
                    if (flag == 0) {
                        printf("%d", l);
                        flag = 1;
                    } else {
                        printf(" %d", l);
                    }
                }
            } else {
                if (num[l] > num[l+1] && num[l] > num[l-1] || num[l] < num[l+1] && num[l] < num[l-1]) {
                    if (flag == 0) {
                        printf("%d", l);
                        flag = 1;
                    } else {
                        printf(" %d", l);
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
