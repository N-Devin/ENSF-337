// OLList.cpp
// ENSF 337 Fall 2021 Lab 8 Exercise A and B

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != nullptr && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        // point three
    if (maybe_doomed !=nullptr && maybe_doomed->item == itemA){
        doomed_node = maybe_doomed;
        before->next = maybe_doomed->next;
    }
    }
    delete doomed_node;
}

void OLList::destroy()
{
    Node *pointer = headM;
    Node *ptr;
    while (pointer != nullptr){
        ptr = pointer;
        pointer = pointer ->next;
        delete ptr;
    }
    headM = nullptr;
}

void OLList::copy(const OLList& source)
{
    if(source.headM == nullptr){
        headM = nullptr;
        return;
    }
    headM = new Node;
    Node *temp_node = headM;
    const Node *source_node = source.headM;
    while(true){
        temp_node-> item = source_node-> item;
        source_node = source_node -> next;
        if( source_node == nullptr ){
            break;
        }
        temp_node->next = new Node;
        temp_node = temp_node->next;
    }
    temp_node->next = nullptr;
}


