#include <iostream>
#include <vector>

std::vector<int> sorted(std::vector<int> vec)
{
    int target_num = (int)((vec.size()/2)) > 5 ? 5 : (int)((vec.size()/2)) * 2 + 1;
    std::vector<int> res(vec.size(), 0);
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

    for(int i = idx.size()-1; i >= 0; i--)
    {
        vec.erase(vec.begin()+idx[i]);
    }

    count = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        res[i+count] = vec[i];
        if(i < idx.size())
            count += 1;
    }
    return res;
}

int main()
{
    std::vector<int> vec = {2,4,6,8,10,1,3,5,7,9};
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
