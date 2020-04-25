#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

typedef struct LinkNode
{
    int val;
    LinkNode* next;
    LinkNode(int x) : val(x), next(NULL) {};
} LinkNode;

LinkNode* rev(LinkNode* head)
{
    if(!head)
    {
        return head;
    }
    LinkNode* pre = NULL;
    LinkNode* cnt = head;
    while(head->next)
    {
        head = head->next;
        cnt->next = pre;
        pre = cnt;
        cnt = head;
    }
    cnt->next = pre;
}

void print(std::string s, LinkNode* head)
{
    LinkNode* print_head = head;
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
        LinkNode* node = new LinkNode(0);
        LinkNode* head = node;
        for(int i = 0; i < test_case.size(); i++)
        {
            LinkNode* node_tmp = new LinkNode(test_case[i]);
            node -> next = node_tmp;
            node = node_tmp;
        }

        print("input:", head->next);
        LinkNode* res =  rev(head->next);
        print("output:", res);
    }

    return 0;
}