// Peak finding in 1D and 2D arrays
#include <iostream>
using namespace std;

// Take middle element and check left/right
int peak1D(int arr[], int left, int right)
{
    // when only 1 element remain
    if(left == right) return arr[left];
    // when only 2 elements remain
    if(right - left == 1)
    {
        if (arr[left] >= arr[right]) return arr[left];
        else return arr[right];
    }
    int middleIndex = (left + right) / 2;
    // middle value higher than left and right
    if (arr[middleIndex] >= arr[middleIndex-1] && arr[middleIndex] >= arr[middleIndex+1]) return arr[middleIndex];
    // left value higher
    else if (arr[middleIndex] < arr[middleIndex-1]) return peak1D(arr, left, middleIndex-1);
    else return peak1D(arr, middleIndex+1, right);
}

int main()
{
    int arr[] = {1, 1, 3};

    cout << "Peak: " << peak1D(arr, 0, sizeof(arr)/sizeof(int) - 1) << endl;

    return 0;
}