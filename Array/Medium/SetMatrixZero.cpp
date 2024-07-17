#include<bits/stdc++.h>
using namespace std;

class Solution {
    void update(vector<vector<int>>& matrix, int r, int c, int row, int col) {
        for(int j=0; j<col; j++) {
            matrix[r][j] = 0;
        }
        for(int i=0; i<row; i++) {
            matrix[i][c] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> mp;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j]==0) {
                    mp.push_back({i,j});
                }
            }
        }
        for(int i=0; i<mp.size(); i++) {
            update(matrix, mp[i].first, mp[i].second, row, col);
        }
    }
};