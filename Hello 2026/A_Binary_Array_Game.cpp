#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
#define edl '\n'

void solve() {
    int n;
    cin >> n;
    int arr[2] = {0, 0};
    cin >> arr[0];
    for (int i = 0; i < n - 2; i++) {
        int tmp;
        cin >> tmp;
    }
    cin >> arr[1];
    if (arr[1] == 1 || arr[0] == 1) {
        cout << "Alice" << edl;
    } else {
        cout << "Bob" << edl;
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