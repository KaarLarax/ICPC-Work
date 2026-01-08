#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define edl '\n'


void solve() {
    ll n, a = 0, b = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        (str[i] != '-' ? a : b)++;
    }
    ll ans = 0;
    if (a != 0 && b >= 2) {
        cout << ((b + 1) / 2) * a * (b / 2) << edl;
    } else {
        cout << ans << edl;
        return;
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