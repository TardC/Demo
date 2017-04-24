#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 256; i++) {
        int num = i * i;
        int digit[10], cnt = 0;

        while (num != 0) {
            digit[cnt++] = num % 10;
            num /= 10;
        }

        int flag = 1;

        for (int j = 0; j < cnt; j++) {
            if (digit[j] != digit[cnt-1-j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("%d\n", i);
    }

    return 0;
}
