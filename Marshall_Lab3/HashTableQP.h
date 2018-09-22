// Jacob Marshall // 2876707 // EECS560 // Lab2 // 17 Sept 2018 //
#ifndef HASHTABLEQP_H
#define HASHTABLEQP_H


#include<string>
#include<iostream>
using namespace std;

class HashTableQP{
  public:
    //Contrcutor of HashTable, creates a HashTable with the passed in size
    HashTableQP(int size);

    //Destructor, deletes the HashTable
    ~HashTableQP();

    //inserts a given string into the hashTable, first checking to see if it already exists, and then hashes the string and inserts it into the correct list. Returns true if insetion is succesful
    void insert(int x);

    //deletes a given string from the hashTable, returns true if deletion is succesful
    void deleteEntry(int x);

    //finds a given string in the hashTable, returns true if the string is found
    bool find(int x);

    //uses the hash formula given in order to calculate the correct index that a given string should be hashed to, returns that index
    int hash(int x);

    //prints out the contents of each bucket
    void printAll();


    double getLoadFactor();

  private:
    //size of the hash table
    const static int hashTableSize = 53;
    int buckets[hashTableSize];
    bool flags[hashTableSize];
    int tableSize;

};
#endif
