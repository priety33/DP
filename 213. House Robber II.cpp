class Solution {
public:

    int robOriginal(vector<int>& nums) {
        int a = 0, b = 0, res = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            res = max(b + nums[i], a);
            a = b;
            b = res;
        }
        
        return res;
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> numsA(nums.begin() + 1, nums.end()); //robbed first house, => consider till second last house
        vector<int> numsB(nums.begin(), nums.end()-1);   // didnt rob first house, => consider till last house
        
        return max(robOriginal(numsA), robOriginal(numsB));
    }
};
