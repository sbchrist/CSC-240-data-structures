//============================================================================
// Description : Test Driver for RedAlert program for auditing/alerting
// Author      : Alan Angell
// Version     : 05/12/2021
// License     : MIT License type free use
//============================================================================

#include <iostream>
#include <fstream>
#include "Poller.h"
#include "NodeType.h"
using namespace std;

const int MAX_SERVERS = 100;

int main() {
	// Build golden config from file
	// Build cluster BST with in data
  // Poll nodes for deltas
	// Alerts
	ifstream inFile;
	inFile.open("inData.txt");
	string nodeName;
	bool isDown;
	int priorityNode;
	Poller<Node> cluster(MAX_SERVERS);

  while (inFile){
		inFile >> nodeName >> isDown >> priorityNode;
	  	Node tmp = new Node(nodeName, isDown, priorityNode);
		cluster.addNode(tmp);
	}
	cluster.removeNode(tmp);

	cout << tmp << endl;

	// Prompt user to start Poller
  // Poller runs until user input to stop
	// Periodic alerts/prompts for user action
	//  choice: ACK, SNOOZE, CLEAR
	//          each choice has action in driver

	//Step 1:
	//Step 2: Get top node in priority and give option to kill
	//			If user chooses yes, remove node
	//			If not, queue it into
	//Step 3:
  inFile.close();
	return 0;
}
