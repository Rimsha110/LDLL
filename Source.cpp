#include <iostream>
using namespace std;
template <class T>
class DNode
{
public:
	T info;
	DNode<T>* next;
	DNode<T>* prev;
	DNode(T val)
	{
		info = val;
		next = prev = nullptr;
	}
};
template <class T>
class LinkedList
{
public:
	DNode<T>* head;
	LinkedList()
	{
		head = nullptr;
	}
	void insertAtHead(T val)
	{
		if (!head)
		{
			head = new DNode<T>(val);
		}
		else
		{
			DNode<T>* n = new DNode<T>(val);
			n->next = head;
			head->prev = n;
			head = n;
		}
	}
	void insertAtTail(T val)
	{
		if (!head)
		{
			head = new DNode<T>(val);
		}
		else
		{
			DNode<T>* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new DNode<T>(val);
			temp->next->prev = temp;
		}
	}
	void deleteAtHead()
	{
		if (!head)
			return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	void deleteAtTail()
	{
		if (!head)
			return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->prev->next = nullptr;
		delete temp;
	}
	void insertBefore(T key, T val)
	{
		if (!head)
			return;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		DNode<T>* temp = head->next;
		while (temp)
		{
			if (temp->info == key)
			{
				DNode<T>* n = new DNode<T>(val);
				n->next = temp;
				n->prev = temp->prev;
				temp->prev->next = n;
				temp->prev = n;
				return;
			}
			temp = temp->next;
		}
	}
	void insertAfter(T key, T val)
	{
		if (!head)
			return;
		DNode<T>* temp = head;
		while (temp)
		{
			if (temp->info == key)
			{
				if (temp->next == nullptr)
				{
					insertAtTail(val);
					return;
				}
				DNode<T>* n = new DNode<T>(val);
				n->next = temp->next;
				n->prev = temp;
				temp->next->prev = n;
				temp->next = n;
				return;
			}
			temp = temp->next;
		}
	}
	void deleteBefore(T key)
	{
		if (!head || !head->next)
			return;
		if (head->info == key)
			return;
		if (head->next->info == key)
		{
			deleteAtHead();
			return;
		}
		DNode<T>* temp = head->next->next;
		while (temp)
		{
			if (temp->info = key)
			{
				DNode<T>* toDelete = temp->prev;
				temp->prev = toDelete->prev;
				toDelete->prev->next = temp;
				delete toDelete;
				return;
			}
			temp = temp->next;
		}
	}
	void deleteAfter(T key)
	{
		if (!head || !head->next)
			return;
		DNode<T>* temp = head;
		while (temp)
		{
			if (temp->info == key)
			{
				if (temp->next == nullptr)
				{
					return;
				}
				if (temp->next->next == nullptr)
				{
					deleteAtTail();
					return;
				}
				DNode<T>* toDelete = temp->next;
				temp->next = temp->next->next;
				temp->next->prev = toDelete->prev;
				delete toDelete;
				return;
			}
			temp = temp->next;
		}
	}
	void display()
	{
		if (!head)
			return;
		DNode<T>* temp = head;
		while (temp)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{
	LinkedList<int> ll;
	ll.insertAtTail(5);
	ll.insertAtTail(7);
	ll.insertAtHead(2);
	ll.insertAtTail(9);
	ll.display();
	ll.deleteAtHead();
	ll.display();
	ll.deleteAtTail();
	ll.display();
	ll.insertAfter(5, 3);
	ll.display();
	ll.insertBefore(3, 6);
	ll.display();
	ll.deleteAfter(5);
	ll.display();
	ll.deleteBefore(7);
	ll.display();
	return 0;
}