/*
总结

优点：
	实现状态恢复、撤销操作的功能，用户可以恢复到指定的历史状态，让软件系统更加人性化；
	备忘录封装了信息，除了原生器以外，其他对象访问不了备忘录的代码；

缺点：
	资源消耗大。如果需要保存原生器对象的多个历史状态，那么将创建多个备忘录对象；或者如果原生器对象的很多状态都需要保存，也将消耗大量存储资源。

适用环境：
	保存一个对象的历史状态，系统需要设计回退或者撤销功能；
	备忘录类可以封装一个对象的历史状态，避免对象的历史状态被外界修改。
*/




#include <iostream>
#include <vector>
using namespace std;

namespace Memento
{

#ifndef __MEMENTO_H__
#define __MEMENTO_H__

class Memento
{
public:
	Memento() {}
	Memento(int iVersion, string iDate, string iLabel) {
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	void setVersion(int iVersion) {
		version = iVersion;
	}
	int getVersion() {
		return version;
	}
	void setLabel(string iLabel) {
		label = iLabel;
	}
	string getLabel() {
		return label;
	}
	void setDate(string iDate) {
		date = iDate;
	}
	string getDate() {
		return date;
	}
private:
	int version;
	string date;
	string label;
};

#endif




#ifndef __CODEVERSION_H__
#define __CODEVERSION_H__

// 原生器：CodeVersion
class CodeVersion
{
public:
	CodeVersion() {
		version = 0;
		date = "1900-01-01";
		label = "none";
	}
	CodeVersion(int iVersion, string iDate, string iLabel) {
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	// 保存代码
	Memento* save() {
		return new Memento(this->version, this->date, this->label);
	}
	// 回退版本
	void restore(Memento* memento) {
		setVersion(memento->getVersion());
		setDate(memento->getDate());
		setLabel(memento->getLabel());
	}
	void setVersion(int iVersion) {
		version = iVersion;
	}
	int getVersion() {
		return version;
	}
	void setLabel(string iLabel) {
		label = iLabel;
	}
	string getLabel() {
		return label;
	}
	void setDate(string iDate) {
		date = iDate;
	}
	string getDate() {
		return date;
	}
private:
	// 代码版本
	int version;
	// 代码提交日期
	string date;
	// 代码标签
	string label;
};

#endif








#ifndef __CODEMANAGER_H__
#define __CODEMANAGER_H__



// 管理者
class CodeManager
{
public:
	CodeManager() {}
	void commit(Memento* m) {
		printf("提交：版本-%d, 日期-%s, 标签-%s\n", m->getVersion(), m->getDate().c_str(), m->getLabel().c_str());
		mementoList.push_back(m);
	}
	// 切换到指定的版本，即回退到指定版本
	Memento* switchToPointedVersion(int index) {
		mementoList.erase(mementoList.begin() + mementoList.size() - index, mementoList.end());
		return mementoList[mementoList.size() - 1];
	}
	// 打印历史版本
	void codeLog() {
		for (int i = 0; i < mementoList.size(); i++) {
			printf("[%d]：版本-%d, 日期-%s, 标签-%s\n", i, mementoList[i]->getVersion(),
				mementoList[i]->getDate().c_str(), mementoList[i]->getLabel().c_str());
		}
	}
private:
	vector<Memento*> mementoList;
};

#endif


}
