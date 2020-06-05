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

private:
	uint listLength;
	ListNode* head;
	ListNode* tail;
};

