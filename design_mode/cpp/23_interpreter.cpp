 // ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ

#include <iostream>
#include <vector>

using namespace std;

class Content;

class Interpreter {
public:
  virtual void Interpret(Content* content) = 0;
};

class TerminalExpression : public Interpreter {
public:
  void Interpret(Content* content) {
    cout << "�ն˽�����" << endl;
  }
};

class NontermialExpression :public Interpreter {
public:
  void Interpret(Content* content) {
    cout << "���ն˽�����" << endl;
  }
};

class Content {
private:
  string date_ = "";
};

int main23()
{
  Content* content = new Content();
  vector<Interpreter*> interpre;
  interpre.push_back(new TerminalExpression());
  interpre.push_back(new NontermialExpression());
  interpre.push_back(new NontermialExpression());
  
  for (vector<Interpreter*>::iterator i = interpre.begin(); i != interpre.end(); i++) {
    (*i)->Interpret(content);
  }

	return 0;
}