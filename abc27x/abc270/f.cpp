#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
int N, M, X[200000], Y[200000], A[200000], B[200000], Z[200000];

using st = array<int, 3>;

ll solve(int N, vector<st> &v) {
    ll ans = 0;
    dsu d(N);
    sort(v.begin(), v.end());
    for (auto [c, a, b] : v) {
        if (d.same(a, b)) continue;
        d.merge(a, b);
        ans += c;
    }
    return d.groups().size() == 1 ? ans : 1e18;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < N; ++i) cin >> Y[i];
    for (int i = 0; i < M; ++i) cin >> A[i] >> B[i] >> Z[i], --A[i], --B[i];

    vector<st> v[4];
    for (int k = 0; k < 4; ++k)
        for (int i = 0; i < M; ++i) v[k].push_back({Z[i], A[i], B[i]});

    for (int i = 0; i < N; ++i) v[1].push_back({X[i], i, N});
    for (int i = 0; i < N; ++i) v[2].push_back({Y[i], i, N});
    for (int i = 0; i < N; ++i) v[3].push_back({X[i], i, N});
    for (int i = 0; i < N; ++i) v[3].push_back({Y[i], i, N + 1});

    ll ans = 1e18;
    for (int k = 0; k < 4; ++k) chmin(ans, solve(N + __builtin_popcount(k), v[k]));

    cout << ans << '\n';
}
