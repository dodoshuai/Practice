#include<iostream>
#include<string.h>
using namespace std;
class Score
{
	private:
		float computer;
		float english;
		float mathematics;
		
	public:	
		Score(float c=0,float e=0,float m=0);
		void show();		
};

Score::Score(float c,float e,float m)
{
	computer=c;
	english=e;
	mathematics=m;
}
void Score::show()
{
	cout<<"\n计算机成绩："<<computer;
	cout<<"\n英语成绩："<<english;
	cout<<"\n数学成绩："<<mathematics;
}
class Student
{
	private:
		char *xue;
		char *name;
		Score scorel;
		static float sco;
		static int num;
	public:
		Student(char *x,char *n,float c,float e,float m);
		~Student();
		void show();
		static void show2()
	{
		cout<<"学生总人数："<<num<<endl;
		cout<<"学生总成绩："<<sco<<endl;
	}	
		
};

Student::Student(char * x,char * n,float c,float e,float m):scorel(c,e,m)
{
	xue=new char[strlen(x)+1];
	strcpy(xue,x);
	name=new char[strlen(n)+1];	
	strcpy(name,n);
	num++;
	sco=c+e+m;
}
Student::~Student()
{
	delete []xue;
	delete []name;		
}
void Student::show()
{
	cout<<"\n学号："<<xue;
	cout<<"\n姓名："<<name;
	scorel.show();
	
}
int Student::num=0;
float Student::sco=0;
int main()
{
	Student stu1("李小明","990201",90,80,70);
	stu1.show();
	cout<<endl;
	Student stu2("张永生","990202",95,85,75);
	stu2.show();
	cout<<endl;
	stu2.show2();

	/*char *x;
	char *n;
	float c,e,m;
	int i;
	
	Student *A= new Student[100];
	for(;;) */
	return 0;
}
