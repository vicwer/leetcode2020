class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return {};
        }

        if(nums.size() == 1)
        {
            return {std::to_string(nums[0])};
        }

        vector<string> res;
        vector<vector<int>> res_tmp;
        vector<int> cnt_list;
        for(int i = 0; i < nums.size()-1; i++)
        {
            //std::cout << nums[i] << " " << i << std::endl;
            if(cnt_list.size() == 0)
            {
                cnt_list.push_back(nums[i]);
            }
            if(nums[i]+1 == nums[i+1])
            {
                if(cnt_list.size() == 1)
                    cnt_list.push_back(nums[i+1]);
                else
                    cnt_list[1] = nums[i+1];
            }
            else
            {
                res_tmp.push_back(cnt_list);
                cnt_list = {nums[i+1]};
                //std::cout << nums[i+1] << " " << cnt_list[0] << std::endl;
            }
        }
        res_tmp.push_back(cnt_list);

        for(int i = 0; i < res_tmp.size(); i++)
        {
            if(res_tmp[i].size() == 1)
                res.push_back(std::to_string(res_tmp[i][0]));
            else
                res.push_back(std::to_string(res_tmp[i][0])+"->"+std::to_string(res_tmp[i][1]));
        }

        return res;
    }
};
