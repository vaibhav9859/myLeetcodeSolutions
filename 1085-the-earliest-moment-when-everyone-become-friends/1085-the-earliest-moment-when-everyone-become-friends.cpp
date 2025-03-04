class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int sz = logs.size();
        vector<int> par(n, 0);
        for(int i=0; i<n; i++) par[i] = i;

        vector<int> sizeUnion(n, 1);
        sort(logs.begin(), logs.end());

        for(int i=0; i<sz; i++){
            int node1 = logs[i][1], node2 = logs[i][2];
            unionFunc(node1, node2, par, sizeUnion);

            int pNode1 = findUPar(node1, par);
            int pNode2 = findUPar(node2, par);

            if(sizeUnion[pNode1] == n or sizeUnion[pNode2] == n){
                return logs[i][0];
            }
        }

        return -1;
    }

    int findUPar(int node, vector<int> &par){
        
        if(par[node] != node){
            par[node] = findUPar(par[node], par);
        }

        return par[node];
    }

    void unionFunc(int node1, int node2, vector<int> &par, vector<int> &sizeUnion){
        int pNode1 = findUPar(node1, par);
        int pNode2 = findUPar(node2, par);

        // if both are in same component
        if(pNode1 == pNode2) return;

        if(sizeUnion[pNode1] >= sizeUnion[pNode2]){
            // Connection pnode2 to pnode1
            sizeUnion[pNode1] += sizeUnion[pNode2];
            par[pNode2] = pNode1;
        }
        else if(sizeUnion[pNode1] < sizeUnion[pNode2]){
            // connet pnode1 to pnode2
            sizeUnion[pNode2] += sizeUnion[pNode1];
            par[pNode1] = pNode2;
        }
    }
};