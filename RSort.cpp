#include <iostream>
#include <string>
#include "stackQueue.cpp"
using namespace std;

class RSort{
  public:
  
  LLQueue hashTable[2][256];
  string data;
  int currentTable;
  int longestStringLength;
  int currentPosition;

  RSort(){
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 256; j++){
        hashTable[i][j] = LLQueue();
      }
    }
  }

  void firstReading(ifstream &inFile, ofstream &outFile){
    outFile << "Performing first Reading" << endl;
    string data;
    inFile >> data;
    longestStringLength = data.length();
    while(inFile >> data){
      if (data.length() > longestStringLength){
        longestStringLength = data.length();
      }
    }
  }

  string padString(string data){
    string pad = data;
    if (data.length() < longestStringLength){
      for (int i = data.length(); i < longestStringLength; i++){
        pad += " ";
      }
    }
    return pad;
  }

  LLStack* loadStack(ifstream &inFile, ofstream &outFile){
    outFile << "Performing first Reading" << endl;
    cout << "sdfsdf1" << endl;
    LLStack *S = new LLStack();
    string data;
    inFile >> data;
    string paddedData;
    while (inFile >> data){
      paddedData = padString(data);
      listNode newNode(paddedData);
      (*S).push(&newNode);
    }
    return S;
  }

  char getChar(listNode *node, int currentPostion){
     return (*node).data.at(currentPosition);
  }

  void addTail(LLQueue *queue, listNode *node){
    (*queue).insertQ(node);
  }

  listNode* deleteHead(LLQueue *queue){
    return (*queue).deleteQ();
  }

  void moveStack(LLStack *S, int currentPosition, int currentTable, ofstream &outFile){
    outFile << "Performing moveStack" << endl;
    while ((*S).isEmpty() == false){
      listNode node = (*(*S).pop());
      char chr = getChar(&node, currentPosition);
      int hashIndex = (int)chr;
      addTail(&hashTable[currentTable][hashIndex], &node);
    }
  }

  void printTable(int table, ofstream &outFile){
    for (int i = 0; i < 256; i++){
      if (!hashTable[table][i].isEmpty()){
        outFile << "Table [" << table << "][" << i << "]:" << endl;
        hashTable[table][i].printQueue(outFile);
      }
    }
  }

  void printSortedData(int table, ofstream &outFile){
    
  }
};