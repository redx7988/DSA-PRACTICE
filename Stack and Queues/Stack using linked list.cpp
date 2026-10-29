#include <bits/stdc++.h>
using namespace std;

class node // here we create two different classes so that one stores data other handles methods .3
{
public:
    int data; // we create data and next .
    node *next;

    node(int data) // constructor to create a linkedlist.
    {
        this->data = data;
        next = nullptr;
    }
};

class stackll
{
public:
    node *top = nullptr;
    int currentsize = 0;

    void push(int val) // so top points to nullptr . we create a new node and say its next is equal to top which stores nullptr.
    {
        node *temp = new node(val); // thus making new node point to null ptr, in next step we make top = temp so that when we
        temp->next = top;           // create a new node top will point to first element of stack while temp->next will make new node point to temp
        top = temp;                 // which will connect temp to first node , then we again shift the top to temp, thus making top point to top .
        currentsize++;
    }
    /*
    Push 7: [7 | nullptr]
    Push 2: [2] -> [7 | nullptr]
    Push 3: [3] -> [2] -> [7 | nullptr]
            ^
          topNode
    */
    void pop()
    {
        node *temp = top; // pop in stack means remove top/last element . so create a temp as a refference to top .
        top = top->next;  // shift top to next element .
        delete temp;      // delete temp as temp only point to the top element now
        currentsize--;
    }

    void peek()
    {
        cout << top->data << endl;
    }

    void size()
    {
        cout << currentsize << endl;
    }
    void print()
    {
        node *temp = top;
        for (int i = 0; i < currentsize; i++)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    stackll stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();
    stack.peek();
    stack.size();
}