#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        char oct[32] = {0};

        itoa(n, oct, 8);
        printf("%s\n", oct);
    }

    return 0;
}
