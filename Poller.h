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
  // Function: return number of nodes within the data structure
  void getCurrentNode(Node&);
  // Function: sets reference parameter to data member currentNode
  // Pre: currentNode is initialized
  void setCurrentNode(Node&);
  // Function: sets data member currentNode to Node reference parameter
  // Pre: currentNode is initialized
  // Post: data member currentNode seet to reference parameter
  void addNode(Node&);
  // Function: calls PQType member function enqueue and adds a Node data type to the data structure.
  //           increments numNodes data member by one
  // Pre: Node is initialized. PriorityQueue list is initialized and not full
  // Post: Data structure has an additional node and is sorted.
  void removeNode(Node& n);
  //Function: call PQType member function dequeu and removes the topmost node in the data structure and assigns it 
  //          to the Node reference parameter. 
  //          decrements numNodes by one. 
  //          Sets current node to node that is to be removed
  // Pre: Node is initialized. PriorityQueue list is initialized and not empty.
  // Post: Data structure has top node removed and is re-sorted.  currentNode set to dequed node.
  bool CheckNode();
  // Function: Check link status of highest priority (next) node
  // Pre: currentNode is initialized
  // Post: function value is value of currentNode's data member, down;
  void SendAlert();
  // Function: Check node and print alert based on priority. Calls CheckNode functions
  // Pre: Node is initialized
  // Post: Alert and Node data printed to screen
  void AgeNodes();
  // Function: To access the AgeItems function of the superclass PQType<Node>
  // Pre: PQType has function AgeItems defined for incresaing Node age value
  // Post: Every node in PQ has age increased by 1
private:
  int numNodes;  //number of nodes within data structure
  Node currentNode;  //node be manipulated currently by the program
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
  // Post: Data structure has an additional node and is sorted.

  PQType<Node>::Enqueue(n);
  numNodes++;
}

void Poller::removeNode(Node& n){
  // Post: Data structure has top node removed and is re-sorted.  currentNode set to dequed node.

  PQType<Node>::Dequeue(n);
  setCurrentNode(n);
  numNodes--;
}

bool Poller::CheckNode(){
  // Post: function value is value of currentNode's data member, down;

  return currentNode.getStatus();
}

void Poller::SendAlert(){
  // Post: Alert and Node data printed to screen

  if (CheckNode()){
    string sev[3] = {"Blue Alert!", "Yellow Alert!!", "Red Alert!!!"};
    int p = currentNode.getPriority();
    cout << sev[p] << endl;
    cout << currentNode << endl;
  }
}

void Poller::AgeNodes(){
  // Post: Every node in PQ has age increased by 1

  PQType<Node>::AgeItems();
}


#endif
