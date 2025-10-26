#include <bits/stdc++.h>

using namespace std;

bool check(const vector<int>& arr, int setSize, int distance)
{
    int count = 1, curr = arr[0];
    for (int i = 1; i < arr.size(); i++) if (arr[i] >= curr + distance)
    {
        if (count == setSize) return true;

        count++;
        curr = arr[i];
    }

    return count == setSize;
}

int binaryDistanceSearch(const vector<int>& arr, int setSize, int low, int high)
{
    if (high < low) return -1;

    int mid = (low + high) / 2;

    int best = -1;
    if (check(arr, setSize, mid))
    {
        best = mid;
        
        int tmp = binaryDistanceSearch(arr, setSize, mid + 1, high);

        if (tmp == -1) return best;

        return tmp;
    }

    return binaryDistanceSearch(arr, setSize, low, mid - 1);
}

int main() 
{
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int seqSize, setSize;
        cin >> seqSize >> setSize;

        vector<int> arr(seqSize);
        for (int i = 0; i < seqSize; i++) cin >> arr[i];

        if (setSize == 1) 
        {
           cout << 1 << '\n';
           continue;
        }

        sort(arr.begin(), arr.end());

        if (setSize == 2)
        {
            cout << 2 << '\n';
            continue;
        }

        int max = (arr[seqSize - 1] - arr[0]) / 2;

        cout << binaryDistanceSearch(arr, setSize, 0, max) << '\n';
    }

    return 0;
}
