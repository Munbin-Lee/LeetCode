class Solution {
public:
    vector<int> parents;
    vector<vector<int>> indegrees;

    int find(int x) {
        if (x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a > b) swap(a, b);
        parents[a] = b;
    }

    bool isCycle(int cur, int target, bool first) {
        if (!first && cur == target) return true;

        for (int indegree : indegrees[cur]) {
            if (isCycle(indegree, target, false)) return true;
        }

        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parents.resize(n + 1);
        iota(parents.begin(), parents.end(), 0);
        indegrees.resize(n + 1);

        int doubleIndegree = -1;
        vector<int> cycle;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            indegrees[v].emplace_back(u);

            if (indegrees[v].size() == 2) {
                doubleIndegree = v;
            }

            if (find(u) == find(v)) {
                cycle = {u, v};
            } else {
                merge(u, v);
            }
        }

        if (doubleIndegree == -1) return cycle;

        int a = indegrees[doubleIndegree][0];
        int b = indegrees[doubleIndegree][1];

        if (cycle.empty()) return {b, doubleIndegree};

        for (int i : {b, a}) {
            if (isCycle(i, doubleIndegree, true)) return {i, doubleIndegree};
        }

        return {b, doubleIndegree};
    }
};