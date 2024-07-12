#include <iostream>
#include <vector>
#include <algorithm>

// Iterative approach in O(n)
bool isSortedIterative(const std::vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Recursive approach in O(n)
bool isSortedRecursive(const std::vector<int> &arr, size_t index = 1)
{
    if (index == arr.size())
    {
        return true;
    }
    if (arr[index] < arr[index - 1])
    {
        return false;
    }
    return isSortedRecursive(arr, index + 1);
}

// Using STL in O(n)
bool isSortedSTL(const std::vector<int> &arr)
{
    return std::is_sorted(arr.begin(), arr.end());
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    // std::vector<int> arr = {1, 2, 2, 0, 0, 2, 7, 6}; // Not sorted

    if (isSortedIterative(arr))
    {
        std::cout << "Array is sorted (Iterative)" << std::endl;
    }
    else
    {
        std::cout << "Array is not sorted (Iterative)" << std::endl;
    }

    if (isSortedRecursive(arr))
    {
        std::cout << "Array is sorted (Recursive)" << std::endl;
    }
    else
    {
        std::cout << "Array is not sorted (Recursive)" << std::endl;
    }

    if (isSortedSTL(arr))
    {
        std::cout << "Array is sorted (STL)" << std::endl;
    }
    else
    {
        std::cout << "Array is not sorted (STL)" << std::endl;
    }

    return 0;
}