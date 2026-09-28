#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};
// the whole code is to find the location of any vector element.
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    node *head = new node(arr[0]);
    cout << head;

    return 0;
}