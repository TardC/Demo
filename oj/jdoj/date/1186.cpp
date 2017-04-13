#include <stdio.h>
#define ISYEAP(x) x % 400 == 0 || (x % 4 == 0 && x % 100 != 0) ? 1 : 0

int day_of_month[13][2] = {
    0, 0,
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31
};

struct date {
    int year;
    int month;
    int day;

    void next_day()
    {
        day++;
        if (day > day_of_month[month][ISYEAP(year)]) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

int main()
{
    date d;
    int counter;
    while (scanf("%d%d", &d.year, &counter) != EOF) {
        d.day = 1;
        d.month = 1;
        while (--counter) {
            d.next_day();
        }
        printf("%04d-%02d-%02d\n", d.year, d.month, d.day);
    }

    return 0;
}
