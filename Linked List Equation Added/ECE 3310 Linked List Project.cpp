#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"

DLL mergeLists(DLL* firstList, DLL* secondList)
{
    DLL newList;

    Node* current, *temp;
    cout << "List size: " << firstList->listsize << endl;

    if (firstList->first != nullptr)
    {
        int counter = 0;
        current = firstList->last;

        do
        {
            newList.insert(current);
            current = current->prev;
            counter++;
        } while (counter < firstList->listsize);
    }

    //newList.display();

    if (secondList->first != nullptr)
    {
        int counter = 0;
        current = secondList->last;
       
        do
        {
            newList.insert(current);
            current = current->prev;
            counter++;
        } while (counter < secondList->listsize);
    }

    newList.sortList();
    newList.combineTerms();

    return newList;
}

int main()
{
    Node* n1 = new Node(2, 0);
    Node* n2 = new Node(4, 4);
    Node* n3 = new Node(9, 11);
    Node* n4 = new Node(15, 25);
    Node* n5 = new Node(6, 88);

    Node* n6 = new Node(3, 0);
    Node* n7 = new Node(4, 11);
    Node* n8 = new Node(5, 45);

    DLL list1;
    DLL list2;

    //if (mylist.empty() == true)
      //  cout << "\n The list is now empty\n";
    list1.insert(n1);
    list1.insert(n2, n1);
    list1.insert(n3, n2);
    list1.insert(n4, n3);
    list1.insert(n5, n4);

    //list1.display();
    list1.highLowDisplay(1);

    list2.insert(n6);
    list2.insert(n7, n6);
    list2.insert(n8, n7);

    //list2.display();
    list2.highLowDisplay(2);

    DLL newList = mergeLists(&list1, &list2);
    //newList.display();

    cout << "Sorted List: \n";
    //newList.insertionSort();
    //newList.sortList();
    newList.display();
    
    newList.highLowDisplay(3);

    return 0;
}