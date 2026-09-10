#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long contador = 0, maxcontador = 0;
    string prase;
    cin >> prase;
    char aux = prase[0];
    for(auto& c: prase) {
        if(aux == c) {
            contador++;
        } else {
            aux = c;
            contador = 1;
        }
     maxcontador = max(maxcontador, contador);
    }
    cout << maxcontador << endl;
    return 0;
}
