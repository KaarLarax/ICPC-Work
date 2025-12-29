#include <bits/stdc++.h>

using namespace std;

#define edl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    long long ab = 0, bc = 0;

    for (int d = 0; d < n; ++d) {
        bool ok = true;
        for (int t = 0; t < n; ++t) {
            if (a[t] >= b[(t + d) % n]) {
                ok = false;
                break;
            }
        }
        if (ok) ++ab;
    }

    for (int d = 0; d < n; ++d) {
        bool band = true;
        for (int t = 0; t < n; ++t) {
            if (b[t] >= c[(t + d) % n]) {
                band = false;
                break;
            }
        }
        if (band) ++bc;
    }

    long long ans = 1LL * n * ab * bc;
    cout << ans << edl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr); // Fast I/O Setup
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
// By KaarLarax