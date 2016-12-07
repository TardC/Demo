/**
File name: scan_sourcefile.c
Description: Scan the source file and print it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int read_buffer();

int i;
FILE *fp;
char buffer[256];

int main()
{
    char path[50];
    printf("Please input file path: ");
    scanf("%s", path);
    printf("\n");
	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("The file doesn`t open!\n");
		exit(0);
	}
//	if ((fp = fopen("C:\\a.c", "r")) == NULL)
//    {
//        printf("The file doesn`t open!\n");
//		exit(0);
//    }
	while (!feof(fp))
	{
		int j = 0;
		read_buffer();
		while (j < i)
		{
			printf("%c", buffer[j]);
			j++;
		}
		printf("\n");
		getch();
	}
	fclose(fp);
	getch();

	return 0;
}

int read_buffer()
{
	int j = 0;
	char ch;
	while(j < 256)
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			i = j;
			return 0;
		}
		buffer[j] = ch;
		++j;
	}
	return 1;
}

