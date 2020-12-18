#include "Queue.h"

#include <gtest.h>

TEST(Queue, can_create_Queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> v(3));
}

TEST(Queue, can_create_Queue_with_zero_size)
{
	ASSERT_NO_THROW(Queue<int> v(0));
}

TEST(Queue, throws_when_create_Queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> v(3));
}

TEST(Queue, IsFull)
{
	Queue<int>q(1);
	int m = 2;
	q.push(m);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Queue, IsFull_second)
{
	Queue<int> q(2);
	for (int i = 0; i < 2; i++)
		q.push(i);
	EXPECT_EQ(q.IsFull(),1);
}

TEST(Queue, IsEmpty)
{
	Queue<int>q(1);
	int m = 2;
	q.push(m);
	q.pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Queue, IsEmpty_second)
{
	Queue<double> q(2);
	for (int i = 0; i < 2; i++)
		q.push(i);

	for (int i = 0; i < n; i++)
		q.pop();

	EXPECT(q.IsEmpty(), 1);
}

TEST(Queue, can_create_copied_Queue)
{
	Queue<int> v(13);

	ASSERT_NO_THROW(Queue<int> v1(v));
}

TEST(Queue, copied_Queue_has_its_own_memory)
{
	Queue<int>A(8);
	Queue<int>B(A);
	EXPECT_NE(A.GetMemory(), B.GetMemory());
}

TEST(Queue, can_get_size)
{
	Queue<int> v(5);

	EXPECT_EQ(5, v.GetSize());
}
TEST(Queue, can_get_size_second)
{
	Queue<int> q(12);

	EXPECT_EQ(5, q.GetSize());
}


TEST(Queue, findInNULLQueue)
{
	Stack<int>a;
	ASSERT_ANY_THROW(a.find(1));
}

TEST(Queue, findInEmptyQueue)
{
	Queue<int>a(1);
	int b = 2;
	a.push(b);
	a.pop();
	ASSERT_ANY_THROW(a.find(2));
}
TEST(Queue, findInQueue)
{
	Queue<int>a(2);
	int b = 25;
	int c = 321;
	a.push(b);
	a.push(c);
	EXPECT_EQ(a.find(1), 0);
}
TEST(Queue, findInQueue2)
{
	Queue<int>a(2);
	int b = 99;
	int c = 3;
	a.push(b);
	a.push(c);
	EXPECT_EQ(a.find(99), 1);
}




