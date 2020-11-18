//Question
/*A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<unordered_set<int>> adjacencylist(n);
        if(n==1)
            return {0};
       for(vector<int> itr:edges)
        {
            adjacencylist[itr[0]].insert(itr[1]);
            adjacencylist[itr[1]].insert(itr[0]);
        }
        vector<int> leaves;
        for(int i=0;i<n;i++)
        {
            if(adjacencylist[i].size()==1)
            {
                leaves.push_back(i);
            }
        }
        //1 2 5
        int remainingNodes=n; //6
        
       
        while(remainingNodes>2){
            vector<int> newleaves;
            int noofLeaves=leaves.size(); //1
            remainingNodes-=noofLeaves; //2
            for(int i=0;i<noofLeaves;i++)
            {
                int removenode=leaves[i]; //1 //2 //5
                for(auto itr: adjacencylist[removenode])
                {    
                     int x=itr;
                     adjacencylist[x].erase(removenode);
                    if(adjacencylist[x].size()==1)
                        newleaves.push_back(itr);
                }
            }
            leaves=newleaves;
        }
        return leaves;
    }
};