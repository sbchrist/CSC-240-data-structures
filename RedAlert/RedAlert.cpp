//============================================================================
// Name        : RedAlert.cpp
// Author      : Alan Angell
// Version     : 05/07/2021
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "Poller.h"
// #include "PQType.h"
#include "NodeType.h"
using namespace std;

int main() {
	// Build golden config from file
  // Poll nodes for deltas
	// Alerts
	Node tmp;
	Poller<Node> servers(10);
	Node node("columbus01", true);
	servers.Enqueue(node);
	cout << "Servers: " << endl << endl << servers << endl;
	servers.removeNode(tmp);
  servers.SendAlert();

	return 0;
}
