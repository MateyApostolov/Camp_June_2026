#include "train.h"
#include "train.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

namespace{

int n;
std::vector<int> switches;

};

int experiment(std::string states){
	std::vector<int> lamps(n);
	for(int i = 0; i < n; i ++){
		if(states[i] == '0') continue;
		lamps[switches[i]] = 1;
	}

	int screams = 0;
	for(int i = 0; i + 1 < n; i ++){
		if(lamps[i] != lamps[i + 1]){
			screams += 1;
		}
	}

	return screams;
}

int main(){
	std::cin >> n;
	switches.resize(n);
	for(int i = 0; i < n; i ++){
		std::cin >> switches[i];
	}

	std::vector<int> c_answer = find_switches(n);

	for(auto x : c_answer){
		cout << x << " ";
	} cout << endl;
}

