#include <bits/stdc++.h>
#define max 5
using namespace std;

class arrayqueue
{
private:
    int qu[max];         // created an array of size 5 .
    int start = -1;      // let start and end be -1 . why use start and end why not just top?
    int end = -1;        // answer --> in queue we use FIFO first in first out . such that we need a pointer for first term that is start and end helps to add data in later or end part of array.
    int currentsize = 0; // currentsize be zero .

public:
    void push(int val)
    {
        if (currentsize == max) // if the queue is full then edge case .
        {
            cout << "Queue is full";
            return;
        }
        if (currentsize == 0) // if the array is empty we will use to start = end =0 so that we end first val at index 0;
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % max; // now suppose our array is full as when we use pop we actually do not remove the element
        } // so suppose using start and end we came to start =3 and end =4 (index starts at 0) that an end so by using end =(end+1)%max we will have
        qu[end] = val; // end = (4+1)%4 which will give us 0 thus pointing at start . thus creating a circular loop.
        currentsize++; // ofc our array is empty but we have came till last so we use this formula to shift to first term at index[0].
    }

    int pop()
    {
        if (currentsize == 0) // An edge case if array is empty.
        {
            cout << "Queue is empty!!";
            return -1;
        }
        int el = qu[start]; // create an el if suppose you want to later say we removed *specific* number return at last to do this.

        if (currentsize == 1) // if current size is 1 means only one element then do start = end =-1 this means our queue is empty.
        {
            start = end = -1;
        }
        else
        {
            start = (start + 1) % max; // again what we did with push . if our queue is full and our start = 4 end = 1 we came here by doing pop at last term where end = 4
        } // using start =(start+1)%max will take us to 0 index thus making a circular loop.
        currentsize--; // decrease the currentsize
        return el;
    }

    void peek()
    {
        if (currentsize == 0)
        {
            cout << "Queue is empty!!" << endl;
        }
        cout << endl
             << qu[start] << endl;
    }

    void size()
    {
        cout << currentsize << endl;
    }

    void isempty()
    {
        if (currentsize == 0)
        {
            cout << "Queue is empty!!" << endl;
        }
        else
        {
            cout << "Queue is not empty!!" << endl;
        }
    }

    void print()
    {
        for (int i = 0; i < currentsize; i++)
        {
            cout << qu[i] << " ";
        }
    }
};
int main()
{
    arrayqueue queue;

    queue.isempty();

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    queue.print();
    queue.peek();
    queue.size();

    queue.pop();
    queue.pop();
    queue.pop();

    queue.print();

    queue.isempty();

    return 0;
}