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
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("������ѧ����Ϣ��\n");
	printf(" ����  ѧ��  �Ա�  Ӣ��  ��ѧ  �Ƶ�  C����\n");
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
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf(" ����  ѧ��  �Ա�  Ӣ��  ��ѧ  �Ƶ�  C����\n");
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
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("�˵�ѡ��\n1.����\t2.���\t3.�޸�\t4.ɾ��\t5.�鿴\t6.�˳�\n���������ѡ���ܣ�\n");
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
	default:printf("��������ȷ�Ĳ˵�ѡ�\n");
	}
}


void find(stu *head)
{
	int x;
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("��ѡ����ҷ�ʽ��\n1.��ѧ�Ų���\t2.����������\n���������ѡ���ܣ�\n");
	scanf("%d",&x);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	switch(x)
	{
	case 1:findNUM(head);break;
	case 2:findNAME(head);break;
	default:printf("��������ȷ�Ĳ˵�ѡ�\n");
	}
}


void findNAME(stu *head)
{
	stu *p2;
	char name[20];
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("������Ҫ����ѧ����������\n");
	scanf("%s",name);
	getchar();
	system("cls");
	p2=head;
	while(p2!=NULL)
	{
		if(strcmp(name,p2->Name)==0)
		{
			printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
			printf("---------------------------------------------------------------------\n\n\n\n");
			printf("��ѧ������Ϣ���£�\n");
			printf("������%s  ѧ�ţ�%d  �Ա�%s  Ӣ�%d  ��ѧ��%d  �Ƶ���%d  C���ԣ�%d\n",p2->Name,p2->NUM,p2->sex,p2->score.eng_,p2->score.mat_,p2->score.com_,p2->score.clg_);
			break;
		}
		p2=p2->next;
	}
	if(p2==NULL)printf("δ�ҵ���ѧ����Ϣ����ȷ�������Ƿ���ȷ\n");
	printf("\n\n\n\n---------------------------------------------------------------------\n");
}


void findNUM(stu *head)
{
	void back_menu(stu *head);
	int num;
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("������Ҫ����ѧ����ѧ�ţ�\n");
	scanf("%d",&num);
	getchar();
	system("cls");
	stu *p2=head;
	while(p2!=NULL)
	{
		if(num==p2->NUM)
			{
				printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("��ѧ������Ϣ���£�\n");
				printf("������%s  ѧ�ţ�%d  �Ա�%s  Ӣ�%d  ��ѧ��%d  �Ƶ���%d  C���ԣ�%d\n",p2->Name,p2->NUM,p2->sex,p2->score.eng_,p2->score.mat_,p2->score.com_,p2->score.clg_);
				break;
			}
		p2=p2->next;
	}
	if(p2==NULL)printf("δ�ҵ���ѧ����Ϣ����ȷ�������Ƿ���ȷ\n");
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	back_menu(head);
}


void add(stu *head)
{
	stu *p1,*p2;
	p1=(stu*)malloc(sizeof(stu));
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("������Ҫ��ӵ�ѧ����Ϣ��\n");
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
			printf("��ӳɹ���\n");
			break;
		}
		else p2=p2->next;
	}
	if(p2->next==NULL)
	{
		p1->next=p2->next;
		p2->next=p1;
		printf("��ӳɹ���\n");
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
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("ѡ��ɾ��ѧ����Ϣ���ҷ�ʽ��\n1.��ѧ�Ų���ɾ��\t2.����������ɾ��\n");
	scanf("%d",&x);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	switch(x)
	{
	case 1:{
				printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("������ѧ�ţ�\n");
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
						printf("ɾ���ɹ���\n");
						break;
					}
					else p2=p2->next;
				}
				if(p2==NULL)printf("δ�ҵ���ѧ����Ϣ����ȷ�������Ƿ���ȷ\n");
				print_(head);
		}break;
	case 2:{
				printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("������Ҫɾ����ѧ��������\n");
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
						printf("ɾ���ɹ���\n");
						break;
					}
					else p2=p2->next;
				}
				if(p2==NULL)printf("δ�ҵ���ѧ����Ϣ����ȷ�������Ƿ���ȷ\n");
				print_(head);
		   }break;
	default:printf("��������ȷ�Ĳ˵�ѡ�\n");
	}
	getchar();
	system("cls");
}


