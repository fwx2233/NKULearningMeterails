#include"server.h"
#include<iostream>

using namespace std;

int main() {
	cout << "/***************************/\n";
	cout << "/******\t������ 3.2\t************/\n";
	cout << "/***************************/\n";

	// ����������
	if (serverMain() == 0) {
		cout << "������������\n";
	}
	else {
		cout << "��������쳣\n";
	}
	//cout << "serverMain����\n";

	return 0;
}