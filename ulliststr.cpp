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
  if (tail_ -> last == ARRSIZE) {
    Item* newItem = new Item;
    newItem -> last = 1;
    (newItem -> val)[0] = val;
    newItem -> prev = tail_;
    tail_ -> next = newItem;
    newItem -> next = nullptr;
    tail_ = newItem;
  }
  else {
    (tail_ -> val)[(tail_ -> last)++] = val;
  }
  size_++;
}

void ULListStr::pop_back() {
  (tail_ -> last)--;
  if (tail_ -> last - tail_ -> first == 0) {
    if (tail_ -> prev == nullptr) {
      Item* temp = tail_;
      head_ = nullptr;
      tail_ = nullptr;
      delete temp;
      size_--;
      return;
    }
    Item* temp = tail_;
    tail_ = tail_ -> prev;
    tail_ -> next = nullptr;
    delete temp;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val) {
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
  if (head_ -> first == 0) {
    Item* newItem = new Item;
    head_ -> prev = newItem;
    newItem -> last = 1;
    (newItem -> val)[0] = val;
    newItem -> prev = nullptr;
    newItem -> next = head_;
    head_ = newItem;
  }
  else {
    (head_ -> val)[--(head_ -> first)] = val;
  }
  size_++;
}

void ULListStr::pop_front() {
  (head_ -> first)++;
  if (head_ -> last - head_ -> first == 0) {
    if (head_ -> next == nullptr) {
      Item* temp = head_;
      head_ = nullptr;
      tail_ = nullptr;
      delete temp;
      size_--;
      return;
    }
    Item* temp = head_;
    head_ = head_ -> next;
    delete temp;
    head_ -> prev = nullptr;
  }
  size_--;
}

std::string const & ULListStr::back() const {
  return tail_ -> val[tail_ -> last - 1];
}

std::string const & ULListStr::front() const {
  return head_ -> val[head_ -> first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  Item* temp = head_;
  while (true) {
    if (temp == nullptr) {
      //std::cout << "nullptr" << std::endl;
      return NULL;
    }
    //std::cout << temp -> last << " " << temp -> first << std::endl;
    if (loc <= temp -> last - temp -> first - 1) {
      //std::cout << "if" << std::endl;
      return &((temp -> val[loc + temp -> first]));
    }
    else {
      loc -= (temp -> last - temp -> first);
      //std::cout << "else" << loc << std::endl;
    }
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
