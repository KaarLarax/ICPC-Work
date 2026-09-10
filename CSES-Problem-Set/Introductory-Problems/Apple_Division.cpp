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
ll diference(vi x, int index, ll sumgrupo1, ll sumgrupo2) {
    if (index < 0) {
        return abs(sumgrupo1 - sumgrupo2);
    }
    ll grupo1 = diference(x, index - 1, sumgrupo1 + x[index], sumgrupo2);
    ll grupo2 = diference(x, index - 1, sumgrupo1, x[index] + sumgrupo2);
    return min(grupo1, grupo2);
}
// Main funtion
int main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vi apples(n);
    for (int i = 0; i < n; ++i) {
        cin >> apples[i];
    }
    cout << diference(apples, n - 1, 0ll, 0ll) << edl;
    return 0;
}