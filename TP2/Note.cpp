#include "Note.h"

#include <iostream>
#include <string>

Note::Note(){
    std::cout << "Note default constructor called" << std::endl;
    std::string n, p;
    std::array<int, 3> h;
    std::cout << "Введите вашу фамилию и имя: ";
    std::cin >> n;
    std::cout << "Введите ваш номер телефона: ";
    std::cin >> p;
    std::cout << "Введите год вашего рождения: ";
    std::cin >> h[2];
    std::cout << "Введите месяц вашего рождения: ";
    std::cin >> h[1];
    std::cout << "Введите день вашего рождения: ";
    std::cin >> h[0];

    setName(n);
    setPhone(p);
    setHD(h);
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

std::string Note::getName(){
    return this->name;
}

std::string Note::getPhone(){
    return this->phone;
}

std::array<int, 3> Note::getHD(){
    return this->hd;
}

void Note::setName(const std::string name) {
    this->name = name;
}

void Note::setPhone(const std::string phone) {
    this->phone = phone;
}

void Note::setHD(std::array<int, 3> hd){
    this->hd = hd;
}

std::istream& operator>>(std::istream& is, Note& other){
    std::string name, phone;
    std::array<int, 3> hd;
    is >> name >> phone >> hd[0] >> hd[1] >> hd[2];
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
