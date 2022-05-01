class Solution {
public:
    //Approach
    //Logic is that we can swap more pairs of nodes than what is mentioned as "pairs" in input parameter
    //ques is how?
    //Basically if 0 can be swapped with 2 and 2 can be swapped with 4, then 0 can also be swapped with 4
    //Like this first we are going to create an adj list which will save what nodes are coonected to each other
    //in a way that they can be swapped even though they are not explicitly mentioned in the input parameter
    
    
    //After creating the list, we are going to start from one node.. and gonna apply dfs
    //now when applying dfs we are getting all the nodes which can be considered in one group and they can be swapped with one
    //another
    
    
    //so we will keep pushing this "one group" of value and corrosponding index in the two differnt arrays
    //Now we can sort them independently... so we will have indexex as well and string in sorted order
    //Now we can put that particular character on that particular index..
    //and we will repeat this for all the components.. and we are done!
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        
        vector<int> vis(n, 0);
        vector<int> index; vector<int> chr;
        
        vector<int> adj[n];
        
        for(int i=0; i<pairs.size(); i++){
            adj[pairs[i][0]].push_back(pairs[i][1]); 
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                // vis[i] = 1;
                dfs(adj, s, vis, index, chr, i);
                
                sort(index.begin(), index.end());
                sort(chr.begin(), chr.end());
                
                for(int it=0; it<index.size(); it++){
                    s[index[it]] = chr[it];
                }
                
                index.clear(); chr.clear();
            }
        }
        
        
        return s;
    }
    
    
    void dfs(vector<int> adj[], string &s, vector<int> &vis, vector<int> &index, vector<int> &chr, int curNode){
        if(!vis[curNode]){
            vis[curNode] = 1;
            index.push_back(curNode); chr.push_back(s[curNode]);
            
            for(auto &node: adj[curNode]){
                dfs(adj, s, vis, index, chr, node);
            }   
        }
    }
};