#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造，初始化参数 容量
	MyArray(int capacity)
	{
		//cout << "MyArray的有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造函数
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray的拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];//深拷贝
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=防止浅拷贝
	MyArray& operator=(const MyArray& myarray)
	{
		//cout << "MyArray的operator=调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size;
		this->pAddress = new T[myarray.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = myarray.pAddress[i];
		}
		return *this;
	}

	//尾插法插入数据
	void Push_Back(const T &value)
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = value;//在数组末尾插入数据
		this->m_Size++;//更新数组大小
	}

	//尾删法删除数据
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;//不访问最后一个元素
	}

	//通过下标访问数组元素
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int get_Capacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int get_Size()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "MyArray的析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}


private:
	T* pAddress;//指向一个堆空间，这个空间存储真正的数据
	int m_Capacity;//数组最大容量
	int m_Size;//数组实际大小
};