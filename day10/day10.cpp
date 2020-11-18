/*
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].*/


class Solution {
public:
    void reverse(vector<int> &temp)
    {
        int l=0;
        int h=temp.size()-1;
        while(l<h)
        {
            swap(temp[l],temp[h]);
            l++;
            h--;
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n=A.size();
        int m=A[0].size();
        for(int i=0;i<n;i++)
        {
            reverse(A[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                A[i][j]=1-A[i][j];
            }
        }
        
        return A;
        
    }
};