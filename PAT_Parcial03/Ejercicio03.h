#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <map>>

using std::string;
using namespace std;

class TimeMap
{
private:
	unordered_map<string, vector<pair<int, string>> > mp;

public:
	TimeMap();

	void set(string key, string value, int timestamp);

	string get(string key, int timestamp);
};

