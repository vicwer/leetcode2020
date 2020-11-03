class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return std::max(nums[0], nums[1]);
        
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > a)
            {
                c = b;
                b = a;
                a = nums[i];
            }
            else if(nums[i] == a)
            {
                continue;
            }
            else if(nums[i] > b)
            {
                c = b;
                b = nums[i];
            }
            else if(b == nums[i])
            {
                continue;
            }
            else if(nums[i] > c)
            {
                c = nums[i];
            }
        }

        if(b == LONG_MIN || c == LONG_MIN) return a;
        return c;
    }
};
