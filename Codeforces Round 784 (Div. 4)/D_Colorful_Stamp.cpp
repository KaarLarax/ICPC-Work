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
    string s;
    cin >> s;
    string ans;
    for (auto& c : s) {
        if (ans.empty() || ans.back() != c) {
            ans += c;
        }
    }
    if (sz(ans) == 1 && (ans[0] != 'W')) {
        cout << "NO" << edl;
        return;
    } else if (sz(ans) == 2 && (ans == "WB" || ans == "WR" || ans == "RW" || ans == "BW")) {
        cout << "NO" << edl;
        return;
    } else if(sz(ans) == 2) {
        cout << "YES" << edl;
        return;
    }
    bool band = ans.find("WRW") == string::npos;
    band &= ans.find("WBW") == string::npos;
    band &= ans.substr(0, 2) != "RW" && ans.substr(0, 2) != "BW";
    reverse(ans.begin(), ans.end());
    band &= ans.substr(0, 2) != "RW" && ans.substr(0, 2) != "BW";
    cout << (band ? "YES" : "NO") << edl;
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