#include "cat.h"

Cat::Cat() {};
Cat::Cat(string name) : name(name) {
    std::cout << "Constructor of Cat: " << this->name << std::endl;
};

Cat::~Cat() {
    std::cout << "Destructor of Cat: " << this->name << std::endl;
};
