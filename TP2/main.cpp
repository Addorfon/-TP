#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>
#include "Note.h"

using namespace std;

void taskMenu(){
    cout << "1. First task" << endl;
    cout << "2. Second task" << endl;
    cout << "3. Exit" << endl;
}

void menu2(){
    cout << "\n1. Enter our text" << endl;
    cout << "2. Load text from file" << endl;
    cout << "3. Back"<< endl;
}

void menu1() {
    cout << "1. Add student(s)" << endl;
    cout << "2. Show all students" << endl;
    cout << "3. Show students, whose birthdays are in a certain month" << endl;
    cout << "4. Back"<< endl;
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

void checkFirstLetter (char* f){
    if (f[0] == 'a' || f[0] == 'e' || f[0] == 'y' || f[0] == 'u' || f[0] == 'i' || f[0] == 'o'){
        f[0] = toupper(f[0]);
    }
}  

int main()
{   
    vector<Note> Notes;
    int choose;
    int count = 0;
    Note note;
    while (1){
        taskMenu();
        cout << "Enter your choose: ";
        cin >> choose;
        if (choose == 1){
            while(1){
                int choose1 = 0;
                menu1();
                cout << "Enter your choose: ";
                cin >> choose1;
                if (choose1 == 1){
                    cin >> note;
                    Notes.push_back(note);
                }
                else if (choose1 == 2){
                    mySort(Notes);
                    for (int i = 0; i < Notes.size(); ++i){
                        cout << Notes[i] << endl;
                    }
                }   
                else if(choose1 == 3){
                    int month;
                    cout << "Enter number of month, which you want to show: ";
                    cin >> month;
                    for (int i = 0; i < Notes.size(); ++i){
                        if (Notes[i].getHD()[1] == month){
                            cout << Notes[i] << endl;
                        }
                    }
                }
                else if(choose1 == 4){
                    Notes.clear();
                    break;
                }
                else {
                    cout << "Enter correct number for menu!" << endl;
                }
            }
        }
        else if (choose == 2){
            while(1){
                int choose2 = 0;
                menu2();
                cout << "Enter your choose: ";
                cin >> choose2;
                if (choose2 == 1){
                    cin.ignore();
                    char buffer[200] ;
                    cout << "Enter your text:" << endl;
                    cin.getline(buffer,200) ;
                    char * f = strtok(buffer," ") ;
                    while ( f )
                    {
                        checkFirstLetter(f);
                        cout << f << " ";
                        f=strtok(NULL," ") ;
                    }
                }
                else if (choose2 == 2){
                    string filename, line;
                    char buffer[50];
                    cout << "Enter file from file: " << endl;
                    cin >> filename;
                    ifstream file(filename);
                    if (file.is_open()){
                        while (!file.eof()){
                           file >> buffer;
                            checkFirstLetter(buffer);
                            cout << buffer << " ";
                        } 
                        cout << endl;
                    }
                    else{
                        cout << "Unable to open file" << endl;
                    }
                } 
                else if (choose2 == 3){
                    break;
                }
                else {
                    cout << "Enter correct number for menu!" << endl;
                }
            }
        } 
        else if (choose == 3){
            break;
        }
        else {
            cout << "Enter correct number for menu!" << endl;
        }
    }
    return 0;
}

