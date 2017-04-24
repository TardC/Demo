#include <stdio.h>

int main(void)
{
    for (int i = 1000; i < 10000; i++) {
        if (i/1000 + (i/100)%10*10 + (i/10)%10*100 + i%10*1000 == 9*i)
            printf("%d\n", i);
    }

    return 0;
}
