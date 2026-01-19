
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Global counters
long long operationCount = 0;
int maxDepth = 0;

void complexRec(int n, int depth) {
    // Track max recursion depth
    if (depth > maxDepth) maxDepth = depth;

    if (n <= 2) {
        return;
    }

    // Count operations in the while loop
    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operationCount++; // Count each assignment as an operation
        }
        p >>= 1;
        operationCount++; // Count each shift as an operation
    }

    // Count operations in the for loop
    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operationCount++;
    }

    // Count reverse as n operations
    reverse(small.begin(), small.end());
    operationCount += n;

    // Three recursive calls
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}
// T(n)=3T(n/2)+O(n)    recurrence relation
int main() {
    vector<int> testSizes = {8};
    for (int n : testSizes) {
        operationCount = 0;
        maxDepth = 0;
        auto start = high_resolution_clock::now();
        complexRec(n, 1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "n = " << n;
        cout<< ", Operations = " << operationCount;
        cout<< ", Max Depth = " << maxDepth;
        cout<< ", Time = " << duration.count() << " ms" << endl;
    }
    return 0;
}