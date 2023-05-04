class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> res;
        vector<int> temp1, temp2;
        unordered_map<int, int> umap1, umap2;
        unordered_set<int> uset1, uset2;

        for(auto it : nums1)
        {
            uset1.insert(it);
        }

        for(auto it : nums2)
        {
            uset2.insert(it);
        }a

        for(auto it : uset1)
        {
            umap1[it]++;
        }

        for(auto it : uset2)
        {
            if(umap1.find(it) == umap1.end())
            {
                temp1.push_back(it);
            }
        }

        for(auto it : uset2)
        {
            umap2[it]++;
        }

        for(auto it : uset1)
        {
            if(umap2.find(it) == umap2.end())
            {
                temp2.push_back(it);
            }
        }

        res.push_back(temp2);
        res.push_back(temp1);

        return res;
    }
};
