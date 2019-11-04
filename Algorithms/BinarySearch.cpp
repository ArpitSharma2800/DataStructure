#include <iostream>
using namespace std;
int BinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - 1) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return BinarySearch(arr, l, mid - 1, x);
        if (arr[mid] < x)
            return BinarySearch(arr, mid + 1, r, x);
    }
    return 0;
}

int main()
{
    int arr[10], i, n, x;
    cin >> n;
    cin >> x;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BinarySearch(arr, 0, n - 1, x);
}