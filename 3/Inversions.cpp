#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right, int& count)
{
    int leftSize = left.size(), rightSize = right.size();

    vector<int> merged;

    int leftCurr = 0, rightCurr = 0;
    while (leftCurr < leftSize && rightCurr < rightSize)
    {
        int curr;
        if (left[leftCurr] > right[rightCurr])
        {
            count += (leftSize - leftCurr);
            curr = right[rightCurr];

            rightCurr++;
        }
        else 
        {
            curr = left[leftCurr];
            leftCurr++;
        }

        merged.push_back(curr);
    }

    if (leftCurr < leftSize) for (int i = leftCurr; i < leftSize; i++)
        merged.push_back(left[i]); 

    if (rightCurr < rightSize) for (int i = rightCurr; i < rightSize; i++)
        merged.push_back(right[i]); 

    return merged;
}

vector<int> modifiedMergeSort(vector<int>& arr, int size, int& count)
{
    if (size <= 1) return arr;

    vector<int> left(size / 2), right(size - size / 2);

    for (int i = 0; i < size / 2; i++) left[i] = arr[i];
    for (int i = size / 2; i < size; i++) right[i - size / 2] = arr[i];

    left = modifiedMergeSort(left, size / 2, count);
    right = modifiedMergeSort(right, size - size / 2, count);

    return merge(left, right, count);
}

int main()
{
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) cin >> arr[i];

    int count = 0;
    modifiedMergeSort(arr, size, count);

    cout << count << '\n';

    return 0;
}