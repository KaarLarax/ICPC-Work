// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'
#define vsCode cout << flush, system("Pause")

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e3 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    cin.ignore();
    string lines[n];
    for (int i = 0; i < n; i++) {
        getline(cin, lines[i]);
    }
    for (int i = 0; i < n; i++) {
        stringstream tmp(lines[i]);
        for (int c = 0; tmp; c++) {
            string aux;
            tmp >> aux;

            if (aux == "" || aux == " ") {
                continue;
            }

            if (c) {
                cout << ' ';
            }
            bool nodigit = aux.end() != find_if(aux.begin(), aux.end(), [](const char &a) {
                               return !isdigit(a);
                           });
            if (nodigit) {
                cout << aux;
                continue;
            }
            int zeros = 0;
            for (int j = sz(aux) - 1; j >= 1; j--, zeros++) {
                if (aux[j] != '0') {
                    break;
                }
            }
            if (zeros < 4) {
                cout << aux;
                continue;
            }

            if (sz(aux) - zeros == 1) {
                if (aux[0] == '1') {
                    cout << "10^{" << zeros << "}";
                } else {
                    cout << aux[0] << "\\cdot10^{" << zeros << "}";
                }
            } else if (aux[0] != '0') {
                cout << aux[0] << "." << aux.substr(1, sz(aux) - zeros - 1) << "\\cdot10^{" << sz(aux) - 1 << "}";
            } else {
                cout << aux;
            }
            c++;
        }
        cout << edl;
    }
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax