#include <stdio.h>
#include <math.h>

double max_3(double a, double b, double c)
{
    double max_num;

    if (a >= b && a >= c) {
        max_num = a;
    } else if (b >= a && b >= c) {
        max_num = b;
    } else if (c >= a && c >= b) {
        max_num = c;
    }

    return max_num;
}

int main()
{
    double p, t, g1, g2, g3, gj;
    /*
      For each problem, there is a full-mark P and a tolerance T(<P) given. The grading rules are:
        A problem will first be assigned to 2 experts, to obtain G1 and G2.
        If the difference is within the tolerance, that is, if |G1 - G2| ¡Ü T, this problem's grade will be the average of G1 and G2.
        If the difference exceeds T, the 3rd expert will give G3.
        If G3 is within the tolerance with either G1 or G2, but NOT both, then this problem's grade will be the average of G3 and the closest grade.
        If G3 is within the tolerance with both G1 and G2, then this problem's grade will be the maximum of the three grades.
        If G3 is within the tolerance with neither G1 nor G2, a judge will give the final grade GJ.
    */
    while (scanf("%lf %lf %lf %lf %lf %lf", &p, &t, &g1, &g2, &g3, &gj) != EOF) {
        double t_12 = fabs(g1 - g2);
        double ans = 0.0;

        if (t_12 <= t) {
            ans = (g1 + g2) / 2;
        } else {
            double t_13 = fabs(g1 - g3);
            double t_23 = fabs(g2 - g3);
            if (t_13 <= t && t_23 <= t) {
                ans = max_3(g1, g2, g3);
            } else if (t_13 <= t || t_23 <= t) {
                if (t_13 >= t_23) {
                    ans = (g2 + g3) / 2;
                } else {
                    ans = (g1 + g3) / 2;
                }
            } else {
                ans = gj;
            }
        }
        printf("%.1lf\n", ans);
    }

    return 0;
}
