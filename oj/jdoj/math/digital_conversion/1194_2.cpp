#include <stdio.h>

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        int oct[32], size = 0;

        do {
            oct[size++] = n % 8;
            n /= 8;
        } while (n != 0);

        for (int i = size - 1; i >= 0; i--)
            printf("%d", oct[i]);
        printf("\n");
    }

    return 0;
}
