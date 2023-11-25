#include "Ejercicio02.h"
#include <unordered_map>
#include <vector>

using namespace std;

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    vector<string>* resultado = new vector<string>();
    unordered_map<string, int> mapaAux;

    string curr = "";
    Node<char>* temp = head;

    while (temp != nullptr) {
        curr += temp->value;

        if (curr.length() == 10) {
            if (mapaAux.find(curr) == mapaAux.end()) {
                mapaAux[curr] = 0;
            }
            else if (mapaAux[curr] == 0) {
                resultado->push_back(curr);
                mapaAux[curr]++;
            }

            curr.erase(0, 1);
        }

        temp = temp->next;
    }

    return resultado;
}
