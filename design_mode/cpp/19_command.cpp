// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ����ģʽ

#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

// ������ ��
class Receiver {
public:
  void Action() {
    cout << "receive do action." << endl;
  }
};

// ������ ������
class Command {
public:
  virtual void SetReceiver(Receiver* receiver) = 0;
  virtual void Execute() = 0;

protected:
  Receiver* receiver_ = nullptr;
};

// ʵ�������� ��
class ConcreteCommand : public Command {
public:
  void SetReceiver(Receiver* receiver) {
    receiver_ = receiver;
  }

  void Execute() {
    if (receiver_) {
      receiver_->Action();
    }
  }
};

// ������ ��
class Invoker {
public:
  void SetCommand(Command* command) {
    command_ = command;
  }

  void ExecuteCommand() {
    command_->Execute();
  }

private:
  Command* command_ = nullptr;
};


int main()
{
  Receiver* receiver = new Receiver();
  Command* command = new ConcreteCommand();
  command->SetReceiver(receiver);
  Invoker* invoker = new Invoker();
  invoker->SetCommand(command);

  invoker->ExecuteCommand();

  SAFE_DELETE(invoker);
  SAFE_DELETE(command);
  SAFE_DELETE(receiver);

	return 0;
}


