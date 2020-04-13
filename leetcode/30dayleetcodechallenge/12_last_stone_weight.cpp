class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 1st solution
        for(int i = stones.size() - 1; i > 0; i--){
            sort(stones.begin(), stones.end());
            if(stones[i] == stones[i-1]){
                stones.pop_back();
                stones.pop_back();
                i--;
            } else {
                stones[i] -= stones[i-1];
                stones[i-1] = stones[i];
                stones.pop_back();
            }
        }
        if(!stones.empty())
            return stones[0];
        else 
            return 0;
    }
};