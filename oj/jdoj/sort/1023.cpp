#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct s {
    int id;
    char name[9];
    int score;
} stu[100000];

int n, c, counter = 0;

bool cmp(const s &a, const s &b)
{
    if (c == 1) {
        return a.id < b.id;
    } else if (c == 2) {
        int res = 0;
        res = strcmp(a.name, b.name);
        if (res == 0)
            return a.id < b.id;
        else
            return res < 0;
    } else if (c == 3) {
        if (a.score == b.score)
            return a.id < b.id;
        else
            return a.score < b.score;
    }
}

int main()
{
    while (scanf("%d%d", &n, &c) != EOF){
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);
        }
        counter++;

        sort(stu, stu + n, cmp);

        printf("Case %d:\n", counter);
        for (int i = 0; i < n; i++) {
            printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
        }
    }

    return 0;
}

