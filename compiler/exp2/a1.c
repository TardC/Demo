#include <stdio.h>
#include <string.h> 
#include <stdlib.h>  
 /*保留字表*/   
  char *key0[]={" ","auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for",\
	  	  "goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","_Complex","_Imaginary","union","unsigned","void","volatile","while"};  
  /*分隔符表*/ 
  char *key1[]={" ","(",")","[","]","{","}",",",";","'"}; 
 /*运算符表*/ 
  char *key2[]={" ","+","-","*","/","%","<",">","==",">=","<=","!=","!","&&","||","<<",">>","~","|","^","&","=","?:","->","++","--",".","+=","-=","*=","/="};   
  int xx0[35],xx1[10],xx2[31];   
  int temp_key3=0,temp_c40=0,temp_c41=0,temp_c42=0,temp_c43=0;   
  /*******   初始化函数   *******/   
  void load() 
  {int mm;
   FILE *floading; 
   for (mm=0;mm<=34;mm++)  
	 {   xx0[mm]=0;  }   
   for (mm=0;mm<=9;mm++)  
	 {   xx1[mm]=0;  }   
   for (mm=0;mm<=30;mm++)  
     {   xx2[mm]=0;  }  
   /*建立保留字表文件：key0.txt*/  
   if ((floading=fopen("key0.txt","w"))==NULL)  
    { printf("Error! Can't create file : key0.txt"); 
      return;  }  
   fclose (floading);  
   /*建立分隔符表文件：key1.txt*/  
   if ((floading=fopen("key1.txt","w"))==NULL)  
    { printf("Error! Can't create file : key1.txt");
      return;  }  
   fclose(floading); 
   /*建立运算符表文件：key2.txt*/ 
   if ((floading=fopen("key2.txt","w"))==NULL)  
    { printf("Error! Can't create file : key2.txt"); 
      return;  }  
   fclose(floading);  
   /*建立标识符表文件：key3.txt*/  
   if ((floading=fopen("key3.txt","w"))==NULL) 
    { printf("Error! Can't create file : key3.txt");
      return;  }  
   fclose (floading);  
   /*建立整数类型常量表文件：c40.txt*/ 
   if ((floading=fopen("c40.txt","w"))==NULL) 
    { printf("Error! Can't create file : c40.txt");
      return;  }   
   fclose (floading);   
   /*建立浮点类型常量表文件：c41.txt*/  
  if ((floading=fopen("c41.txt","w"))==NULL)  
   { printf("Error! Can't create file : c41.txt");
     return;  }   
    fclose (floading);   
    /*建立字符类型常量表文件：c42.txt*/ 
  if ((floading=fopen("c42.txt","w"))==NULL) 
   { printf("Error! Can't create file : c42.txt");
     return;  }  
  fclose (floading);  
  /*建立字符串类型常量表文件：c43.txt*/  
if ((floading=fopen("c43.txt","w"))==NULL) 
{   printf("Error! Can't create file : c43.txt");
return;  }   
fclose (floading);   
/*建立注释文件：defination.txt*/ 
if ((floading=fopen("defination.txt","w"))==NULL)
{   printf("Error! Can't create file : defination.txt");   
return;  }    
fclose (floading);   
/*建立内部码文件：output.txt*/   
if ((floading=fopen("output.txt","w"))==NULL)  
{   printf("Error! Can't create file : output.txt"); 
return;  }  
fclose (floading);  
/*建立保留字临时表文件：temp_key1*/ 
if ((floading=fopen("temp_key1.txt","w"))==NULL) 
{   printf("Error! Can't create file : temp_key1"); 
    return;  }   
    fclose (floading);   
/*建立运算符临时表文件：temp_key2*/ 
if ((floading=fopen("temp_key2.txt","w"))==NULL) 
{   printf("Error! Can't create file : temp_key1"); 
return;  }   
fclose (floading);   
/*建立标识符临时文件：temp_key3*/ 
if ((floading=fopen("temp_key3.txt","w"))==NULL)  
{   printf("Error! Can't create file : temp_key3");
return;  }   
fclose (floading);  
/*建立整数类型常量临时文件：temp_c40*/ 
if ((floading=fopen("temp_c40.txt","w"))==NULL)  
{   printf("Error! Can't create file : temp_c40");  
return;  }   
fclose (floading);  
/*建立浮点类型常量临时文件：temp_c41*/ 
if ((floading=fopen("temp_c41.txt","w"))==NULL)  
{   printf("Error! Can't create file : temp_c41");
return;  }  
fclose (floading);   
/*建立字符类型常量临时文件：temp_c42*/  
if ((floading=fopen("temp_c42.txt","w"))==NULL)  
{   printf("Error! Can't create file : temp_c42"); 
return;  }  
fclose (floading);   
/*建立字符串类型常量临时文件：temp_c43*/ 
if ((floading=fopen("temp_c43.txt","w"))==NULL) 
{    printf("Error! Can't create file : temp_c43");
  return;
}
fclose (floading);   
} 
  
  /*******   保留字及标识符判断函数   *******/   
  void char_search(char *word) 
  {int m,line=0,csi=0;  
  int value=0;  /*value=0表示不是保留字，如果是1则是保留字*/
  int value2=0;    /*value2判断在output和temp_key3中是否重复，在temp_key3中已有，则values=1，否则为0*/
  char c,cs[100];   
  FILE *foutput,*finput;  
  for (m=1;m<=34;m++)       /*判断当前temp和word中是否是保留字*/
  {   if (strcmp(word,key0[m])==0)   
         {    value=1;    
         break;   }  
  }   
  if (value==1)  
  {   if (xx0[m]==0)   
       { foutput=fopen("key0.txt","a");    
       fprintf(foutput,"0\t%d\t\t%s\n",m,word);    
       fclose(foutput);    
       xx0[m]=1;   }   
      foutput=fopen("output.txt","a");   
      fprintf(foutput,"0\t%d\t\t%s\n",m,word);   
      fclose(foutput);  }  
     else  
     {   if (temp_key3==0)  
     {    foutput=fopen("temp_key3.txt","a");   
     fprintf(foutput,"%s\n",word);    
     fclose(foutput);    
     temp_key3++;    
     foutput=fopen("key3.txt","a");    
     fprintf(foutput,"3\t1\t\t%s\n",word);   
     fclose(foutput);    
     }    
     finput=fopen("temp_key3.txt","r");   
     c=fgetc(finput);  
     while (c!=EOF)   
     {    while (c!='\n')    
        {     cs[csi++]=c;     
              c=fgetc(finput);    }   
         cs[csi]='\0';   
         csi=0;    
         line++;    
         if ((strcmp(cs,word))==0)    
         {     value2=1;    
         break;    }   
         else    
         {     value2=0;     
         c=fgetc(finput);    
         }   
     }    
     fclose(finput);   
     if (value2==1)   
     {    foutput=fopen("output.txt","a");    
     fprintf(foutput,"3\t%d\t\t%s\n",line,word); 
     fclose(foutput);   
     }   
     else   
     {    foutput=fopen("temp_key3.txt","a");    
     fprintf(foutput,"%s\n",word);    
     fclose(foutput);    
     temp_key3++;    
     foutput=fopen("output.txt","a");   
     fprintf(foutput,"3\t%d\t\t%s\n",temp_key3,word);
     fclose(foutput);    
     foutput=fopen("key3.txt","a");   
     fprintf(foutput,"3\t%d\t\t%s\n",temp_key3,word);
     fclose(foutput);   
  }   
  }  
  }
  
