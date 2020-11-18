/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size();
        int x=0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        int maximum=0;
        for(int i=1;i<n;i++)
        {
            if(A[i]>A[i-1])
                left[i]+=left[i-1]+1;
            
        }
        for(int i=n-2;i>=0;i--)
        {
            if(A[i]>A[i+1])
            right[i]+=right[i+1]+1;
        }
        for(int i=0;i<n;i++)
        {
            if(left[i]!=0 && right[i]!=0){
            x=left[i]+right[i]+1;
            maximum=max(maximum,x);
        }
        }
        return maximum;
    }
};