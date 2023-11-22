class Solution {
public:
    int parents[1001];

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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        iota(parents, end(parents), 0);

        vector<int> answer;

        for (auto &edge : edges) {
            int a = edge[0], b = edge[1];

            if (find(a) == find(b)) {
                answer = {a, b};
                continue;
            }

            merge(a, b);
        }

        return answer;
    }
};