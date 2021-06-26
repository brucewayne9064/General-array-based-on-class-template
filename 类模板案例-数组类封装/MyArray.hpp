#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	//�вι��죬��ʼ������ ����
	MyArray(int capacity)
	{
		//cout << "MyArray���вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//�������캯��
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray�Ŀ����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];//���
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=��ֹǳ����
	MyArray& operator=(const MyArray& myarray)
	{
		//cout << "MyArray��operator=����" << endl;
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

	//β�巨��������
	void Push_Back(const T &value)
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = value;//������ĩβ��������
		this->m_Size++;//���������С
	}

	//βɾ��ɾ������
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;//���������һ��Ԫ��
	}

	//ͨ���±��������Ԫ��
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int get_Capacity()
	{
		return this->m_Capacity;
	}

	//���������С
	int get_Size()
	{
		return this->m_Size;
	}

	//��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "MyArray��������������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}


private:
	T* pAddress;//ָ��һ���ѿռ䣬����ռ�洢����������
	int m_Capacity;//�����������
	int m_Size;//����ʵ�ʴ�С
};