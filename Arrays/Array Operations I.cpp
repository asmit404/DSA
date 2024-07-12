#include <iostream>
#include <vector>

// Function to traverse the array
void traverseArray(const std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to access an element at a specific index
int accessElement(const std::vector<int> &arr, int index)
{
    if (index >= 0 && index < arr.size())
    {
        return arr[index];
    }
    else
    {
        std::cerr << "Index out of bounds" << std::endl;
        return -1; // Return an invalid value to indicate error
    }
}

// Function to search for an element in the array
int searchElement(const std::vector<int> &arr, int element)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == element)
        {
            return i; // Return the index of the element
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to insert an element at a specific position
void insertElement(std::vector<int> &arr, int element, int position)
{
    if (position >= 0 && position <= arr.size())
    {
        arr.insert(arr.begin() + position, element);
    }
    else
    {
        std::cerr << "Position out of bounds" << std::endl;
    }
}

// Function to delete an element at a specific position
void deleteElement(std::vector<int> &arr, int position)
{
    if (position >= 0 && position < arr.size())
    {
        arr.erase(arr.begin() + position);
    }
    else
    {
        std::cerr << "Position out of bounds" << std::endl;
    }
}

// Function to update an element at a specific index
void updateElement(std::vector<int> &arr, int index, int newValue)
{
    if (index >= 0 && index < arr.size())
    {
        arr[index] = newValue;
    }
    else
    {
        std::cerr << "Index out of bounds" << std::endl;
    }
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    // Traversal
    std::cout << "Array elements: ";
    traverseArray(arr);

    // Access
    int index = 2;
    std::cout << "Element at index " << index << ": " << accessElement(arr, index) << std::endl;

    // Search
    int element = 3;
    int foundIndex = searchElement(arr, element);
    if (foundIndex != -1)
    {
        std::cout << "Element " << element << " found at index " << foundIndex << std::endl;
    }
    else
    {
        std::cout << "Element " << element << " not found" << std::endl;
    }

    // Insertion
    int newElement = 6;
    int position = 3;
    insertElement(arr, newElement, position);
    std::cout << "Array after insertion: ";
    traverseArray(arr);

    // Deletion
    deleteElement(arr, position);
    std::cout << "Array after deletion: ";
    traverseArray(arr);

    // Update
    int newValue = 10;
    updateElement(arr, index, newValue);
    std::cout << "Array after update: ";
    traverseArray(arr);

    return 0;
}