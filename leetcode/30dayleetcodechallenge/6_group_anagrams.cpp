#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    int calculate_hash(string s){
        int hash_value = 0; 
        for(int i = 0; i < s.size(); i++){
            hash_value += int(s[i]);
        }
        return hash_value;
    }
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams_grouped;
        for(string s: strs){
            //int hash = calculate_hash(s); 
            //my first idea was to use this function (calculate_hash()) 
            //to create a unique key for the words, but i noticed that 
            //there were collisions
            string s_copy = s;
            sort(s.begin(), s.end()); 
            anagrams_grouped[s].push_back(s_copy);
        }
        vector<vector<string>> ans;
        for (auto const& x : anagrams_grouped){
           ans.push_back(x.second);
        }
        
        return ans;
    }
};