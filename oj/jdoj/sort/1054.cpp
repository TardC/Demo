#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    char s[201];
    int len;

    while (scanf("%s", s) != EOF) {
        len = strlen(s);
        sort(s, s + len);
        printf("%s\n", s);
    }

    return 0;
}
