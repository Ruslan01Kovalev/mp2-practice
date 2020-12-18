
#include <iomanip>
#include "Stack.h"
#include "Queue.h"
#include <stack>

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int size;
	cin >> size;
	int* ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = i + rand() % 100
	}
	Stack<int>mystack1(size);
	stack<int>mystack2;

	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << " ";
		mystack2.push(ptr[i]);
		mystack1.push(ptr[i]);
	}
	
	cout << "\n";
	for (int i = mystack1.GetFirst(); i < mystack1.GetSize(); i++)
	{
		cout << mystack1.pop() << " ";
	}
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << mystack2.top()<<" ";
		mystack2.pop();
	}

	int a1[10];
	Queue<int>queue(10);
	for (int i = 0; i < 10; i++)
	{
		a1[i] = i;
		queue.push(a1[i]);
	}
	for (int i = 0; i < queue.GetSize(); i++)
	{
		cout << queue.pop() << "\n";
	
}


