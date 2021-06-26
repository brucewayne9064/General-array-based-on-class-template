#include<iostream>
#include<string>
using namespace std;
#include"MyArray.hpp"
/////////////内置数据类型测试///////////////////////////////
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
	cout << "arr1的打印输出为：" << endl;
	//MyArray<int> arr2(arr1);//拷贝构造
	//MyArray<int> arr3(100);
	//arr3 = arr1;
	printArray(arr1);

	cout << "arr1的容量：" << arr1.get_Capacity() << endl
		<< "arr1的大小：" << arr1.get_Size() << endl;

	MyArray<int> arr2(arr1);
	cout << "arr2的打印输出为：" << endl;
	printArray(arr2);
	arr2.Pop_Back();
	cout << "arr2的容量：" << arr2.get_Capacity() << endl
		<< "arr2的大小：" << arr2.get_Size() << endl;
}


/////////////自定义数据类型测试///////////////////////////////
class Person
{
public:
	//如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
	//新创建数组的时候没有参数，此时如果用户自己没有提供默认构造，会出错
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

	cout << "arrp的打印输出为：" << endl;
	printPersonArray(arrp);

	cout << "arrp的容量为：" << arrp.get_Capacity() << endl;
	cout << "arrp的大小为：" << arrp.get_Size() << endl;

}

int main()
{
	test01();//内置数据类型
	test02();//自定义数据类型 
	system("pause");
	return 0;
}