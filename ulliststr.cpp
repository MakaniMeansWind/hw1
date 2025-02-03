
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

void ULListStr::push_back(const std::string& val)
{

	if(size_ == 0)
	{

		Item* newItem = new Item();

		newItem->val[newItem->first] = val;

		head_ = newItem;

		tail_ = newItem;

		newItem->last = 1;

		size_++;

		return;

	}

	if(tail_->last < 10)
	{

		tail_->val[tail_->last] = val;

		tail_->last += 1;

		size_++;

		return;

	}

	else if(tail_->last == 10)
	{

		Item* newItem = new Item();

		newItem->val[newItem->first] = val;

		newItem->prev = tail_;

		tail_->next = newItem;

		tail_ = newItem;

		size_++;

		newItem->last = 1;

		return;

	}

}

void ULListStr::pop_back()
{

	if(size_ == 0)
	{

		return;

	}

	if(tail_->last <= 10 && tail_->last > 1)
	{

		tail_->last -= 1;

		tail_->val[tail_->last] = " ";

		size_--;

		return;

	}

	else if(tail_->last == 1 || tail_->last == 0)
	{

		// tail_->last -= 1;

		// tail_->val[tail_->last] = " ";

		if(tail_->next == NULL && tail_->prev == NULL)
		{

			ULListStr::clear();

			return;

		}

		size_--;

		Item* temporaryTailPointer = tail_;

		tail_ = tail_->prev;

		tail_->next = NULL;

		delete temporaryTailPointer;

	}

}

void ULListStr::push_front(const std::string& val)
{

	if(size_ == 0)
	{

		Item* newItem = new Item();

		newItem->first = 0;

		newItem->last = 1;

		newItem->val[newItem->first] = val;

		newItem->prev = NULL;

		newItem->next = NULL;

		head_ = newItem;

		tail_ = newItem;

		size_++;

		return;
	
	}

	else if(head_->first > 0)
	{
		
		head_->first -= 1;

		head_->val[head_->first] = val;

		size_++;

	}

	else if(head_->first == 0)
	{

		Item* newItem = new Item();

		newItem->first = 9;

		newItem->last = 10;

		newItem->val[newItem->first] = val;

		newItem->next = head_;

		newItem->prev = NULL;

		head_->prev = newItem;

		head_ = newItem;

		size_++;

		return;
		
	}

}

void ULListStr::pop_front()
{

	if(size_ == 0)
	{

		return;

	}

	if((int)size_ == 1)
	{

		head_->val[head_->first] = " ";

		if(head_->prev == NULL && head_->next == NULL && size_ == 1)
		{

			ULListStr::clear();

			return;

		}

		Item* temporaryHeadPointer = head_;

		head_ = head_->next;

		head_->prev = NULL;

		size_--;

		delete temporaryHeadPointer;

	}

  else if(head_->last == 10 && head_->first == 9)
  {

    Item* temporaryHeadPointer = head_;

		head_ = head_->next;

		head_->prev = NULL;

		size_--;

		delete temporaryHeadPointer;

  }
	
	else if(head_->first >= 0 && head_->first < 9)
	{

		head_->val[head_->first] = " ";

		head_->first++;

		size_--;

	}



}

std::string const & ULListStr::back() const
{

	return tail_->val[tail_->last - 1];

}

std::string const & ULListStr::front() const
{

	return head_->val[head_->first];

}

std::string* ULListStr::getValAtLoc(size_t loc) const
{

	Item* trackerNode = head_;

	int currentIndex = head_->first;

	int currentNodesPassed = 0;

	while(currentIndex < 10)
	{

		if(currentNodesPassed == int(loc))
		{

			return &trackerNode->val[currentIndex];

		}

		currentIndex++;

		currentNodesPassed++;

		if(currentIndex == 10 && trackerNode->next == NULL)
		{

			return NULL;

		}

		else if(currentIndex == 10 && trackerNode->next != NULL)
		{

			trackerNode = trackerNode->next;

			currentIndex = trackerNode->first;

		}

	}

	return NULL;

}

