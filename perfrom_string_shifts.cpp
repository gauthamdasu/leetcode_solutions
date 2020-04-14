// This file has a brief description and solution class for the problem of string shifts.

/*
Question:  You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:
direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.
 
Example 1:
Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
Example 2:
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 
Constraints:
1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
Solution : 
The idea of the solution is to use the in built reverse function.
We have left and right rotate to be done and it  is given in the form of a matrix.

We shift the letters in the string left or right accordingly, this is broken into subproblems of reversing the string from starting to the length d, from d to end and then a total reverse.

While right reverse can be seen as as left reverse from s.length-d.
*/


class Solution {
public:
    void rotate_left(string &input, int d) 
        { 
        reverse(input.begin(), input.begin()+d); 
        reverse(input.begin()+d, input.end()); 
        reverse(input.begin(), input.end()); 
        } 
  
    void rotate_right(string &input1, int d1) 
        {    
           rotate_left(input1, input1.length()-d1); 
        } 
    string stringShift(string s, vector<vector<int>>& shift) {
    for(auto i : shift)
    {
        
        int a  = i[0];
        int b = i[1];
        if(a==0)
        {
            rotate_left(s,b);
        }
        else
        {
            rotate_right(s,b);
        }
        
    }
        return s;
    }
};






