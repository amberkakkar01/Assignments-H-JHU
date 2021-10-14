class Solution {
public:
    int numTrees(int n) {
        if (n == 0 or n == 1)
            return 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = numTrees(i - 1);
            int y = numTrees(n - i);
            ans += (x * y);
        }
        return ans;

    }
};

class Solution {
public:
    int numTreeshelper(int n, vector<int>&dp)
    {
        if (n == 0 or n == 1)
            return 1;
        if (dp[n] != 0)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = numTreeshelper(i - 1, dp);
            int y = numTreeshelper(n - i, dp);
            ans += (x * y);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        return numTreeshelper(n, dp);

    }
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            int ans = 0;
            for (int j = 1; j <= i; j++)
            {
                int x = dp[j - 1];
                int y = dp[i - j];
                ans += (x * y);
            }
            dp[i] = ans;
        }

        return dp[n];
    }
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= i; j++)
            {
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }

        return dp[n];
    }
};