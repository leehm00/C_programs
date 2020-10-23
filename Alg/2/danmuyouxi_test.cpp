#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i=0; i<n; i++) cin >> arr[i];
    int min = INT_MAX, max = INT_MIN;
    for (int num : arr)
    {
        min = min < num ? min : num;
        max = max > num ? max : num;
    }
    if (min == max)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<bool> flag(n+1, false);
    vector<int> mins(n+1, INT_MAX);
    vector<int> maxs(n+1, INT_MIN);
    for (int i=0; i<n; i++)
    {
        int mid = (int)((long)arr[i] - (long)min)*(long)n / ((long)max - (long)min);
        mins[mid] = flag[mid] ? (arr[i] < mins[mid] ? arr[i] : mins[mid]) : arr[i];
        maxs[mid] = flag[mid] ? (arr[i] > maxs[mid] ? arr[i] : maxs[mid]) : arr[i];
        flag[mid] = true;
    }
    int res = 0;
    int lastLargest = maxs[0];
    for (int i=1; i<=n; i++)
    {
        if (flag[i])
        {
            res = res > mins[i] - lastLargest ? res : mins[i] - lastLargest;
            lastLargest = maxs[i];
        }
    }
    cout << res << endl;
    return 0;
}