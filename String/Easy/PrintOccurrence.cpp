#include<bits/stdc++.h>
using namespace std;

//Using Map
int main() {
    string s = "";
    cout << "Enter a string = ";
    cin >> s;
    unordered_map<char,int> mp;
    for(auto c : s) {
        mp[c]++;
    }
    for(auto it : mp) {
        cout << "Frequency of character " << it.first << " in string s = " << it.second << endl; 
    }
    return 0;
}

//Using character array
int main() {
    string s = "";
    cout << "Enter a string = ";
    cin >> s;
    int arr[26] = {0};
    for(auto c : s) {
        arr[c-'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(arr[i] > 0) {
            cout << "Frequency of character " << char(i + 'a') << " in string s = " << arr[i] << endl;
        }
    }
    return 0;
}