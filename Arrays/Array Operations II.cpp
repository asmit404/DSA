#include <iostream>
#include <vector>
#include <algorithm>

// Function to print an array
void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Sorting function
void sortArray(std::vector<int> &arr, bool ascending = true)
{
    if (ascending)
    {
        std::sort(arr.begin(), arr.end());
    }
    else
    {
        std::sort(arr.rbegin(), arr.rend());
    }
}

// Merging function
std::vector<int> mergeArrays(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
    std::vector<int> merged(arr1.size() + arr2.size());
    std::merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), merged.begin());
    return merged;
}

// Splitting function
std::pair<std::vector<int>, std::vector<int>> splitArray(const std::vector<int> &arr)
{
    std::vector<int> subArray1(arr.begin(), arr.begin() + arr.size() / 2);
    std::vector<int> subArray2(arr.begin() + arr.size() / 2, arr.end());
    return {subArray1, subArray2};
}

// Resizing function
void resizeArray(std::vector<int> &arr, size_t newSize, int defaultValue = 0)
{
    arr.resize(newSize, defaultValue);
}

// Reversing function
void reverseArray(std::vector<int> &arr)
{
    std::reverse(arr.begin(), arr.end());
}

// Finding Minimum/Maximum function
std::pair<int, int> findMinMax(const std::vector<int> &arr)
{
    auto minElement = std::min_element(arr.begin(), arr.end());
    auto maxElement = std::max_element(arr.begin(), arr.end());
    return {*minElement, *maxElement};
}

int main()
{
    // Example array
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};

    // Sorting
    sortArray(arr); // Ascending
    std::cout << "Sorted array (ascending): ";
    printArray(arr);

    sortArray(arr, false); // Descending
    std::cout << "Sorted array (descending): ";
    printArray(arr);

    // Merging
    std::vector<int> arr1 = {1, 3, 5};
    std::vector<int> arr2 = {2, 4, 6};
    std::vector<int> merged = mergeArrays(arr1, arr2);
    std::cout << "Merged array: ";
    printArray(merged);

    // Splitting
    auto [subArray1, subArray2] = splitArray(arr);
    std::cout << "First half: ";
    printArray(subArray1);
    std::cout << "Second half: ";
    printArray(subArray2);

    // Resizing
    resizeArray(arr, 10, 0); // Resize to 10 elements, new elements initialized to 0
    std::cout << "Resized array: ";
    printArray(arr);

    // Reversing
    reverseArray(arr);
    std::cout << "Reversed array: ";
    printArray(arr);

    // Finding Minimum/Maximum
    auto [minElement, maxElement] = findMinMax(arr);
    std::cout << "Minimum element: " << minElement << std::endl;
    std::cout << "Maximum element: " << maxElement << std::endl;

    return 0;
}