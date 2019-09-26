/*
 - Solution to remove duplicated elements from the a singly linked list in O(n)
*/

#include <iostream>
#include <unordered_set>
#include "LinkedList.cpp"

using namespace std;

void removeDups(SinglyLinkedList<int> &ls)
{
    Node<int> *curr = ls.head;
	Node<int> *prev = NULL;
	Node<int> *next = NULL;

	unordered_set <int> mp;

    while (curr != NULL)
    {
        next = curr->getNext();

        int key = curr->getValue();
        
        if (mp.count(key) > 0)
            ls.remove(curr, prev);
        else
        {
            mp.insert(key);
            prev = curr;
        }

        curr = next;
    }
}

int main()
{
    SinglyLinkedList<int> ls;
    
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(1);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_back(4);
    ls.push_back(3);
    ls.push_back(5);

    removeDups(ls);

    ls.print();
}
