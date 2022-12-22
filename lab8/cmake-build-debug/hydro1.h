#include <fstream>

#include <iostream>
#include <stdlib.h>
#include <string>
#include "list1.h"
using namespace std;

string file = "flow.txt";

void displayHeader();
int readData(const string& filePath, FlowList *list);
void menu(int *entries, FlowList list);
void display(FlowList list);
void addData(FlowList list, const int *entries);
void removeData(FlowList list, const int *entries);
double average(FlowList list);
void saveData(const string& filePath, FlowList list);
void pressEnter();
void clearBuffer();