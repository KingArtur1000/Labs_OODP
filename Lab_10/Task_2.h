#pragma once

#include <algorithm>
#include <iostream>
#include <thread>
#include <string>


using std::thread;
using std::string;
using std::cout;
using std::this_thread::get_id;


void threadFunction2(int i) {
	cout << "Я поток #" << i << "\n\n";
	
}


