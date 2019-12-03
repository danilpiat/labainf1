#ifndef ANIMAL_H
#define ANIMAL_H


#include <iostream>
#include <string>


class Animal
{
    std::string name;
    int age;

public:
    Animal() : name("Sharik"), age(10) {}
    Animal(std::string name, int age) : name(name), age(age) {}

    std::string getName() const;
    int getAge() const;

    bool operator ==(const Animal& a);
    bool operator !=(const Animal& a);

    friend std::ostream& operator<<(std::ostream& os, const Animal& a);
};


#endif // ANIMAL_H
