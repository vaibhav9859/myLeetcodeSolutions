class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int sz = fruits.size();
        int maxFruits = 0;

        while(r < sz){
            // putting current value in the map
            mp[fruits[r]]++;

            // valid mp
            if(mp.size() <= 2){
                maxFruits = max(maxFruits, r-l+1);
            }
            else {
                int typeL = fruits[l];
                mp[typeL]--;
                if(mp[typeL] == 0) mp.erase(typeL);
                l++;
            }

            r++;
        }

        return maxFruits;
    }
};