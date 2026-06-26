#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int a[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, ans = 0;
    bool t = true;
    cin >> n;
    cin >> a[0];
    for(int i = 1; i < 2 * n; i++) {
        cin >> a[i];
        if(abs(a[i]) != abs(a[i - 1])) t = false;
    }
    if(n == 1) {
        if(a[0] < 0) cout << 0;
        else cout << 1;
        return 0;
    } else if(!t){
        cout << (n * (n - 1)) / 2;
        return 0;
    }
    queue<int> poz, otr;
    int otm = 0;
    while(!poz.empty()) {
        for(int i = otm; i < 2 * n + otm; i++) {
            if(a[i + otm] > 0 && (i + otm) % 2 == 0) poz.push(i);
            if(a[i + otm] < 0 && (i + otm) % 2 != 0) otr.push(i);
        }
        int p = poz.front(), o = otr.front();
        poz.pop();
        otr.pop();
        while(p > o) {
            ans++;
            if(a[p - 1 + otm] > 0 && (p - 1 + otm) % 2 == 0) otm++;
            int h = a[p + otm];
            a[p + otm] = a[p - 1 + otm];
            a[p - 1 + otm] = h;
            p--;
        }
        while(o >= p) {
            ans++;
            if(a[p - 1 + otm] < 0 && (p - 1 + otm) % 2 != 0) otm++;
            int h = a[o + otm];
            a[o + otm] = a[o - 1 + otm];
            a[o - 1 + otm] = h;
            o--;
        }
        for(int i = otm; i < 2 * n + otm; i++) {
            a[i + otm] = a[i];
        }
    }
    cout << ans;
    return 0;
}
