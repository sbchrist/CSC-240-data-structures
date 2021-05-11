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
#include "TreeType.h"
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
	TreeType<Node> cluster;
	Node tmp;
	Poller<Node> PollQ(MAX_SERVERS);

	PollQ.Enqueue(Node("columbus01", true));
	cout << "Servers: " << endl << PollQ << endl;
	PollQ.removeNode(tmp);
  PollQ.SendAlert();

  while (inFile){
		inFile >> nodeName >> isDown >> priorityNode;
		cluster.PutItem(Node(nodeName, isDown, priorityNode));
	}
	cluster.Print(cout);

	// Prompt user to start Poller
  // Poller runs until user input to stop
	// Periodic alerts/prompts for user action
	//  choice: ACK, SNOOZE, CLEAR
	//          each choice has action in driver

  inFile.close();
	return 0;
}
