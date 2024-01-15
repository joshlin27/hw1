/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Node* n1 = new Node(19, nullptr);
    Node* n2 = new Node(24, n1);
    Node* n3 = new Node(32, n2);
    Node* n4 = new Node(256, n3);
    Node* n5 = new Node(1, n4);
    
    Node* temp = n5;
    while (temp != nullptr) {
        std::cout << temp -> value << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;

    Node* odds = nullptr;
    Node* evens = nullptr;
    split(n5, odds, evens);
    if (n5 == nullptr) {
        std::cout << "null" << std::endl;
    }
    while (odds != nullptr) {
        std::cout << odds -> value << " ";
        odds = odds -> next;
    }
    std::cout << std::endl;
    while (evens != nullptr) {
        std::cout << evens -> value << " ";
        evens = evens -> next;
    }
    std::cout << std::endl;
}
