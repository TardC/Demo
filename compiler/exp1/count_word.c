/**
File name: count_word.c
Description: Count the frequency of a word in a article.(Don't deal with punctuation.)
Author: TardC
Date: 2016/12/7
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void count_word();

FILE *fp;
int num = 0;//单词个数
char word[1000][20];//单词数组
int frequency[1000] = {0};//单词次数

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
    count_word();
    printf("The number of word: %d\n", num);
    printf("\n");
    printf("%-20s %-20s\n", "Word", "Frequency");
    int k;
    for (k = 0; k < num; k++)
    {
        printf("%-20s %-20d\n", word[k], frequency[k]);
    }
	fclose(fp);
	getch();

	return 0;
}

void count_word()//统计出现的单词和次数
{
    char word_t[20];
    fscanf(fp, "%s", word[0]);
    frequency[0]++;
    num++;
    while(!feof(fp))
    {
        int i;
        int flag = 1;//是否为新单词
        fscanf(fp, "%s", word_t);
        for (i = 0; i < num; i++)
        {
            if (strcmpi(word_t, word[i]) == 0)//不是新单词，将对应单词次数加1
            {
                frequency[i]++;
                flag = 0;
                break;
            }
        }
        if (flag == 1)//是新单词，记录并置次数为1
        {
            strcpy(word[num], word_t);
            frequency[num]++;
            num++;
        }
    }
}
