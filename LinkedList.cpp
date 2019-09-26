#include <iostream>

using namespace std;

template <class T>
class Node
{
private:
	T value;
	Node<T>* next;

public:
	Node(T value)
	{
		this->value = value;
	}

	T getValue()
	{
		return value;
	}

	Node<T>* getNext()
	{
		return next;
	}

	void setNext(Node<T> *n)
	{
		next = n;
	}
};

template <class T>
class SinglyLinkedList
{
public:

	Node<T> *head, *tail;
	int count;

	SinglyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	~SinglyLinkedList()
	{
		if (head != NULL)
		{
			if (count == 1)
			{
				delete head;
				delete tail;
			}
			else
			{
				Node<T>* curr = head;
				while (curr != NULL)
				{
					Node<T> *n = curr->getNext();
					delete curr;
					curr = n;
				}
			}
		}
	}

	void push_back(T val)
	{
		Node<T>* n = new Node<T>(val);

		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->setNext(n);
			tail = n;
		}

		count++;
	}

	void push_front(T val)
	{
		Node<T> *n = new Node<T>(val);
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			n->setNext(head);
			head = n;
		}

		count++;
	}

	void delete_front()
	{
		if (head != NULL)
		{
			if (head->getNext() == NULL)
			{
				delete head;
				head = NULL;
				count--;
			}
			else
			{
				Node<T> *tmp = head->getNext();
				delete head;
				head = tmp;
				count--;
			}
		}
	}

	void remove(Node<T> *curr, Node<T> *prev)
	{
		if (prev == NULL)
			head = curr->getNext();
		else if (curr->getNext() == NULL)
		{
			tail = prev;
			tail->setNext(NULL);
		}
		else
			prev->setNext(curr->getNext());

		delete curr;
		count--;
	}

	void print()
	{
		Node<T>* curr = head;

		while (curr != NULL)
		{
			cout << curr->getValue() << " ";
			curr = curr->getNext();
		}

		cout << endl;
	}
};