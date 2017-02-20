#include<iostream>

using namespace std;

int MagicIndex(int arr[], int l, int r)
{
    if(l>r) return -1;
    int mid = l + (r-l)/2;
    if(arr[mid] == mid) return 1;
    if(arr[mid] < mid)  return MagicIndex(arr, l, arr[mid]);
    else return MagicIndex(arr, arr[mid], r);
}

int main()
{
    int arr[] = {0, 2,4,4,5,6,9,9,9};
    cout<<MagicIndex(arr, 1, 8);
    return 0;
}
