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

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 1e6 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    map<int, string> temps;
    for (int i = 0; i <= 25; i++) {
        string temp;
        for (const auto &item: str) {
            temp += 'a' + (((item - 'a') + i) % 26);
        }
        temps[i] = temp;
    }
    map<int, int> ans;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (auto& item: temps) {
            ans[item.fi] += item.se.find(temp) != string::npos;
        }
    }
    for (auto& item : ans) {
        if (item.second == n) {
            cout << temps[item.fi] << edl;
            return;
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
    return 0;
}
// By KaarLarax