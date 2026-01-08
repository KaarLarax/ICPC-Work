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
constexpr int MxN = 3e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

using namespace std;

vi gdps(const vi &arr) {
    vi temp = arr;
    sort(temp.begin(), temp.end(), greater<>());
    vi prefix(temp.size() + 1, 0);
    for (int i = 0; i < sz(temp); i++) {
        prefix[i + 1] = prefix[i] + temp[i];
    }
    return prefix;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll bcost4 = 0;
    vi arr3;
    for (int i = 2; i <= n; i++) {
        arr3.pb(a[i]);
    }
    vi pre3 = gdps(arr3);
    ll candidate3 = pre3[k] + a[1];
    bcost4 = max(bcost4, candidate3);

    vi arr4;
    for (int i = 1; i <= n - 1; i++) {
        arr4.pb(a[i]);
    }
    vi pre4 = gdps(arr4);
    ll candidate4 = pre4[k] + a[n];
    bcost4 = max(bcost4, candidate4);

    for (int r = 2; r <= n - 1; r++) {
        int lz = r - 1;
        int rz = n - r;
        if (lz < 1 || rz < 1) { continue; }

        vi larr;
        larr.reserve(lz);
        for (int i = 1; i < r; i++) {
            larr.pb(a[i]);
        }
        vi pl = gdps(larr);

        vi rarr;
        rarr.reserve(rz);
        for (int i = r + 1; i <= n; i++) {
            rarr.pb(a[i]);
        }
        vi pr = gdps(rarr);

        for (int j = 1; j <= k - 1; j++) {
            int ln = j;
            int rn = k - j;
            if (ln > lz || rn > rz) { continue; }
            ll sl = pl[ln];
            ll sr = pr[rn];
            ll candidate = sl + sr + a[r];
            bcost4 = max(bcost4, candidate);
        }
    }

    cout << bcost4 << edl;
}

int main() {
    // freopen("text.in", "r", stdin);
    // freopen("text.out", "w", stdout);
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}

// By KaarLarax