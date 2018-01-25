//
// Created by Anshul jain on 1/25/2018.
//

#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector <int> maxSubarray(vector <int> arr) {

    vector<int> maxSum = {0, 0};

    int maxValue = INT_MIN;
    int max_current = 0;
    maxSum[0] = INT_MIN;

    for(int i = 0; i < arr.size(); i++)
    {
        max_current += arr[i];

        if(max_current > maxSum[0])
            maxSum[0] = max_current;

        if(max_current < 0)
            max_current = 0;

        if(arr[i] > 0)
            maxSum[1] += arr[i];
        else
            maxValue = max(maxValue, arr[i]);
    }

    if(maxSum[1] == 0)
    {
        maxSum[0] = maxSum[1] = maxValue;
        return maxSum;
    }
    return maxSum;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
            cin >> arr[arr_i];
        }
        vector <int> result = maxSubarray(arr);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i != result.size() - 1 ? " " : "");
        }
        cout << endl;


    }
    return 0;
}
