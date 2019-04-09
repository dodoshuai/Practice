#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct Student  stu;
struct Score
{
	int eng_;
	int mat_;
	int com_;
	int clg_;
};
struct Student
{
	char Name[20];
	int NUM;
	char sex[1];
	struct Score score;
	stu *next;
};
void menu(stu *head);
void findNUM(stu *head);
void findNAME(stu *head);
void find(stu *head);
void add(stu *head);
void cancel(stu *head);
void back_menu(stu *head);
void change(stu *head);


stu *build(int n)
{
	stu *head,*p1,*p2;
	int i;
	p2=head=(stu*)malloc(sizeof(stu));
	for(i=0;i<n-1;i++)
	{
		p1=(stu*)malloc(sizeof(stu));
		p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	p2=head;
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("请输入学生信息：\n");
	printf(" 姓名  学号  性别  英语  数学  计导  C语言\n");
	while(p2!=NULL)
	{
		scanf("%s%d%s%d%d%d%d",&p2->Name,&p2->NUM,&p2->sex,&p2->score.eng_,&p2->score.mat_,&p2->score.com_,&p2->score.clg_);
		p2=p2->next;
	}
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	return head;
}


void print_(stu *head)
{
	stu *p2;
	p2=head;
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf(" 姓名  学号  性别  英语  数学  计导  C语言\n");
	while(p2!=NULL)
	{
		printf("%5s     %d     %s    %d     %d     %d     %d\n",p2->Name,p2->NUM,p2->sex,p2->score.eng_,p2->score.mat_,p2->score.com_,p2->score.clg_);
		p2=p2->next;
	}
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	if (kbhit() == 27)menu(head);
}


void menu(stu *head)
{
	getchar();
	system("cls");
	int x;
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("菜单选择：\n1.查找\t2.添加\t3.修改\t4.删除\t5.查看\t6.退出\n请输入序号选择功能：\n");
	scanf("%d",&x);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	switch(x)
	{
	case 1:find(head);break;
	case 2:add(head);break;
	case 3:change(head); break;
	case 4:cancel(head);break;
	case 5:print_(head); break;
	case 6:exit(0);
	default:printf("请输入正确的菜单选项！\n");
	}
}


void find(stu *head)
{
	int x;
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("请选择查找方式：\n1.按学号查找\t2.按姓名查找\n请输入序号选择功能：\n");
	scanf("%d",&x);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	switch(x)
	{
	case 1:findNUM(head);break;
	case 2:findNAME(head);break;
	default:printf("请输入正确的菜单选项！\n");
	}
}


void findNAME(stu *head)
{
	stu *p2;
	char name[20];
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("请输入要查找学生的姓名：\n");
	scanf("%s",name);
	getchar();
	system("cls");
	p2=head;
	while(p2!=NULL)
	{
		if(strcmp(name,p2->Name)==0)
		{
			printf("---------------------------学生成绩管理系统--------------------------\n");
			printf("---------------------------------------------------------------------\n\n\n\n");
			printf("该学生的信息如下：\n");
			printf("姓名：%s  学号：%d  性别：%s  英语：%d  数学：%d  计导：%d  C语言：%d\n",p2->Name,p2->NUM,p2->sex,p2->score.eng_,p2->score.mat_,p2->score.com_,p2->score.clg_);
			break;
		}
		p2=p2->next;
	}
	if(p2==NULL)printf("未找到该学生信息，请确认输入是否正确\n");
	printf("\n\n\n\n---------------------------------------------------------------------\n");
}


void findNUM(stu *head)
{
	void back_menu(stu *head);
	int num;
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("请输入要查找学生的学号：\n");
	scanf("%d",&num);
	getchar();
	system("cls");
	stu *p2=head;
	while(p2!=NULL)
	{
		if(num==p2->NUM)
			{
				printf("---------------------------学生成绩管理系统--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("该学生的信息如下：\n");
				printf("姓名：%s  学号：%d  性别：%s  英语：%d  数学：%d  计导：%d  C语言：%d\n",p2->Name,p2->NUM,p2->sex,p2->score.eng_,p2->score.mat_,p2->score.com_,p2->score.clg_);
				break;
			}
		p2=p2->next;
	}
	if(p2==NULL)printf("未找到该学生信息，请确认输入是否正确\n");
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	back_menu(head);
}


void add(stu *head)
{
	stu *p1,*p2;
	p1=(stu*)malloc(sizeof(stu));
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("请输入要添加的学生信息：\n");
	scanf("%s%d%s%d%d%d%d",&p1->Name,&p1->NUM,&p1->sex,&p1->score.eng_,&p1->score.mat_,&p1->score.com_,&p1->score.clg_);
	getchar();
	system("cls");
	p2=head;
	while(p2->next!=NULL)
	{
		if(p1->NUM>p2->NUM&&p1->NUM<p2->next->NUM)
		{
			p1->next=p2->next;
			p2->next=p1;
			printf("添加成功！\n");
			break;
		}
		else p2=p2->next;
	}
	if(p2->next==NULL)
	{
		p1->next=p2->next;
		p2->next=p1;
		printf("添加成功！\n");
	}
	print_(head);
}		


void cancel(stu *head)
{
	int x,num;
	char name[20];
	stu *p1,*p2;
	p2=head;
	p1=head;
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("选择删除学生信息查找方式：\n1.按学号查找删除\t2.按姓名查找删除\n");
	scanf("%d",&x);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	switch(x)
	{
	case 1:{
				printf("---------------------------学生成绩管理系统--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("请输入学号：\n");
				scanf("%d",&num);
				while(p2!=NULL)
				{
					if(p2==head)p1=head;
					else p1->next=p2;
					if(num==p2->NUM)
					{
						if(p2==head)head=p2->next;
						else
						{
							if(p2->next==NULL)p1->next=NULL;
							else 
							{
								p1->next=p2->next;
							}
						}
						printf("删除成功！\n");
						break;
					}
					else p2=p2->next;
				}
				if(p2==NULL)printf("未找到该学生信息，请确认输入是否正确\n");
				print_(head);
		}break;
	case 2:{
				printf("---------------------------学生成绩管理系统--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("请输入要删除的学生姓名：\n");
				scanf("%s",name);

				while(p2!=NULL)
				{
					if(p2==head)p1=head;
					else p1->next=p2;
					if(strcmp(name,p2->Name)==0)
					{
						if(p2==head)head=p2->next;
						else
						{
							if(p2->next==NULL)p1->next=NULL;
							else 
							{
								p1->next=p2->next;
							}
						}
						printf("删除成功！\n");
						break;
					}
					else p2=p2->next;
				}
				if(p2==NULL)printf("未找到该学生信息，请确认输入是否正确\n");
				print_(head);
		   }break;
	default:printf("请输入正确的菜单选项！\n");
	}
	getchar();
	system("cls");
}


void change(stu *head)
{
	int x;
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("请选择查找要修改学生信息的方式:\n");
	printf("1.按学号查找\t2.按姓名查找\n");
	scanf("%d", &x);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	switch (x)
	{
	case 1:
	{
		int num;
		printf("---------------------------学生成绩管理系统--------------------------\n");
		printf("---------------------------------------------------------------------\n\n\n\n");
		printf("请输入要查找学生的学号：\n");
		scanf("%d", &num);
		getchar();
		system("cls");
		stu *p2 = head;
		while (p2 != NULL)
		{
			if (num == p2->NUM)
			{
				printf("---------------------------学生成绩管理系统--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("该学生的信息如下：\n");
				printf("姓名：%s  学号：%d  性别：%s  英语：%d  数学：%d  计导：%d  C语言：%d\n", p2->Name, p2->NUM, p2->sex, p2->score.eng_, p2->score.mat_, p2->score.com_, p2->score.clg_);
				break;
			}
			p2 = p2->next;
		}
		if (p2 == NULL)printf("未找到该学生信息，请确认输入是否正确\n");
		printf("请输入修改后的学生信息：\n");
		printf(" 姓名  学号  性别  英语  数学  计导  C语言\n");
		scanf("%s%d%s%d%d%d%d", &p2->Name, &p2->NUM, &p2->sex, &p2->score.eng_, &p2->score.mat_, &p2->score.com_, &p2->score.clg_);
		printf("修改成功！\n");
		getchar();
		system("cls");
		print_(head);
		back_menu(head);
	}break;
	case 2:
	{
		stu *p2;
		char name[20];
		printf("---------------------------学生成绩管理系统--------------------------\n");
		printf("---------------------------------------------------------------------\n\n\n\n");
		printf("请输入要查找学生的姓名：\n");
		scanf("%s", name);
		getchar();
		system("cls");
		p2 = head;
		while (p2 != NULL)
		{
			if (strcmp(name, p2->Name) == 0)
			{
				printf("---------------------------学生成绩管理系统--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("该学生的信息如下：\n");
				printf("姓名：%s  学号：%d  性别：%s  英语：%d  数学：%d  计导：%d  C语言：%d\n", p2->Name, p2->NUM, p2->sex, p2->score.eng_, p2->score.mat_, p2->score.com_, p2->score.clg_);
				break;
			}
			p2 = p2->next;
		}
		if (p2 == NULL)printf("未找到该学生信息，请确认输入是否正确\n");
		printf("请输入修改后的学生信息：\n");
		printf(" 姓名  学号  性别  英语  数学  计导  C语言\n");
		scanf("%s%d%s%d%d%d%d", &p2->Name, &p2->NUM, &p2->sex, &p2->score.eng_, &p2->score.mat_, &p2->score.com_, &p2->score.clg_);
		printf("修改成功！\n");
		getchar();
		system("cls");
		print_(head);
		back_menu(head);
	}break;
	default:
	{
		printf("请输入正确的菜单选项！\n");
		change(head);
	}
	}
}


void back_menu(stu *head)
{
	printf("\t\t\t\t\t\t\t回车返回主菜单\n");
	menu(head);
}


int main()
{
	int n;
	stu *build(int n),*head;
	printf("---------------------------学生成绩管理系统--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("请输入学生人数：\n");
	scanf("%d",&n);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	head=build(n);
	print_(head);
	menu(head);
	return 0;
}