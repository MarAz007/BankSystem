#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<sstream>   
using namespace std;
//قسمنا السطر وحولناه vector["1000","mariam","12345","$","0"]
inline vector<string>split(const string& s, char delimiter) {
	vector<string>result;
	string part;
	stringstream ss(s);
	while (getline(ss, part, delimiter)) {
		result.push_back(part);
	}
	return result;
}