void change(stu *head)
{
	int x;
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("��ѡ�����Ҫ�޸�ѧ����Ϣ�ķ�ʽ:\n");
	printf("1.��ѧ�Ų���\t2.����������\n");
	scanf("%d", &x);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	switch (x)
	{
	case 1:
	{
		int num;
		printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
		printf("---------------------------------------------------------------------\n\n\n\n");
		printf("������Ҫ����ѧ����ѧ�ţ�\n");
		scanf("%d", &num);
		getchar();
		system("cls");
		stu *p2 = head;
		while (p2 != NULL)
		{
			if (num == p2->NUM)
			{
				printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("��ѧ������Ϣ���£�\n");
				printf("������%s  ѧ�ţ�%d  �Ա�%s  Ӣ�%d  ��ѧ��%d  �Ƶ���%d  C���ԣ�%d\n", p2->Name, p2->NUM, p2->sex, p2->score.eng_, p2->score.mat_, p2->score.com_, p2->score.clg_);
				break;
			}
			p2 = p2->next;
		}
		if (p2 == NULL)printf("δ�ҵ���ѧ����Ϣ����ȷ�������Ƿ���ȷ\n");
		printf("�������޸ĺ��ѧ����Ϣ��\n");
		printf(" ����  ѧ��  �Ա�  Ӣ��  ��ѧ  �Ƶ�  C����\n");
		scanf("%s%d%s%d%d%d%d", &p2->Name, &p2->NUM, &p2->sex, &p2->score.eng_, &p2->score.mat_, &p2->score.com_, &p2->score.clg_);
		printf("�޸ĳɹ���\n");
		getchar();
		system("cls");
		print_(head);
		back_menu(head);
	}break;
	case 2:
	{
		stu *p2;
		char name[20];
		printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
		printf("---------------------------------------------------------------------\n\n\n\n");
		printf("������Ҫ����ѧ����������\n");
		scanf("%s", name);
		getchar();
		system("cls");
		p2 = head;
		while (p2 != NULL)
		{
			if (strcmp(name, p2->Name) == 0)
			{
				printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
				printf("---------------------------------------------------------------------\n\n\n\n");
				printf("��ѧ������Ϣ���£�\n");
				printf("������%s  ѧ�ţ�%d  �Ա�%s  Ӣ�%d  ��ѧ��%d  �Ƶ���%d  C���ԣ�%d\n", p2->Name, p2->NUM, p2->sex, p2->score.eng_, p2->score.mat_, p2->score.com_, p2->score.clg_);
				break;
			}
			p2 = p2->next;
		}
		if (p2 == NULL)printf("δ�ҵ���ѧ����Ϣ����ȷ�������Ƿ���ȷ\n");
		printf("�������޸ĺ��ѧ����Ϣ��\n");
		printf(" ����  ѧ��  �Ա�  Ӣ��  ��ѧ  �Ƶ�  C����\n");
		scanf("%s%d%s%d%d%d%d", &p2->Name, &p2->NUM, &p2->sex, &p2->score.eng_, &p2->score.mat_, &p2->score.com_, &p2->score.clg_);
		printf("�޸ĳɹ���\n");
		getchar();
		system("cls");
		print_(head);
		back_menu(head);
	}break;
	default:
	{
		printf("��������ȷ�Ĳ˵�ѡ�\n");
		change(head);
	}
	}
}


void back_menu(stu *head)
{
	printf("\t\t\t\t\t\t\t�س��������˵�\n");
	menu(head);
}


int main()
{
	int n;
	stu *build(int n),*head;
	printf("---------------------------ѧ���ɼ�����ϵͳ--------------------------\n");
	printf("---------------------------------------------------------------------\n\n\n\n");
	printf("������ѧ��������\n");
	scanf("%d",&n);
	printf("\n\n\n\n---------------------------------------------------------------------\n");
	getchar();
	system("cls");
	head=build(n);
	print_(head);
	menu(head);
	return 0;
}