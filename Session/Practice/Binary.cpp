#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr1 = {3, 2, 1, 4, 6}; // sorted after apply sort algo
    vector<int> arr2 = {3, 4, 5, 1, 1};
    sort(arr1.begin(), arr1.end());
    int find;
    cin >> find;

    int count;
    for (int i = 0; i < arr2.size(); i++)
    {
        int tar = find - arr2[i];
        int l = 0;
        int r = arr1.size();
        
        while (l <= r)
        {

            int mid = l + (r - l) / 2;
            if(arr1[mid]>=tar)
            {

            }
            if (arr1[mid] == tar)
            {
                return 1;
            }
            if (arr1[mid] < find)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }

    return 0;
}