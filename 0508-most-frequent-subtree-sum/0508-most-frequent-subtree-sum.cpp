class Solution {
// I have to create an unordered map to store sum and their freq
unordered_map<int, int> mp;
private:
    int rec(TreeNode* root) {
        int sum = 0, lsum = 0, rsum = 0;

        if(root->left) lsum = rec(root->left);
        if(root->right) rsum = rec(root->right);

        sum = lsum + rsum + root->val;
        mp[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        rec(root);
        priority_queue<pair<int, int>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }

        int mostFreq = pq.top().first;
        int freqSum = pq.top().second;
        pq.pop();
        ans.push_back(freqSum);
        while(!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            int currFreq = ele.first;
            int currEle = ele.second;
            if(mostFreq > currFreq) break;
            if(mostFreq == currFreq) ans.push_back(currEle);
        }
        return ans;
    }
};