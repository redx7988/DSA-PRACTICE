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
void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
node *convert2dll(vector<int> arr)
{
    node *head = new node(arr[0]);
    node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

node *inserthead(node *head, int val)
{
    node *newnode = new node(val, head, nullptr); // what happens here is we create a dll of val 10 then its next value is connected to head as 10 is new first value and then its back is nullptr as head node have back as nullptr .
    head->back = newnode;                         // now we will connect the back of the head to the newnode we just createdd .
    return newnode;                               // we have now connected both front and back so we just return newnode as new head;
}
node *inserttail(node *head, int val)
{
    node *temp = head;    // suppose a array {12 , 3 , 5, 8} we want to add number after 5 and before 8;
    node *prev = nullptr; // create a prev which points to nullptr for now .
    while (temp->next != nullptr)
    {
        temp = temp->next; // we will use while loop to loop till last number only which is 8
    }
    prev = temp->back;                         // prev will be temp-> back , which is 5
    node *newnode = new node(val, prev, temp); // we will create a newnode who point it next to prev(8) and back to back(5).
    prev->next = newnode;                      // now we will connect prev->next which is 5 to newnode .
    temp->back = newnode;                      // now we connect temp->back which is 8 to newnode thus making outer connections.
    newnode->back = prev;                      // to make inner connection we will connect newnode->back to the 5 as 10(the number we want to add) will come after 5.
    newnode->next = temp;                      // we will make newnode->next to the temp , temp is our last number(8).
    return head;                               // making all the connections sucessfully we will return the head.
}
node *insertk(node *head, int val, int pos)
{
    if (pos == 1)
    {
        return inserthead(head, val); // a edge case if the pos is 1 .
    }
    node *temp = head; // temp will be used to itterate through the whole dll.
    node *prev = nullptr;
    int counter = 0;
    while (temp != nullptr)
    {
        counter++;
        if (pos == counter)
        {
            node *newnode = new node(val, temp, prev); // the below lines contains the same logic as insert tail . so kindely reffer them.
            temp->back = newnode;
            prev->next = newnode;
            newnode->next = temp;
            newnode->back = prev;
        }
        prev = temp;       // we will store the temp to prev and in next step we will itterate the temp to next term thus keeping the prev always a node before temp.
        temp = temp->next; // alaways first keep the old value of temp in prev then itterate the temp to next .
    }
    return head;
}
int main()
{
    vector<int> arr = {12, 3, 5, 8};
    node *head = convert2dll(arr);
    print(head);
    head = inserthead(head, 10);
    print(head);
    head = inserttail(head, 20);
    print(head);
    head = insertk(head, 100, 3);
    print(head);
    return 0;
}