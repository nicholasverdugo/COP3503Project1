#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class LinkedList {
public:
    //default constructor
    LinkedList() { //sets head and tail pointer to nullptr, and the total amount of nodes to 0
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
    }
    //nested class Node
    class Node {
    public:
        //variables for pointers to the next and prev node to the node object, and for any data it will store
        Node *next;
        Node *prev;
        T data;
    };

    //AddHead function, adds a new node to the head of the linked list.
    void AddHead (const T &data){
        //creates a new temp node, so its pointers can be manipulated to be added to the list
        Node *temp = new Node();
        temp->data = data;
        temp->next = nullptr;
        temp->prev = nullptr;
        //if there are no values in the list yet, set the pointers to head and tail to point to the temp node
        if (head == nullptr){
            head = temp;
            tail = temp;
            //set the next and previous pointers of the temp node to nullptr, since no other values are in the list
            temp->next = nullptr;
            temp->prev = nullptr;
        }
        else {
            head->prev = temp;
            temp->next = head;
            head = temp;
            temp = nullptr;
        }
        nodeCount++;
    }
    //AddTail function, adds a new node to the tail of the linked list
    void AddTail (const T &data){
        //creates a new temp node, so its pointers can be manipulated to be added to the list
        Node *temp = new Node();
        temp->data = data;
        temp->next = nullptr;
        temp->prev = nullptr;
        //if there are no values in the list yet, set the pointers to head and tail to point to the temp node
        if (tail == nullptr){
            head = temp;
            tail = temp;
            //set the next and previous pointers of the temp node to nullptr, since no other values are in the list
            temp->next = nullptr;
            temp->prev = nullptr;
        }
        else {
            //sets the tail's next pointer to temp, sets the temp's prev pointer to tail, and sets tail's pointer to temp's pointer
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            temp = nullptr;
        }
        nodeCount++;
    }
    //AddNodesHead function, given an array of data, adds a new node for each data point at the beginning of the list, keeping the original order of data consistent
    void AddNodesHead(const T *data, unsigned int count){
        //finds the last value's index in the data array
        //this needs to be done since you need to preserve the order of the array of data
        int reverseIndex = (int)count - 1;
        //calls AddHead from the end of the array, loops until the array is empty
        for (int i = reverseIndex; i >= 0; --i){
            AddHead(data[i]);
        }
    }
    //AddNodesTail function, given an array of data, adds a new node for each data point at the end of the list, keeping the original order of data consistent
    void AddNodesTail(const T *data, unsigned int count){
        //calls AddTail from the beginning of the array, loops until the array is empty
        for (unsigned int i = 0; i < count; ++i){
            AddTail(data[i]);
        }
    }
    //returns the amount of nodes currently in the list
    unsigned int NodeCount() const{
        return nodeCount;
    }
    //prints the list from head to tail
    void PrintForward() const{
        //create a pointer that points to the current node
        Node *curr = head;
        while (curr != nullptr){
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
    //prints the list from tail to head
    void PrintReverse() const{
        //create a pointer that points to the current node
        Node *curr = tail;
        while (curr != nullptr){
            cout << curr->data << endl;
            curr = curr->prev;
        }
    }
    //returns a pointer to the head of the list
    Node *Head() const{
        return head;
    }
    //returns a pointer to the tail of the list
    Node *Tail() const{
        return tail;
    }
    //deletes all nodes
    void Clear() {
        Node *temp;
        Node *ptr = Head();
        while (ptr != nullptr){
            temp = ptr->next;
            delete ptr;
            ptr = temp;
        }
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
    }
    ~LinkedList(){
        Clear();
    }
private:
    //variables for pointers to the next/prev node to the current node, pointers to the head and tail of the linked list, a temp pointer,
    //and an iterator pointer to show which node is currently being accessed
    Node *next;
    Node *prev;
    Node *head;
    Node *tail;
    Node *iter;
    Node *temp;
    unsigned int nodeCount;
};