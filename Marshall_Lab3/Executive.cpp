// Jacob Marshall // 2876707 // EECS560 // Lab3 // 17 Sept 2018 //
#include<iostream>
#include<fstream>
#include<string>
#include"HashTableDH.h"
#include"HashTableQP.h"
#include"Executive.h"
using namespace std;


Executive::Executive(string theFile){
  fileToOpen = theFile;
  run();

}


void Executive::run(){
  ifstream inFile;
  inFile.open(fileToOpen);
  
  HashTableDH* htdh = new HashTableDH(53);
  HashTableQP* htqp = new HashTableQP(53);
  string newData;
  int intnewData;
  while (inFile >> newData) {
    intnewData = stoi(newData);
    htqp->insert(intnewData);
    htdh->insert(intnewData);
  }
  bool quit;
  quit = false;
  while(quit == false){
    cout<<"\nPlease choose one of the following commands: \n";
    cout<<"1-Insert\n";
    cout<<"2-Delete\n";
    cout<<"3-Find\n";
    cout<<"4-Print\n";
    cout<<"5-Exit\n";
    cout<<">";
    string command;
    cin>>command;
    if(command == "1"){
      cout<<"Enter a string to be inserted:\n>";
      string insertion;
      cin>>insertion;
      int intinsertion = stoi(insertion);
      htqp->insert(intinsertion);
      htdh->insert(intinsertion);
      cout<<"Load factor of hash table with quadratic probing is: "<<htqp->getLoadFactor()<<"\n"; 
      cout<<"Load factor of hash table with double hashing is: "<<htdh->getLoadFactor()<<"\n";  
    }
    if(command == "2"){
      cout<<"Enter a string to delete:\n>";
      string deletion;
      cin>>deletion;
      int intdeletion = stoi(deletion);
      htqp->deleteEntry(intdeletion);
      htdh->deleteEntry(intdeletion);
      cout<<"Load factor of hash table with quadratic probing is: "<<htqp->getLoadFactor()<<"\n"; 
      cout<<"Load factor of hash table with double hashing is: "<<htdh->getLoadFactor()<<"\n"; 
    }
    if(command == "3"){
      cout<<"Enter a string to be found:\n>";
      string find;
      cin>>find;
      int intfind = stoi(find);
      if(htqp->find(intfind) == true){
        cout<<find<<" is found in the hash table using quadratic probing. \n";
      }
      else{
        cout<<find<<" is not found in the hash table using quadratic probing. \n";
      }
      if(htdh->find(intfind) == true){
        cout<<find<<" is found in the hash table using double hashing. \n";
      }
      else{
        cout<<find<<" is not found in the hash table using double hashing. \n";
      }

    }
    if(command == "4"){
      htqp->printAll();
      htdh->printAll();
    }
    if(command == "5"){
      cout<<"Byebye! \n\n\n\n\n\n\n\n\n\n\n";
      quit = true;
    }

  }


}
