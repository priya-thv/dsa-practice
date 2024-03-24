
#include <bits/stdc++.h>
using namespace std;

bool safe(int i, int j, int n, int m, int **matrix, vector<vector<bool>>& v) {
    return (i >= 0 && j >= 0 && i < n && j < m && matrix[i][j] == 1 && !v[i][j]);
}

int minCostToDestination(int **matrix, int n, int m, int x, int y) {
    vector<vector<bool>> v(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    dist[0][0] = 0;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (safe(ni, nj, n, m, matrix, v)) {
                v[ni][nj] = true;
                q.push(make_pair(ni, nj));
                dist[ni][nj] = dist[i][j] + ((dx[k] == 0) ? 0 : 1); // No cost for left or right movement
            }
        }
    }

    return (dist[x][y] == INT_MAX) ? -1 : dist[x][y];
}
