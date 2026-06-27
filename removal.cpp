#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 1;
const int d7 = 1e9 + 7;
int n;
int nc[maxn], parent[maxn];

int find_nm(int l, int r, bool t) {
    int nm = maxn + 1, pos;
    for(int i = l; i <= r; i++) {
        if(nc[i] < nm) {
            nm = nc[i];
            pos = i;
        }
    }
    if(t) parent[nc[nm]] = l - 1;
    else parent[nc[nm]] = r + 1;
    return pos;
}

int brint (int l, int r) {
    if(l == r) return 1;
    int nmi = find_nm(l, r);
    cout << nmi << ':';
    int v1 = brint(l, nmi - 1, 0);
    int v2 = brint(nmi + 1, r, 1);
    if(parent)
    return (v1 + 1) * (v2 + 1) - 2;
}

int main () {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    cout << brint(0, n - 1);
    return 0;
}
