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
    multiset<string> a;
    vector<string> tmp(n * 3);
    for (int i = 0; i < n * 3; i++) {
        cin >> tmp[i];
        a.insert(tmp[i]);
    }
    auto cal = [&](const string &x) {
        int apper = a.count(x);
        if (apper == 1) {
            return 3;
        }
        if (apper == 2) {
            return 1;
        }
        return 0;
    };
    vi ans(3, 0);
    for (int i = 0; i < n; i++) {
        ans[0] += cal(tmp[i]);
    }
    for (int i = 0; i < n; i++) {
        ans[1] += cal(tmp[i + n]);
    }
    for (int i = 0; i < n; i++) {
        ans[2] += cal(tmp[i + (n * 2)]);
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << edl;
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