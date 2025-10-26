#include <bits/stdc++.h>

using namespace std;

bool compareEnds(pair<int, int>& a, pair<int, int>& b) 
{
    return a.second < b.second;
}

int main()
{
    int num;
    cin >> num;

    vector<pair<int, int>> segments(num);

    for (int i = 0; i < num; i++) cin >> segments[i].first >> segments[i].second;

    sort(segments.begin(), segments.end(), compareEnds);

    int curr = 0, count = 1;
    
    if (num == 1) cout << 1 << '\n';
    else 
    {
        for (int i = 1; i < num; i++)
        {
            if (segments[i].first > segments[curr].second)
            {
                curr = i;
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}