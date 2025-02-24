class Solution {
public:
    vector<vector<int>> adjList;
    vector<int> BobMap;
    int aliceIncome;

    bool DFSbob(int curr, int t, vector<bool>& visited) {
        visited[curr] = true;
        BobMap[curr] = t;

        if (curr == 0) {
            return true; // reached target
        }

        for (auto ngbr : adjList[curr]) {
            if (!visited[ngbr]) {
                if (DFSbob(ngbr, t + 1, visited)) {
                    return true;
                }
            }
        }
        BobMap[curr] = -1; // Mark as not part of Bob's path
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
        visited[curr] = true;

        if (BobMap[curr] == -1 || t < BobMap[curr]) {
            income += amount[curr];
        } else if (t == BobMap[curr]) {
            income += (amount[curr] / 2);
        }

        // Leaf node check
        if (adjList[curr].size() == 1 && curr != 0) {
            aliceIncome = max(aliceIncome, income);
        }

        for (auto ngbr : adjList[curr]) {
            if (!visited[ngbr]) {
                DFSAlice(ngbr, t + 1, income, visited, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adjList.resize(n);
        BobMap.assign(n, -1);
        aliceIncome = INT_MIN;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);
        DFSbob(bob, 0, visited);

        visited.assign(n, false);
        DFSAlice(0, 0, 0, visited, amount);

        return aliceIncome;
    }
};
