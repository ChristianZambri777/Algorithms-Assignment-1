// Assignment 1 Algorithims.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


//
struct Node
{
    int ID;
    string name;
    float price;
    string category;
    struct Node* next ;


};


class LinkedList
{
public:
    void Insert(Node * newNode);
    void Update();
    void Search();
    void PrintList();
    void DeleteNode();
    void InsertionSort();
private:
    Node* head = nullptr;

};


void LinkedList::Insert(Node* newNode)
{


    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;

    }
};

void LinkedList::PrintList()
{
    

    if (head == nullptr)
    {
        return;
    }

    Node* temp = head;

    cout << "Printing List :\n";
    while (temp != nullptr)
    {

        cout <<  temp->ID<< ", " <<
            temp->name << ", " << temp->price << ", " << temp->category << "\n";
        temp = temp->next;
    }

}

void LinkedList::Search()
{

    int searchID;
    bool foundID = false;

    cout << "\nEnter the ID of the product you want to find: ";
    cin >> searchID;

    if (head == nullptr)
    {
        return;
    }

    Node* temp = head;

    while (temp != nullptr)
    {
        if (searchID == temp->ID)
        {
            foundID = true;
            break;
        }
        temp = temp->next;
       
    }

    if (foundID)
    {
        cout << "The ID was found. Here is the product info:\nName: " <<
            temp->name << "\nPrice: " << temp->price << "\nCategory: " << temp->category;
    }

    else
    {
        cout << "The ID was not found.\n";
    }

    


}

void LinkedList::InsertionSort()
{
    Node* current = head;
    Node* sorted = nullptr;

    while (current != nullptr)
    {
        Node * next = current->next;

        if(sorted == nullptr || sorted->price >= current->price)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
        Node* sortCur = sorted;


        while (sortCur->next != nullptr && sortCur->next->price < current->price)
        {
            sortCur = sortCur->next;
        }
        current->next = sortCur->next;
        sortCur->next = current;
        }
        current = next;
        
    }
   

    head = sorted;
};

void LinkedList::DeleteNode()
{
    Node* temp = head;
    head = temp->next;
    delete temp;
};


void LinkedList::Update()
{

    int searchID;
    int modifyChoice;
    bool foundID = false;

    cout << "\n\nEnter the ID of the product you want to update: ";
    cin >> searchID;

    if (head == nullptr)
    {
        return;
    }

    Node* temp = head;

    while (temp != nullptr)
    {
        if (searchID == temp->ID)
        {
            foundID = true;
            break;
        }
        temp = temp->next;

    }

    if (foundID)
    {
        cout << "The ID was found. Here is the product info:\nName: " <<
            temp->name << "\nPrice: " << temp->price << "\nCategory: " << temp->category <<
            "\nWhat cateogory would you like to modify? \nID (1)\nName (2)\nPrice (3)\nCategory (4)\nEnter your choice: ";


        cin >> modifyChoice;

        switch (modifyChoice)
        {
        case 1:
            cout << "Enter the new ID: ";
            cin >> temp->ID;
            break;
        case 2:
            cout << "Enter the new name: ";
            cin >> temp->name;
            break;
        case 3:
            cout << "Enter the new price: ";
            cin >> temp->price;
            break;
        case 4:
            cout << "Enter the new cateogory: ";
            cin >> temp->category;
            break;
                

        }




    }

    else
    {
        cout << "The ID was not found.";
    }


    cout << "\n";

}




void ReadFile(LinkedList *myList);



int main()
{

    Node* head = new Node();
    LinkedList myList;
    ReadFile(&myList);
    myList.PrintList();
    myList.InsertionSort();
    cout << "\n\nDeleting the first Node\n\n";
    myList.DeleteNode();
    myList.PrintList();
    cout << "\n\n\n";
    myList.Search();
    myList.Update();
    myList.PrintList();
    


    




}

void ReadFile(LinkedList * list)
{
    try
    {
        ifstream inFile;
        inFile.open("product_data.txt");
        string line;
        string id, price,name,cat;
        
     

        while (getline(inFile, line))
        {
            Node* node = new Node();
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, price, ',');
            getline(ss, cat, ',');

           
   
               node->ID = stoi(id);
               node->name = name;
               node->price = stof(price);
               node->category = cat;
               list->Insert(node);
            

        }



        inFile.close();
    }
    catch (const exception& e)
    {
        cout << "Error in file reading";
    }
}

