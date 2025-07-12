class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        // map: column -> list of {row, value}
        map<int, vector<pair<int, int>>> colMap;

        // queue: node -> {row, col}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front(); q.pop();
            int row = pos.first;
            int col = pos.second;

            colMap[col].emplace_back(row, node->val);

            if (node->left) q.push({node->left, {row + 1, col - 1}});
            if (node->right) q.push({node->right, {row + 1, col + 1}});
        }

        for (auto& [col, vec] : colMap) {
            sort(vec.begin(), vec.end()); // sort by row, then value
            vector<int> colValues;
            for (auto& [row, val] : vec) {
                colValues.push_back(val);
            }
            res.push_back(colValues);
        }

        return res;
    }
};
