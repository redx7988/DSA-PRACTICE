#include <bits/stdc++.h>
using namespace std;
// the below code is for creating a array which can show first term only.
struct node
{
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

node *ll(vector<int> arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    node *head = ll(arr);
    cout << head->data;
}