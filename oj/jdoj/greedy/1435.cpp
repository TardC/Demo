#include <stdio.h>
#include <algorithm>
#define MAX 100

using namespace std;

int main()
{
    int c;
    int n, v, w;
    int con[100];

    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d%d%d", &n, &v, &w);
        for (int i = 0; i < n; i++) {
            scanf("%d", &con[i]);
        }

        int v_ans = 0;
        float w_ans = 0.00;

        sort(con, con + n);

        if (con[0] > w) {
            printf("%d %.2f\n", v_ans, w_ans);
            continue;
        }
        for (int i = 0; i < n; i++) {
            if ((w_ans*v_ans + float(con[i])/100*v) / (v_ans + v) > float(w)/100) {
                printf("%d %.2f\n", v_ans, w_ans);
                break;
            } else {
                w_ans = (w_ans*v_ans + float(con[i])/100*v) / (v_ans + v);
                v_ans += v;
                if (i == n - 1) {
                    printf("%d %.2f\n", v_ans, w_ans);
                    break;
                }
            }
        }
    }

    return 0;
}
