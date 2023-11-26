#include "Ejercicio03.h"

TimeMap::TimeMap()
{
}

void TimeMap::set(string key, string value, int timestamp)
{
	mp[key].push_back({ timestamp, value });
}

string TimeMap::get(string key, int timestamp)
{
    if (mp.find(key) == mp.end())    return "";
    else if (mp[key][0].first > timestamp)   return "";
    else {
        int n = mp[key].size();
        int low = 0, high = n - 1;
        int resPos = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ts = mp[key][mid].first;

            if (ts > timestamp) high = mid - 1;
            else resPos = mid, low = mid + 1;
        }

        return resPos == -1 ? "" : mp[key][resPos].second;
    }
}
