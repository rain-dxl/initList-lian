/*初步使用顺序表完成简单学生成绩系统，可实现以下功能：
1.创建一个顺序表，顺带添加第一位同学信息
2.可根据姓名或学号或成绩来查找同学信息
3.插入同学信息，不会改变表顺序
4.根据姓名或学号或序号删除同学信息
由于初始化线性表时内置一位同学信息，所以使用时全功能可直接使用，不会有内存报错情况
编辑于2020年8月31日姓名：rain
2020.9.1 编辑删除函数不会更改表格顺序*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define N 10			//用于最大学生信息个数
#define OVERFLOW  -1	//用于错误退出系统
#define OK 1			//用于返回函数执行是否成功
#define ERROR 0			//返回错误

typedef int Status;

typedef struct
{
	char XH[50];		//学号
	char XM[20];		//姓名
	int CJ;				//数据结构成绩
}Student;						//学生信息结构类型Student

typedef struct
{
	Student *elem;
	int Length;
}SqList;						//学生信息顺序存储结构类型SqList

Status InitList(SqList *L)
{
	printf("正在初始化\n");
	L->elem=new Student[N]; 
	if(!L->elem)
	{
		printf("存储内存分配失败！\n");
		exit(OVERFLOW);
	}
	else
	{
		printf("成功建立顺序表！\n");
		strcpy(L->elem[0].XM,"rain" );
		strcpy(L->elem[0].XH,"Y01814088");
		L->elem[0].CJ = 100;
		L->Length = 1;
	}
	return OK;
}								//顺序表初始化

//根据个数依次录入同学信息
Status Input(SqList *L)
{
	int n;
	printf("\n-------------请在下方输入学生信息----------------\n");
	printf("需要录入几位同学信息(当前已有1位,0-9)：");
	scanf("%d",&n);
	int s = n+1;
	while(n>0)
	{
		int i=0;
		char lsxm[20],lsxh[50];
		printf("\n-----第%d位同学信息-----\n",(s-n));
		printf("该同学姓名：");scanf("%s",L->elem[s-n].XM); L->elem[s-n].XM[sizeof(L->elem[s-n].XM)]='\0';
		printf("%s同学学号：",L->elem[s-n].XM); scanf("%s",L->elem[s-n].XH); L->elem[s+1-n].XH[sizeof(L->elem[s-n].XH)]='\0';
		printf("%s同学数据结构成绩：",L->elem[s-n].XM); scanf("%d",&(L->elem[s-n].CJ));
		L->Length++;
		printf("%s同学录入成功!\n",L->elem[s-n].XM);
		printf("该同学姓名为%s,学号为%s,数据结构成绩为%d\n",L->elem[s-n].XM,L->elem[s-n].XH,L->elem[s-n].CJ);
		n--;
	}
	printf("\n-------------------录入完毕----------------------\n");
	return OK;
}

//查找同学在表中位置
int LocateElem(SqList *L)
{
	int choose,i=0,p=0;
	printf("\n-------------当前表中已有%d位同学---------------\n",L->Length);
	printf("请问需要使用哪种关键字查找(1.姓名2.学号3.分数4.序号)");
	scanf("%d",&choose);
	if(choose==1)
	{
		printf("\n已选择使用姓名方式查询！\n");
		char xm[20];
		printf("输入该同学姓名：");
		scanf("%s",xm);
		printf("\n正在查询%s\n",xm);
		for(i=0;i<L->Length;i++)
			if(strcmp(L->elem[i].XM,xm)==0)
			{
				p=1;
				break;
			}
	}
	if(choose==2)
	{
		printf("\n已选择使用学号方式查询！\n");
		char xh[50];
		printf("输入该同学学号：");
		scanf("%s",xh);
		printf("\n查询中\n");
		for(i=0;i<L->Length;i++)
			if(strcmp(L->elem[i].XH,xh)==0)
			{
				p=1;
				break;
			}
	}
	if(choose==3)
	{
		printf("\n已选择使用数据结构成绩查询！\n");
		int cj;
		printf("输入该同学数据结构成绩：");
		scanf("%d",&cj);
		printf("\n查询数据结构成绩为%d的同学中\n",cj);
		for(i=0;i<L->Length;i++)
			if(L->elem[i].CJ==cj)
			{
				p=1;
				break;
			}
	}
	if(choose==4)
	{
		printf("\n已选择使用序号查询！\n");
		printf("输入同学序号：");
		scanf("%d",&i);
		printf("\n正在查询！\n");
		p=1;
		i=i-1;
	}
	if(p==1)
	{
		printf("成功找到该同学！\n");
		printf("该同学序号：%d\n姓名：%s\n学号：%s\n数据结构成绩:%d\n\n",i+1,L->elem[i].XM,L->elem[i].XH,L->elem[i].CJ);
	}
	else
		printf("查找失败！该同学不在表中！\n\n");
	return 1;
	printf("\n-----------------查找结束-------------------\n");
}

//插入同学信息
Status InSert(SqList *L)
{
	int n,s;
	s=L->Length;
	printf("请问要在哪个位置插入，当前系统中有%d位同学:",L->Length);
	scanf("%d",&n);
	if(n>N||n<0)		printf("\n数据位置错误！\n");
	if(s==N)		printf("\n数据已满！\n");
	if(s<N)
	{
		while(s>=n)
		{
			L->elem[s]=L->elem[s-1];
			s--;
		}
		printf("\n输入该同学的姓名：");scanf("%s",L->elem[s].XM);
		printf("\n输入该同学的学号：");scanf("%s",L->elem[s].XH);
		printf("\n输入该同学的数据结构成绩：");scanf("%d",&L->elem[s].CJ);
		printf("插入完成！");
		L->Length++;
	}
	return OK;
}

//删除同学信息
Status ListDelete(SqList *L)
{
	int choose;
	int i=0;
	printf("\n-------------当前表中已有%d位同学---------------\n",L->Length);
	printf("请问需要使用哪种关键字删除(1.姓名2.学号3.分数4.序号)");
	scanf("%d",&choose);
	if(choose==1)
	{
		printf("\n已选择使用姓名方式删除！\n");
		char xm[20];
		printf("输入该同学姓名：");
		scanf("%s",xm);
		printf("\n正在删除%s\n",xm);
		for(i=0;i<L->Length;i++)
			if(strcmp(L->elem[i].XM,xm)==0)
			{
				while(i<(L->Length-1))
				{
					L->elem[i]=L->elem[i+1];
					i++;
				}
				L->Length--;
				break;
			}
	}
	if(choose==2)
	{
		printf("\n已选择使用学号方式删除！\n");
		char xh[50];
		printf("输入该同学学号：");
		scanf("%s",xh);
		printf("\n删除中\n");
		for(i=0;i<L->Length;i++)
			if(strcmp(L->elem[i].XH,xh)==0)
			{
				while(i<(L->Length-1))
				{
					L->elem[i]=L->elem[i+1];
					i++;
				}
				L->Length--;
				break;
			}
	}
	if(choose==3)
	{
		printf("\n已选择使用数据结构成绩删除！\n");
		int cj;
		printf("输入该同学数据结构成绩：");
		scanf("%d",&cj);
		printf("\n删除数据结构成绩为%d的同学中\n",cj);
		for(i=0;i<L->Length;i++)
			if(L->elem[i].CJ==cj)
			{
				while(i<(L->Length-1))
				{
					L->elem[i]=L->elem[i+1];
					i++;
				}
				L->Length--;
				break;
			}
	}
	if(choose==4)
	{
		printf("\n已选择使用序号删除！\n");
		printf("输入同学序号：");
		scanf("%d",&i);
		printf("\n正在删除！\n");
		while(i<L->Length)
		{
				L->elem[i-1]=L->elem[i];
				i++;
		}
		L->Length--;
	}
	printf("\n-----------------删除成功-------------------\n");
	return OK;
}

//依次打印同学信息
void print(SqList *L)
{
	int length,n=0;
	length = L->Length;
	printf("\n-------------当前表中有%d位同学--------------------\n",length);
	while(n<length)
	{
		printf("姓名：%s,学号：%s,数据结构成绩:%d\n",L->elem[n].XM,L->elem[n].XH,L->elem[n].CJ);
		n++;
	}
	printf("\n\n----------------表格输出完成---------------------\n\n");
}

void main(void)
{
	SqList L;
	InitList(&L);
	printf("**************rain的学生数据结构成绩系统*************\n");
	printf("功能0：退出系统\n");
	printf("功能1：初次输入学生信息\n");
	printf("功能2：插入学生信息\n");
	printf("功能3：删除学生信息\n");
	printf("功能4：查找学生信息\n");
	printf("功能5：统计当前表格学生信息\n\n");
	int choose;
	while(1)
	{
		printf("请输入你要选择的功能序号：");
		scanf("%d",&choose);
		if(choose==0) break;
		if(choose==1) Input(&L);		//初次输入
		if(choose==2) InSert(&L);		//插入数据
		if(choose==3) ListDelete(&L);	//删除数据
		if(choose==4) LocateElem(&L);	//查找信息
		if(choose==5) print(&L);			//查看当前表

	}
}
