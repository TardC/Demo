#include <stdio.h>
#define MAX 1000000

long s1[MAX];
long s2[MAX];
long s3[2*MAX];

int main()
{
    int c1, c2;

    while (scanf("%d", &c1) != EOF) {
        for (int i = 0; i < c1; i++) {
            scanf("%d", &s1[i]);
        }
        scanf("%d", &c2);
        for (int i = 0; i < c2; i++) {
            scanf("%d", &s2[i]);
        }

        int i = 0, j = 0, k = 0;
        for (; i < c1 && j < c2;) {
            if (s1[i] < s2[j]) {
                s3[k] = s1[i];
                i++;
                k++;
            } else if(s1[i] > s2[j]) {
                s3[k] = s2[j];
                j++;
                k++;
            } else {
                s3[k++] = s1[i];
                s3[k++] = s2[j];
                i++;
                j++;
            }
        }
        if (i == c1) {
            for (; j < c2; j++, k++) {
                s3[k] = s2[j];
            }
        } else if (j == c2) {
            for (; i < c1; i++, k++) {
                s3[k] = s1[i];
            }
        }

        if (k % 2 == 0) {
            printf("%d\n", s3[k/2-1]);
        } else if (k % 2 == 1) {
            printf("%d\n", s3[k/2]);
        }
    }

    return 0;
}
