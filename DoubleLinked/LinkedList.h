#pragma once
#include "ListNode.h"

#ifndef uint
	#define uint unsigned int
#endif // !uint

class LinkedList
{
public:

	LinkedList();
	~LinkedList();

	uint length() { return listLength; };

	ListNode* getHead() { return head; };
	ListNode* getTail() { return tail; };

	ListNode* getPtrFromIndex(uint index);

	bool isEmpty() { return (listLength == 0); };

	void pushBack();
	void pushBack(int _data);

	void pushFront();
	void pushFront(int _data);

	void insert(ListNode* _next);

	void popFront();

	void popBack();

	void erase(ListNode* _target);

private:

	uint listLength;
	ListNode* head;
	ListNode* tail;

	void createFirst();
	void createFirst(int _data);
};

