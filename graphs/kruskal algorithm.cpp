#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

void makeset(vector<int>& parent, vector<int>& rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int checkparent(vector<int>& parent, int node) {
    while (parent[node] != node) {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return parent[node];
}

void unionset(int u, int v, vector<int>& parent, vector<int>& rank) {
    int x = checkparent(parent, u);
    int y = checkparent(parent, v);
    if (rank[x] > rank[y]) {
        parent[y] = x;
    } else if (rank[y] > rank[x]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        rank[x]++;
    }
}

void kruskalalgo(vector<vector<int>>& vi, int n, int m, vector<vector<int>>& ans) {
    sort(vi.begin(), vi.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n, 0);
    makeset(parent, rank, n);
    int count = 0;
    for (int i = 0; i < m; i++) {
        int u = checkparent(parent, vi[i][0]);
        int v = checkparent(parent, vi[i][1]);
        if (u != v) {
            vector<int> c;
            if (vi[i][0] < vi[i][1]) {
                c.push_back(vi[i][0]);
                c.push_back(vi[i][1]);
                c.push_back(vi[i][2]);
            } else {
                c.push_back(vi[i][1]);
                c.push_back(vi[i][0]);
                c.push_back(vi[i][2]);
            }
            ans.push_back(c);
            unionset(u, v, parent, rank);
            count++;
            if (count == n - 1) // If we have added n-1 edges, exit the loop
                break;
        }
    }
}

int main() {
    int m, n;
    cin >> n >> m;
    vector<vector<int>> vi;
    vector<vector<int>> ans;
    for (int i = 0; i < m; i++) {
        int u, b, w;
        cin >> u >> b >> w;
        vector<int> c;
        c.push_back(u);
        c.push_back(b);
        c.push_back(w);
        vi.push_back(c);
    }
    kruskalalgo(vi, n, m, ans);
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
    }

    return 0;
}
