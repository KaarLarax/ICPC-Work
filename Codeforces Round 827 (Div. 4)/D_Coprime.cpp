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
    vi arr(n);
    set<int> tmp;
    map<int, vector<int>> indexes;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tmp.insert(arr[i]);
        indexes[arr[i]].pb(i + 1);
    }
    arr.assign(tmp.begin(), tmp.end());
    int ans = -1;
    for (int i = 0; i < sz(arr); i++) {
        for (int j = i; j < sz(arr); j++) {
            if (__gcd(arr[i], arr[j]) == 1) {
                ans = max(indexes[arr[i]].back() + indexes[arr[j]].back(), ans);
            }
        }
    }
    cout << ans << edl;
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