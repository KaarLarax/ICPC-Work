#include <iostream>
#include <vector>

using namespace std;

int main() {
    long int n;
    cin >> n;

    vector<int> secuencia(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> secuencia[i];
    }

    long int sumaTotal = (n * (n + 1)) / 2;

    long int sumaSecuencia = 0;
    for (int i = 0; i < n - 1; ++i) {
        sumaSecuencia += secuencia[i];
    }

    long int numeroFaltante = sumaTotal - sumaSecuencia;

    cout << numeroFaltante << endl;

    return 0;
}
