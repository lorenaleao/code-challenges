class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<int> elems_counter(1005, 0);
        for(int n : arr){
            elems_counter[n]++;
        }
        
        int count = 0;
        for(int i = 0; i < 1001; i++){
            if(elems_counter[i+1] > 0)
                count += elems_counter[i];
        }
        return count;
    }
};