#include<iostream>
#include<string>
using namespace std;
#include"MyArray.hpp"
/////////////�����������Ͳ���///////////////////////////////
void printArray(MyArray<int> & arr)
{
	for (int i = 0; i < arr.get_Size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < arr1.get_Capacity(); i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;
	//MyArray<int> arr2(arr1);//��������
	//MyArray<int> arr3(100);
	//arr3 = arr1;
	printArray(arr1);

	cout << "arr1��������" << arr1.get_Capacity() << endl
		<< "arr1�Ĵ�С��" << arr1.get_Size() << endl;

	MyArray<int> arr2(arr1);
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	printArray(arr2);
	arr2.Pop_Back();
	cout << "arr2��������" << arr2.get_Capacity() << endl
		<< "arr2�Ĵ�С��" << arr2.get_Size() << endl;
}


/////////////�Զ����������Ͳ���///////////////////////////////
class Person
{
public:
	//����û��ṩ�вι��죬�����������ṩĬ�Ϲ��죬���ṩ��������
	//�´��������ʱ��û�в�������ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����
	Person() {};
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
public:
	int m_age;
	string m_name;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.get_Size(); i++)
	{
		cout << arr[i].m_name << " " << arr[i].m_age << endl;
	}
	cout << endl;
}


void test02()
{
	MyArray<Person> arrp(10);
	Person p1("batman",30 );
	Person p2("superman",35 );
	Person p3("wonderwoman",28 );
	Person p4("aquaman", 40);
	Person p5("flash",20 );
	arrp.Push_Back(p1);
	arrp.Push_Back(p2);
	arrp.Push_Back(p3);
	arrp.Push_Back(p4);
	arrp.Push_Back(p5);

	cout << "arrp�Ĵ�ӡ���Ϊ��" << endl;
	printPersonArray(arrp);

	cout << "arrp������Ϊ��" << arrp.get_Capacity() << endl;
	cout << "arrp�Ĵ�СΪ��" << arrp.get_Size() << endl;

}

int main()
{
	test01();//������������
	test02();//�Զ����������� 
	system("pause");
	return 0;
}