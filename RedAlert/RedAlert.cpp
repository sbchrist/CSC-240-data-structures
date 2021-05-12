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

const int MAX_SERVERS = 1000;

int main() {
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
		Node tmp(nodeName, isDown, priorityNode);
		cluster.addNode(tmp);
	}

	cout << "RedAlert simulation." << endl;
	char answer = '\0';
  while (answer != '2'){
		if (!cluster.IsEmpty()){
			Node next;
		  cluster.removeNode(next);
			cluster.SendAlert();
			cout << "What to do with node in alert?" << endl;
			cout << "0: ignore" << endl;
			cout << "1: fix" << endl;
			cout << "2: STOP polling" << endl;
			cin >> answer;
			switch (answer){
				case '0':
				  cluster.addNode(next);
					cout << "ignored" << endl;
				  break;
				case '1':
				  next.setLink(1);
					cout << "fixed" << endl;
				  break;
				case '2':
				  answer = '2';
					cout << "STOP" << endl;
					break;
				default:
				  cout << "Invalid input. Try again!";
			}
		// ToDo: Noussair wants to add parallelsim where the poller continues
		//       working while waiting for user or new nodes
		}
	}
  inFile.close();
	return 0;
}
