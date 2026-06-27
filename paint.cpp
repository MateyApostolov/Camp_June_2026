#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 1;
int paint[maxn];
vector <pair<int, int>> tree[maxn];


int main () {
    int n, i, j, v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> paint[i];
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> i >> j >> v;
        tree[i].push_bacK({j, v});
        tree[j].push_bacK({i, v});
    }

    return 0;
}
