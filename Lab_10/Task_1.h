#pragma once

#include <algorithm>
#include <iostream>
#include <thread>
#include <string>


using std::thread;
using std::string;
using std::cout;


void threadFunction(string str) {
	cout << "�������� �����: " << str << "\n\n";
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	cout << "���������: " << str << "\n\n";
}


