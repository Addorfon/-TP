#ifndef TP2_NOTE_N
#define TP2_NOTE_N

#include <iostream>
#include <string>

class Note {
private:
    std::string surname;
    std::string name;
    std::string phone;
    int hd[3];
public:
    Note();
    Note(const std::string surname, const std::string name, const std::string phone, const int hd[3]);
    ~Note();
    std::string getName();
    std::string getSurname();
    std::string getPhone;
    int *getHD();

};


#endif