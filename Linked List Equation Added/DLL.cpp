#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"

DLL::DLL() {
    first = nullptr;
    last = nullptr;
    listsize = 0;
}

bool DLL::empty()
{
    if (first == nullptr)
        return true;
    else
        return false;
}

void DLL::insert(Node* newnode) {
    if (first == nullptr)
    {
        first = newnode;
    }
    else
    {
        first->prev = newnode;
        newnode->next = first;
        first = newnode;
    }
    listsize++;
}

void DLL::insert(Node* newnode, Node* pred)
{
    if (pred->next != nullptr)
    {
        pred->next->prev = newnode;
        newnode->next = pred->next;
    }

    pred->next = newnode;
    newnode->prev = pred;
    last = newnode;

    listsize++;
}

void DLL::erase(Node* n)
{
    if (n->prev == nullptr)
    {
        first = n->next;
    }
    else
    {
        n->prev->next = n->next;
    }

    if (n->next == nullptr)
    {
        n->prev->next = first;
    }
    else
    {
        n->next->prev = n->prev;
    }

    n->prev = nullptr;
    n->next = nullptr;

    listsize--;
}

void DLL::display()
{
    Node* current;
    int counter = 0;

    if (first != nullptr)
    {
        current = first;
        do
        {
            cout << current->coefficient << "x^" << current->exponent << "   ";
            current = current->next;
            counter++;
        } while (counter <= listsize - 1);
        cout << "\n";
    }
    else
    {
        cout << "\n The list is empty\n";
    }
}

void DLL::highLowDisplay(int eqID)
{
    Node* current;
    int counter = 0;

    if (first != nullptr)
    {
        current = last;
        cout << "p" << eqID << "(x) = ";
        do
        {
            if (current->prev == nullptr)
            {
                cout << current->coefficient << "x^" << current->exponent;

            }
            else
            {
                cout << current->coefficient << "x^" << current->exponent << " + ";
            }

            current = current->prev;
            counter++;

        } while (counter <= listsize - 1 && current != nullptr);
        cout << "\n";
    }
    else
    {
        cout << "\n The list is empty\n";
    }
}

bool DLL::checkExistence(Node* n)
{
    Node* temp;
    temp = first;
    int count = 0;

    while (n != NULL)
    {
        count++;
        //cout << "Loops: " << count << endl;

        if (temp == n)
        {
            return true;
        }

        if (temp->next == NULL)
        {
            return false;
        }

        temp = temp->next;
    }

    return false;
}

void DLL::combineTerms()
{
    Node* current = first;
    Node* temp = first;
    while (current->next != nullptr)
    {
        if (current->exponent == current->next->exponent)
        {
            current->coefficient += current->next->coefficient;
            erase(current->next);
        }

        current = current->next;
        last = current;
    }

    first = temp;
    current = temp;
    while (current->next != nullptr)
    {
        current = current->next;
        if (current->next == nullptr)
        {
            last = current;
        }
    }
}

void DLL::sortList()
{
    int swapped, i;
    Node* ptr1;
    Node* lptr = NULL;

    /* Checking for empty list */
    if (first == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = first;

        while (ptr1->next != lptr)
        {
            if (ptr1->exponent > ptr1->next->exponent)
            {
                swap(ptr1->exponent, ptr1->next->exponent);
                swap(ptr1->coefficient, ptr1->next->coefficient);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }

        last = ptr1;
        lptr = ptr1;
    } while (swapped);

}