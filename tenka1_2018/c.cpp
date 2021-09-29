#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

bool calc(ll v1, ll v2, ll q1, ll q2) {
    ll diff_1 = abs(v1 - q1) + abs(v2 - q2);
    ll diff_2 = abs(v1 - q2) + abs(v2 - q1);
    if (diff_1 > diff_2) {
        return true;
    } else {
        return false;
    }
}
ll n;
vector<ll> a;
ll solve(bool flag) {
    deque<ll> q;
    int j = n - 1;
    int i = 0;

    if (flag) {
        q.push_back(a[0]);
        i++;
    } else {
        q.push_back(a[n - 1]);
        j--;
    }

    while (i <= j) {
        if (j - i + 1 >= 2) {
            ll v1, v2;
            if (flag) {
                v1 = a[j];
                v2 = a[j - 1];
            } else {
                v1 = a[i];
                v2 = a[i + 1];
            }
            if (calc(v1, v2, q.front(), q.back())) {
                q.push_front(v1);
                q.push_back(v2);
            } else {
                q.push_front(v2);
                q.push_back(v1);
            }
            if (flag)
                j -= 2;
            else
                i += 2;
        } else {
            ll v;
            if (flag)
                v = a[j];
            else
                v = a[i];
            if (abs(v - q.front()) > abs(abs(v - q.back()))) {
                q.push_front(v);
            } else {
                q.push_back(v);
            }
            if (flag)
                j--;
            else
                i++;
        }
        flag = !flag;
    }
    ll res = 0;
    rep(i, n - 1) res += abs(q[i] - q[i + 1]);

    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll res = max(solve(true), solve(false));
    cout << res << endl;
    return 0;
}