#include "iostream"
#include <stdio.h>
#include <time.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

namespace Proxy
{


// 抽象主题角色
class Subject
{
public:
	Subject() {}
	virtual void method() = 0;
};


// 真实主题角色
class RealSubject :public Subject
{
public:
	RealSubject() {}
	void method() {
		printf("调用业务方法\n");
	}
};


// Log类
class Log
{
public:
	Log() {}
	void getTime() {
		struct tm t;   //tm结构指针
		time_t now;  //声明time_t类型变量
		time(&now);      //获取系统日期和时间
		localtime_s(&t, &now);   //获取当地日期和时间

		printf("年：%d\n", t.tm_year + 1900);
		printf("月：%d\n", t.tm_mon + 1);
		printf("日：%d\n", t.tm_mday);
		printf("周：%d\n", t.tm_wday);
		printf("一年中：%d\n", t.tm_yday);
		printf("时：%d\n", t.tm_hour);
		printf("分：%d\n", t.tm_min);
		printf("秒：%d\n", t.tm_sec);
		printf("夏令时：%d\n", t.tm_isdst);

	}
};

// 代理类
class Proxy :public Subject
{
public:
	Proxy() {
		realSubject = new RealSubject();
		log = new Log();
	}
	void preCallMethod() {
		log->getTime();
		//printf("方法method()被调用，调用时间为%s\n", log->getTime().c_str());
	}
	void method() {
		preCallMethod();
		realSubject->method();
		postCallMethod();
	}
	void postCallMethod() {
		printf("方法method()调用调用成功!\n");
	}
private:
	RealSubject* realSubject;
	Log* log;
};

}
