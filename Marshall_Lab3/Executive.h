// Jacob Marshall // 2876707 // EECS560 // Lab3 // 17 Sept 2018 //
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include<string>
#include"HashTableDH.h"
#include"HashTableQP.h"
using namespace std;

class Executive{
  public:
    Executive(string file);
    void run();
  private:
    string fileToOpen;
    HashTableDH* htdh;
    HashTableQP* htqp;

};

#endif
