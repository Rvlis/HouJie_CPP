#ifndef CAT_H
#define CAT_H
#include <iostream>
#include <string>

using namespace std;

class Cat {
public:
    Cat(string name);
    Cat();
    ~Cat();
    void cat_info() const {
        cout << "cat info name: " << name << endl;
    }
    string get_name() const {
        return name;
    }
    void set_name(const string& name) {
        this->name = name;
    }
private:
    string name = "mimi";
};

#endif