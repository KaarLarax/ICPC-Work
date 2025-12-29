#include <bits/stdc++.h>

using namespace std;

#define edl '\n'

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0, tmp = a, tmp1 = b, extra = 1;
    bool band = true;
    while (true) {
        if (band && tmp >= extra) {
            ans++;
            tmp -= extra;
        } else if (!band && tmp1 >= extra) {
            ans++;
            tmp1 -= extra;
        } else {
            break;
        }
        band = !band;
        extra <<= 1;
    }
    int ans2 = 0;
    tmp = b, tmp1 = a, extra = 1;
    band = true;
    while (true) {
        if (band && tmp >= extra) {
            ans2++;
            tmp -= extra;
        } else if (!band && tmp1 >= extra) {
            ans2++;
            tmp1 -= extra;
        } else {
            break;
        }
        band = !band;
        extra <<= 1;
    }
    cout << max(ans, ans2) << edl;
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