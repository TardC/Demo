#include <stdio.h>

struct student
{
	char name[21];
	int score;
};

int main()
{
	struct student stu[100], t;
	int i, j, n;

	scanf("%d", &n);
	for (i=1; i<=n; i++)
		scanf("%s %d", stu[i].name, &stu[i].score);
	for (i=1; i<=n-1; i++)
	{
		for (j=1; j<=n-i; j++)
		{
			if (stu[j].score < stu[j+1].score)
			{
				t = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = t;
			}
		}
	}
	printf("=================================\n");
	for (i=1; i<=n; i++)
		printf("%s %d\n", stu[i].name, stu[i].score);

	getchar();getchar();
	return 0;
}