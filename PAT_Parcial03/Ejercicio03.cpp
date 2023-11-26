#include "Ejercicio03.h"
#include <map>
#include <iterator>

TimeMap::TimeMap()
{
    mapita = new unordered_map<string, vector<Mapa*>>();
}

void TimeMap::set(string key, string value, int timestamp)
{
    (*mapita)[key].emplace_back(new Mapa{ timestamp, value });
}

string TimeMap::get(string key, int timestamp)
{
    if (mapita->find(key) == mapita->end())
        return "";

    vector<Mapa*> valores = (*mapita)[key];

    unsigned int top = valores.size();
    unsigned int bottom = 0;
    unsigned int middle;

    if (valores[bottom]->tiempo > timestamp)
        return "";

    if (valores[top - 1]->tiempo <= timestamp)
        return values[top - 1]->valor;

    while (bottom < top) {
        middle = (top + bottom) >> 1;

        if (valores[middle]->tiempo == timestamp)
            return values[middle]->valor;

        if (valores[middle]->tiempo < timestamp)
            bottom = middle + 1;
        else
            top = middle;
    }

    return valores[middle]->valor;
}

TimeMap::~TimeMap()
{
    for (auto& entry : *mapita) {
        for (auto& mapa : entry.second) {
            delete mapa;
        }
    }
    delete mapita;
}