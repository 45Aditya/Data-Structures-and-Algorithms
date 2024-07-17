#include<bits/stdc++.h>
using namespace std;

// Brute Force 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// Optimal [Dutch national flag algorithm]

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        while(mid <= high) {
            if(nums[mid]==0) {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            } else if(nums[mid]==1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};