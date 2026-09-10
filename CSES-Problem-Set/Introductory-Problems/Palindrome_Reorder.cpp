#include <bits/stdc++.h>

#define ll long long
#define edl '\n'

using namespace std;

ll matrix[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;

    while(cin.get(c)) {
        if (c == '\n') {
            break;
        }
        matrix[c - 'A']++;
    }

    int band = 0;
    char aux = ' ';
    string str, str1;

    for (int a = 0; a < 30; a++) {
        if (matrix[a] % 2 == 1) {
            band++;
            aux = (char) ('A' + a);
        }
        for (ll i = 0; i < (matrix[a] / 2); ++i) {
            str += (char) ('A' + a);
        }
        if (band > 1) {
            cout << "NO SOLUTION" << edl;
            return 0;
        }


    }
    str1 = str;
    reverse(str1.begin(), str1.end());

    cout << (band ? (str + aux + str1) : (str + str1)) << edl;

    return 0;
}