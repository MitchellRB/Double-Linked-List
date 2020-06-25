// DoubleLinked.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "LinkedList.h"

#include <time.h>
#include <random>

#include <string>

int main()
{
    LinkedList list;

    std::string input;

    srand(time(nullptr));

    for (size_t i = 0; i < 10; i++)
    {
        list.pushFront(rand() % 100 + 1);
    }

    //Main loop
    while (input != "exit")
    {

        using std::cout;
        using std::cin;
        using std::endl;

        cout << "> ";
        cin >> input;

        if (input == "print")
        {
            list.printAll();
            cout << endl;
        }
        else if (input == "clear")
        {
            system("cls");
        }
        else if (input == "sort")
        {
            list.bubbleSort();
            list.printAll();
            cout << endl;
        }
        else if (input == "push_back")
        {
            cout << "Enter value: ";
            int value;
            cin >> value;
            list.pushBack(value);
        }
        else if (input == "push_front")
        {
            cout << "Enter value: ";
            int value;
            cin >> value;
            list.pushFront(value);
        }
        else if (input == "insert")
        {
            cout << "Enter value: ";
            int value;
            cin >> value;
            cout << "Enter location: ";
            int index;
            cin >> index;
            if (index < list.length())
            {
                list.insert(list.getPtrFromIndex(index), value);
            }
        }
        else if (input == "pop_back")
        {
            list.popBack();
        }
        else if (input == "pop_front")
        {
            list.popFront();
        }
        else if (input == "remove")
        {
            cout << "Enter value: ";
            int value;
            cin >> value;
            list.remove(value);
        }
        else if (input == "help")
        {
            cout << "print - show all values\n";
            cout << "clear - clear screen\n";
            cout << "sort - sort and print list\n";
            cout << "push_back - add value to end of list\n";
            cout << "push_front - add value to start of list\n";
            cout << "insert - add value after an index\n";
            cout << "pop_back - remove last value\n";
            cout << "pop_front - remove first value\n";
            cout << "remove - remove all instances of a value from the list\n";
            cout << "help - show this list\n";
            cout << "exit - close program\n";
        }
        else if (input != "exit")
        {
            cout << "Unkown command. Enter \"help\" for help\n";
        }
    }

    return 0;
}
