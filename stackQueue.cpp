#include <iostream>
#include <string>
#include "listNode.cpp"
#include <fstream>
using namespace std;

class LLStack{
  private:

  listNode *top;
  friend class listNode;
  friend class Rsort; 

  public:

  LLStack(){
    listNode dummy("dummyNode");
    top = &dummy;
  }

  void push(listNode *node){
    listNode *prev = (*top).next; 
    (*top).next = node;
    (*node).next = prev;
  }

  listNode* pop(){
    if ((*top).next != nullptr){
      listNode *prevTop = (*top).next;
      (*top).next = (*(*top).next).next;
      return prevTop;
    }
  }

  bool isEmpty(){
    if ((*top).next == nullptr){
      return true;
    }
    else{
      return false;
    }
  }

  static void printStack(LLStack *S, ofstream &outFile){
    outFile << "Printing Stack" << endl;
    listNode *trav = (*S).top;
    while ((*trav).next != nullptr){
      (*trav).printNode(outFile);
      cout << 6 << endl;
      trav = ((*trav).next);
      cout << 7 << endl;
    }
    cout << 8 << endl;
  }

};

class LLQueue{

  private:
  
  friend class Rsort; 
  listNode *head = nullptr;
  listNode *tail = nullptr;

  public:

  LLQueue(){
    listNode dummy("dummyNode");
    head = tail = &dummy;
  }

  void insertQ(listNode *node){
    tail = (*tail).next = node;
  }

  listNode* deleteQ(){
    listNode *deleted = (*head).next;
    (*head).next = (*(*head).next).next;
    return deleted;
  }

  bool isEmpty(){
    if (head == tail){
      return true;
    }
    else{
      return false;
    }
  }

  void printQueue(ofstream &outFile){
    listNode trav = *head;
    while (trav.next != nullptr){
      trav.printNode(outFile);
      trav = (*(trav).next);
    }

  }

};