#include<bits/stdc++.h>
using namespace std;

//Using DFS
class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int row, int col, int original){
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : directions) {
            int nr = sr + dir.first;
            int nc = sc + dir.second;
            if (nr >= 0 && nc >= 0 && nr < row && nc < col && image[nr][nc] == original) {
                image[nr][nc] = color;
                dfs(image, nr, nc, color, row, col, original);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int original = image[sr][sc];
        if (original != color) {  
            image[sr][sc] = color;
            dfs(image, sr, sc, color, row, col, original);
        }
        return image;
    }
};

//Using BFS
class Solution {
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, int original) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;               
                if (nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size() && image[nr][nc] == original) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];       
        if (original != color) { 
            bfs(image, sr, sc, color, original);
        }       
        return image;
    }
};
