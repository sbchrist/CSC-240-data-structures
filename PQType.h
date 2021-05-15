#ifndef PQTYPE_H
#define PQTYPE_H
class FullPQ{};
class EmptyPQ{};
#include <iostream>
#include "Heap.h"
using namespace std;
#define MAX_ITEMS 100

template<class ItemType>
class PQType
{
public:
  PQType();				//default constructor
  PQType(int);          // parameterized class constructor
  ~PQType();            // class destructor

  PQType operator=(const PQType& rhs);
  // Function: assignment overload for copies of PQType
  // Pre: PQType is initilized
  // Post: PQ items and data member values replaced with those from rhs
  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Pre: PQ is initialized
  // Post: Queue is empty.
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Pre: PQ is initialized
  // Post: Function value = (queue is empty)
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Pre: PQ is initialized
  // Post: Function value = (queue is full)
  void Enqueue(ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Pre: PQ is initialized
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.
  void Dequeue(ItemType& item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Pre: PQ is initialized
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
  void AgeItems();
  // Function: Increment age value for all items in the Heap
  // Pre: Heap is initialized with NodeType at least one
  // Post: All Nodes have age increased by one
  template <class ItemPQ>
  friend ostream& operator<<(ostream& out, const PQType<ItemPQ>& pq);
  // Function: Friend function overloading ostream operator to print PQ
  // Pre: PQ is initilized as an array
  // Post: all items in the Heap are printed to screen
private:
  int length;  // number of items in Heap
  HeapType<ItemType> items;  // Max Heap to hold queue items
  int maxItems;  // size of dynamically allocated array of items
};

template<class ItemType>
PQType<ItemType>::PQType(){
	maxItems = MAX_ITEMS;
	items.elements = new ItemType[maxItems];
	length = 0;
}

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
  maxItems = max;
  items.elements = new ItemType[maxItems];
  length = 0;
}

template<class ItemType>
PQType<ItemType> PQType<ItemType>::operator=(const PQType<ItemType>& rhs){
	if(this == &rhs){
		return *this;
	}
	else{
		delete [] items.elements;
		length = rhs.length;
		maxItems = rhs.maxItems;
		items.elements = new ItemType[rhs.maxItems];

		int count = 0;
		while(count < rhs.length){
			items.elements[count] = rhs.items.elements[count];
			count++;
		}
	}
	return *this;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
  delete [] items.elements;
}

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
{
  if (length == 0)
    throw EmptyPQ();
  else
  {
    item = items.elements[0];
    items.elements[0] = items.elements[length-1];
    length--;
    items.ReheapDown(0, length-1);
  }
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
{
  if (length == maxItems)
    throw FullPQ();
  else
  {
    length++;
    items.elements[length-1] = newItem;
    items.ReheapUp(0, length-1);
  }
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
{
  return length == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
{
  return length == 0;
}

template<class ItemType>
void PQType<ItemType>::AgeItems(){
  for (int i = 0; i < length; i++)
    items.elements[i].incrementAge();
}

template <class ItemPQ>
ostream& operator<<(ostream& out, const PQType<ItemPQ>& pq){
	for(int i = 0; i < pq.length; i++){
    out << pq.items.elements[i];
	}
	return out;
}


#endif
