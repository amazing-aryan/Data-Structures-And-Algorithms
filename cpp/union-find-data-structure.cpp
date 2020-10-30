#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> component;
    int components;
    
    UnionFind(int n) {
        components = n;
        for(int i=0;i<=n;i++) {
            component.push_back(i);
        }
    }
    
    bool unite(int a, int b) {
        if( findComponent(a) == findComponent(b) ) {
            return false;
        }
        component[findComponent(a)] = b;
        components--;
        return true;
    }
    
    int findComponent(int a) {
        if(component[a]!=a) {
            component[a] = findComponent(component[a]);
        }
        return component[a];
    }
    
    bool united() {
        return components == 1;
    }
};