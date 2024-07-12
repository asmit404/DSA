#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

// O(nlogn) approach
int findSecondLargestNLogN(const std::vector<int> &arr)
{
    if (arr.size() < 2)
    {
        return -1; // Not enough elements
    }
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());
    for (int i = sortedArr.size() - 2; i >= 0; --i)
    {
        if (sortedArr[i] != sortedArr.back())
        {
            return sortedArr[i];
        }
    }
    return -1; // All elements are the same
}

// O(n) approach with two passes
int findSecondLargestTwoPass(const std::vector<int> &arr)
{
    if (arr.size() < 2)
    {
        return -1; // Not enough elements
    }
    int first = INT_MIN;
    for (int num : arr)
    {
        if (num > first)
        {
            first = num;
        }
    }
    int second = INT_MIN;
    for (int num : arr)
    {
        if (num > second && num < first)
        {
            second = num;
        }
    }
    return (second == INT_MIN) ? -1 : second; // Check if second largest exists
}

// O(n) approach with single pass
int findSecondLargestSinglePass(const std::vector<int> &arr)
{
    if (arr.size() < 2)
    {
        return -1; // Not enough elements
    }
    int first = INT_MIN, second = INT_MIN;
    for (int num : arr)
    {
        if (num > first)
        {
            second = first;
            first = num;
        }
        else if (num > second && num < first)
        {
            second = num;
        }
    }
    return (second == INT_MIN) ? -1 : second; // Check if second largest exists
}

int main()
{
    std::vector<int> arr = {1, 2, 2, 0, 0, 2, 7, 6};

    int secondLargestNLogN = findSecondLargestNLogN(arr);
    if (secondLargestNLogN != -1)
    {
        std::cout << "Second largest element (O(nlogn)): " << secondLargestNLogN << std::endl;
    }
    else
    {
        std::cout << "No second largest element found (O(nlogn))" << std::endl;
    }

    int secondLargestTwoPass = findSecondLargestTwoPass(arr);
    if (secondLargestTwoPass != -1)
    {
        std::cout << "Second largest element (O(n) two passes): " << secondLargestTwoPass << std::endl;
    }
    else
    {
        std::cout << "No second largest element found (O(n) two passes)" << std::endl;
    }

    int secondLargestSinglePass = findSecondLargestSinglePass(arr);
    if (secondLargestSinglePass != -1)
    {
        std::cout << "Second largest element (O(n) single pass): " << secondLargestSinglePass << std::endl;
    }
    else
    {
        std::cout << "No second largest element found (O(n) single pass)" << std::endl;
    }

    return 0;
}