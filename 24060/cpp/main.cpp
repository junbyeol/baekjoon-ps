#include <iostream>
using namespace std;

void merge_sort(int *arr, int left, int right, int *pntr);
void merge(int *arr, int left, int mid, int right, int *pntr);

int captured = -1;

int main()
{
    int N, K;
    int arr[500000];
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int *pntr = &K;

    merge_sort(arr, 0, N - 1, pntr);

    cout << captured;

    return 0;
}

void merge_sort(int *arr, int left, int right, int *pntr)
{
    // cout << left << " " << right << " " << *pntr << endl;
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid, pntr);
        merge_sort(arr, mid + 1, right, pntr);
        merge(arr, left, mid, right, pntr);
    }
}

void merge(int *arr, int left, int mid, int right, int *pntr)
{
    int i = left, j = mid + 1, t = 0;
    int tmp[500000];
    while (i <= mid && j <= right)
        tmp[t++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

    while (i <= mid)
        tmp[t++] = arr[i++];

    while (j <= right)
        tmp[t++] = arr[j++];

    int arr_i = left, tmp_i = 0;
    while (arr_i <= right)
    {
        *pntr -= 1;
        if (*pntr == 0)
            captured = tmp[tmp_i];
        arr[arr_i++] = tmp[tmp_i++];
    }
}