#pragma once
#include <iostream>

using namespace std;
template<class T>
class Stack
{
private:

	const T** Array;
	int size;
	int first;
	int last;
	int DataCount;

public:

	Stack()
	{
		Array = 0;
		size = 0;
		first =0;
		last = -1;
		DataCount = 0;
		
	}
	Stack(int _size)
	{
		if (_size < 0)throw logic_error("negative size");
		Array = new const T*[_size];
		size = _size;
		first = 0;
		last = -1;
		DataCount = 0;
		
	}
	Stack(const Stack& ob)
	{
		Array = new const T*[ob.size];
		size = ob.size;
		first = ob.first;
		last = ob.last;
		DataCount = ob.DataCount;
		
	}

	virtual ~Stack()
	{
		delete[] Array;
	}
	
	 void push (const T& el)
	{
		if (DataCount==0) throw logic_error("Container is overflow");
		if (Array == 0) throw logic_error("memory error");
		last++;
		Array[last] = &el;
		DataCount++;
	}

	 bool find(const T& el)
	 {
		 if (DataCount==0) throw logic_error("Container is empty");
		 if (Array == 0) throw logic_error("memory error");
		 for (int i = first; i < DataCount; i++)
		 {
			 if (el == (*Array[i]))return 1;
		 }
		 return 0;
	 }
	
	const T& pop()
	{
		if (DataCount==0) throw logic_error("Stack is empty");
		if (Array == 0) throw logic_error("memory error");
		const T* tmp = Array[last];
		Array[last] = 0;
		last--;
		DataCount--;
		return (*tmp);
	}
	int GetSize(){return size;}
	bool IsEmpty() { return(DataCount == 0); }
	bool IsFull() { return(DataCount == size); }
	const T** GetMemory() { return Array; }
	
};