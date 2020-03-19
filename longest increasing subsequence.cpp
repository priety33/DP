// O(nlogn)- binary search
//we place every element encountered in the lis array, after finding where to place it in the already existing lis.
//length if array at the end will give us the maxm length

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        
        int lis[nums.size()];
        lis[0]=nums[0]; //first element forming lis of length one => len=1
        int len=1;
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > lis[len-1])
            {
                len++; //increasing length of lis
                lis[len-1]=nums[i];// appending it to to current lis
            }   
            else if(nums[i] <= lis[0]) lis[0]=nums[i];    // new smallest value- start new sequence
            else
            {
                int start=0, end=len-1;
                while(end- start>1)
                {
                    int mid= start+(end-start)/2; //finding elements smaller than this in lis using binary search
                    if(lis[mid]>=nums[i]) end=mid; //when lis[mid]=nums[i] we have to put nums[i] at that position only, 
                                                   //therefore we shift end, because at end of loop we are placing elements 
                                                   //at end pointer
                    else start=mid;
                }
                lis[end]=nums[i];
            }
        }
        return len;
    }
};
