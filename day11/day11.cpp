/*
Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

 */
class Solution {
public:
    double distance(vector<int> &p1,vector<int> &p2)
    {
        double side12=(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]);
        return side12;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        sort(points.begin(),points.end(),[&](vector<int> &p1,vector<int> &p2)
             {
                return p2[0] == p1[0] ? p1[1] - p2[1] : p1[0] - p2[0];
             });
        double side12=distance(points[0],points[1]);
        double side14=distance(points[3],points[0]);
        
        double side23=distance(points[1],points[2]);
        double side34=distance(points[2],points[3]);
        double diag1=distance(points[0],points[2]);
        double diag2=distance(points[1],points[3]);
        if(diag1==diag2 && side12==side14 && side14==side23 && side23==side34)
            return true;
        else
            return false;
    }
};