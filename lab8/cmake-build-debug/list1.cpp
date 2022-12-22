using namespace std;
#include "list1.h"

FlowList::FlowList()
        : headM(0)
{
}

FlowList::FlowList(const FlowList& source)
{
    copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

FlowList::~FlowList()
{
    destroy();
}

void FlowList::print() const
{
    cout << "Year\tFlow"<<endl;

    if (headM != NULL) {
        cout << headM->item.year << '\t' << headM->item.flow;

        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << "\n" << p->item.year << '\t' << p->item.flow;
    }
}

void FlowList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;

    if (headM == NULL || (itemA.flow <= headM->item.flow && itemA.year <= headM->item.year) ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;
        Node *after = headM->next;
        while(after != NULL && itemA.flow > after->item.flow && itemA.year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}

void FlowList::remove(const string& year)
{
    // if list is empty, do nothing
    if (headM == NULL || (stoi(year) < headM->item.year))
        return;

    Node *doomed_node = NULL;

    if (stoi(year) == headM->item.year) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != NULL && stoi(year) > maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }

        before->next=maybe_doomed->next;
        delete maybe_doomed;
    }

}

void FlowList::destroy()
{
    while(headM){
        Node *old = headM;
        headM = headM->next;
        delete old;
    }
    headM = NULL;
}


double FlowList::average(){
    int entry = 0;
    double s = 0, average = 0;

    while (headM != NULL) {
        s += headM->item.flow;
        entry += 1;
        headM = headM->next;
    }
    average = s / entry;
    return average;
};

void FlowList::save(const string& filePath){
    Node *latest = headM;
    ofstream out_object;
    out_object.open(filePath);

    while (latest){
        out_object << latest->item.year << '\t' << latest->item.year << endl;
        latest = latest->next;
    }
    out_object.close();
}

void FlowList::copy(const FlowList& source)
{
    Node * latestNode = NULL;
    Node * nextNode = NULL;
    if( source.headM == NULL )
        headM = NULL;

    else {
        headM = new Node;
        headM->item = source.headM->item;

        latestNode = headM;
        nextNode = source.headM->next;
    }

    while( nextNode )
    {
        latestNode->next = new Node;
        latestNode = latestNode->next;
        latestNode->item = nextNode->item;

        nextNode = nextNode->next;
    }
    latestNode->next = NULL;

}

