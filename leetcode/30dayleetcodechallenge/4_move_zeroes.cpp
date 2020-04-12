class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /* 1st solution, using extra space and copying the array

        vector<int> copy(nums.size());
        int j, k;
        j = 0;
        k = nums.size() - 1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                copy[k] = 0;
                k--;
            } else {
                copy[j] = nums[i];
                j++;
            }            
        }
        
        nums = copy;
        */
        // 2nd attempt
        int zero = 0;
        while(nums[zero] and zero < nums.size() - 1)
            zero++;
        for(int i = 0; i < nums.size(); i++){   
            if(nums[i] and zero < i){
                nums[zero] = nums[i];
                nums[i] = 0;
                
                while(nums[zero] and zero < nums.size() - 1)
                    zero++;
            }           
        }

        /*
        // errichto's solution
        // yt video: https://www.youtube.com/watch?v=E7xxGi84Tso&t

        int n = nums.size();
        int nxt = 0;

        for(int x : nums){
            if(x != 0){
                nums[nxt] = x;
                nxt++;
            }
        }

        for(int i = nxt; i < n; i++){
            nums[i] = 0;
        }
        */
    }
};