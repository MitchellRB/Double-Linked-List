// DoubleLinked.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "LinkedList.h"

#include <time.h>
#include <random>

int main()
{
    LinkedList list;

    srand(time(nullptr));

    for (size_t i = 0; i < 10; i++)
    {
        list.pushBack(rand() % 100);
    }

    for (size_t i = 0; i < 5; i++)
    {
        list.pushBack(40);
    }

    list.printAll();

    std::cout << std::endl;

    list.bubbleSort();

    list.printAll();

    std::cout << std::endl;

    list.remove(40);

    list.printAll();

    std::cout << std::endl;

    std::cin.get();

    return 0;
}