/*******   整数类型判断函数   *******/   
void inta_search(char *word) 
{   FILE *foutput,*finput;  
char c;   char cs[100]; 
 int csi=0;  
int line=0;  
int value2=0; 
 if (temp_c40==0)  
{   foutput=fopen("temp_c40.txt","a");   
fprintf(foutput,"%s\n",word);   
fclose(foutput);   
temp_c40++;   
foutput=fopen("c40.txt","a");   
fprintf(foutput,"4\t0\t1\t%s\n",word);   
fclose(foutput); 
 }   
finput=fopen("temp_c40.txt","r");  
c=fgetc(finput);  
while (c!=EOF)  
{   while (c!='\n')   
{    cs[csi++]=c;    
c=fgetc(finput);   
}   
cs[csi]='\0';   
csi=0;   line++;   
if (strcmp(cs,word)==0)   
{    value2=1;   
 break;   }  
 c=fgetc(finput);  
}   
fclose(finput);  
if (value2==1)  
{   foutput=fopen("output.txt","a");   
fprintf(foutput,"4\t0\t%d\t%s\n",line,word);  
 fclose(foutput);  }  
else    
 {   foutput=fopen("temp_c40.txt","a");   
fprintf(foutput,"%s\n",word);   
fclose(foutput);   
temp_c40++;   
foutput=fopen("output.txt","a");   
fprintf(foutput,"4\t0\t%d\t%s\n",temp_c40,word);   
fclose(foutput);   foutput=fopen("c40.txt","a");   
fprintf(foutput,"4\t0\t%d\t%s\n",temp_c40,word);  
 fclose(foutput);  } } 
 

  /*******   浮点类型判断函数   *******/   
