#include "Ejercicio03.h"

TimeMap::TimeMap()
{
}

void TimeMap::set(string key, string value, int timestamp)
{
    if (data.find(key) == data.end()) {
        std::map<int, std::string> timestampMap;
        timestampMap[timestamp] = value;
        data[key] = timestampMap;
    }
    else {
        data[key][timestamp] = value;
    }
}

string TimeMap::get(string key, int timestamp)
{
    if (data.find(key) != data.end()) {
        auto& timestampMap = data[key];
        auto it = timestampMap.upper_bound(timestamp);
        if (it != timestampMap.begin()) {
            --it;
            return it->second;
        }
    }
    return "";
}
