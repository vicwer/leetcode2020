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
        if(vec[i] % 2 == 0 && count < target_num && i >= count)
        {
            res[count] = vec[i];
            count += 2;
            continue;
        }
        idx.push_back(i);
    }

    count = 0;
    for(int i = 0; i < idx.size(); i++)
    {
        if(res[count] == INT_MAX)
            res[count++] = vec[idx[i]];
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
