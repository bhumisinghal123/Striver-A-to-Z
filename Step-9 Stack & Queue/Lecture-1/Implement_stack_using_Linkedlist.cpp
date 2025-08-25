#include <bits/stdc++.h>
using namespace std;

class stackNode
{
public:
  int data;
  stackNode *next;

  stackNode(int value)
  {
    data = value;
    next = nullptr;
  }
};

class MyStack
{
private:
  stackNode *top;
  int size;

public:
  MyStack()
  {
    top = nullptr;
    size = 0;
  }

  void stackPush(int x)
  {
    stackNode *element = new stackNode(x);
    element->next = top;
    top = element;
    cout << "Element pushed: " << x << "\n";
    size++;
  }

  void stackPop()
  {
    if (isEmpty())
    {
      cout << "Stack Underflow! Cannot pop.\n";
      return;
    }
    stackNode *temp = top;
    top = top->next;
    cout << "Element popped: " << temp->data << "\n";
    delete temp;
    size--;
  }

  int stackPeek()
  {
    if (isEmpty())
    {
      cout << "Stack is empty!\n";
      return -1;
    }
    return top->data;
  }

  bool isEmpty()
  {
    return top == nullptr;
  }

  int getSize()
  {
    return size;
  }

  void display()
  {
    if (isEmpty())
    {
      cout << "Stack is empty!\n";
      return;
    }
    cout << "Stack elements: ";
    stackNode *temp = top;
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "\n";
  }
};

int main()
{
  MyStack s;

  s.stackPush(10);
  s.stackPush(20);
  s.stackPush(30);
  s.display();

  cout << "Top element: " << s.stackPeek() << "\n";
  s.stackPop();
  s.display();

  cout << "Size of stack: " << s.getSize() << "\n";

  return 0;
}
