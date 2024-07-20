#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
public:
    int strStr(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 < n2) return -1;
        int i=0, j=0;
        int index = -1;
        while(i < n1) {
            if(s1[i]!=s2[j]) {
                i++;
            } else {
                int k = i;
                index = i;
                while(k<n1 && j<n2) {
                    if(s1[k]==s2[j]) {
                        k++;
                        j++;
                    } else {
                        break;
                    }
                }
                if(j<n2) {
                    j=0;
                    i++;
                } else {
                    return index;
                }
            }
        }
        return -1;
    }
};

//Sliding window

class Solution {
public:
    int strStr(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 < n2) return -1;
        int i=0, j=0, ans=-1;
        string s = "";
        while(j < n1) {
            s += s1[j];
            if(j-i+1==n2) {
                if(s==s2) {
                    ans = i;
                    break;
                } else {
                    i++;
                    s.erase(s.begin(), s.begin()+1);
                }
            }
            j++;
        }
        return ans;
    }
};