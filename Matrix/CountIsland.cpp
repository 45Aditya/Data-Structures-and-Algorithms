#include<bits/stdc++.h>
using namespace std;

//Using BFS
class Solution {
    void helper(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visit, int n, int m, int& count) {
        visit[i][j] = 1;
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int,int>> q;
        q.push({i, j});
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto dir : directions) {
                int nr = row + dir.first;
                int nc = col + dir.second;
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1' && !visit[nr][nc]) {
                    q.push({nr,nc});
                    visit[nr][nc] = 1;
                }
            }
        }
        count++;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visit(n, vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1' && !visit[i][j]) {
                    helper(i, j, grid, visit, n, m, count);
                }
            }
        }
        return count;
    }
};

//Using BFS
class Solution {
    void helper(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visit, int n, int m) {
        visit[i][j] = 1;
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int row = i;
        int col = j;
        for(auto dir : directions) {
            int nr = row + dir.first;
            int nc = col + dir.second;
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1' && !visit[nr][nc]) {
                visit[nr][nc] = 1;
                helper(nr, nc, grid, visit, n, m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visit(n, vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1' && !visit[i][j]) {
                    helper(i, j, grid, visit, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};