void intb_search(char *word) 
{   FILE *foutput,*finput;  
char c;   char cs[100];  
int csi=0;  int line=0;  
int value2=0;  if (temp_c41==0)  
{   foutput=fopen("temp_c41.txt","a");   
fprintf(foutput,"%s\n",word);   
fclose(foutput);   
temp_c41++;   
foutput=fopen("c41.txt","a");   
fprintf(foutput,"4\t1\t1\t%s\n",word);   
fclose(foutput);  }   
finput=fopen("temp_c41.txt","r"); 
 c=fgetc(finput);  
while (c!=EOF)  
{   while (c!='\n')   
{    cs[csi++]=c;   
 c=fgetc(finput);  
 }   
cs[csi]='\0';  
 csi=0;  
 line++;  
 if (strcmp(cs,word)==0)  
{    value2=1;    
break;   }   
c=fgetc(finput);  
}   
fclose(finput); 
 if (value2==1)  
{   foutput=fopen("output.txt","a");   
fprintf(foutput,"4\t1\t%d\t%s\n",line,word); 
  fclose(foutput);  } 
 else  {   foutput=fopen("temp_c41.txt","a");   
fprintf(foutput,"%s\n",word);  
 fclose(foutput);   
temp_c41++;   
foutput=fopen("output.txt","a");  
 fprintf(foutput,"4\t1\t%d\t%s\n",temp_c41,word);  
 fclose(foutput);   
foutput=fopen("c40.txt","a");  
 fprintf(foutput,"4\t1\t%d\t%s\n",temp_c41,word);   
fclose(foutput);  } } 


 /*******   字符串常量判断函数   *******/   
void cc_search(char *word) 
{   FILE *foutput,*finput;   
 char c;  
 char cs[100]; 
 int csi=0;  
int line=0;  
int value2=0;  
if (temp_c43==0)  
{   foutput=fopen("temp_c43.txt","a");   
fprintf(foutput,"%s\n",word);   
fclose(foutput);   
temp_c43++;  
 foutput=fopen("c43.txt","a");  
 fprintf(foutput,"4\t3\t1\t%s\n",word);   
fclose(foutput);  
}   
finput=fopen("temp_c43.txt","r"); 
 c=fgetc(finput);  
while (c!=EOF)  
{   while (c!='\n')   
{    cs[csi++]=c;    
c=fgetc(finput);   }  
 cs[csi]='\0';   
csi=0;   
line++;  
 if (strcmp(cs,word)==0)   
{    value2=1;   
 break;   }  
 c=fgetc(finput);  }  
 fclose(finput); 
 if (value2==1)  
{   foutput=fopen("output.txt","a");  
 fprintf(foutput,"4\t3\t%d\t%s\n",line,word);  
 fclose(foutput);  } 
 else  {   foutput=fopen("temp_c43.txt","a");   
fprintf(foutput,"%s\n",word);  
 fclose(foutput);   
temp_c43++;  
 foutput=fopen("output.txt","a");   
fprintf(foutput,"4\t3\t%d\t%s\n",temp_c43,word);   
fclose(foutput);   
foutput=fopen("c43.txt","a");   
fprintf(foutput,"4\t3\t%d\t%s\n",temp_c43,word);   
fclose(foutput);  } } 



/*******   字符常量判断函数   *******/   
void c_search(char *word)
 {   FILE *foutput,*finput;  
    char c; 
    char cs[100];  
    int csi=0;  
    int line=0; 
    int value2=0;  
    if (temp_c42==0)  
	{   foutput=fopen("temp_c42.txt","a");   
        fprintf(foutput,"%s\n",word);   
        fclose(foutput);   
        temp_c42++;   
        foutput=fopen("c42.txt","a");   
        fprintf(foutput,"4\t2\t1\t%s\n",word);  
        fclose(foutput);  
	}   
   finput=fopen("temp_c42.txt","r");  
   c=fgetc(finput); 
   while (c!=EOF)  
   {   while (c!='\n')   
   {    cs[csi++]=c;    
        c=fgetc(finput);  
   }   
   cs[csi]='\0';  
   csi=0;   
   line++;   
   if (strcmp(cs,word)==0)   
   {    value2=1;    
        break;   
   }   
   c=fgetc(finput); 
   }   
   fclose(finput);  
   if (value2==1)  
   {   foutput=fopen("output.txt","a");   
       fprintf(foutput,"4\t2\t%d\t%s\n",line,word);   
       fclose(foutput);  }  
   else  
   {   foutput=fopen("temp_c42.txt","a");   
       fprintf(foutput,"%s\n",word);   
       fclose(foutput);    
       temp_c42++;       
       foutput=fopen("output.txt","a");   
       fprintf(foutput,"4\t2\t%d\t%s\n",temp_c42,word);   
       fclose(foutput);  
       foutput=fopen("c42.txt","a");   
       fprintf(foutput,"4\t2\t%d\t%s\n",temp_c42,word);  
       fclose(foutput);  
   }
} 


