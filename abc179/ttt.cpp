#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 998244353;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll L, R;
    vector<int> S;
    rep(i, k)
    {
        cin >> L >> R;
        reps(j, R + 1, L)
        {
            S.pb(j);
        }
    }
    int m = S.size();
    sort(S.begin(), S.end());
    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    reps(i, n, 1)
    {
        for (auto d : S)
        {
            if (i + d <= n)
            {
                dp[i + d] = (dp[i + d] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
