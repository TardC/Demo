/*标识符由字母数字下划线组成，且不以数字开头。

字符串（编码）:     
include(1)  void(2)  main(3)  float(4)  char(5)  int(6)  string(7)  for(8)
while(9)  if(10)  else(11)  scanf(12)  printf(13)  break(14)  continue(15)
return(16)  define(17)  typedef(18)  struct(19)  switch(20)  case(21)
sixeof(22)  default(23)  数字(24)  标识符(25)  ( (31)  ) (32)  [ (33)  . (34)  ] (35)  % (36)  , (37)  ; (38)  # (39)  ' (40)  { (41)  " (42)  : (43)  } (44)  != (45)  ! (46)  ++ (47)  += (48)  + (49)  -- (50)  -= (51)  ->( 52)  - (53)  */ 
/*(54)  *= (55)  * (56) 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 500
#define LISTINCREMENT 100
int k=0;//用于为无法识别的字符计数
char f[100];//用于暂时保存无法识别的字符

typedef struct { char *elem;
                 int length;
                 int listsize;
               }sqlist;

typedef struct LNode { char key[20];
                       int number;
                       struct LNode *next;
                     } LNode, *linklist;

//顺序表的初始化
void Initlist_sq(sqlist *l)
    { l->elem=(char*)malloc(LIST_INIT_SIZE*sizeof(char));
    //  if(!l->elem) exit(OVERFLOW);
      l->length=0;
      l->listsize=LIST_INIT_SIZE;
    }

//顺序表的建立，并输入数据，暂时存放输入的待分析的程序代码
void listinsert_sq(sqlist *l)
  {  int i=0;
     char e;
     scanf("%c",&e);
     while(e!='\t')
          {//if(l->length>=l->listsize)
           //    newbase=(char*)realloc(l->elem,(l->listsize+LISTINCREMENT)*sizeof(char));
         // l->elem=newbase;
            l->elem[i]=e;
            l->length++;
            i++;
            scanf("%c",&e);

          }

   }

//单链表的建立，存放关键字
void createlist_l(linklist l)
   {  linklist p,q;
      int i;
      q=l;
      for(i=1;i<=23;i++)
        { p=(linklist)malloc(sizeof(LNode));
          p->next=NULL;
          switch(i)
            { case 1:strcpy(p->key,"include");break;
              case 2:strcpy(p->key,"void");break;
              case 3:strcpy(p->key,"main");break;
              case 4:strcpy(p->key,"float");break;
              case 5:strcpy(p->key,"char");break;
              case 6:strcpy(p->key,"int");break;
              case 7:strcpy(p->key,"string");break;
              case 8:strcpy(p->key,"for");break;
              case 9:strcpy(p->key,"while");break;
              case 10:strcpy(p->key,"if");break;
              case 11:strcpy(p->key,"else");break;
              case 12:strcpy(p->key,"scanf");break;
              case 13:strcpy(p->key,"printf");break;
              case 14:strcpy(p->key,"break");break;
              case 15:strcpy(p->key,"continue");break;
              case 16:strcpy(p->key,"return");break;
              case 17:strcpy(p->key,"define");break;
              case 18:strcpy(p->key,"typedef");break;
              case 19:strcpy(p->key,"struct");break;
              case 20:strcpy(p->key,"switch");break;
              case 21:strcpy(p->key,"case");break;
              case 22:strcpy(p->key,"sixeof");break;
              case 23:strcpy(p->key,"default");break;
              default:break;
            }
          p->number=i;
          q->next=p;
          q=q->next;
        }
    }

//进行匹配 判段是数字 标识符 关键字 无法识别的字符
int search(sqlist *p,linklist q,int i)
   { char a[20];
     int j=0;
     linklist t=q->next;
     if(i<p->length){   if('a'<=p->elem[i]&&p->elem[i]<='z'||'A'<=p->elem[i]&&p->elem[i]<='Z'||p->elem[i]=='_')//标识符
                             while(i<p->length)
                               {  if('a'<=p->elem[i]&&p->elem[i]<='z'||'A'<=p->elem[i]&&p->elem[i]<='Z'||p->elem[i]=='_'||'0'<=p->elem[i]&&p->elem[i]<='9')
                                    { a[j]=p->elem[i];
                                      i++;
                                      j++;
                                    }
                                  else { a[j]='\0';break; }
                                }

                         else if('0'<=p->elem[i]&&p->elem[i]<='9')//数字
                                 while(i<p->length)
                                    if('0'<=p->elem[i]&&p->elem[i]<='9')
                                       { a[j]=p->elem[i];
                                         i++;
                                         j++;
                                        }
                                    else { a[j]='\0';break; }

                      }

 
      if(j>0){ while(t!=NULL)
                   if(strcmp(a,t->key)==0)
                      { printf("%-20s  %d\n",a,t->number);//关键字 
                        break;}
                   else t=t->next;
               if(t==NULL)if('0'<=a[0]&&a[0]<='9') printf("%-20s  24\n",a);
                          else   printf("%-20s  25\n",a);  //非关键字的标识符 
              }
      else if(i<p->length)
              switch(p->elem[i])//运算符
                 {  case '(':printf("%-20c  31\n",p->elem[i]);i++;break;
                    case ')':printf("%-20c  32\n",p->elem[i]);i++;break;
                    case '[':printf("%-20c  33\n",p->elem[i]);i++;break;
                    case '.':printf("%-20c  34\n",p->elem[i]);i++;break;
                    case ']':printf("%-20c  35\n",p->elem[i]);i++;break;
                    case '%':printf("%-20c  36\n",p->elem[i]);i++;break;
                    case ',':printf("%-20c  37\n",p->elem[i]);i++;break;
                    case ';':printf("%-20c  38\n",p->elem[i]);i++;break;
                    case '#':printf("%-20c  39\n",p->elem[i]);i++;break;
                    case '\'':printf("%-20c  40\n",p->elem[i]);i++;break;//为什么单引号是\'   ？
                    case '{':printf("%-20c  41\n",p->elem[i]);i++;break;
                    case '"':printf("%-20c  42\n",p->elem[i]);i++;break;
                    case ':':printf("%-20c  43\n",p->elem[i]);i++;break;
                    case '}':printf("%-20c  44\n",p->elem[i]);i++;break;
                    case '!':if(p->elem[i+1]=='=') { printf("%c%-20c  45\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else { printf("%-20c  46\n",p->elem[i]); i++;break; }
                    case '+':if(p->elem[i+1]=='+') { printf("%c%-20c  47\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else if(p->elem[i+1]=='=') { printf("%c%-20c  48\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                                  else { printf("%c  49\n",p->elem[i]); i++;break; }
                    case '-':if(p->elem[i+1]=='-') { printf("%c%-20c  50\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else if(p->elem[i+1]=='=') { printf("%c%-20c  51\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else if(p->elem[i+1]=='>') { printf("%c%-20c  52\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                                  else { printf("%-20c  53\n",p->elem[i]);i++;break;}
                    case '*':if(p->elem[i+1]=='/') { printf("%c%-20c  54\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else if(p->elem[i+1]=='=') { printf("%c%-20c  55\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                                  else { printf("%-20c  56\n",p->elem[i]); i++;break; }
                    case '/':if(p->elem[i+1]=='*') { printf("%c%-20c  57\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else if(p->elem[i+1]=='=') { printf("%c%-20c  58\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                                  else { printf("%-20c  59\n",p->elem[i]); i++;break; }
                    case '>':if(p->elem[i+1]=='=') { printf("%c%-20c  60\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else { printf("%-20c  61\n",p->elem[i]); i++;break; }
                    case '<':if(p->elem[i+1]=='=') { printf("%c%-20c  62\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else { printf("%-20c  63\n",p->elem[i]); i++;break; }
                    case '=':if(p->elem[i+1]=='=') { printf("%c%-20c  64\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else { printf("%-20c  65\n",p->elem[i]); i++;break; }
                    case '&':if(p->elem[i+1]=='&') { printf("%c%-20c  66\n",p->elem[i],p->elem[i+1]);i++;i++;break;}
                             else { printf("%-20c  67\n",p->elem[i]); i++;break; }

                 
                  // case'\n':break;
                  // case'空格':break;// 根本不起作用     
                   default:f[k]=p->elem[i];i++;k++;break;
                  }

     if(i>=p->length) return 1;
     else return search(p,q,i);
   }

 

void main()
 {  sqlist p;
    linklist q;
    int i=0;
    q=(linklist)malloc(sizeof(LNode));
    q->next=NULL;
    printf("End with space Tab \\n \n");
    printf("------------------------------------------------\n");
    createlist_l(q);
    Initlist_sq(&p);
    listinsert_sq(&p);
    printf("--------------------Token-----------------------\n\n");
    i=search(&p,q,0);
    printf("--------------------Error-----------------------\n\n");
    printf("cant differ:");
    for(i=0;i<k;i++)
      if(f[i]=='\n'||f[i]==32)continue;//为什么在case语句中不正确???
      else printf("%c  ",f[i]);
    getchar();
  }

