#include <bits/stdc++.h>

#define ll long long
#define edl '\n'
#define sz(x) (int) x.size()

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int q, sizes;
    string str;
    cin >> q;
    while(q--) {
        cin >> sizes >> str;
        char aux = str[0];
        string result;
        for (int i = 1; i < sizes; i++) {
            if (str[i] == aux) {
                result += aux;
                aux = str[i + 1];
                i++;
            }
        }
        cout << result << edl;
    }




    return 0;
}