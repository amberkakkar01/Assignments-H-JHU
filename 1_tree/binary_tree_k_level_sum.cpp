//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*
Just keep track of the levels. You dont actually need to construct a tree.
Maintain a level count, on encountering any '(' increment the level and
similarly on encountering any ')' decrement the current level. Whenever you
encounter an integer, that integer will belong to the level stored by the
level counter at that point. Make a map to keep track of the same.
*/

class Solution {
public:
    int kLevelSum(int K, string S) {
        // code here
        int lvl = -1, res = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (isdigit(S[i]))
            {
                if (lvl == K)
                {
                    int num = 0;
                    while (i < S.size())
                    {
                        if (S[i] == ')' or S[i] == '(')
                        {
                            i--;
                            break;
                        }

                        num = num * 10 + (S[i] - '0');
                        i++;
                    }
                    res += num;
                }
            }
            else if (S[i] == '(')
                lvl++;
            else
                lvl--;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin >> K;
        cin >> S;

        Solution ob;
        cout << ob.kLevelSum(K, S) << endl;
    }
    return 0;
}  // } Driver Code Ends