/*******   主扫描函数   *******/   
void scan() 
{   int count;  
char chin;  
FILE *fin;  
FILE *fout;   
char filename[50];  
char temp[100];  
char target[3]="'";   
printf("请输入文件名：");  
scanf("%s",filename);   
if ((fin=fopen(filename,"r"))==NULL)  
{ printf("Error! Can't open file : %s\n",filename);   
  return;  
}   
chin=fgetc(fin); 
while (chin!=EOF)  
{  if (chin=='#')   {while (chin!='>')   chin=fgetc(fin); }       /*chin=fgetc(fin);*/   /*对文件包含、宏定义进行处理*/
   else if ((chin==' ')||(chin=='\t'))   {    ;   }               /*对空格符、水平制表符进行处理*/  
   else if (chin=='\n')   {    ;   }                              /*对回车符进行处理*/  
   else if (chin==target[0])                                      /*对单引号内的字符常量进行处理*/
   {if (xx1[9]==0)    
   { fout=fopen("key1.txt","a");    
     fprintf(fout,"1\t9\t\t%c\n",target[0]);                        /*fprintf(fout,"1\t9\t\t%c\n",target[0]); */
     fclose(fout);   
     xx1[9]=1;    
   }    
   temp[0]=chin;    
   chin=fgetc(fin);    
   temp[1]=chin;    
   chin=fgetc(fin);    
   if (chin!=target[0])    
   {     temp[2]=chin;     
         chin=fgetc(fin);     
         temp[3]=chin;     
         temp[4]='\0';   
   }    
   else    
   {     temp[2]=chin;  
         temp[3]='\0';   
   }   
   c_search(temp); 
   }    
   else if (chin=='"')                                              /*对双引号内的字符串常量进行处理*/  
   {    int i=0;    
        temp[i++]='"';    
        chin=fgetc(fin);   
        while (chin!='"')    
		{     temp[i++]=chin;   
              chin=fgetc(fin);  
		}    
        temp[i]='"';   
        temp[i+1]='\0';    
        cc_search(temp);  
   }    
   else if (((chin>='A')&&(chin<='Z'))||((chin>='a')&&(chin<='z'))||(chin=='_'))  /*对保留字、标识符进行处理*/   
 {     int i=0;  
       while  (((chin>='A')&&(chin<='Z'))||((chin>='a')&&(chin<='z'))||(chin=='_')||((chin>='0')&&(chin<='9')))    
	   {     temp[i++]=chin;    
             chin=fgetc(fin);   
	   }   
       temp[i]='\0';   
       char_search(temp);   
       if (chin!=EOF)     fseek (fin,-1L,SEEK_CUR);  
 }  
  else if ((chin>='0')&&(chin<='9'))                              /*对整型、浮点型数据进行处理*/   
  {    int dotcount=0;    
       int i=0;   
       while (((chin>='0')&&(chin<='9'))||(chin=='.'))    
	   {     if (chin=='.')      dotcount++;    
             if (dotcount==2)      break;     
             temp[i++]=chin;     
             chin=fgetc(fin);    
	   }    
       temp[i]='\0';    
       if (dotcount==1)     intb_search(temp);    
       else     inta_search(temp);   
       if (chin!=EOF)     fseek (fin,-1L,SEEK_CUR);  
  }   
  else if (chin=='/')                                             /*对注释进行处理*/ 
{    chin=fgetc(fin);    
      if (chin=='=')    
         {     fout=fopen("output.txt","a");     
               fprintf(fout,"2\t30\t\t/=\n");                        /*fprintf(fout,"2\t30\t\t/=\n");*/
               fclose(fout);   
          }   
       else if (chin!='*')    
        {   fout=fopen("output.txt","a");    
            fprintf(fout,"2\t4\t\t/\n");                          /*fprintf(fout,"2\t4\t\t/\n"); */
            fclose(fout);     
            fseek(fin,-1L,SEEK_CUR);    
	   }   
      else if (chin=='*')    
	  {     count=0;    
            chin=fgetc(fin);    
            fout=fopen("defination.txt","a");    
            fprintf(fout,"/*");    
            while (count!=2)     
			{      count=0;     
                   while (chin!='*')     
				   {       fprintf(fout,"%c",chin);     
                           chin=fgetc(fin);     
				   }     
                   count++;     
                  fprintf(fout,"%c",chin);     
                  chin=fgetc(fin);     
                  if (chin=='/')     
				  {       count++;      
                          fprintf(fout,"%c\n",chin);    
				  }     
                  else      
				  {       fprintf(fout,"%c",chin);    
                          chin=fgetc(fin);     
				  }    
			}   
	  }   
  }    
/*对运算符、分隔符进行处理*/  
  else   
  {    int time=0;    
       int firstblood=0;   
       temp[0]=chin;    
       chin=fgetc(fin);   
       if (chin!=EOF)    
	   {     temp[1]=chin;    
             temp[2]='\0';    
             for (time=1;time<=30;time++)       /*判断当前的符号是否是运算符，是运算符 firstblood为1*/
			 {       if (strcmp(temp,key2[time])==0) 
			 {       firstblood=1;      
                     if (xx2[time]==0)      
					 {        fout=fopen("key2.txt","a");    
                              fprintf(fout,"2\t%d\t\t%s\n",time,temp);      
                              fclose(fout);      
                              xx2[time]=1;      
					 }       
                     fout=fopen("output.txt","a");     
                     fprintf(fout,"2\t%d\t\t%s\n",time,temp);      
                     fclose(fout);      
                      break;      
			 }    
			 }     
            if (firstblood!=1)    
			{      fseek(fin,-1L,SEEK_CUR);   
                   temp[1]='\0';     
                   for (time=1;time<=9;time++)       /*判断是否是分隔符*/
				   {       if (strcmp(temp,key1[time])==0)     
				   {        if (xx1[time]==0)       
				   {          fout=fopen("key1.txt","a");       
                              fprintf(fout,"1\t%d\t\t%s\n",time,temp);        
                              fclose(fout);       
                              xx1[time]=1;       
				   }       
                            fout=fopen("output.txt","a");      
                            fprintf(fout,"1\t%d\t\t%s\n",time,temp);       
                            fclose(fout);       
                           break;     
				   }    
				   }     
                   for (time=1;time<=30;time++)     /*在firstblood为1时判断是否为运算符*/
				   {       if (strcmp(temp,key2[time])==0)   
				   {        if (xx2[time]==0)      
				   {          fout=fopen("key2.txt","a");        
                              fprintf(fout,"2\t%d\t\t%s\n",time,temp);    
                              fclose(fout);        
                              xx2[time]=1;       
				   } 
                            fout=fopen("output.txt","a");      
                            fprintf(fout,"2\t%d\t\t%s\n",time,temp);      
                            fclose(fout);       
                            break;      
				   }      
				   }    
			}  
	   } 
  }  
 chin=fgetc(fin);   
 }  
 fout=fopen("output.txt","a");  
fprintf(fout,"1\t6\t\t}\n");                                      /*fprintf(fout,"1\t6\t\t}\n"); */
 fclose(fout); 
} 

