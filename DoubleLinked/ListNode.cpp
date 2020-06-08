#include "ListNode.h"

ListNode::ListNode()
{
	//Generate some data to store in this node.
	srand(time(nullptr));
	data = (rand() % 100) + 1;
	next = nullptr;
	previous = nullptr;
}

ListNode::ListNode(ListNode* _previous, ListNode* _next)
{
	//Generate some data to store in this node.
	srand(time(nullptr));
	data = (rand() % 100) + 1;
	next = _next;
	previous = _previous;
}

ListNode::~ListNode()
{
	if (next != nullptr)
		next->previous = previous;
	if (previous != nullptr)
		previous->next = next;
}