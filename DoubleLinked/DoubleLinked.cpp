// DoubleLinked.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList list;

    list.pushBack(50);

    list.search(50)->print();

    return 0;
}
