 // ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ���ģʽ

#include <iostream>
#include <vector>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

class Component {
public:
	Component() {}
	Component(string name) {
		name_ = name;
	}

	virtual void Add(Component* component) = 0;
	virtual void Remove(Component* component) = 0;
	virtual void Display(int depth) = 0;

public:
	string name_ = "";
};

// Ҷ�ӽ��
class Leaf : public Component {
public:
	Leaf(string name) {
		name_ = name;
	}

	void Add(Component* component) {
		cout << "not have a component" << endl;
	}

	void Remove(Component* component) {
		cout << "not have a component" << endl;
	}

	void Display(int depth) {
		for (int n = 0; n < depth; n++) {
			cout << "-";
		}
		cout << name_ << endl;
	}; 
};

// ���
class Composite : public Component {
public:
	Composite(string name) {
		name_ = name;
	}

	void Add(Component* component) {
		component_vector_.push_back(component);
	}

	void Remove(Component* component) {
		component_vector_.emplace_back(component);
	}

	// �����ý�㣬�Լ��ý��ӵ�е��ӽڵ�
	void Display(int depth) {
		for (int n = 0; n < depth; n++) {
			cout << "-";
		}
		cout << name_ << endl;

		for (auto iter = component_vector_.begin(); iter != component_vector_.end(); iter++) {
			(*iter)->Display(depth + 2);
		}
	}

private:
	vector<Component*> component_vector_;
};

int main()
{
	// ���ڵ㼰����Ҷ�ӽ��
	Composite* root = new Composite("root");
	root->Add(new Leaf("leaf_a"));
	root->Add(new Leaf("leaf_b"));

	// �ӽ��һ��������Ҷ�ӽ��
	Composite* comp_1 = new  Composite("comp_1");
	comp_1->Add(new Leaf("comp1_a"));
	comp_1->Add(new Leaf("comp1_b"));

	// �ӽ��һ���ڸ��ڵ���
	root->Add(comp_1);
	
	// �ӽ�����������Ҷ�ӽ��
	Composite* comp_2 = new  Composite("comp_2");
	comp_2->Add(new Leaf("comp2_a"));
	comp_2->Add(new Leaf("comp2_b"));

	// �ӽ��������ӽ��һ��
	comp_1->Add(comp_2);

	// �ӽ������������Ҷ�ӽ��
	Composite* comp_3 = new  Composite("comp_3");
	comp_3->Add(new Leaf("comp3_a"));
	comp_3->Add(new Leaf("comp3_b"));

	// �ӽ�������ڸ��ڵ���
	root->Add(comp_3);

	// �Ӹ��ڵ㿪ʼ����
	root->Display(1);

	SAFE_DELETE(comp_3);
	SAFE_DELETE(comp_2);
	SAFE_DELETE(comp_1);
	SAFE_DELETE(root);

	return 0;
}