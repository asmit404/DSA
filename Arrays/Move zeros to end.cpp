#include <iostream>
#include <vector>

// Maintain the relative order of non-zero elements
void moveZerosToEnd(std::vector<int> &nums)
{
    int writeIndex = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            nums[writeIndex++] = nums[i];
        }
    }
    for (int i = writeIndex; i < nums.size(); ++i)
    {
        nums[i] = 0;
    }
}

int main()
{
    std::vector<int> nums = {1, 2, 2, 0, 0, 2, 7, 6};
    moveZerosToEnd(nums);
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    return 0;
}