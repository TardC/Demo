#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
    char str[50];

    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        stack<char> op_s;
        stack<double> num_s;

        int tmp = 0;
        int rank = 1;

        for (int i = 0; i < len; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                tmp = tmp * rank + str[i] - '0';
                rank *= 10;

                if (str[i+1] >= '9' && str[i+1] <= '0') {
                    num_s.push(tmp);
                    int tmp = 0;
                    int rank = 1;
                }
            } else {
                if (op_s.empty())
                    op_s.push(str[i]);
                else if (str[i] == '*' || str[i] == '/') {
                    op_s.push(str[i]);
                } else if (str[i] == '+' || str[i] == '-') {
                    if (op_s.top() == '+' || op_s.top() == '-') {
                        op_s.push(str[i]);
                    } else {
                        double a = num_s.top();
                        num_s.pop();
                        double b = num_s.top();
                        num_s.pop();
                        char c = op_s.top();
                        op_s.pop();

                        switch (c) {
                            case ''
                        }
                    }
                }
            }
        }
    }
}
