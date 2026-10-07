#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *back;

    node(int data, node *next, node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }
    node(int data)
    {
        this->data = data;
        next = nullptr;
        back = nullptr;
    }
};

node *convert2ll(vector<int> &arr)
{
    node *head = new node(arr[0]); // keeping head as the first node element .
    node *prev = head;             // setting the prev as head .
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr, prev); // suppose {12,5,8,7} now we have created 12 as a node with nullptr as next and back as prev which will connect it to prev which is 12 now we create node 5
        prev->next = temp;                            // the 12 which is prev will be connected to 5 now , we can also write temp->back = prev; if we create a constructor for arr[i] only
        prev = temp;                                  // now we will shift the prev to 5 now such that when we create 8 ,5 will be prev .
    }
    return head;
}
void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    vector<int> arr = {12, 5, 8, 7};
    node *head = convert2ll(arr);
    print(head);
    return 0;
}