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
node *removehead(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    node *prev = head;
    head = head->next; // suppose {12,3,5,8} to delete the head we first shift head from 12 to 3 .

    head->back = nullptr; // in next step the new head (3) back will be disconnected from 12 by making it connect it to null ptr .
    prev->next = nullptr; // now we connect the next for prev(12) to nullptr , thus making the prev(12) disconnect from all elements .

    delete prev; // now we just delete that element which no longer have any reference to any element .
    return head;
}
node *removetail(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    node *tail = head;    // suppose {12,3,5,8} tail will point at head for now later it will point at last term in dll.
    node *prev = nullptr; // create a prev whch for now points at nullptr .
    while (tail->next != nullptr)
    {
        tail = tail->next; // used this loop to loop till last number in dll (8).
    }
    prev = tail->back;    // stored the value of tail->back(which is 5) in the prev which directly gives us the prev of last number ;
    prev->next = nullptr; // prev(5) next will point at nullptr thus removing its connection to 8.
    tail->back = nullptr; // tail(8) back will point to nullptr which used to store pointer to 5 thus removing tis connection to 5.
    delete tail;          // since tail have not refference to any number now we can safely remove it.
    return head;
}
node *removek(node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr; // if the dll is empty we will return just nullptr making it get delete;
    }
    int counter = 0;
    node *temp = head;    // creating temp wich point to head and prev and front which points to nullptr for now but later we chnage its value .
    node *prev = nullptr; // suppose {12 , 3 , 5 ,8} . suppose the value for k is 3 which is 5 in value
    node *front = nullptr;
    while (temp != nullptr)
    {
        counter++;
        if (counter == k)  // we use a while loop to loop to the position we want and put temp to that exact position(3) and value is 5 .
            break;         // break so we do not go any position any front of it.
        temp = temp->next; // to switch to next number in dll.
    }
    prev = temp->back;  // now we are at number 5 , prev will be back of temp which is 3
    front = temp->next; // front will be next of the temp which will be 8 .
    if (prev == nullptr && front == nullptr)
    {
        return nullptr; // it is a edge case at which there is only one term in dll so the front anf prev both point at null;
    }
    else if (prev == nullptr)
    {
        return removehead(head); // if prev = nullptr that would mean we are at head as prev of head is null ptr .
    }
    else if (front == nullptr)
    {
        return removetail(head); // if front = nullptr that would mean we are at tail as next of tail is null ptr .
    }
    prev->next = front;   // now {12,3,5,8} we will connect 3 to the 8 thus removing the connection of 3 next from 5 to 8.
    front->back = prev;   // now we will connect the back of 8 to the 3 thus removing the connection of 8 back from 5 to 3.
    temp->next = nullptr; // now 3 and 8 are not connected to 5 but 5 is still connected to them so will disconnect 5 from 3 and 8.
    temp->back = nullptr; // we first disconnect the 8 from 5 next then 3 from 5 back by keeping null ptr.
    delete temp;          // now our temp (5) is not connected to any number so well will just delete it and return the head .
    return head;
}
int main()
{
    vector<int> arr = {12, 3, 5, 8};
    node *head = convert2dll(arr);
    print(head);
    head = removek(head, 3);
    print(head);
    head = removehead(head);
    print(head);
    head = removetail(head);
    print(head);
}