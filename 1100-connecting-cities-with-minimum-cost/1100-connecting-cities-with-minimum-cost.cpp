class Solution {
public:
    static bool compare(vector<int> &con1, vector<int> &con2){
        return con1[2] < con2[2];
    }

    int findUPar(int node, vector<int> &uPar){
        if(uPar[node] == node) return node;

        return uPar[node] = findUPar(uPar[node], uPar);
    }

    void unionBySize(int node1, int node2, vector<int> &uPar, vector<int> &sizeVec){
        if(sizeVec[node1] >= sizeVec[node2]){
            uPar[node2] = node1;
            sizeVec[node1] += sizeVec[node2];
        } 
        else{
            uPar[node1] = node2;
            sizeVec[node2] += sizeVec[node1];
        }
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), compare);
        vector<int> uPar(n+1);
        vector<int> sizeVec(n+1, 1);

        for(int i=0; i<=n; i++){
            uPar[i] = i;
        }
        
        int pathLen = 0;
        int minCost = 0;

        for(auto &con: connections){
            int uParCity1 = findUPar(con[0], uPar);
            int uParCity2 = findUPar(con[1], uPar);

            if(uParCity1 != uParCity2){
                unionBySize(uParCity1, uParCity2, uPar, sizeVec);
                pathLen++;
                minCost += con[2];
                if(pathLen == n-1) break;
            }
        }

        if(pathLen != n-1) return -1;

        return minCost;
    }
};