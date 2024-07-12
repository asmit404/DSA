#include <iostream>
#include <vector>
#include <algorithm> // For std::rotate and std::fill

// Function to traverse the array
void traverseArray(const std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to shift elements within the array by a certain number of positions
void shiftArray(std::vector<int> &arr, int positions)
{
    if (positions > 0 && positions < arr.size())
    {
        std::vector<int> temp(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            temp[(i + positions) % arr.size()] = arr[i];
        }
        arr = temp;
    }
}

// Function to rotate elements of the array by a specified number of positions
void rotateArray(std::vector<int> &arr, int positions)
{
    std::rotate(arr.begin(), arr.begin() + positions, arr.end());
}

// Function to fill the array with a specific value
void fillArray(std::vector<int> &arr, int value)
{
    std::fill(arr.begin(), arr.end(), value);
}

// Function to search for a specific pattern in the array
bool searchPattern(const std::vector<int> &arr, const std::vector<int> &pattern)
{
    for (int i = 0; i <= arr.size() - pattern.size(); i++)
    {
        bool found = true;
        for (int j = 0; j < pattern.size(); j++)
        {
            if (arr[i + j] != pattern[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Original array: ";
    traverseArray(arr);

    // Shift array by 3 positions
    shiftArray(arr, 3);
    std::cout << "Array after shifting by 3 positions: ";
    traverseArray(arr);

    // Rotate array by 2 positions
    rotateArray(arr, 2);
    std::cout << "Array after rotating by 2 positions: ";
    traverseArray(arr);

    // Fill array with value 5
    fillArray(arr, 5);
    std::cout << "Array after filling with 5: ";
    traverseArray(arr);

    // Search for a pattern {5, 5, 5}
    std::vector<int> pattern = {5, 5, 5};
    bool found = searchPattern(arr, pattern);
    std::cout << "Pattern {5, 5, 5} found: " << (found ? "Yes" : "No") << std::endl;

    return 0;
}