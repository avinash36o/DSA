/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }

    Node* helper(vector<vector<int>>& grid, int r, int c, int n) {
        // Check if all elements are the same
        bool same = true;

        for (int i = r; i < r + n; i++) {
            for (int j = c; j < c + n; j++) {
                if (grid[i][j] != grid[r][c]) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        // If all elements are the same, create a leaf node
        if (same) {
            return new Node(grid[r][c], true);
        }

        // Divide the grid into four parts
        Node* root = new Node(true, false);
        int half = n / 2;

        root->topLeft = helper(grid, r, c, half);
        root->topRight = helper(grid, r, c + half, half);
        root->bottomLeft = helper(grid, r + half, c, half);
        root->bottomRight = helper(grid, r + half, c + half, half);

        return root;
    }
};
