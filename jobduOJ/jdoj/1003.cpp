#include <stdio.h>
#include <string.h>
#define MAX 15

int main()
{
    char num1[MAX], num2[MAX];
    long long  a, b, c;
    int len1, len2;

    while (scanf("%s %s", num1, num2) != EOF) {
        len1 = strlen(num1);
        len2 = strlen(num2);

        a = 0;
        for (int i = len1 - 1, w = 1; i >= 0; i--) {
            if (num1[i] >= '0' && num1[i] <= '9') {
                a += (num1[i] - '0') * w;
                w *= 10;
            } else if (num1[i] == ',') {
                continue;
            } else if (num1[i] == '-') {
                a = -a;
            }
        }

        b = 0;
        for (int i = len2 - 1, w = 1; i >= 0; i--) {
            if (num2[i] >= '0' && num2[i] <= '9') {
                b += (num2[i] - '0') * w;
                w *= 10;
            } else if (num2[i] == ',') {
                continue;
            } else if (num2[i] == '-') {
                b = -b;
            }
        }
        c = a + b;

        printf("%lld\n", c);
    }

    return 0;
}
