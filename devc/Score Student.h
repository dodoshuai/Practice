class class Score
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
	cout<<"\n������ɼ���"<<computer;
	cout<<"\nӢ��ɼ���"<<english;
	cout<<"\n��ѧ�ɼ���"<<mathematics;
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
		cout<<"ѧ����������"<<num<<endl;
		cout<<"ѧ���ܳɼ���"<<sco<<endl;
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
	cout<<"\nѧ�ţ�"<<xue;
	cout<<"\n������"<<name;
	scorel.show();
	
}
int Student::num=0;
float Student::sco=0; 
