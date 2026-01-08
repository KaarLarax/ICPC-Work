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
    int n, m;
    cin >> n >> m;
    vector<string> ans(n), ans2(n, string(m, '.'));
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 'o') {
                ans2[i][j] = 'o';
                int contador = 0;
                for (int k = i - 1; k >= 0; k--) {
                    if (ans[k][j] == 'o') {
                        break;
                    }
                    if (ans[k][j] == '*') {
                        contador++;
                    }
                }
                for (int k = i - 1; k >= 0 && contador; k--, contador--) {
                    ans2[k][j] = '*';
                }
            } else if (i == n - 1 && (ans[i][j] == '.' || ans[i][j] == '*')) {
                ans2[i][j] = ans[i][j];
                int contador = 0;
                for (int k = i - 1; k >= 0; k--) {
                    if (ans[k][j] == 'o') {
                        break;
                    }
                    if (ans[k][j] == '*') {
                        contador++;
                    }
                }
                for (int k =  i + (ans[i][j] == '*' ? -1 : 0); k >= 0 && contador; k--, contador--) {
                    ans2[k][j] = '*';
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans2[i] << edl;
    }
    cout << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    // vsCode;
    return 0;
}
// By KaarLarax