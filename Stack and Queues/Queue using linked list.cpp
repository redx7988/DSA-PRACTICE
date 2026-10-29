#include <bits/stdc++.h>
using namespace std;

class node // we have created two different classes so that one stores data other handles methods .
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class queuell
{
public:
    node *start = nullptr; // set start and end to nullptr .
    node *end = nullptr;
    int currentsize = 0;

    void push(int val) // what we do in push is . if our queue is empty we keep start and end as nullptr
    {
        node *temp = new node(val);
        if (start == nullptr)
        {
            start = end = temp; // we connect the start and end to the temp.
        }
        else
        {
            end->next = temp; // as we can see the end -> next which is at 7 will connect to our new term 2
            end = temp;       // we will increase the end to point at temp
        }
        currentsize++;
    }
    /*
    Push 7: [start, end] -> [7 | nullptr]
    Push 2: [start] -> [7] -> [2 | nullptr] <- [end]
    Push 3: [start] -> [7] -> [2] -> [3 | nullptr] <- [end]
    Push 5: [start] -> [7] -> [2] -> [3] -> [5 | nullptr] <- [end]
    */

    void pop()
    {
        if (start == nullptr)
        {
            cout << "Queue is empty" << endl; // if queue is empty
            return;
        }
        node *temp = start;  // we can use start->next as it will point to next term to it . end->next points to nullptr
        start = start->next; // shift start to new term and delete the temp term;
        if (start == nullptr)
        {
            end = nullptr; // it have nothing so we will set end to nullptr as well.
        }
        delete temp;
        currentsize--;
    }
    void size()
    {
        cout << currentsize << endl;
    }
    void peek()
    {
        cout << start->data << endl;
    }
    void print()
    {
        node *temp = start;
        for (int i = 0; i < currentsize; i++)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    queuell q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    q.pop();
    cout << "After pop" << endl;
    q.print();
    q.peek();
    q.size();
}