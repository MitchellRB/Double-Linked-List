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

	void addToEnd();

	void addToBeginning();

	bool addIndex(uint index);

	bool remove(uint index);

private:

	uint listLength;
	ListNode* head;
	ListNode* tail;

	void createFirst();
};

