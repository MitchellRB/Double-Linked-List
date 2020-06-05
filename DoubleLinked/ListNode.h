#pragma once

#include <random>
#include <time.h>

class ListNode
{
public:

	ListNode();
	~ListNode();

	int getData() { return data; };
	void setData(int _data) { data = _data; };

	ListNode* getPrevious() { return previous; };
	ListNode* getNext() { return next; };

	void setPrevious(ListNode* ptr) { previous = ptr; };
	void setNext(ListNode* ptr) { next = ptr; };

private:

	int data;
	ListNode* previous;
	ListNode* next;
};