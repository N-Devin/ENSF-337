#include <iostream>
using namespace std;

#include "list1.h"
#include "hydro1.h"

int main(){
    FlowList list;
    int entries = readData(file, &list);
    displayHeader();
    menu(&entries, list);
}

void displayHeader(){
    cout << "\nProgram: Flow Studies–Fall 2022}\n";
    cout << "Version: 1.0\n";
    cout << "Lab section: B02 \n";
    cout << "Produced By: Mehvish Shakeel\n";
}

int readData(const string& filePath, FlowList *list){
    ifstream in_object;
    string s;

    int i = 0;
    in_object.open(filePath);

    if (!in_object){
        cout << "cannot open the file" << endl;
        exit(1);
    }

    while(!in_object.eof()){
        getline(in_object, s);
        i++;
    }

    in_object.clear();

    in_object.seekg(0, ios::beg);

    while(!in_object.eof()){
        int year;
        double flow;
        ListItem insertItem;

        in_object >> insertItem.year >> insertItem.flow;
        list->insert(insertItem);
        getline(in_object, s);
    }

    in_object.close();
    return i;
}

void menu(int *entries, FlowList list){
    int option = 0, endS = 1;

    while (endS) {
        while (!option) {
            pressEnter();

            cout << "\nPlease select on the following operations\n";
            cout << "1.Display flow list, and the average.\n";
            cout << "2.Add data.\n";
            cout << "3.Save data into the file.\n";
            cout << "4.Remove data..\n";
            cout << "5.Quit.\n";
            cout << "Enter your option (1, 2, 3, 4, or 5):\n";
            cin >> option;
            clearBuffer();

            if(option==1){
                display(list);
                option = 0;
            } else if(option==2){
                addData(list, entries);
                cout << "Data Added" << endl;
                option = 0;
            } else if(option==3){
                saveData(file, list);
                cout << "Data Saved" << endl;
                option = 0;
            } else if(option==4){
                removeData(list, entries);
                cout << "Data Removed" << endl;
                option = 0;
            } else if(option==5){
                cout << "Exiting Program" << endl;
                endS = 0;
            }
        }
    }
}

void display(FlowList list){
    list.print();
    cout << "\nThe annual average of the flow is: " << average(list) << " billions cubic metres" << endl;
}

double average(FlowList list){
    return list.average();
}

void addData(FlowList list, const int *entries){
    ListItem newItem;
    cout<<"\nYear: ";
    cin>>newItem.year;
    cout<<"\nFlow: ";
    cin>>newItem.flow;

    list.insert(newItem);
    clearBuffer();
    pressEnter();
    entries += 1;
}

void saveData(const string& filePath, FlowList list){
    list.save(filePath);
}

void removeData(FlowList list, const int *entries){
    string year;
    cout<<"\nYear: ";
    cin>>year;

    list.remove(year);
    pressEnter();
    entries -= 1;
}

void pressEnter(){
    cout << "\n<<< Press Enter to Continue >>>";
    cin.get();
    clearBuffer();
}

void clearBuffer(){
    cin.clear();
    cin.ignore(10000,'\n');
}