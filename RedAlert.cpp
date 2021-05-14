//============================================================================
// Description : Test Driver for RedAlert program for auditing/alerting
// Author      : Alan Angell
// Version     : 05/13/2021
// License     : Only for CSC240 Oakton College
//============================================================================
#include <iostream>
#include <fstream>
#include "Poller.h"
using namespace std;

const int MAX_SERVERS = 1000;

int main() {
	ifstream inFile;
	inFile.open("inData.txt");
	string nodeName;
	bool isDown;
	int priorityNode;
	Poller cluster(MAX_SERVERS);

  inFile >> nodeName >> isDown >> priorityNode;
  while (inFile){
		Node tmp(nodeName, isDown, priorityNode);
		cluster.addNode(tmp);
		inFile >> nodeName >> isDown >> priorityNode;
	}

	cout << "RedAlert simulation." << endl << endl;
	char answer = '\0';
  while (answer != '2'){
		if (!cluster.IsEmpty()){
			cout << endl << "There are " << cluster.getNumNodes() << " unhealthy nodes." << endl;
			Node next;
		  cluster.removeNode(next);
			cluster.SendAlert();
			cout << "What to do with node in alert?" << endl;
			cout << "0: ignore" << endl;
			cout << "1: fix" << endl;
			cout << "2: stop polling" << endl;
			cin >> answer;
			switch (answer){
				case '0':
				  next.incrementAge();
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
			// How to make AgeNodes act more directly on Heap elements?
      cluster.AgeNodes();
		}
	  else{
	    cout << endl << "All alerts clear!" << endl;
			cout << "1: resume polling" << endl;
			cout << "2: quit" << endl;
			cin >> answer;
	  }
		// ToDo: Noussair wants to add parallelsim where the poller continues
		//       working while waiting for user or new nodes
	}
  inFile.close();
	return 0;
}
