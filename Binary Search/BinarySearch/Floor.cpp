#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, h=n-1;
    while(l<=h) {
        int mid = l + (h-l)/2;
        if(arr[mid]==k) {
            return mid;
        } else if(arr[mid] < k) {
            l = mid+1;
        } else {
            h = mid-1;
        }
    }
    return h;
}