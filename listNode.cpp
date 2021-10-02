#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class listNode{

  private:

  friend class LLStack;
  friend class LLQueue;
  friend class Rsort;


  public:

  string data;
  listNode *next;

  listNode(string datax){
    data = datax;
  }

  void printNode(ofstream &outFile){
    cout << "1" << endl;
    string text = "";
    if (next == nullptr){
      cout << "2" << endl;
      text = "(" + data + "," + "NULL" + ")-->";
    }
    else{
      cout << "3" << endl;
      text += "(" + data + "," + (next)->data + ")-->";
    }
     cout << "4" << endl;
    outFile << text << endl;
     cout << "5" << endl;
  }

};

