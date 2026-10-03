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
    node(int data, node *head)
    {
        this->data = data;
        next = head;
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
void print(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//-------------------DELETION PART---------------------------
node *removehead(node *head)
{
    node *temp = head;
    head = head->next; // inside head we store the value of next term such that all head value can be removed in next step.
    free(temp);        // OR YOU CAN USE DELETE(TEMP)
    return head;
}
node *removetail(node *head)
{
    node *temp = head;
    if (head == NULL || head->next == NULL)
        return NULL;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr; // suppose array = {1,3,5,7} we will got till 5 then remove temp->next which is 7 and connect temp->next=nullptr in short we will connect 5 to nullptr.
    return head;
}
node *removek(node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1) // USE head->data == k .IF WE DO THIS WE CAN EASILY DELETE A NUMBER JUST BY TYPING ITS VALUE{1,3,5,7} JUST WRITE 3 AND IT DELETES IT.
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int counter = 0; // NO NEED FOR A COUNTER IN VALUE DELETE.
    node *temp = head;
    node *prev = NULL;
    while (temp != nullptr)
    {
        counter++;        // NO NEED FOR THIS IN VALUE DELETE
        if (counter == k) // TEMP->DATA == K FOR VALUE DELETE PURPOSE.
        {
            prev->next = prev->next->next; // suppose array= {1,3,5,7,9} . we want to remove 5 then what we do is we connect 3 to 7 thus eliminating 5. at start temp = head which is 1 while prev is null.
            free(temp);
            break;
        }
        prev = temp; // what we do here is we make temp value store in prev and in next step we shift temp to next value thus making prev at a position less than temp.
        temp = temp->next;
    }
    return head;
}
// ------------------DELETION PART IS OVER----------------------------------------------
//-------------------INSERTION PART STARTS HERE00---------------------------------------
node *inserthead(node *head, int val)
{
    node *temp = new node(val, head); // we are creating a new node and adding a value of head in its next such that it is connected to next now .
    return temp;                      // we will return the value of temp such that temp will become new head and new starting point for our linked list.
}
node *inserttail(node *head, int val)
{
    if (head == NULL)
    {
        return new node(val);
    }
    node *temp = head;
    while (temp->next != NULL) // cannot write as temp = null only temp-next =null .
    {
        temp = temp->next; // we traverse till the last value in array .
    }
    node *newnode = new node(val);
    temp->next = newnode; // we connect the newnode to the last value this inserting at last
    return head;
}
node *insertk(node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        { // we are inserting at second position as our first pos is 0 and our
            return new node(val);
        }
        else
        {
            return head; // if there is elements like k value is more than 1 it is an error as our linked list empty . this is an error case we take.
        }
    }
    if (k == 1) // insert at beginning .
    {
        return new node(val, head);
    }
    int counter = 0;
    node *temp = head;
    while (temp != NULL)
    {
        counter++;
        if (counter == k - 1) // suppose {1,3,5,7,9} we want to add a term after 3 at pos 3 , we at 3 will add a new node we will connect it to 5 first so that we do not lose the pointer to 5 then we add newnode to 3.
        {
            node *newnode = new node(val);
            newnode->next = temp->next; // we do this first if we do this last then we will just loose the pointer to the 5 and not be able to connect to 5 later.
            temp->next = newnode;       // now connecting 3 to the new node ;
            break;
        }
        temp = temp->next; // help in traverse
    }
    return head;
}
node *insertbeforevalue(node *head, int val, int el)
{ // el is our term we need to look for to add val before it
    if (head == NULL)
    {
        return head; // if our linked list is empty there is no point to search for a value to exist inside it .
    }
    if (head->data == el)
    {
        return new node(val); // just normally add a new value here .
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->next->data == el) // suppose {1,3,5,7,9} . we will go the number just before the given number el , if i want to add before 5 i go to 3 and do temp->next which is our 5 from 3 and again data which will show the value at that node
        {                           // which we will again compare with the given el value if equal we will do what we did in kth term insertion .
            node *newnode = new node(val);
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    node *head = ll(arr);

    cout << "The length of array is : " << lengthofll(head) << endl;
    searchnumber(head, 5);

    // THIS IS WHERE NEW PART FOR THIS CODE STARTS
    print(head);
    head = removehead(head); // HERE WE ARE STORING THE NEW VALUE OF HEAD IN OLD HEAD . THIS IS IMPORTANT .
    print(head);
    head = removetail(head);
    print(head);
    head = removek(head, 3);
    print(head);
    head = inserthead(head, 0);
    print(head);
    head = inserttail(head, 9);
    print(head);
    head = insertk(head, 10, 5); // 5 is the position while 10 is the value
    print(head);
    head = insertbeforevalue(head, 10, 5);
    print(head);
    return 0;
}