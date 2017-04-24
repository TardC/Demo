#include <stdio.h>
#include <string.h>

int main(void)
{
    char digits[1024];

    while (scanf("%s", digits) != EOF && digits[0] != '0') {
        if (strlen(digits) == 1) {
            printf("%c\n", digits[0]);
            continue;
        }

        int sum = 0;

        while (strlen(digits) > 1) {
            for (int i = 0; digits[i] != 0; i++) {
                sum += digits[i] - '0';
            }
            memset(digits, 0, sizeof(char)*1024);
            sprintf(digits, "%d", sum);
            sum = 0;
        }
        printf("%c\n", digits[0]);
    }

    return 0;
}
