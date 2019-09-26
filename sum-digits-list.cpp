/*
    You have two numbers represented by a linked list where each node contains a single digit.
    The digits are stored in REVERSE order, such as the 1's digit is at the head of the list.
    Write a function that adds the two numbers and returns the sum as a linked list

    This is the solution
*/

#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{
	SinglyLinkedList<int> l1;
	SinglyLinkedList<int> l2;

	l1.push_back(7);
	l1.push_back(1);
	l1.push_back(6);

	l2.push_back(5);
	l2.push_back(9);
	
	int val = 0;
	int decimal_place = 0;

	Node<int> *curr1 = l1.head;
	Node<int> *curr2 = l2.head;

	while(curr1 != NULL || curr2 != NULL)
	{
		if (curr1 != NULL)
		{
			val += curr1->getValue() * pow(10, decimal_place);
			curr1 = curr1->getNext();
		}

		if(curr2 != NULL)
		{
			val += curr2->getValue() * pow(10, decimal_place);
			curr2 = curr2->getNext();
		}

		decimal_place++;
	}

	cout << val << endl;

	return 0;
}