// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<double>;
using ii = pair<double, double>;
using vii = vector<ii>;
using vvll = vector<vll>;

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
    vii prefix(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        prefix[i].first = x + prefix[i - 1].first;
        prefix[i].second = y + prefix[i - 1].second;
    }
    vll ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] = (prefix[i].first - prefix[i].second) / (prefix[i].first + prefix[i].second);
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (ans[x] == 0) {
            cout << "NEUTRO" << edl;
        } else if (ans[x] < 0) {
            cout << "VENDA" << edl;
        } else {
            cout << "COMPRA" << edl;
        }
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