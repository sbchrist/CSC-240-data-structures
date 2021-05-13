//============================================================================
// Description : Header for fault Poller sim (Inherit PQType)
// Author      : Alan Angell
// Version     : 05/13/2021
// License     : Only for CSC240 Oakton College
//============================================================================
#ifndef POLLERTYPE_H
#define POLLERTYPE_H
#include <string>
#include "PQType.h"
#include "NodeType.h"

class Poller: public PQType<Node>{
public: Poller(int);
  int getNumNodes() const;
  void getCurrentNode(Node&);
  void setCurrentNode(Node&);
  void addNode(Node&);
  void removeNode(Node& n);
  bool CheckNode();
  // Function: Check link status of highest priority (next) node
  // Pre: currentNode is initialized
  // Post: function value is bool getStatus();
  void SendAlert();
  // Function: Check node and print alert based on priority
  // Pre: Node is initialized
  // Post: Alert is printed to screen
  void PollNodes();
  void AgeNodes();
  // Function: To access the AgeItems function of the superclass PQType<Node>
  // Pre: PQType has function AgeItems defined for incresaing Node age value
  // Post: Every node in PQ has age increased by 1
private:
  int numNodes;
  Node currentNode;
};


Poller::Poller(int size) : PQType<Node>(size){
  numNodes = 0;
}

int Poller::getNumNodes() const{
  return numNodes;
}

void Poller::getCurrentNode(Node& n){
  n = currentNode;
}

void Poller::setCurrentNode(Node& n){
  currentNode = n;
}

void Poller::addNode(Node& n){
// enq Node into the PQ (heap)
  PQType<Node>::Enqueue(n);
// increment numNodes
  numNodes++;
}

void Poller::removeNode(Node& n){
// deq Node from the PQ (heap)
  PQType<Node>::Dequeue(n);
// add the Node to the schedule
  setCurrentNode(n);
// decrement numNodes
  numNodes--;
}

bool Poller::CheckNode(){
  return currentNode.getStatus();
}

void Poller::SendAlert(){
  if (CheckNode()){
    string sev[3] = {"Blue Alert!", "Yellow Alert!!", "Red Alert!!!"};
    int p = currentNode.getPriority();
    cout << sev[p] << endl;
    cout << currentNode << endl;
  }
}

void Poller::AgeNodes(){
  PQType<Node>::AgeItems();
}

void Poller::PollNodes(){

}

#endif
