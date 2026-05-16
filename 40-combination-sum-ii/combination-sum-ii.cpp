class Solution {
public:
    void func(int i,int target,vector<int>& candidates,vector<vector<int>> &ans,vector<int> &temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[j]);
            func(j+1,target-candidates[j],candidates,ans,temp);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(0,target,candidates,ans,temp);
        return ans;
        
    }
};