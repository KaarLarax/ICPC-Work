// By KaarLarax
// codeforces/Kaarlarax
// github/KaarLarax
// youtube/KaarLarax

#include  <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using vull = vector<ull>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll x;
    cin >> x;
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES" << endl;
        return;
    }
    ll value = -INF;
    for (int i = 0; i < n; i++) {
        ll tmp = x - a[i];
        ll l = min(a[i], tmp), r = max(a[i], tmp);
        if (l >= value) {
            value = l;
        } else if (r >= value) {
            value = r;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

// Main function
int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}