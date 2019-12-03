#include <iostream>
#include <string>

#include "Animal.h"


std::string Animal::getName() const
{
    return name;
}

int Animal::getAge() const
{
    return age;
}

bool Animal::operator==(const Animal& a)
{
    return (name == a.getName() &&
            age  == a.getAge());
}

bool Animal::operator!=(const Animal& a)
{
    return !(*this == a);
}

std::ostream& operator<<(std::ostream& os, const Animal& a)
{
    std::cout << "Name: " << a.getName() << std::endl << "Age: " << a.getAge() << "\n\n";
    return os;
}
