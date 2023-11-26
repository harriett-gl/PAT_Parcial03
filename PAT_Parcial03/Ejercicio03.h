#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class TimeMap
{
private:
	struct Mapa {
		int tiempo;
		string valor;
	};

	unordered_map<string, vector<Mapa*>>* mapita;

public:
	TimeMap();

	void set(string key, string value, int timestamp);

	string get(string key, int timestamp);

	~TimeMap();
};