class Solution {
// I have to create an unordered map to store sum and their freq
unordered_map<int, int> mp;
private:
    int rec(TreeNode* root, int &high) {
        int sum = 0, lsum = 0, rsum = 0;

        if(root->left) lsum = rec(root->left, high);
        if(root->right) rsum = rec(root->right, high);

        sum = lsum + rsum + root->val;
        mp[sum]++;
        high = max(high, mp[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int high = 0;
        rec(root, high);
        // cout << high ;
        // priority_queue<pair<int, int>> pq;
        // for(auto it: mp) {
        //     pq.push({it.second, it.first});
        // }

        // int mostFreq = pq.top().first;
        // int freqSum = pq.top().second;
        // pq.pop();
        // ans.push_back(freqSum);
        // while(!pq.empty()) {
        //     auto ele = pq.top();
        //     pq.pop();
        //     int currFreq = ele.first;
        //     int currEle = ele.second;
        //     if(mostFreq > currFreq) break;
        //     if(mostFreq == currFreq) ans.push_back(currEle);
        // }

        for(auto it: mp) {
            if(it.second == high) ans.push_back(it.first);
        }
        return ans;
    }
};