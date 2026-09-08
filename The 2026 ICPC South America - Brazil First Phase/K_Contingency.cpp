// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvll = vector<vll>;
using viii = vector<pair<int, ii>>;

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
    viii ans(n, {0, {0, 0}});
    vi al(n), re = al;
    for (int i = 0; i < n; i++) {
        cin >> al[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> re[i];
    }
    for (int i = 0; i < n; i++) {
        if (re[i] > al[i]) {
            cout << -1 << edl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i].first = al[i] - re[i];
        ans[i].second.first = al[i];
        ans[i].second.second = re[i];
    }
    sort(ans.begin(), ans.end(), [&](const auto &a, const auto &b) {
        if (a.first < b.first) {
            return false;
        }

        if (a.first == b.first) {
            return a.second.second > b.second.second;
        }

        return true;
    });
    ll val = ans.back().second.second;
    for (int i = 0; i < n - 1; i++) {
        val +=ans[i].second.first;
    }
    cout << val << edl;
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