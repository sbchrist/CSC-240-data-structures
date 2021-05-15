//============================================================================
// Description : Header for Node <ItemType> for Poller Type
// Author      : Alan Angell
// Version     : 05/13/2021
// License     : Only for CSC240 Oakton College
//============================================================================
#ifndef NODETYPE_H
#define NODETYPE_H


#include <string>
#include <iostream>
using namespace std;
class Node
{
public:
  Node(); // class default constructor
  Node(string, bool, int, int); // class cosntructor
  int getAge() const;
  // Function:  determines age of Node
  // Pre: Node has been initialized
  // Post: Function value = age
  void decrementAge();
  // Function:  decrements age data member of Node
  // Pre : Node has been initialized
  // Post: Node age--
  void incrementAge();
  // Function: increments age data member of Node
  // Pre: Node has been initialized
  // Post: Node age++
  int getPriority() const;
  // Function: returns priority data member of Node
  // Pre : priority has been initialized
  // Post: function value = priority
  bool getStatus();
  // Function: returns the down data member of Node
  // Pre: down data member has bee initialized
  // Post: function value = priority
  void setLink(bool status);
  // Function: sets the priority data member to status
  // Pre: down data member initialized
  // Post: member variable down is set to value of status
  friend ostream& operator<<(ostream& out, const Node& j);
  // Function:  streaming friends function which accepos a stream vriable and node objects as parameters
  // Pre: Node and data members name, age, and priority are initialized
  // Post: Node attributes name, age, and priority printed to screen
  bool operator<(Node otherNode);
  // Function: compares priority and age value to otherNode parameter
  // Pre: Both nodes are initialized
  // Post: function value = bool based on age and priority
  bool operator>(Node otherNode);
  // Function: compares priority and age value to otherNode parameter
  // Pre: Both nodes are initialized
  // Post: function value = bool based on age and priority
  bool operator==(Node otherNode);
  // Function: compares priority and age value to otherNode parameter
  // Pre: Both nodes are initialized
  // Post: function value = bool (this->priority == otherNode.priority && this->age == otherNode.age)
  bool operator<=(Node otherNode);
  // Function: compares priority and age value to otherNode parameter, taking into account nodes with equal priorities
  // Pre: Both nodes are initialized
  // Post: function value = bool based on age and priority,
private:
  string name;  // node name
  int age;  // how long node has been in queue
  int priority;  // severity of alert
  bool down;  // if node has problem
};


Node::Node() {
  name = "default";
  down = false;
  age = 0;
  priority = 0;
}

Node::Node(string n, bool d = false, int p = 0, int a = 0) {
  name = n;
  down = d;
  age = a;
  priority = p;
}

int Node::getAge() const {
  return age;
}

void Node::decrementAge() {
  age--;
}

void Node::incrementAge() {
  age++;
}

int Node::getPriority() const {
  return priority;
}

bool Node::getStatus(){
  return down;
}

void Node::setLink(bool status){
  down = status;
}

ostream& operator<<(ostream& out, const Node& n) {
  out << "Name: " << n.name << endl;
  out << "Priority: " << n.priority << endl;
  out << "Age: " << n.age << endl;
  return out;
}

bool Node::operator<(Node otherNode) {
  if (this->priority < otherNode.priority){
    if (this->age > otherNode.age)
      return false;
    else
      return true;
  }
  else
    return false;
}

bool Node::operator>(Node otherNode) {
  if (this->priority > otherNode.priority){
    if (this->age < otherNode.age)
      return false;
    else
      return true;
  }
  else
    return false;
}

bool Node::operator==(Node otherNode) {
  if (this->priority == otherNode.priority &&
      this->age == otherNode.age)
    return true;
  else
    return false;
}

bool Node::operator<=(Node otherNode) {
  if (this->priority <= otherNode.priority){
    if (this->age > otherNode.age)
      return false;
    else
      return true;
  }
  else
    return false;
}

#endif
