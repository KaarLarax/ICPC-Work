#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define edl '\n'

void solve() {
    ll n, k, m;
    cin >> n >> m >> k;
    ll ans = 0;

    auto good = [&](ll l, ll r) {
        if (l == 0 && r == 0) return 0LL;
        if (l == 0) return 2 * r - 1;
        if (r == 0) return 2 * l - 1;
        return l + r + max(l, r) - 1;
    };

    if (k == 1 || k == n) {
        ll max_dist = (k == 1) ? n - 1 : k - 1;
        ll l1 = 0, r1 = max_dist, best = 0;
        while (l1 <= r1) {
            ll mid1 = l1 + (r1 - l1) / 2;
            if (good(0, mid1) <= m) {
                best = mid1;
                l1 = mid1 + 1;
            } else {
                r1 = mid1 - 1;
            }
        }
        cout << best + 1 << edl;
        return;
    } else {
        for (ll i = 0; i <= k - 1; i++) {
            if (i > 0 && good(i, 0) > m) continue;
            ll l1 = 0, r1 = n - k, best_R = 0;
            while (l1 <= r1) {
                ll mid1 = l1 + (r1 - l1) / 2;
                if (good(i, mid1) <= m) {
                    best_R = mid1;
                    l1 = mid1 + 1;
                } else {
                    r1 = mid1 - 1;
                }
            }
            ans = max(ans, i + best_R);
        }
        cout << ans + 1 << edl;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}