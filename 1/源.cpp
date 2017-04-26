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
//创建
void creat()
{
	int chose=1;
	while (chose == 1)
	{
		ofstream outfile("zf.txt", ios::app);
		student *s = new student;
		cout << "输入姓名：";
		cin >> s->name;
		cout << "输入学号：";
		cin >> s->num;
		cout << "输入成绩:";
		cin >> s->grade;
		outfile.write((char*)s, sizeof(student));
		outfile.close();
		cout << "是否继续输入\n1.继续\t2.放弃" << endl;
		cin >> chose;
	}
}
//显示
void display()
{
	student *read = new student;
	ifstream readfile("zf.txt", ios::in);
	while (readfile.peek() != EOF)
	{
		readfile.read((char*)read, sizeof(student));
		cout << "名字"<<read->name<<endl;
		cout <<"学号"<<read->num<<endl;
		cout << "成绩" << read->grade << endl;
		cout << endl;
	}
	system("pause");
}

//删除
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
	cout << "输入学号" << endl;
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
		cout << "查无此人" << endl;
	}
	else
	{
		int a = 0;
		cout << "确定删除\n1.确定\t2.放弃\n" << endl;
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
//修改
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
	cout << "输入学号" << endl;
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
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "请修改" << endl;
		cout << "输入姓名：";
		cin >>mystudent[i].name;
		cout << "输入学号：";
		cin >> mystudent[i].num;
		cout << "输入成绩:";
		cin >> mystudent[i].grade;
		
		ofstream writefile("zf.txt", ios::out);
		for ( i = 0; i < all; i++)
		{
			read = &mystudent[i];
			writefile.write((char*)read, sizeof(student));
		}
		cout << "修改完毕" << endl;
	}


}
//菜单
void meun()
{
	cout << "\t\t**************学生管理系统******** " << endl;
	cout << "\t\t**		1.创建		**" << endl;
	cout << "\t\t**		2.修改		**" << endl;
	cout << "\t\t**		3.显示		**" << endl;
	cout << "\t\t**		4.排序		**" << endl;
	cout << "\t\t**		5.删除		**" << endl;
	cout << "\t\t**		6.帮助		**" << endl;
	cout << "\t\t**********************************" << endl;
}
//创建链表,未完成
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

//数组实现排序
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
	cout << "1.按学号排序\t2.按成绩排序\t" << endl;
	cin >> chose;
	switch (chose)
	{
	case 1:
		sort(mystudent, mystudent + i, cmp_2);
		break;
	case 2:
		sort(mystudent, mystudent + i, cmp_1);
	default:cout << "输入有误" << endl;
		break;
	}
	for ( i= 0; i < all; ++i)
	{
		cout << "名字" << mystudent[i].name << endl;
		cout << "学号" << mystudent[i].num<< endl;
		cout << "成绩" << mystudent[i].grade << endl;
		cout << endl;
	}
	system("pause");
}

//帮助
void help()
{
	cout << "此程序没有丝毫健壮性，情小心呵护\n";
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