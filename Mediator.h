#include <iostream>
using namespace std;

namespace Mediator
{

	class Colleague;
	class Landlord;
	class Tenant;
	class Mediator;
	class Agency;

#ifndef __COMMON_H__
#define __COMMON_H__

// 公共头文件

#include <vector>
using namespace std;

enum PERSON_TYPE
{
	NONE_PERSON,
	LANDLORD,
	TENANT
};

#endif  //__COMMON_H__


// 抽象同事类
class Colleague
{
public:
	Colleague() {}
	void setMediator(Mediator* iMediator) {
		this->mediator = iMediator;
	}
	Mediator* getMediator() {
		return this->mediator;
	}
	void setPersonType(PERSON_TYPE iPersonType) {
		this->personType = iPersonType;
	}
	PERSON_TYPE getPersonType() {
		return this->personType;
	}
	virtual void ask() = 0;
	virtual void answer() = 0;
private:
	PERSON_TYPE personType;
	Mediator* mediator;
};

// 具体同事类：租客
class Tenant :public Colleague
{
public:
	Tenant();
	Tenant(string name);
	void ask();
	void answer();
private:
	string name;
};


// 具体同事类：房东
class Landlord :public Colleague
{
public:
	Landlord();
	Landlord(string iName, int iPrice, string iAddress, string iPhoneNum);
	void ask();
	void answer();
private:
	string name;
	int price;
	string address;
	string phoneNumber;
};



// 抽象中介者
class Mediator
{
public:
	Mediator() {}
	// 声明抽象方法
	virtual void operation(Colleague*) = 0;
	// 声明注册方法
	virtual void registerMethod(Colleague*) = 0;
};

// 具体中介者
class Agency :public Mediator
{
public:
	Agency() {}
	void registerMethod(Colleague* person) {
		switch (person->getPersonType()) {
		case LANDLORD:
			landlordList.push_back((Landlord*)person);
			break;
		case TENANT:
			tenantList.push_back((Tenant*)person);
			break;
		default:
			printf("wrong person\n");
		}
	}
	void operation(Colleague* person) {
		switch (person->getPersonType()) {
		case LANDLORD:
			for (int i = 0; i < tenantList.size(); i++) {
				tenantList[i]->answer();
			}
			break;
		case TENANT:
			for (int i = 0; i < landlordList.size(); i++) {
				landlordList[i]->answer();
			}
			break;
		default:
			break;
		}
	}
private:
	vector<Landlord*>landlordList;
	vector<Tenant*>tenantList;
};










Landlord::Landlord() {
	name = "none";
	price = 0;
	address = "none";
	phoneNumber = "none";
	setPersonType(NONE_PERSON);
}

Landlord::Landlord(string iName, int iPrice,
	string iAddress, string iPhoneNum) {
	name = iName;
	price = iPrice;
	address = iAddress;
	phoneNumber = iPhoneNum;
	setPersonType(LANDLORD);
}

void Landlord::answer() {
	printf("房东姓名：%s, 房租：%d, 地址：%s, 联系电话：%s\n",
		name.c_str(), price, address.c_str(), phoneNumber.c_str());
}

void Landlord::ask() {
	printf("房东%s查看租客信息：\n", name.c_str());
	(this->getMediator())->operation(this);
}





Tenant::Tenant() {
	name = "none";
	setPersonType(NONE_PERSON);
}

Tenant::Tenant(string iName) {
	name = iName;
	setPersonType(TENANT);
}

void Tenant::ask() {
	printf("租客%s询问房东信息\n", name.c_str());
	(this->getMediator())->operation(this);
}

void Tenant::answer() {
	printf("租客姓名：%s\n", name.c_str());
}



}
