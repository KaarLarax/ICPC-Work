#include <bits/stdc++.h>

using namespace std;

#define edl '\n'

void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    if (s.find("2025") != string::npos && s.find("2026") == string::npos) {
        cout << 1 << edl;
    } else {
        cout << 0 << edl;
    }
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