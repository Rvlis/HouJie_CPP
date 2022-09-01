#include <iostream>
#include <memory>
#include "cat.h"
using namespace std;

//int main() {
//   /* Cat c1("OK");
//    c1.cat_info();
//    {
//        Cat c1("not OK");
//        c1.cat_info();
//    }*/
//
//    /*Cat* c_p1 = new Cat("yy");
//    c_p1->cat_info();
//    {
//        Cat* c_p2 = new Cat("oo");
//        c_p2->cat_info();
//        delete c_p2;
//        c_p2 = nullptr;
//    }
//    delete c_p1;
//    c_p1 = nullptr;*/
//    //Cat* c_p2 = new Cat("xy");
//    //unique_ptr<Cat> u_c_p1(c_p2);
//    ///*c_p2->cat_info();*/
//    //delete c_p2;
//    //c_p2 = nullptr;
//    //u_c_p1->cat_info();
//    /*unique_ptr<Cat> u_c_p2(new Cat("dd"));
//    u_c_p2->cat_info();
//    u_c_p2->set_name("oo");
//    u_c_p2->cat_info();*/
//
//    //unique_ptr<Cat> u_c_p3 = make_unique<Cat>();
//    //u_c_p3->cat_info();
//    //u_c_p3->set_name("hoho");
//    //u_c_p3->cat_info();
//
//    //unique_ptr<int> u_i_p1 = make_unique<int>(100);
//    //cout << u_i_p1.get() << endl;
//    //cout << *u_i_p1 << endl;
//    //cout << u_c_p3.get() << endl;
//
//
//
//    cout << "----------------" << endl;
//    return 0;
//}