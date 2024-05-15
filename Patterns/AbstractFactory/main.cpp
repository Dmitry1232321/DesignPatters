#include <iostream>

using namespace std;


/*
    ������� ������������� ����� �� �������� ��������
*/


class ScrollBar
{
};

class WinScrollBar : public ScrollBar
{
public:
  WinScrollBar()
  {
    cout << "Create Windows scrollbar \n";
  }
};

class LinuxScrollBar : public ScrollBar
{
public:
  LinuxScrollBar()
  {
    cout << "Create Linux scrollbar \n";
  }
};



class Button
{
};

class WinButton : public Button
{
public:
  WinButton()
  {
    cout << "Create Windows button \n";
  }
};

class LinuxButton : public Button
{
public:
  LinuxButton()
  {
    cout << "Create Linux button \n";
  }
};



class ControlFactory
{
public:
  virtual ScrollBar CreateScrollBar() = 0;
  virtual Button CreateButton() = 0;
};

class WindowsControlFactory : public ControlFactory
{
public:
  ScrollBar CreateScrollBar() override
  {
    return WinScrollBar();
  }

  Button CreateButton() override
  {
    return WinButton();
  }
};

class LinuxControlFactory : public ControlFactory
{
public:
  ScrollBar CreateScrollBar() override
  {
    return LinuxScrollBar();
  }

  Button CreateButton() override
  {
    return LinuxButton();
  }
};



void createControls(ControlFactory& factory)
{
  Button button = factory.CreateButton();
  ScrollBar scrollBar = factory.CreateScrollBar();
}

int main()
{
  ControlFactory* factory = new LinuxControlFactory();
  
  createControls(*factory);
  
  delete factory;
}