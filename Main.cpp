#include <iostream>
#include <string>
#include <fstream>
#include "RSort.cpp"
using namespace std;

int main(int argc, char* argv[]){

ifstream inFile;
ofstream outFile1;
ofstream outFile2;
inFile.open(argv[1]);
outFile1.open(argv[2]);
outFile2.open(argv[3]); 
RSort rsort;
rsort.firstReading(inFile, outFile2);
inFile.close();
inFile.open(argv[1]); 
LLStack *S = rsort.loadStack(inFile, outFile2);
LLStack::printStack(S, outFile2);
cout << "sdfsdf2" << endl;
int currentPosition = rsort.longestStringLength - 1;
int currentTable = 0;
rsort.moveStack(S ,currentPosition, currentTable, outFile2);

int nextTable = 0;
while (currentPosition > 0){
currentPosition--;
int currentQueue = 0;
nextTable = (currentTable + 1) % 2;
  while (currentQueue < 256){
    while (!rsort.hashTable[currentTable][currentPosition].isEmpty()){
      listNode *node = rsort.deleteHead((&rsort.hashTable[currentTable][currentQueue]));
      char chr = rsort.getChar(node, currentPosition);
      int hashIndex = int(chr);
      rsort.addTail(&rsort.hashTable[nextTable][hashIndex], node);
    }
    currentQueue++;
  }
  rsort.printTable(nextTable, outFile1);
  currentTable = nextTable;
}

//rsort.printSortedData(nextTable, outFile1);

outFile1.close();
outFile2.close();
}
  