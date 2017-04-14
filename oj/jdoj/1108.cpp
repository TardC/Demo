#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;

        stack<int> s;

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == 'P') {
                int p;
                scanf("%d", &p);
                s.push(p);
            } else if (c == 'O') {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (c == 'A') {
                if (s.empty()) {
                    printf("E\n");
                } else {
                    printf("%d\n", s.top());
                }
            }
        }
        printf("\n");
    }

    return 0;
}
