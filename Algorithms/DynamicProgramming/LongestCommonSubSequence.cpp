//
// Created by Anshul jain on 1/25/2018.
//
#include <bits/stdc++.h>

using namespace std;

vector <int> longestCommonSubsequence(vector <int> a, vector <int> b) {

    vector<int> sequence;
    if(a.size() == 0 || b.size() == 0)
        return sequence;

    int m = a.size();
    int n = b.size();

    int dp[m+1][n+1];
    for(int i = 0; i < m+1; i++)
        for(int j = 0; j < n+1; j++)
            dp[i][j] = 0;

    for(int i = 0; i < m+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int maxLength = dp[m][n];

    vector<int> lcs(maxLength);

    int i = m, j = n;

    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            lcs[maxLength-1] = a[i-1];
            i--; j--; maxLength--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    return lcs;

}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
        cin >> b[b_i];
    }
    vector <int> result = longestCommonSubsequence(a, b);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

