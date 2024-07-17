#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN;
        int i=0, j=height.size()-1;
        while(i<j) {
            int l = min(height[i], height[j]);
            int b = j - i;
            area = max(area, l*b);
            height[i] < height[j] ? i++ : j--; 
        }
        return area;
    }
};