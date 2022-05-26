class Solution {
public:
static bool comp(vector<int> &a, vector<int> &b)
{
    if(a[0]==b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

int binSearch(vector<int>& lis, int target)
{
    int l = 0;
    int r = lis.size();
    
    int idx = -1;
    while(l<=r)
    {
        int mid = l + (r - l)/2;
        if(lis[mid] < target)
        {
            idx = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return idx;
    
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
 
    if(envelopes.size()==0)
        return 0;
    if(envelopes.size() == 1)
        return 1;
    
    sort(envelopes.begin(), envelopes.end(), comp);
    vector<int> lis(envelopes.size(), INT_MAX);
    lis[0] = envelopes[0][1];
    
    int max = 1;
    for(int i=1; i<envelopes.size(); i++)
    {
        int idx = binSearch(lis, envelopes[i][1]);
        lis[idx + 1] = envelopes[i][1];
        if((idx + 2) > max)
            max = idx + 2;
    }
    return max;
}

};