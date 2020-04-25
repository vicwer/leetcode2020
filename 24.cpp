#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

template <typename T>
struct ListNode
{
    T val;
    ListNode* next;
    ListNode(T x) : val(x), next(NULL) {};
};

template <typename T>
class LinkNode {
public:
    T val;
    LinkNode* next;

    LinkNode(T x) : val(x), next(NULL) {};
};

template <typename T>
LinkNode<T>* rev(LinkNode<T>* head)
{
    if(!head)
    {
        return head;
    }
    LinkNode<T>* pre = NULL;
    LinkNode<T>* cnt = head;
    while(head->next)
    {
        head = head->next;
        cnt->next = pre;
        pre = cnt;
        cnt = head;
    }
    cnt->next = pre;

    return cnt;
}

template <typename T>
void print(std::string s, LinkNode<T>* head)
{
    LinkNode<T>* print_head = head;
    std::cout << s;
    while(print_head)
    {
        std::cout << print_head->val << " ";
        print_head = print_head->next;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::vector<int> > test_cases = {{}, {1}, {1,2, 3, 4}};
    for(auto test_case : test_cases)
    {
        LinkNode<int>* node = new LinkNode<int>(0);
        LinkNode<int>* head = node;
        for(int i = 0; i < test_case.size(); i++)
        {
            LinkNode<int>* node_tmp = new LinkNode<int>(test_case[i]);
            node -> next = node_tmp;
            node = node_tmp;
        }

        print("input:", head->next);
        LinkNode<int>* res =  rev(head->next);
        print("output:", res);
    }

    return 0;
}