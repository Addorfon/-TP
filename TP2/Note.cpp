#include "Note.h"

#include <iostream>
#include <string>
#include <sstream>

Note::Note(){
    std::cout << "Note default constructor called" << std::endl;
};

Note::Note(const std::string name, const std::string phone, std::array<int, 3> hd){
    std::cout << "Note constructor called" << std::endl;
    setName(name);
    setPhone(phone);
    setHD(hd);
};

Note::~Note(){
    std::cout << "Note destructor called" << std::endl;
}

std::string Note::getName()  {
    return this->name;
}

std::string Note::getPhone()  {
    return this->phone;
}

std::array<int, 3> Note::getHD()  {
    return this->hd;
}

void Note::setName(std::string name) {
    this->name = name;
}

void Note::setPhone(std::string phone) {
    this->phone = phone;
}

void Note::setHD(std::array<int, 3> hd) {
    this->hd = hd;
}

std::istream& operator>>(std::istream& is, Note& other){
    std::string name, phone;
    std::array<int, 3> hd;

    is.ignore();

    std::cout << "Enter name and surname: ";
    std::getline(is, name);
    std::cout << "Enter phone: ";
    std::getline(is, phone);
    std::cout << "Enter birthday (DD.MM.YYYY): ";
    std::string birthday;
    std::getline(is, birthday);

    std::istringstream iss(birthday);
    char dot;
    iss >> hd[0] >> dot >> hd[1] >> dot >> hd[2];

    other.setName(name);
    other.setPhone(phone);
    other.setHD(hd);
    return is;
};

std::ostream& operator<<(std::ostream& os, Note& other) {
    os << "Name: " << other.getName() << ", Phone: " << other.getPhone() << ", HD: ";
    for (int num : other.getHD()) {
        os << num << " ";
    }
    return os;
};
