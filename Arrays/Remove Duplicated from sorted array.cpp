#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int writeIndex = 1;
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[writeIndex++] = nums[i];
        }
    }
    return writeIndex;
}

int main()
{
    std::vector<int> nums = {1, 2, 2, 0, 0, 2, 7, 6};
    int newLength = removeDuplicates(nums);
    for (int i = 0; i < newLength; ++i)
    {
        std::cout << nums[i] << " ";
    }
    return 0;
}