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

	void addToEnd();

private:

	uint listLength;
	ListNode* head;
	ListNode* tail;

	void createFirst();
};

