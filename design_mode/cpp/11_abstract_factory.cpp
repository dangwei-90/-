// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ���󹤳�ģʽ

// ���ֹ���ģʽ������
// �򵥹���ģʽ ���ɿͻ���֪ͨ���������������Ʒ�Ķ���
// ����ģʽ     ���ɿͻ���ѡ�񴴽������Ʒ�Ķ���
// ���󹤳�ģʽ ���ͻ��˲���Ҫ���Ĳ�ͬ�����ľ���ʵ�֣�ֻ��Ҫ���ù����ṩ�Ľӿڼ��ɡ�

#include <iostream>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

using namespace std;

// ������û���Ϣ��
class User {
public:
	string getname() {
		return name_;
	}
	void setname(string name) {
		name_ = name;
	}

	int getid() {
		return id_;
	}

	void setid(int id) {
		id_ = id;
	}

private:
	string name_ = "";
	int id_ = 0;
};

// �����û���Ϣ�ĳ����࣬��Ϊ�ӿ�
class IOperateUserDB {
public:
	virtual void insert(User* user) = 0;
	virtual User* select(int id) = 0;
};

// �����û���Ϣ�ľ���ʵ����
class SqlOperateUserDB :public IOperateUserDB {
public:
	void insert(User* user) {
		cout << "sql insert user " << user->getname() << endl;
	}

	User* select(int id) {
		cout << "sql select id " << id << "from user table" << endl;
		return nullptr;
	}
};

// �����û���Ϣ�ľ���ʵ����
class AccessOperateUserDB :public IOperateUserDB {
public:
	void insert(User* user) {
		cout << "access insert user " << user->getname() << endl;
	}

	User* select(int id) {
		cout << "access select id " << id << "from user table" << endl;
		return nullptr;
	}
};

// ����Ĳ�����Ϣ��
class Department {
public:
	void setid(int id) {
		id_ = id;
	}
	int getid() {
		return id_;
	}
private:
	int id_ = 0;
};

// ����������Ϣ�ĳ����࣬��Ϊ�ӿ�
class IOperatePartDB {
public:
	virtual void insert(Department* department) = 0;
	virtual Department* select(int id) = 0;
};

// ����������Ϣ�ľ���ʵ����
class SqlOperatePartDB :public IOperatePartDB {
public:
	void insert(Department* department) {
		cout << "sql insert department " << department->getid() << endl;
	}

	Department* select(int id) {
		cout << "sql select id " << id << "from department table" << endl;
		return nullptr;
	}
};

// ����������Ϣ�ľ���ʵ����
class AccessOperatePartDB :public IOperatePartDB {
public:
	void insert(Department* department) {
		cout << "access insert department " << department->getid() << endl;
	}

	Department* select(int id) {
		cout << "access select id " << id << "from department table" << endl;
		return nullptr;
	}
};

/*
// ��������ӿ�
class IFactory {
public:
	virtual IOperateUserDB* CreateUser() {
		return nullptr;
	}
	virtual IOperatePartDB* CreateDepartment() {
		return nullptr;
	}
};

// ����Ĺ���ʵ���࣬ʵ���˴��������û�/���Ŷ���ķ���
class SqlServerFactory : public IFactory{
public:
	IOperateUserDB* CreateUser() {
		return new SqlOperateUserDB();
	}
	IOperatePartDB* CreateDepartment() {
		return new SqlOperatePartDB();
	}
};

// ����Ĺ���ʵ���࣬ʵ���˴��������û�/���Ŷ���ķ���
class AccessFactory : public IFactory {
public:
	IOperateUserDB* CreateUser() {
		return new AccessOperateUserDB();
	}
	IOperatePartDB* CreateDepartment() {
		return new AccessOperatePartDB();
	}
};
*/

// �������ô�����ͬ�Ĳ����û�/���ŵĶ���
class ControlDatabase {
public:
	IOperateUserDB* CreateUser() {
		IOperateUserDB* opera_user = nullptr;
		switch (dbtype_) {
			case 1:
				opera_user = new SqlOperateUserDB();
				break;
			case 2:
				opera_user = new AccessOperateUserDB();
				break;
			default:
				break;
		}
		return opera_user;
	}

	IOperatePartDB* CreateDepartmentr() {
		IOperatePartDB* idepartment = nullptr;
		switch (dbtype_) {
		case 1:
			idepartment = new SqlOperatePartDB();
			break;
		case 2:
			idepartment = new AccessOperatePartDB();
			break;
		default:
			break;
		}
		return idepartment;
	}

	void setDbtype(int id) {
		dbtype_ = id;
	}
private:
	int dbtype_ = 2; // 1 sql 2 access
};

int main()
{
	/*
	IFactory* ifactory = new SqlServerFactory();
	//IFactory* ifactory = new AccessFactory();

	User* user = new User();
	user->setName("David");
	user->setId(27);
	Department* department = new Department();
	department->setId(297);

	IUser* usercurrent = ifactory->CreateUser();
	usercurrent->insert(user);
	usercurrent->select(27);
	IDepartment* departmentcurrent = ifactory->CreateDepartment();
	departmentcurrent->insert(department);
	departmentcurrent->select(297);
	*/

	ControlDatabase* dbbase = new ControlDatabase();
	dbbase->setDbtype(2);

	User* user = new User();
	user->setname("David");
	user->setid(27);
	Department* department = new Department();
	department->setid(297);

	// �û��Ͳ��ţ�����Ҫ���ľ�������ݿ�������ʵ�֣�ֻ��Ҫ���ýӿڼ���
	IOperateUserDB* usercurrent = dbbase->CreateUser();
	IOperatePartDB* departmentcurrent = dbbase->CreateDepartmentr();
	usercurrent->insert(user);
	usercurrent->select(27);
	departmentcurrent->insert(department);
	departmentcurrent->select(297);

	SAFE_DELETE(usercurrent);
	SAFE_DELETE(departmentcurrent);

	SAFE_DELETE(department);
	SAFE_DELETE(user);

	SAFE_DELETE(dbbase);

	return 0;
}