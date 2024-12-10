#ifndef TP2_NOTE_N
#define TP2_NOTE_N

#include <iostream>
#include <string>
#include <array>

class Note {
private:
    std::string name;
    std::string phone;
    std::array<int, 3> hd;
public:
    Note();
    Note(const std::string name, const std::string phone, std::array<int, 3> hd);
    ~Note();

    std::string getName();
    std::string getPhone();
    std::array<int, 3> getHD();

    void setName(std::string name);
    void setPhone(std::string phone);
    void setHD(std::array<int, 3> hd);

};

std::ostream& operator<<(std::ostream& os, const Note& other); 
std::istream& operator>>(std::istream& is, Note& other); 

#endif