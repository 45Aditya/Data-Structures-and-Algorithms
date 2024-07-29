#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> city(n, vector<int>(n, 1e9));
        
        for (int i = 0; i < n; i++) {
            city[i][i] = 0;
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            city[u][v] = w;
            city[v][u] = w;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (city[i][k] < 1e9 && city[k][j] < 1e9) {
                        city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
                    }
                }
            }
        }

        int minNeighborCount = n;
        int resultCity = -1;

        for (int i = 0; i < n; i++) {
            int currCount = 0; // Reset currCount for each city
            for (int j = 0; j < n; j++) {
                if (i != j && city[i][j] <= distanceThreshold) {
                    currCount++;
                }
            }
            if (currCount <= minNeighborCount) {
                minNeighborCount = currCount;
                resultCity = i;
            }
        }

        return resultCity;
    }
};
