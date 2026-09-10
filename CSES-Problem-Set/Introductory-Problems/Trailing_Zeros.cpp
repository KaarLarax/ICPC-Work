#include <bits/stdc++.h>

#define ll long long
#define edl '\n'

using namespace std;

int matrix[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll result = 0;

    while(n != 0) {
        n /= 5;
        result += n;
    }

    cout << result << edl;

    return 0;
}