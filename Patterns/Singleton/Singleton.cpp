#include <iostream>

using namespace std;


/*
    1. ������ ������������ ������ 1 ��������� ������, � �������� ����� ���������� ����� �����
*/

class Singleton
{

  static Singleton instance;

  int data;

public:

  static Singleton& getInstance() 
  {
    return instance;
  }

  int getData() { return data; }
  void setData(int newData) { data = newData; }

};

Singleton Singleton::instance = Singleton();

int main()
{
  Singleton s = Singleton::getInstance();
  cout << "Singleton data = " << s.getData() << endl;
  s.setData(100);
  cout << "Singleton data = " << s.getData() << endl;
}