#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> firstIndex;
    int sum = 0, maxLen = 0;

    firstIndex[0] = -1;

    for (int i = 0; i < N; i++) {
        if (arr[i] == 'P')
            sum += 1;
        else
            sum -= 1;

        if (firstIndex.count(sum)) {
            maxLen = max(maxLen, i - firstIndex[sum]);
        } else {
            firstIndex[sum] = i;
        }
    }

    cout << maxLen << endl;
    return 0;
}
