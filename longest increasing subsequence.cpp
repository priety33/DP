// O(nlogn)- binary search
//we place every element encountered in the lis array, after finding where to place it in the already existing lis.
//length if array at the end will give us the maxm length
/*1. If A[i] is smallest among all end 
   candidates of active lists, we will start 
   new active list of length 1.

2. If A[i] is largest among all end candidates of 
  active lists, we will clone the largest active 
  list, and extend it by A[i].


3. If A[i] is in between, we will find a list with 
  largest end element that is smaller than A[i]. 
  Clone and extend this list by A[i]. We will discard all
  other lists of same length as that of this modified list.
  
  https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/ */

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
