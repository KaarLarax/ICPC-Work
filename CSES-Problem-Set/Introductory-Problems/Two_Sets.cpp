#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

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
    ll n;
    cin >> n;
    ll verificar = n * (n + 1) / 2;
    if ((verificar & 1ll) != 0) {
        cout << "NO" << edl;
        return;
    }
    list<ll> ans1, ans2;
    if (n & 1ll) {
        for (int i = 1; i <= n / 2; ++i) {
            if (i & 1) {
                ans1.push_back(i);
                ans2.push_back((n + 1) - i);
            } else {
                ans2.push_back(i);
                ans1.push_back((n + 1) - i);
            }
        }
        ans1.push_back((n + 1) / 2);
    } else {
        for (int i = 1; i <= n / 2; ++i) {
            if (i <= n / 4) {
                ans1.push_back(i);
                ans1.push_back(n + 1 - i);
            } else {
                ans2.push_back(i);
                ans2.push_back(n + 1 - i);
            }
        }
    }
    cout << "YES" << edl;
    cout << sz(ans1) << edl;
    for (auto item : ans1) {
        cout << item << ' ';
    }
    cout << edl;
    cout << sz(ans2) << edl;
    for (auto item : ans2) {
        cout << item << ' ';
    }
    cout << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
// By KaarLarax