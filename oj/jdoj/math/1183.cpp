#include <stdio.h>

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        int flag = 0;

        if (n < 10) {
            if (n == n*n % 10)
                flag = 1;
        } else {
            if (n == n*n % 100)
                flag = 1;
        }

        if (flag == 1)
            printf("Yes!\n");
        else if (flag == 0)
            printf("No!\n");
    }

    return 0;
}
