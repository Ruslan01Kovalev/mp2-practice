#pragma once
#include "Stack.h"
#include <iostream>

using namespace std;
template<class T>
class Queue
{
private:

	const T** Array;
	int size;
	int first;
	int last;
	int DataCount;

public:
	template<class T>
	inline Queue<T>::Queue()
	{
		Array = 0;
		size = 0;
		first = 0; 
		last = 0; 
		DataCount = 0;
	}

	
	Queue(int _size)
	{
		if (_size < 0) throw logic_error("negative size");
		Array = new const T * [_size];
		size = _size;
		first = 0;
		last = 0;
		DataCount = 0;
	}

	Queue(Queue& ob) 
	{
		if (ob.size < 0) throw logic_error("negative size");
		Array = new const T * [ob.size];
		for (int i = first; i < last; i++)
			Array[i] = ob.Array[i];
		size = ob.size;
		first = ob.first;
		last = ob.last;
		DataCount = ob.DataCount;
	}

	 ~Queue()
	{
		delete[] Array;
		size = 0;
		first = 0;
		last = 0;

	}

	void push(T& el) 
	{
		if (DataCount==0) throw logic_error("Container is full");
		if (Array == 0) throw logic_error("memory error");
		Array[last] = &el;
		last = (last + 1) % size;
		DataCount++;
	}

	const T& pop() 
	{
		if (DataCount==0) throw logic_error("Queue is empty");
		if (Array == 0) throw logic_error("memory error");
		const T* tmp = Array[first];
		first = (first + 1) % size;
		DataCount--;
		return (*tmp);
	}
	int GetSize(){return size;}
	bool IsEmpty() { return(DataCount == 0); }
	bool IsFull() { return(DataCount == size); }
};

