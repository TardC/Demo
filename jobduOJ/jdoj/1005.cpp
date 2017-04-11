#include <stdio.h>
#include <algorithm>
#define N 40000
#define M 100
#define K 5

using namespace std;

struct student {
    int id;
    float GE;
    float GI;
    float grade;
    int rank;
    int adm;
    int choices[K];

    void init_grade()
    {
        grade = (GE + GI) / 2;
    }
    bool operator<(const student &s) const
    {
        if (grade != s.grade)
            return grade > s.grade;
        else
            return GE >= s.GE;
    }
} stu[N];

int sch[M];
int sch_t[M];

int main()
{
    int n, m, k;

    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        for (int i = 0; i < m; i++)
            scanf("%d", &sch[i]);
        for (int i = 0; i < n; i++) {
            scanf("%f%f", &stu[i].GE, &stu[i].GI);
            for (int j = 0; j < k; j++)
                scanf("%d", &stu[i].choices[j]);
            stu[i].id = i;
        }

        int sch_adm[m][n+1];

        for (int i = 0; i < n; i++)
            stu[i].init_grade();

        sort(stu, stu + n);

        for (int i = 0; i < n; i++) { // rank
            if (i == 0) {
                stu[i].rank = 1;
                continue;
            }

            if (stu[i].grade != stu[i-1].grade)
                stu[i].rank = stu[i-1].rank + 1;
            else if (stu[i].GE != stu[i-1].GE)
                stu[i].rank = stu[i-1].rank + 1;
            else
                stu[i].rank = stu[i-1].rank;
        }

        for (int i = 0; i < m; i++) { // initialing number of admission
            sch_t[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= n; j++) {
                sch_adm[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) { // admit
            if (i == 0) {
                for (int j = 0; j < k; j++) {
                    int tmp = stu[0].choices[j];
                    if (sch_t[tmp] < sch[tmp]) {
                        stu[0].adm = tmp;
                        sch_t[tmp]++;
                        sch_adm[tmp][1] = stu[0].id;
                        sch_adm[tmp][0]++;
                        break;
                    }
                }
                continue;
            }

            for (int j = 0; j < k; j++) {
                int tmp = stu[i].choices[j];
                if (sch_t[tmp] < sch[tmp]) {
                    stu[i].adm = tmp;
                    sch_t[tmp]++;
                    sch_adm[tmp][sch_adm[tmp][0]+1] = stu[i].id;
                    sch_adm[tmp][0]++;
                    break;
                } else {
                    if (stu[i].rank == stu[i-1].rank && tmp == stu[i-1].adm) {
                        stu[i].adm = tmp;
                        sch_t[tmp]++;
                        sch_adm[tmp][sch_adm[tmp][0]+1] = stu[i].id;
                        sch_adm[tmp][0]++;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            sort(sch_adm[i]+1, sch_adm[i]+1 + sch_adm[i][0]);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= sch_adm[i][0]; j++) {
                if (j == 1) {
                    printf("%d", sch_adm[i][1]);
                } else {
                    printf(" %d", sch_adm[i][j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
