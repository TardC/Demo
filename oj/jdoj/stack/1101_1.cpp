#include <stdio.h>

int main()
{
    double t;

    while (scanf("%lf", &t) != EOF) {
        double arr[1000];
        char c;

        arr[0] = t;
        int i = 0;
        while (scanf("%c", &c) != EOF && c!= '\n') {
            scanf("%lf", &t);
            if (c == '+')
                arr[++i] = t;
            else if (c == '-')
                arr[++i] = -t;
            else if (c == '*')
                arr[i] = arr[i] * t;
            else if (c == '/')
                arr[i] = arr[i] / t;
        }
        double sum = 0;
        for (int j = 0; j <= i; j++)
            sum += arr[j];
        printf("%.0f\n", sum);
    }

    return 0;
}
