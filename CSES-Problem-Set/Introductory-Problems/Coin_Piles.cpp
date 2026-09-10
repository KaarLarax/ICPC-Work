#include <bits/stdc++.h>

#define ll long long
#define edl '\n'

using namespace std;

int matrix[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll j;
    cin >> j;

    for (auto i = 0; i < j; i++) {
        ll n, m;
        cin >> n >> m;
        cout << ((n + m) % 3 == 0 && 2 * n >= m && 2* m >= n ? "YES" : "NO") << edl;
    }

    return 0;
}