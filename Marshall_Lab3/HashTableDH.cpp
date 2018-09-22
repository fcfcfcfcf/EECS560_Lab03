// Jacob Marshall // 2876707 // EECS560 // Lab2 // 17 Sept 2018 //

#include<math.h>
#include "HashTableDH.h"
using namespace std;




HashTableDH::HashTableDH(int size){
    for(int i =0; i < hashTableSize; i++){
        buckets[i] = -1;
        flags[i] = false;
    }
}

HashTableDH::~HashTableDH(){
    delete[] buckets;
}


double HashTableDH::getLoadFactor(){

}

void HashTableDH::deleteEntry(int x){
    int index = hash(x);
    if(find(x) == false){
        cout<<x<<" could not be found with doulbe hashing, could not be deleted";
    }
    else{
        buckets[index] = -1;
    }

}

void HashTableDH::printAll(){
    cout<<"Hash table with double hashing: \n";
    for(int i =0; i < hashTableSize; i++){
        if(buckets[i] != -1){
            cout<<"Bucket "<<i<<": "<<buckets[i]<<"\n";
        }
    }
}

void HashTableDH::insert(int x){
    int index = hash(x);
    if(buckets[index] == -1){
        buckets[index] = x;
        flags[index] = true;
    }
    else if(buckets[index] == x){
        cout<<x<<" is already included in the hash table. \n";
    }
    else{
        cout<<x<<" could not be inserted in the hash table with doulbe hashing. \n";
    }
}

bool HashTableDH::find(int x){
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

int HashTableDH::hash(int x){
  int hashNum = 0;
  int i = 0;
  int hashMax = 10;
  int prime = 13;
  int indexToSearch = x%hashTableSize;
  int hash1 = indexToSearch;
  int hash2 = (prime - (x%prime));
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
          if(i == 0){
              indexToSearch = hash2;
          }
          else{
              indexToSearch = (hash1 + i*hash2)%hashTableSize;
          }
      }
  }
  return indexToSearch;
}

