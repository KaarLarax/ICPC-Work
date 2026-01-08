// BY LARA 1424
// https://codeforces.com/profile/DarkoLaraSlowed
// https://github.com/KaarLarax
// https://www.youtube.com/@KaarLarax

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using vull = vector<ull>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};

constexpr int limit = 1e6;
int divisor[limit + 1];
void harmonicNumber() {
    for (int i = 1; i <= limit; ++i) {
        for (int j = i + i; j <= limit; j += i) {
            divisor[j] += i;
        }
    }
}

// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int arr[5];
        for (int i = 0; i < 5; ++i) {
            if (i != 2) {
                cin >> arr[i];
            }
        }
        int anterior = arr[1], anterior2 = arr[0], ans = 0, ans2 = 0;
        arr[2] = arr[3] - arr[1];
        for (int i = 2; i < 5; ++i) {
            int temp = anterior + anterior2;
            if (arr[i] == temp) {
                ans++;
            }
            anterior2 = anterior;
            anterior = arr[i];
        }
        anterior = arr[1], anterior2 = arr[0];
        arr[2] = arr[1] + arr[0];
        for (int i = 2; i < 5; ++i) {
            int temp = anterior + anterior2;
            if (arr[i] == temp) {
                ans2++;
            }
            anterior2 = anterior;
            anterior = arr[i];
        }
        cout << max(ans, ans2) << edl;
    }
    return 0;
}