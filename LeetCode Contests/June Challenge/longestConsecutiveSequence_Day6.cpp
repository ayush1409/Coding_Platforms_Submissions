class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> nmap;
        int ans = 0;
        vector<int> seen(nums.size());
        for (int i = 0; i < nums.size(); i++)
            if (nmap.find(nums[i]) == nmap.end())
                nmap[nums[i]] = i;
        for (auto& n : nums) {
            int curr = n, count = 1;
            if (seen[nmap[curr]]) continue;
            while (nmap.find(curr+1) != nmap.end()) {
                int ix = nmap[++curr];
                if (seen[ix]) {
                    count += seen[ix];
                    break;
                } else seen[ix] = 1, count++;
            }
            seen[nmap[n]] = count;
            ans = max(ans, count);
        }
        return ans;
    }
};