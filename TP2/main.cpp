#include <iostream>
#include <vector>
#include "Note.h"

using namespace std;

void menu() {
    cout << "1. Add student(s)" << endl;
    cout << "2. Show all students" << endl;
    cout << "3. Show students, whose birthdays are in a certain month" << endl;
    cout << "4. Exit"<< endl;
}

int Partition(vector<Note>& Notes, int l, int r){
    Note x = Notes[r];
    int less = l;

    for (int i = l; i < r; ++i){
        if (Notes[i].getName() <= x.getName()){
            swap(Notes[i], Notes[less]);
            ++less;
        }
    }
    swap(Notes[less], Notes[r]);
    return less;
}

void quickSort(vector<Note>& Notes, int l, int r){
    if (l < r){
        int q = Partition(Notes, l, r);
        quickSort(Notes, l, q-1);
        quickSort(Notes, q+1, r);
    }
}

void mySort(vector<Note>& Notes){
    if(!Notes.empty()){
        quickSort(Notes, 0, Notes.size()-1);
    }
}

int main()
{   
    vector<Note> Notes;
    int choose;
    int count = 0;
    Note note;
    while (1){
        menu();
        cout << "Enter your choose: ";
        cin >> choose;
        if (choose == 1){
            cout << "Enter name, phone and birthday (like 01.01.2001) for note " << Notes.size() + 1 << ": ";
            cin >> note;
            Notes.push_back(note);
        }
        else if (choose == 2){
            mySort(Notes);
            for (int i = 0; i < Notes.size(); ++i){
                cout << Notes[i] << endl;
            }
        }   
        else if(choose == 3){
            int month;
            cout << "Enter number of month, which you want to show: ";
            cin >> month;
            for (int i = 0; i < Notes.size(); ++i){
                if (Notes[i].getHD()[1] == month){
                    cout << Notes[i] << endl;
                }
            }
        }
        else if(choose == 4){
            Notes.clear();
            break;
        }
    }
    return 0;
}

