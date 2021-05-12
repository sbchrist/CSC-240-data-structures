//============================================================================
// Description : Header for Node <ItemType> for Poller Type
// Author      : Alan Angell
// Version     : 05/07/2021
//============================================================================
#ifndef NODETYPE_H
#define NODETYPE_H

class Node
{
public:
  Node();
  Node(string, bool, int, int);
  int getAge() const;
  void decrementAge();
  void incrementAge();
  int getPriority() const;
  bool getStatus();
  void setStatus(bool status);
  friend ostream& operator<<(ostream& out, const Node& j);
  bool operator<(Node otherNode);
  bool operator>(Node otherNode);
  bool operator==(Node otherNode);
  bool operator<=(Node otherNode);
  Node* operator=(Node otherNode);
private:
  string name;
  int age;
  int priority;
  bool down;
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
  if(p > 2 || p < 0){
	  priority = 0;
  }else
	  priority=p;
}

int Node::getAge() const {
  return age;
}

void Node::decrementAge() {
	//nxe Check to not reduce age below 0
	if(age > 0)
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

void Node::setStatus(bool status){
  down = status;
}

ostream& operator<<(ostream& out, const Node& n) {
  out << "Name: " << n.name << endl;
  out << "Age: " << n.age << endl;
  out << "Priority: " << n.priority << endl;
  return out;
}

bool Node::operator<(Node otherNode) {
  if (this->priority < otherNode.priority)
    return true;
  else
    return false;
}

bool Node::operator>(Node otherNode) {
  if (this->priority > otherNode.priority)
    return true;
  else
    return false;
}

bool Node::operator==(Node otherNode) {
  if (this->priority == otherNode.priority)
    return true;
  else
    return false;
}

bool Node::operator<=(Node otherNode) {
  if (this->priority <= otherNode.priority)
    return true;
  else
    return false;
}


Node* Node::operator=(Node otherNode) {
  this->priority=otherNode.priority;
  this->age=otherNode.age;
  this->name=otherNode.name;
  this->down=otherNode.down;
}

#endif
