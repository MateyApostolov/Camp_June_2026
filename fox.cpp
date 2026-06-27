#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 1;
int nc[maxn], dp[maxn];

int main () {
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        for(int x = i - 1; x >= 0; x--) {
            if(nc[i] <= nc[x]) continue;
            dp[i] = max(dp[i], dp[x]);
        }
        dp[i]++;
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
