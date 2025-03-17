#pragma once

#include <algorithm>
#include <iostream>
#include <thread>
#include <string>


using std::thread;
using std::string;
using std::cout;


void threadFunction(string str) {
	cout << "Исходный текст: " << str << "\n\n";
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	cout << "Результат: " << str << "\n\n";
}


