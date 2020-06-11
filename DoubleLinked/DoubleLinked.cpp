// DoubleLinked.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList list;

    list.pushBack();

    list.insert(list.getHead());

    list.erase(list.getHead());

    return 0;
}