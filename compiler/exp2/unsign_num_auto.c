#include <stdio.h> //标准输入输出函数
#include <stdlib.h>//标准库函数
#include <conio.h>//控制台输入输出函数
#include <string.h>

#define STATE_NUMBER 4	//状态数目
#define CHAR_NUMBER 2     //输入字符的种类: d 和 .
#define DIGIT 0	        //输入数字在状态表中位于第0列
#define DOT 1            //输入小数点位于状态表的第1列
//State[][]为状态表，以整数组形式存放，0,1,2,3表示状态，-1表示没有此状态,其中1表示整数部分,2表示小数点,3表示小数部分。
int State[STATE_NUMBER][CHAR_NUMBER]={{1,-1},{1,2},{3,-1},{3,-1}};
int Q[STATE_NUMBER] = {0,1,0,1};	//终态标志：0非终态，1终态。

//缓冲区：
//输入缓冲区：由专门函数操作（ReadALine(),GetChar()）
#define BUFFER_SIZE 1000	//表达式缓冲区大小
char Buffer[BUFFER_SIZE];	//表达式缓冲区，以'\0'表示结束
int ipBuffer = 0;		//表达式缓冲区当前位置序号
char ch;	//存放取得的一个字符

//函数声明：
int Run();	//对存储在缓冲区的一行字符串（以'#'结束）进行运行
void Init();	//全局初始化
int ReadALine();	//从键盘读一行（没有空格），存于表达式缓冲区Buffer[]中
char GetChar(); //从缓冲区取一个字符，返回该字符的同时将它存于全局变量ch中



//主程序：
void main()
{
	Init();
	while(ReadALine()) //读一行成功，对它进行判断
	{
		if(Run()) //对该行进行运行，看是否能被接受？
			printf("接受\n\n");
		else
			printf("不接受\n\n");
	}
}
//对存储在缓冲区的一行字符串（以'#'结束）进行运行
//返回：如果是无符号定点实数，返回true；否则返回：false
int Run()
{
	int S=0; //S存放运行时的当前状态，目前为初态
	while(GetChar()!='#')
	{
		if(ch >= '0' && ch <= '9') //数字
			S = State[S][DIGIT]; //将状态转换成输入数字后的状态
		else if(ch == '.')        //小数点
			S = State[S][DOT];   //将状态转换成输入小数点后的状态
		else                 //其他都为非法字符
			return 0;
		if(S == -1) //处于非法状态
			return 0;
	}
	//运行结束，判断S是否为终态
	if(Q[S] == 1) //终态
		return 1;
	else //非终态
		return 0;
}

//全局初始化
void Init()
{
	//好像无需初始化
	printf("程序功能：输入一个字符串，判断它是否是无符号定点实数。\n");
	printf("======================================================\n\n");
}

//从键盘读一行（没有空格），存于表达式缓冲区Buffer[]中，以'#'结束，并置ipBuffer=0；
//读到非空字符串：返回 true；读到单独的"#"：返回 false
int ReadALine()
{
	int l;
	printf("请输入以\"#\"号结束的无空格字符串：");
	scanf("%s",Buffer);
	l = strlen(Buffer); //读入的字符串的长度
	if(l == 0) return ReadALine(); //输入了空字符串，重新输入
	if(Buffer[0] == '#') return 0; //输入单独的'#'表示不再输入
	Buffer[l] = '#';	//最后一个字符用结束标记'#'代替（本来是'\0'）
	ipBuffer = 0;	//初始化缓冲区指针
	return 1;
}

//从缓冲区取一个字符，返回该字符的同时将它存于全局变量ch中
//成功：返回字符；不成功：返回'#'
char GetChar()
{
	if((ch = Buffer[ipBuffer]) != '#')
		ipBuffer++;
	return ch;
}
