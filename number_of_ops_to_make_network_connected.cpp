#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // DSU (Disjoint Set Union) class to manage connected components
    class DSU {
        vector<int> parent;
        int components;

    public:
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0); // Initialize parent of each node to itself
            components = n;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]); // Path compression
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY; // Union
                components--; // Decrease component count when two sets merge
            }
        }

        int getComponents() {
            return components;
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        // If there are fewer cables than n-1, it's impossible to connect all n computers
        if (connections.size() < n - 1) return -1;

        DSU dsu(n);
        for (const auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }

        // To connect k components, we need k-1 cables.
        // We already checked if we have enough total cables.
        // The number of operations needed is simply the number of components - 1.
        return dsu.getComponents() - 1;
    }
};
