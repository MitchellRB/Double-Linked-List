#include "ListNode.h"

ListNode::ListNode()
{
	//Generate some data to store in this node.
	srand(time(nullptr));
	data = (rand() % 100) + 1;
}

ListNode::~ListNode()
{
	next->previous = previous;
	previous->next = next;
}