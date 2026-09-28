#include <bits/stdc++.h>
using namespace std;

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
// for converting an array/vector into a linked list .
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
// to find the length of the linked list .
int lengthofll(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
// to seach a given number in a linked list .
void searchnumber(node *head, int val)
{
    node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            cout << "The given number " << val << " was found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "The given number " << val << " was not founded" << endl;
}
int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    node *head = ll(arr);
    //-------BELOW COMMAND IS FOR TRANSVERE OF LINKED LIST-------------
    node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    //-----------------------TRANSVERSE ENDS HERE----------------------
    cout << "The length of array is : " << lengthofll(head) << endl;
    searchnumber(head, 5);
    return 0;
}