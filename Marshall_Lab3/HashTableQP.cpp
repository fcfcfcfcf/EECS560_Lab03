// Jacob Marshall // 2876707 // EECS560 // Lab2 // 17 Sept 2018 //

#include<math.h>
#include "HashTableQP.h"
using namespace std;




HashTableQP::HashTableQP(int size){
    for(int i =0; i < hashTableSize; i++){
        buckets[i] = -1;
        flags[i] = false;
    }
}

HashTableQP::~HashTableQP(){
    delete[] buckets;
}


double HashTableQP::getLoadFactor(){

}

void HashTableQP::deleteEntry(string x){
    int index = hash(x);
    if(find(x) == false){
        cout<<x<<" could not be found with quadratic probing, could not be deleted";
    }
    else{
        buckets[index] = -1;
    }

}

void HashTableQP::printAll(){
    cout<<"Hash table with quadratic probing: \n";
    for(int i =0; i < hashTableSize; i++){
        if(buckets[i] != -1){
            cout<<"Bucket "<<i<<": "<<buckets[i]<<"\n";
        }
    }
}

void HashTableQP::insert(int x){
    int index = hash(x);
    if(buckets[index] == -1){
        buckets[index] = x;
        flags[index] = true;
    }
    else if(buckets[index] == x){
        cout<<x<<" is already included in the hash table. \n";
    }
    else{
        cout<<x<<" could not be inserted in the hash tbale. \n";
    }
}

bool HashTableQP::find(int x){
    int index = hash(x);
    if(index == -1){
        return false;
    }
    else{
        if(buckets[index] == x){
            return true;
        }
        else{
            return false;
        }
    }



}

int HashTableQP::hash(int x){
  int hashNum = 0;
  int i = 0;
  int hashMax = 10;
  int indexToSearch = x%hashTableSize;
  for(int i = 0; i < hashMax + 1; i++){
      if(i == hashMax){
          indexToSearch = -1;
          break;
      }
      else if(buckets[indexToSearch] == -1){
          if(flags[indexToSearch] == false){
              break;
          }
      }
      else if(buckets[indexToSearch] == x){
          break;
      }
      else{
          indexToSearch = (indexToSearch + pow(i, 2))%hashTableSize;
      }
  }
  return indexToSearch;
}
