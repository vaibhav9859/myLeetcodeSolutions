class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> par(n, -1), sizeArr(n, 1);

        for(int i=0; i<n; i++) par[i] = i;

        for(auto &edge: edges){
            unionBySize(edge[0], edge[1], par, sizeArr);
        }

        // let's put all the unique ulimate parents in a set
        unordered_set<int> uniquePar;

        for(int i=0; i<n; i++){
            uniquePar.insert(findUPar(i, par));
        }

        // let's get total number of pairs which or disconnected
        long long curTotalNodes = n;
        long long totalPairs = 0;

        for(auto &par: uniquePar){
            int curCompSize = sizeArr[par];
            totalPairs += (curCompSize) * (curTotalNodes - curCompSize);
            
            // new total nodes should be decreased by curCompSize as we have already considered it
            curTotalNodes -= curCompSize;
        }


        return totalPairs;
    }   

    int findUPar(int node, vector<int> &par){
        if(node != par[node]){
            // path compression
            par[node] = findUPar(par[node], par);
        }

        return par[node];
    }

    void unionBySize(int node1, int node2, vector<int> &par, vector<int> &sizeArr){
        int uParNode1 = findUPar(node1, par);
        int uParNode2 = findUPar(node2, par);

        if(uParNode1 == uParNode2) return;

        if(sizeArr[uParNode1] >= sizeArr[uParNode2]){
            sizeArr[uParNode1] += sizeArr[uParNode2];
            par[uParNode2] = uParNode1;
        }
        else {
            sizeArr[uParNode2] += sizeArr[uParNode1];
            par[uParNode1] = uParNode2;
        }
    }
};