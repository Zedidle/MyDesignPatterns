#include "iostream"
using namespace std;


namespace Prototype
{


//work model类
class WorkModel
{
public:
	const char* modelName;
	void setWorkModelName(const char* iName) {
		this->modelName = iName;
	}
};


//抽象原型类PrototypeWork
class PrototypeWork
{
public:
	PrototypeWork() {}
	virtual PrototypeWork* clone() = 0;

private:

};

//具体原型类ConcreteWork
class ConcreteWork :public PrototypeWork
{
public:
	ConcreteWork() {}
	ConcreteWork(const char *iName, int iIdNum, const char* modelName) {
		this->name = iName;
		this->idNum = iIdNum;
		this->workModel = new WorkModel();
		this->workModel->setWorkModelName(modelName);
	}

	ConcreteWork* clone() {
		ConcreteWork* work = new ConcreteWork();
		work->setName(this->name);
		work->setIdNum(this->idNum);
		work->workModel = this->workModel;
		return work;
	}

	void setName(const char* iName) {
		this->name = iName;
	}
	void setIdNum(int iIdNum) {
		this->idNum = iIdNum;
	}
	void setModel(WorkModel* iWorkModel) {
		this->workModel = iWorkModel;
	}
	//打印work信息
	void printWorkInfo() {
		printf("name:%s\t\n", this->name);
		printf("idNum:%d\t\n", this->idNum);
		printf("modelName:%s\t\n", this->workModel->modelName);
	}
private:
	const char* name;
	int idNum;
	WorkModel* workModel;
};

}