/*******   Main函数   *******/ 
void main() 
{   FILE *fread;  
char charin;   
char command='Q';  
printf("\n"); 
  printf("********************   C语言词法分析工具   ********************\n"); 
 printf("*                                                             *\n");  
printf("*                                                             *\n");  
printf("*  命令如下：                                                 *\n");  
printf("*  0 --> 查看保留字表文件                                     *\n");  
printf("*  1 --> 查看分隔符表文件                                     *\n"); 
 printf("*  2 --> 查看运算符表文件                                     *\n");  
printf("*  3 --> 查看标识符表文件                                     *\n"); 
 printf("*  4 --> 查看整数类型常量表                                   *\n");  
printf("*  5 --> 查看浮点类型常量表                                   *\n"); 
 printf("*  6 --> 查看字符类型常量表                                   *\n");  
printf("*  7 --> 查看字符串类型常量表                                 *\n");  
printf("*  8 --> 查看注释文件                                         *\n");  
printf("*  9 --> 查看内部码文件                                       *\n");  
printf("* --------------------------                                 *\n");   
printf("*  Q --> 退出                                                 *\n");  
printf("***************************************************************\n"); 
 printf("\n");  
load(); 
 scan();   
printf("\n");   
printf("分析完成！\n");  
getchar();  
printf("\n");
printf("请输入命令：");  
command=getchar();  
 while ((command!='Q')&&(command!='q'))  
{   switch (command)   
{   case '0':    {     printf("*************************\n");   
                       printf("\n");    
                       fread=fopen("key0.txt","r");    
                       charin=fgetc(fread);     
                       while (charin!=EOF)     
                        {      putchar(charin);     
                               charin=fgetc(fread);     }      
                      printf("\n");     
                      printf("*************************\n");    
                      printf("\n");     
                      printf("请输入命令：");     
                      break;    }  
   case '1':    {     printf("*************************\n");     
                      printf("\n");     
                      fread=fopen("key1.txt","r");     
                      charin=fgetc(fread);     
                      while (charin!=EOF)     
                      {      putchar(charin);      
                             charin=fgetc(fread);     }    
                      printf("\n");     
                      printf("*************************\n");     
                      printf("\n");     
                      printf("请输入命令：");     
                      break;    }   
  case '2':    {     printf("*************************\n");      
                     printf("\n");     
                     fread=fopen("key2.txt","r");     
                     charin=fgetc(fread);      
                     while (charin!=EOF)  
                     {       putchar(charin);     
                             charin=fgetc(fread);     }      
                     printf("\n");      
                     printf("*************************\n");    
                     printf("\n");     
                     printf("请输入命令：");    
                     break;     }   
  case '3':    {     printf("*************************\n");     
                     printf("\n");      
                     fread=fopen("key3.txt","r");     
                     charin=fgetc(fread);     
                     while (charin!=EOF)     
                       {      putchar(charin);     
                             charin=fgetc(fread);     }      
                     printf("\n");      
                     printf("*************************\n");     
                     printf("\n");      
                     printf("请输入命令：");      
                     break;     }   
  case '4':    {     printf("*************************\n");     
                     printf("\n");      
                    fread=fopen("c40.txt","r");     
                     charin=fgetc(fread);    
                      while (charin!=EOF)     
                      {      putchar(charin);      
                             charin=fgetc(fread);     }     
                     printf("\n");      
                     printf("*************************\n");     
                     printf("\n");     
                     printf("请输入命令：");    
                     break;     }   
 case '5':    {       printf("*************************\n");  
                     printf("\n");      
                     fread=fopen("c41.txt","r");     
                     charin=fgetc(fread);     
                     while (charin!=EOF)     
                      {      putchar(charin);      
                             charin=fgetc(fread);     }      
                     printf("\n");      
                     printf("*************************\n");     
                     printf("\n");      
                     printf("请输入命令：");     
                     break;     }   
 case '6':    {     printf("*************************\n");    
                    printf("\n");      
                    fread=fopen("c42.txt","r");     
                    charin=fgetc(fread);     
                    while (charin!=EOF)     
                       {      putchar(charin);      
                              charin=fgetc(fread);     }     
                    printf("\n");     
                    printf("*************************\n");    
                    printf("\n");      
                    printf("请输入命令：");     
                    break;  }      
 case '7':    {     printf("*************************\n");    
                    printf("\n");     
                    fread=fopen("c43.txt","r");     
                    charin=fgetc(fread);    
                    while (charin!=EOF)     
                     {      putchar(charin);      
                            charin=fgetc(fread);     }      
                    printf("\n");      
                    printf("*************************\n");     
                    printf("\n");      
                    printf("请输入命令：");       
                    break;  }   
 case '8':    {     printf("*************************\n");    
                    printf("\n");   
                    fread=fopen("defination.txt","r");    
                    charin=fgetc(fread);    
                    while (charin!=EOF)     
                    {      putchar(charin);      
                           charin=fgetc(fread);     }     
                    printf("\n");     
                    printf("*************************\n");     
                    printf("\n");     
                    printf("请输入命令：");     
                    break;    }   
 case '9':    {     printf("*************************\n");     
                    printf("\n");     
                    fread=fopen("output.txt","r");     
                    charin=fgetc(fread);     
                    while (charin!=EOF)     
                     {      putchar(charin);      
                            charin=fgetc(fread);     }     
                    printf("\n");     
                    printf("*************************\n");     
                    printf("\n");     
                    printf("请输入命令：");     
                     break;    }  
 }    
command=getchar();  
 }  
}   