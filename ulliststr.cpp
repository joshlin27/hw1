#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  if (head_ == nullptr) { //check for empty list
    //create the new item, set value and pointers, increment size, move on
    Item* newItem = new Item;
    newItem -> last = 1;
    (newItem -> val)[0] = val;
    newItem -> prev = nullptr;
    newItem -> next = nullptr;
    head_ = newItem;
    tail_ = newItem;
    size_++;
    return;
  }
  //if tail is full, we also need a new item
  if (tail_ -> last == ARRSIZE) {
    Item* newItem = new Item;
    newItem -> last = 1;
    (newItem -> val)[0] = val;
    newItem -> prev = tail_;
    tail_ -> next = newItem;
    newItem -> next = nullptr;
    tail_ = newItem;
  }
  //otherwise, just put val in the next slot
  else {
    (tail_ -> val)[(tail_ -> last)++] = val;
  }
  //make sure to increment size
  size_++;
}

void ULListStr::pop_back() {
  //first, decrement last
  (tail_ -> last)--;
  //only if the last item is now completely empty, do we need to do more stuff
  if (tail_ -> last - tail_ -> first == 0) {
    //check for 1 item list, delete, decrement size, return
    if (tail_ -> prev == nullptr) {
      Item* temp = tail_;
      head_ = nullptr;
      tail_ = nullptr;
      delete temp;
      size_--;
      return;
    }
    //otherwise, update pointers and delete
    Item* temp = tail_;
    tail_ = tail_ -> prev;
    tail_ -> next = nullptr;
    delete temp;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val) {
  //check for empty list
  if (head_ == nullptr) {
    Item* newItem = new Item;
    newItem -> last = 1;
    (newItem -> val)[0] = val;
    newItem -> prev = nullptr;
    newItem -> next = nullptr;
    head_ = newItem;
    tail_ = newItem;
    size_++;
    return;
  }
  //if the front of the first list is occupied, we need a new item
  if (head_ -> first == 0) {
    Item* newItem = new Item;
    head_ -> prev = newItem;
    newItem -> last = 1;
    (newItem -> val)[0] = val;
    newItem -> prev = nullptr;
    newItem -> next = head_;
    head_ = newItem;
  }
  //otherwise, just place val in the new first slot
  else {
    (head_ -> val)[--(head_ -> first)] = val;
  }
  size_++;
}

void ULListStr::pop_front() {
  //first, move the first index up
  (head_ -> first)++;
  if (head_ -> last - head_ -> first == 0) { //check for if first item is now empty
    if (head_ -> next == nullptr) { //check for 1 item list
      Item* temp = head_;
      head_ = nullptr;
      tail_ = nullptr;
      delete temp;
      size_--;
      return;
    }
    //otherwise just delete and update pointers
    Item* temp = head_;
    head_ = head_ -> next;
    delete temp;
    head_ -> prev = nullptr;
  }
  size_--;
}

std::string const & ULListStr::back() const {
  //simply return the tail's last item
  return tail_ -> val[tail_ -> last - 1];
}

std::string const & ULListStr::front() const {
  //simply return the head's first item
  return head_ -> val[head_ -> first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  Item* temp = head_;
  while (true) {
    if (temp == nullptr) { //if empty or invalid index
      return NULL;
    }
    if (loc <= temp -> last - temp -> first - 1) { //if loc is now a valid index, return its value
      return &((temp -> val[loc + temp -> first]));
    }
    else { //otherwise, keep going by subtracting the number of values
      loc -= (temp -> last - temp -> first);
    }
    //update temp
    temp = temp -> next;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
