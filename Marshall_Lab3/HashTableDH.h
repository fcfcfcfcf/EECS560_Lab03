// Jacob Marshall // 2876707 // EECS560 // Lab3 // 24 Sept 2018 //
#ifndef HASHTABLEDH_H
#define HASHTABLEDH_H
#include<string>
#include<iostream>
using namespace std;

class HashTableDH{
  public:
    //Contrcutor of HashTable, creates a HashTable with the passed in size
    HashTableDH(int size);

    //Destructor, deletes the HashTable
    ~HashTableDH();

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

     //calculates and returns the loadfactor for the hashTable
    double getLoadFactor();

  private:
    //size of the hash table
    const static int hashTableSize = 53;

    //array that stores ints, each indice is an indice of the hashTable
    int buckets[hashTableSize];

    //mirrors the HashTable, each index corresponds to an index in the HashTable, flag ticks from 0 to 1 when an int is inseted into that index of the hashTable for the first time
    bool flags[hashTableSize];

    //stores the value of the hashTable, we don't use this because it's not going to change.
    int tableSize;

};
#endif
