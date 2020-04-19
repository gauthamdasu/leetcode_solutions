/*
Searching in rotated sorted array.
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
Solution:
Idea of the problem is that we can use a hashmap and search in the hashmap for the value as given in the following code snippet.
Code Snippets:
*/
int search(vector<int>& nums, int target) {
        int val=-1;
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]=i;
        }
        if(hash.find(target)!=hash.end())
            val=hash[target];
        return val;

/*
The second method is a binary search approach where we locate the existence of the element and accordingly update the low and high pointers in the the binary search.
Code snippet:
*/
class Solution {
public:
   int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, h=n-1, m=0; // declare and initialize the variables.
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]==target)  // found the element return the index.
                   return m;

 // nums[l] <= nums[m] then target in the left region from low to mid.
            else if(nums[l]<=nums[m]){
                  (nums[l] <= target && target<nums[m])?h=m-1: l=m+1;
            } 
//nums[l]<=target && target <nums[m] means target is in the left half else on the right hand similarly for other case also.


 // nums[m] <= nums[h] then target in the right region from mid to high.
 
            else if(nums[m]<=nums[h]){
               (target>nums[m] && target<=nums[h]) ? l=m+1: h=m-1;
            }
        }
        return -1;
    }
};




