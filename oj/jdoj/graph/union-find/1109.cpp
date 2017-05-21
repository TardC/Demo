#include <stdio.h>

#define N 1001
int Tree[N];
int sum[N];

int findRoot(int x)
{
	if (Tree[x] == -1) {
		return x;
	} else {
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

int main(void)
{
	int n, m, i;

	while (scanf("%d %d", &n, &m) != EOF && n != 0) {
		for (i = 1; i <= n; i++) {
			Tree[i] = -1;
			sum[i] = 1;
		}

		while (m-- != 0) {
			int a, b;
			scanf("%d %d", &a, &b);
			a = findRoot(a);
			b = findRoot(b);
			if (a != b) {
				Tree[a] = b;
				sum[b] += sum[a];
			}
		}
		int ans = 1;
		for (i = 1; i <= n; i++) {
			if (Tree[i] == -1 && sum[i] > ans)
				ans = sum[i];
		}
		if (n == ans)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}