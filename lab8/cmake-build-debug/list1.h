#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdlib.h>
#include <fstream>

struct ListItem {
    int year;
    double flow;
};

struct Node {
    ListItem item;
    Node *next;
};

class FlowList {
public:
    FlowList(); // PROMISES: Creates empty list.
    FlowList(const FlowList& source);
    FlowList& operator =(const FlowList& rhs);
    ~FlowList();

    void insert(const ListItem& itemA);
    void remove(const string& year);
    double average();
    void print() const;
    void save(const string& filePath);

private:
    Node *headM;
    void destroy();
    void copy(const FlowList& source);

};

#endif