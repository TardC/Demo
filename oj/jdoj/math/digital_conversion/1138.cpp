#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[64];

    while (scanf("%s", str) != EOF) {
        int digit[64];
        int bin[128]; // record binary result
        int len = strlen(str);
        int count = 0; // record result length

        if (len == 1 && (str[0] == '0' || str[0] == '1')) { // 0 or 1,output directly
            printf("%c\n", str[0]);
            continue;
        }


        for (int i = 0; i < len; i++) // change '0'...'9' to 0..9
            digit[i] = str[i] - '0';

        while (1) {
            int i;

            for (i = 0; i < len; i++) { // filter leading 0
                if (digit[i] != 0)
                    break;
            }
            if (i == len) // if elements of digit array are all 0,exit
                break;
            for (int j = i; j < len; j++) {
                if (j == len - 1) { // when calculate to last element,recode remainder
                    bin[count++] = digit[j] % 2;
                    digit[j] = digit[j] / 2;
                    break;
                }
                digit[j+1] += (digit[j] % 2) * 10;
                digit[j] /= 2;
            }
        }

        for (int i = count - 1; i >= 0; i--) {
            printf("%d", bin[i]);
        }
        printf("\n");
    }

    return 0;
}
