#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
//二叉树公共z
using namespace std;
#include<iostream>

bool queue_is_full(queue * q)
{
	if (q == NULL)
	{
		return false;

	}
	return q->cout >= MAX_LEN;
}


bool queue_is_empty(queue * q)
{
	if (q == NULL)
	{
		return true;

	}
	return q->cout == 0;
}

int init_queue(queue * q)
{
	if (q == NULL)
	{
		q = new queue;

	}
	q->begin = q->end = q->cout = 0;
	memset(q->value, 0, MAX_LEN);
	return 0;
}


int push_queue(queue * q, int val)
{
	if (q == NULL)
	{
		cout << "queue is null,new alloc" << endl;
		init_queue(q);

	}
	if (queue_is_full(q))
	{
		cout << "queue is full" << endl;
		return -1;
	}
	//q->end = (q->end + 1) % MAX_LEN;
	q->value[q->end] = val;
	q->end = (q->end + 1) % MAX_LEN;
	q->cout++;
	return q->end;
}


int pop_queue(queue * q)
{
	if (q == NULL)
	{
		cout << "queue is null" << endl;
		return -1;

	}
	if (queue_is_empty(q))
	{
		cout << "queue is empty" << endl;
		return -1;
	}

	int val = q->value[q->begin];
	q->begin = (q->begin + 1) % MAX_LEN;
	q->cout--;
	return val;
}

void detroy_queue(queue *q)
{
	if (q)
		delete q;
}
