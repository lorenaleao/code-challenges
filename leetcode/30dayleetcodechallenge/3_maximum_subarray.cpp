#include <bits/stdc++.h> 

class Solution {
public:
    // observations: 
    //  - if all the numbers are positive, then the answer is the sum of all the numbers

    int maxSubArray(vector<int>& nums) {
        /* 

        // O(n²) solution (the first I came up with)  
        // It calculates the sum of all the subarrays and finds the maximum one
        // intervals_sum[i][j] represents the sum of the subarray from index i to j

        vector<vector<int>> intervals_sum(nums.size(), vector<int>(nums.size()));
        int max_sum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            intervals_sum[0][i] = sum;
            if(intervals_sum[0][i] > max_sum)
                max_sum = intervals_sum[0][i];
        }
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(i == j){
                    intervals_sum[i][j] = nums[i];
                } else {
                    intervals_sum[i][j] = intervals_sum[i-1][j] - intervals_sum[i-1][i-1];   
                } 
                
                if(intervals_sum[i][j] > max_sum)
                    max_sum = intervals_sum[i][j];
            }
        }
        
        return max_sum;

        */

        // 2nd solution --> O(n)

        int max_sum = nums[0];
        int curr_sol = max_sum;
        
        for(int i = 1; i < nums.size(); i++){
            int possible_next_solution = curr_sol + nums[i];
            
            //cout << possible_next_solution << ' ' << curr_sol << ' ' << nums[i] << endl;
            
            if(nums[i] > possible_next_solution){
                curr_sol = nums[i];
            } else {
                curr_sol = possible_next_solution;
            }
            
            if(curr_sol > max_sum)
                max_sum = curr_sol;
        }
        return max_sum;
    }
};