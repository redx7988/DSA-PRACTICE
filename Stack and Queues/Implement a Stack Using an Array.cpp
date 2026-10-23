#include <bits/stdc++.h>
#define max 10 // I have defined the max as 10 so the max array size is 10 ;
using namespace std;

class arraystack
{
private:
    int st[max];         // array of size 10.
    int top = -1;        // the top will be -1 so that the first term we store will be top +1 which is 0 , also helps in finding if array is empty .
    int currentsize = 0; // used current size to know current size.

public:
    void push(int val)
    {
        if (top == max - 1) // if our top is at 9 that means our stack is full as we start from 0 not from 1.so total size 10 is full
        {
            cout << "Stack overflow";
            return;
        }
        top = top + 1; // we will increase our top to 0 from -1 .
        st[top] = val; // we will store the value at point top which is 0 for now.
        currentsize++; // increase currentsize as we added a new term.
    }

    void pop()
    {
        if (top == -1) // if our stack is empty as -1 means empty
        {
            cout << "Stack underflow . stack is empty";
            return;
        }

        top = top - 1; // just shift top from its current position to left . no need to delete it as we use push we just rewrite its value.
        currentsize--; // just decrease the currentsize .
    }

    void peek()
    {
        cout << "Top element is :" << st[top] << endl; // print the top element as stack uses LIFO means last in is the first/top element.
    }

    void size()
    {
        cout << "Current size is :" << currentsize; // use the currentsize to show the size .
    }

    void isempty()
    {
        if (top == -1) // if stack is empty or not .
        {
            cout << "The stack is empty" << endl;
        }
        else
        {
            cout << endl
                 << "Stack is not empty" << endl;
        }
    }

    void print()
    {
        for (int i = 0; i < currentsize; i++)
        {
            cout << st[i] << " "; // go to each element to print it .
        }
        cout << endl;
    }
};
int main()
{
    arraystack stack;
    stack.isempty();
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();
    stack.push(40);
    stack.push(50);
    stack.print();
    stack.peek();
    stack.pop();
    stack.pop();
    stack.print();
    stack.size();
    stack.isempty();
}