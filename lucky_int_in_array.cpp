/*
3. Find Lucky Integer in an Array
Easy
Given an array of integers arr, a lucky integer is an integer which has a frequency in the array equal to its value.
Return a lucky integer in the array. If there are multiple lucky integers return the largest of them. If there is no lucky integer return -1
Solution : Use hashmaps for the solution. Put the contents and the count for each of the element in the array in a hashmap. Next for count of each of the element is equal to the frequency then that element is lucky. Next check for the max element and return that element that is maximum in case of repeating elements.
*/
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int lucky_int=-1;
        int max=INT_MIN;
        unordered_map<int,int> hash;
        for(int i=0;i<arr.size();i++)
            hash[arr[i]]++;
        for(int i=0;i<=arr.size();i++)
        {
            if(i==hash[i] & hash[i]>0)
                if(i>max)
                {
                    max=i;
                    lucky_int= i;        
                }  
         }
        return lucky_int;
    }
};

