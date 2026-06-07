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

bool primos[int(1e7 + 5)];
vll values;
void criba(const int &n) {
    values.reserve(1e7);
    for (int i = 2; i * i <= n; i++) {
        if (!primos[i]) {
            for (int j = i + i; j <= n; j += i) {
                primos[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!primos[i]) {
            values.pb(i);
        }
    }

}

void solve() {
    criba(1e7);
    string n;
    map<ll, int> ans;
    auto facto = [&](ll value) {
        int idx = 0;
        while(value > 1 && idx < sz(values)) {
            if (value % values[idx] == 0) {
                value /= values[idx];
                ans[values[idx]]++;
            } else {
                idx++;
            }
        }
        if (value > 1) {
            ans[value]++;
        }
    };
    cin >> n;
    if (sz(n) > 10) {
        ll temporal = stoll(n.substr(0, 10));
        ans[2] += sz(n) - 10;
        ans[5] += sz(n) - 10;
        facto(temporal);
    } else {
        facto(stoll(n));
    }
    cout << sz(ans) << edl;
    for (auto i : ans) {
        cout << i.fi << ' ' << i.se << edl;
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