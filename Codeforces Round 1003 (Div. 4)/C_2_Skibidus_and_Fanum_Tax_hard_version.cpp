#include  <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vvi = vector<vector<int> >;

#define  sz(x) int(x.size())
#define  fi first
#define  se second
#define  pb emplace_back
#define  edl '\n'

constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a(n), v(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES" << edl;
        return;
    }
    ll value = -INF;
    for (int i = 0; i < n; i++) {
        ll result = LLINF;
        if (a[i] >= value ) {
            result = a[i];
        }
        ll mini = 0, maxi = m - 1;
        while (mini <= maxi) {
            ll midi = mini + (maxi - mini) / 2;
            ll tmp =  v[midi] - a[i];
            if (tmp >= value) {
                result = min(tmp, result);
                maxi = midi - 1;
            } else {
                mini = midi + 1;
            }
        }
        if (result == LLINF) {
            cout << "NO" << edl;
            return;
        }
        value = result;
    }
    cout << "YES" << edl;
}


int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// By KaarLarax
// codeforces/Kaarlarax
// github/KaarLarax
// youtube/KaarLarax