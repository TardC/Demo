#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_word();
void check_word();
void print_word();

char work[8];//关键字临时数组
char word[100][8];//关键字数组
int k = 0;//关键字数目

int main()
{
    printf("Please input word: ");
    while(get_word())
    {
        check_word();
    }
    print_word();

    return 0;
}

int get_word()
{
    int i = 0;
    char ch;
    while((ch = getchar()) != ',')
    {
        if (ch == ';')
            return 1;
        if (ch == 13 || ch == 10)//清除换行符
            return 0;
        if (i == 0)
        {
            if (!(ch >= 'a' && ch <='z' || ch >= 'A' && ch <= 'Z'))
            {
                printf("Error.\n");
                return 0;
            }
        }
        if (!(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9'))
        {
            printf("Error.\n");
            return 0;
        }
        work[i] = ch;
        i++;
    }

    return 1;
}

void check_word()
{
    int i;

    if (strlen(work) == 0)
        return ;
    for(i = 0; i < k; i++)
    {
        if (!strcmp(word[i], work))
        {
            return ;
        }
    }
    strcpy(word[k], work);
    k++;
    for(i = 0; i < 8; i++)//初始化关键字临时数组
        work[i] = '\0';
}

void print_word()
{
    int i;

    if (k == 0)
        printf("The array is empty.\n");
    for (i = 0; i < k; i++)
    {
        printf("The %dst word is: %s\n", i + 1, word[i]);
    }
}
