class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        vector<vector<int>> cnt(n, vector<int>(26));
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        int processed = 0;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            processed++;
            cnt[f][colors[f] - 'a']++;
            ans = max(ans, cnt[f][colors[f] - 'a']);
            for (auto nbr : graph[f]) {
                indegree[nbr]--;
                if (!indegree[nbr]) {
                    q.push(nbr);
                }
                for (int j = 0; j < 26; j++) {
                    cnt[nbr][j] = max(cnt[nbr][j], cnt[f][j]);
                }
            }
        }
        return (processed == n)? ans : -1;
    }
};