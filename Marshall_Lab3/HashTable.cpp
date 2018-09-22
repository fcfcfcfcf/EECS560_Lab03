#include<math.h>
#include"HashTable.h"
#include"Node.h"

using namespace std;


HashTable::HashTable(int size){
    tablesize = size;
    
}

HashTable::~HashTable(){
    delete[] buckets;
}


