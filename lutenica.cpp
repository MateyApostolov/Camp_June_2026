#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 1;
const int max_mon = 1e4 + 1;
int a[maxn], b[maxn], preff_dp[maxn][], suff_dp[maxn][];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, mon1, mon2;
    cin >> n >> mon1 >> mon2;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < mon1; j++) {
            if(a[i] <= j) {
                pref_dp[i][j] = min(pref_dp[i + 1][j + a[i]], pref[i + 1][x - a[i]] + b[i]);
            } else {
                suff_dp[i][y] = max(suff_dp[i + 1][y], suff_dp[i + 1][y + b[i] + 1);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int x = 0; x < mon1; x++) {
            pref[i][x] = max(suff_dp[i + 1], )
        }
    }

    return 0;
}
