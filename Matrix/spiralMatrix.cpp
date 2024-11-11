#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> visit(row, vector<int>(col, 0));
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int dir = 0;
        int r=0, c=0;
        for(int i=0; i<row * col; i++) {
            ans.push_back(matrix[r][c]);
            visit[r][c] = 1;
            int nr = r + directions[dir][0];
            int nc = c + directions[dir][1];

            if(nr >= 0 && nc >= 0 && nr < row && nc < col && !visit[nr][nc]) {
                r = nr;
                c = nc;
            }

            else {
                dir = (dir + 1) % 4;
                r += directions[dir][0];
                c += directions[dir][1];
            }
        }
        return ans;
    }
};