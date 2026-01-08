#include <bits/stdc++.h>

using namespace std;

#define edl '\n'

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    if (p == 0) {
        cout << -1 << edl;
        return;
    }
    m = abs(m);
    float val = (m * 1.00f / p * 1.00f);
    if (m > 0) {
        if (p > m) {
            cout << 1 << edl;
            return;
        }
        int ans = -1;
        if (val <= (n * 1.00f)) {
            ans = (int) val;
            if (m % p != 0) {
                ans++;
            }
            cout << ans << edl;
        } else {
            cout << ans << edl;
        }
    } else {
        cout << 0 << edl;
    }
}

int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}

// By KaarLarax