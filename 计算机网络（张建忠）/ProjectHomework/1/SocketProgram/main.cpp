#include"client.h"
#include"server.h"
#include <iostream>

int main() {
	cout << "Please select which you want to be:\n0. Server\t1. Client\n";
	int identification;
	cin >> identification;
	cin.get();
	if (identification == 0)
		serverMain();
	else
		clientMain();

	return 0;
}

