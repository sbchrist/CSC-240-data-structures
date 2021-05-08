//============================================================================
// Description : Header for fault Poller sim (Inherit PQType)
// Author      : Alan Angell
// Version     : 05/07/2021
//============================================================================
#ifndef POLLERTYPE_H
#define POLLERTYPE_H
#include "PQType.h"
#include <string>
template <class ItemType>
class Poller: public PQType<ItemType>{
public: Poller(int);
  int getNumNodes() const;
  void getCurrentNode(ItemType&);
  void setCurrentNode(ItemType&);
  void addNode(ItemType&);
  void removeNode(ItemType& n);

  void BuildGolden();
  bool CheckNode();
  // Function: Check link status of highest priority (next) node
  // Pre: currentNode is initialized
  // Post: function value is bool LinkStatus();
  void SendAlert();
  void PollNodes();
private:
  int numNodes;
  ItemType currentNode;
  HeapType<ItemType> golden;
};


template <class ItemType>
Poller<ItemType>::Poller(int size) : PQType<ItemType>(size){
  numNodes = 0;
}

template <class ItemType>
int Poller<ItemType>::getNumNodes() const{
  return numNodes;
}

template <class ItemType>
void Poller<ItemType>::getCurrentNode(ItemType& n){
  n = currentNode;
}

template <class ItemType>
void Poller<ItemType>::setCurrentNode(ItemType& n){
// copy Node (member-wise?) into currentNode;
  currentNode = n;
}

template <class ItemType>
void Poller<ItemType>::addNode(ItemType& n){
// enq ItemType into the PQ (heap)
  PQType<ItemType>::Enqueue(n);
// increment numNodes
  numNodes++;
}

template <class ItemType>
void Poller<ItemType>::removeNode(ItemType& n){
// deq ItemType from the PQ (heap)
  PQType<ItemType>::Dequeue(n);
// add the Node to the schedule
  setCurrentNode(n);
// decrement numNodes
  numNodes--;
}

template <class ItemType>
void Poller<ItemType>::BuildGolden(){

}

template <class ItemType>
bool Poller<ItemType>::CheckNode(){
  return currentNode.getLink();
}

template <class ItemType>
void Poller<ItemType>::SendAlert(){
  if (CheckNode()){
    string sev[3] = {"Blue Alert!", "Yellow Alert!!", "Red Alert!!!"};
    int p = currentNode.getPriority();
    cout << sev[p] << endl;
  }
}

template <class ItemType>
void Poller<ItemType>::PollNodes(){

}

#endif
