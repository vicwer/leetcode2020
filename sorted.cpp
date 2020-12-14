#include <iostream>
#include <vector>
#include <limits.h>

std::vector<int> sorted(std::vector<int> vec)
{
    int target_num = (int)(vec.size()/2) > 5 ? 11 : (int)(vec.size()/2) * 2 + 1;
    std::vector<int> res(vec.size(), INT_MAX);
    int count = 1;
    std::vector<int> idx;
    for(int i = 0; i < vec.size(); i++)
    {
        if(count < target_num)
        {
            if(vec[i] % 2 == 0)
            {
                if(i < count)
                    continue;
                res[count] = vec[i];
                idx.push_back(i);
                count += 2;
            }
        }
        else
        {
            break;
        }
    }

    count = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        int flag = 0;
        for(int j = 0; j < idx.size(); j++)
        {
            if(i == idx[j])
            {
                flag = 1;
            }
        }
        if(flag)
            continue;
        
        if(res[count] == INT_MAX)
            res[count++] = vec[i];
        else
        {
            i--;
            count++;
        }
    }
    return res;
}

int main()
{
    std::vector<int> vec = {2,4,11,13,6,8,10,1,3,5,7,9};
    for(int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::vector<int> res = sorted(vec);
    for(int i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
