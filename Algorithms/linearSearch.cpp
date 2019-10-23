#include <iostream>
using namespace std;
int LinearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << i;
        }
    }
}
int main()
{
    int i, n, x, arr[100];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    LinearSearch(arr, n, x);
}