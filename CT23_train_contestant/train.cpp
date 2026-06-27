#include "train.h"
#include <bits/stdc++.h>
using namespace std;


vector<int> find_switches(int n) {
    vector<int> keys;
    string s;
    if(n <= 30) {
        for(int i = 0; i < n; i++) {
            s += '1';
        }
        for(int i = 0; i < n; i++) {
            s[i] = '0';
            int scream = experiment(s);
            s[i] = '1';
            if(scream == 2) continue;
            keys.push_back(i);
            if(keys.size() == 2) break;
        }
        return keys;
    }
    keys.push_back(0);
    queue <int> p1, p2;
    s += '1';
    for(int i = 1; i < n; i++) {
        if(i % 2 == 0) {
            s += '1';
            p2.push(i);
        }
        else {
            s += '0';
            p1.push(i);
        }
    }
    while(p1.size() != 1 && p2.size() != 1) {
        int scream = experiment(s);
        if(scream % 2 == 0) {
            queue <int> p1;
            s.clear();
            s += '1';
            for(int i = 1; i < n; i++) {
                if(i == p2.front() && p2.front() % 2 == 0) {
                    s += '1';
                    p2.push(i);
                    p2.pop();
                }
                else if(p2.front() % 2 != 0){
                    p1.push(i);
                } else {
                    s += '0';
                }
            }
        } else {
            queue <int> p2;
            s.clear();
            s += '1';
            for(int i = 1; i < n; i++) {
                if(i == p1.front() && p1.front() % 2 == 0) {
                    s += '1';
                    p1.push(i);
                    p1.pop();
                }
                else if(p1.front() % 2 != 0){
                    p2.push(i);
                } else {
                    s += '0';
                }
            }
        }
    }
    if(p1.size() == 1) keys.push_back(p2.front());
    else keys.push_back(p1.front());
    return keys;
}

