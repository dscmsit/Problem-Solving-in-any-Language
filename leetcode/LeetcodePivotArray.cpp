class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {
    int leftSum = 0, rightSum = 0, n = nums.size();
    for (int i = 1; i < n; i++)
      rightSum += nums[i];
    for (int i = 0; i < n; i++)
    {
      if (leftSum == rightSum)
        return i;
      if (i < n - 1)
        leftSum += nums[i + 1];
      rightSum -= nums[i];
    }
    return -1;
  }
};