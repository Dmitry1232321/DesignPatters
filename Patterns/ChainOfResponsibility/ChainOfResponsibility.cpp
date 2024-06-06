#include <iostream>
#include <vector>

using namespace std;


/*
    1. ������ ����� ���� ��������� ����� ��� ����� ��������, ������ ��������� ���������� ������� ���������� � ������ ���� ������ �������������.

    2. ������ ������ ���� ��������� ������ �� ���������� ��������, ��� ������ ��������, ������ ������.

    3. ����� ��������, ��������� ���������� ������, ������ ���������� �����������.
*/


class HelpHandler
{
protected:

  HelpHandler* handler;

  HelpHandler(HelpHandler* hand) : handler(hand) { }

public:

  virtual void HandleHelp()
  {
    if (handler)
      handler->HandleHelp();
  }

  virtual bool HasHelp()
  {
    return true;
  }

};


class Button : public HelpHandler
{
public:

  Button(HelpHandler* hand) : HelpHandler(hand) { }
  
  void HandleHelp() override
  {
    if (HasHelp())
      cout << "Show button's help menu \n";
    else
      HelpHandler::HandleHelp();
  }

  bool HasHelp() override
  {
    return false;
  }
};


class Window : public HelpHandler
{
public:

  Window(HelpHandler* hand) : HelpHandler(hand) { }
  
  void HandleHelp() override
  {
    if (HasHelp())
      cout << "Show window's help menu \n";
    else
      HelpHandler::HandleHelp();
  }

  bool HasHelp() override
  {
    return false;
  }
};


class Application : public HelpHandler
{
public:

  Application() : HelpHandler(nullptr) { }
  
  void HandleHelp() override
  {
    if (HasHelp())
      cout << "Show application's help menu \n";
    else
      HelpHandler::HandleHelp();
  }
};


int main()
{
  Application app;
  Window win(&app);
  Button btn(&win);

  btn.HandleHelp();
}