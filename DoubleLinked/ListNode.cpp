#include "ListNode.h"

ListNode::ListNode()
{
	data = 0;
	next = nullptr;
	previous = nullptr;
}

ListNode::ListNode(ListNode* _previous, ListNode* _next)
{
	data = 0;
	next = _next;
	previous = _previous;
}

ListNode::ListNode(int _data, ListNode* _previous, ListNode* _next)
{
	data = _data;
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

void ListNode::print()
{
	std::cout << data;
}
