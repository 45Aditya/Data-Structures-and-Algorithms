#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int idx = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(nums[mid] >= target) {
            idx = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return idx;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    cout << lowerBound(nums, target) << '\n';
}