#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	void solve(vector<int>nums, int l, int r, vector<int> &pre)
	{
		if (l > r)
			return ;
		int mid = (l + r) / 2;
		pre.push_back(nums[mid]);
		solve(nums, l, mid - 1, pre);
		solve(nums, mid + 1, r, pre);
	}
	vector<int> sortedArrayToBST(vector<int>& nums) {
		vector<int> pre;
		solve(nums, 0, nums.size() - 1, pre);
		return pre;

	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for (auto i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends