#include<cstdio>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<list>
#include<string>
using namespace std;
struct student
{
	char name[20];
	long num;
	int grade;
};

bool cmp_1(student a,student b)
{
	return a.grade > b.grade; 

}
bool cmp_2(student a, student b)
{
	return a.num > b.num;

}
//����
void creat()
{
	int chose=1;
	while (chose == 1)
	{
		ofstream outfile("zf.txt", ios::app);
		student *s = new student;
		cout << "����������";
		cin >> s->name;
		cout << "����ѧ�ţ�";
		cin >> s->num;
		cout << "����ɼ�:";
		cin >> s->grade;
		outfile.write((char*)s, sizeof(student));
		outfile.close();
		cout << "�Ƿ��������\n1.����\t2.����" << endl;
		cin >> chose;
	}
}
//��ʾ
void display()
{
	student *read = new student;
	ifstream readfile("zf.txt", ios::in);
	while (readfile.peek() != EOF)
	{
		readfile.read((char*)read, sizeof(student));
		cout << "����"<<read->name<<endl;
		cout <<"ѧ��"<<read->num<<endl;
		cout << "�ɼ�" << read->grade << endl;
		cout << endl;
	}
	system("pause");
}

//ɾ��
void del()
{
	student mystudent[1000];
	ifstream readfile("zf.txt", ios::in);
	list<student>mylist;
	int i = 0;
	struct student *read;
	for (; (readfile.peek() != EOF); i++)
	{
		read = &mystudent[i];
		readfile.read((char*)read, sizeof(student));
	}
	int all = i;
	cout << "����ѧ��" << endl;
	long num;
	cin >> num;
	for (i = 0; (i <all); i++)
	{
		if (mystudent[i].num == num)
		{
			break;
		}
	}
	if (mystudent[i].num != num)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		int a = 0;
		cout << "ȷ��ɾ��\n1.ȷ��\t2.����\n" << endl;
		cin >> a;
		if (a=1)
		{
			for (; i < all-1; i++)
			{
				mystudent[i] = mystudent[i + 1];
			}
			ofstream writefile("zf.txt", ios::out);
			for (i = 0; i < all-1; i++)
			{
				read = &mystudent[i];
				writefile.write((char*)read, sizeof(student));
			}

		}
	}



}
//�޸�
void change()
{
	student mystudent[1000];
	ifstream readfile("zf.txt", ios::in);
	list<student>mylist;
	int i = 0;
	struct student *read;
	for (; (readfile.peek() != EOF); ++i)
	{
		read = &mystudent[i];
		readfile.read((char*)read, sizeof(student));
	}
	int all = i;
	cout << "����ѧ��" << endl;
	long num;
	cin >> num;
	for ( i = 0;(i <all); i++)
	{
		if (mystudent[i].num == num)
		{
			break;
		}
	}
	if (mystudent[i].num != num)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "���޸�" << endl;
		cout << "����������";
		cin >>mystudent[i].name;
		cout << "����ѧ�ţ�";
		cin >> mystudent[i].num;
		cout << "����ɼ�:";
		cin >> mystudent[i].grade;
		
		ofstream writefile("zf.txt", ios::out);
		for ( i = 0; i < all; i++)
		{
			read = &mystudent[i];
			writefile.write((char*)read, sizeof(student));
		}
		cout << "�޸����" << endl;
	}


}
//�˵�
void meun()
{
	cout << "\t\t**************ѧ������ϵͳ******** " << endl;
	cout << "\t\t**		1.����		**" << endl;
	cout << "\t\t**		2.�޸�		**" << endl;
	cout << "\t\t**		3.��ʾ		**" << endl;
	cout << "\t\t**		4.����		**" << endl;
	cout << "\t\t**		5.ɾ��		**" << endl;
	cout << "\t\t**		6.����		**" << endl;
	cout << "\t\t**********************************" << endl;
}
//��������,δ���
/*void studentlist()
{
	long i;
	student *read = new student;
	ifstream readfile("zf.txt", ios::in);
	list<student>mylist;
	while (readfile.peek() != EOF)
	{
		readfile.read((char*)read, sizeof(student));
		mylist.push_front(new);
		student *read = new student;
	}

}*/

//����ʵ������
void paixu()
{
	student mystudent[1000];
	ifstream readfile("zf.txt", ios::in);
	list<student>mylist;
	int i = 0;
	struct student *read;
	for(;( readfile.peek() != EOF);++i)
	{
		read = &mystudent[i];
		readfile.read((char*)read, sizeof(student));
	}
	int all = i;
	int chose;
	cout << "1.��ѧ������\t2.���ɼ�����\t" << endl;
	cin >> chose;
	switch (chose)
	{
	case 1:
		sort(mystudent, mystudent + i, cmp_2);
		break;
	case 2:
		sort(mystudent, mystudent + i, cmp_1);
	default:cout << "��������" << endl;
		break;
	}
	for ( i= 0; i < all; ++i)
	{
		cout << "����" << mystudent[i].name << endl;
		cout << "ѧ��" << mystudent[i].num<< endl;
		cout << "�ɼ�" << mystudent[i].grade << endl;
		cout << endl;
	}
	system("pause");
}

//����
void help()
{
	cout << "�˳���û��˿����׳�ԣ���С�ĺǻ�\n";
	system("pause");
}
int main()
{
	while (true)
	{
		system("cls");
		int a;
		meun();
		cin >> a;
		switch (a) {
		case 1: creat();
			break;
		case 2:change();
			break;
		case 3:display();
			break;
		case 4:paixu();
			break;
		case 5:del();
			break;
		case 6:help();
			break;
		default:printf("error\n");
		}
	}
}