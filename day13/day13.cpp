/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 
*/

class Solution {
    public Node connect(Node root) {
        Node levelStart=root;
        while(levelStart!=null)
        {
            Node temp=levelStart;
            while(temp!=null)
            {
                if(temp.left!=null)
                    temp.left.next=temp.right;
                if(temp.right!=null && temp.next!=null)
                    temp.right.next=temp.next.left;
                temp=temp.next;
            }
            levelStart=levelStart.left;
        }
        return root;
    }
}