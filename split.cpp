/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

//helper function
void helper(Node*&, Node*&, Node*&, int);



void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == nullptr) { //if in is null at first, we do nothing
    return;
  }
  //else, run the helper function with count = 0
  helper(in, odds, evens, 0);
}

void helper(Node*& in, Node*& odds, Node*& evens, int count) {
  //check for if we are at the end of the list
  if (in -> next == nullptr) {
    //if we are, put the last item in the correct list, and return
    if (in -> value % 2 == 0) {
      evens = in;
      evens -> next = nullptr;
    }
    else {
      odds = in;
      odds -> next = nullptr;
    }
    if (count == 0) {
      in = nullptr;
    }
    return;
  }
  count++; //count how many nodes in "in" BEFORE the recursive call for full sum
  helper(in -> next, odds, evens, count);
  count--; //now decrement to get down to zero AFTER the recursive calls
  //place the item in the correct list
  if (in -> value % 2 == 0) {
    if (evens == nullptr) {
      evens = in;
      evens -> next = nullptr;
    }
    else {
      in -> next = evens;
      evens = in;
    }
  }
  else {
    if (odds == nullptr) {
      odds = in;
      odds -> next = nullptr;
    }
    else {
      in -> next = odds;
      odds = in;
    }
  }
  //once we've gone through everything, set 'in' to null
  if (count == 0) {
    in = nullptr;
  }
}