#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;



// 教程：https://zhuanlan.zhihu.com/p/94877789


#include "SimpleFactory.h"
#include "FactoryMethod.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Prototype.h"
#include "Singleton.h"
#include "Adapter.h"
#include "Bridge.h"
#include "Component.h"
#include "Decorator.h"
#include "Facade.h"
#include "Visitor.h"
#include "Flyweight.h"
#include "Proxy.h"
#include "ChainOfResponsibility.h"
#include "Command.h"
#include "Interpreter.h"
#include "Iterator.h"
#include "Mediator.h"
#include "Memento.h"
#include "Observer.h"
#include "Level.h"
#include "Context.h"
#include "Fingerprint.h"




// 单例多线程测试
#include <process.h>
#include <Windows.h>
#define THREAD_NUM 5
unsigned int __stdcall CallSingleton(void* pPM)
{
	Singleton::Singleton* s = Singleton::Singleton::getInstance();
	int nThreadNum = *(int*)pPM;
	Sleep(50);
	printf("线程编号为%d\n", nThreadNum);
	return 0;
}





int main()
{
	// 简单工厂
	//SimpleFactory::SimpleFactory* SF = new SimpleFactory::SimpleFactory;
	//SF->getSportProduct("Basketball");
	//SF->getSportProduct("Football");
	//SF->getSportProduct("Volleyball");



	// 工厂方法
	//FactoryMethod::AbstractFactory* fac = NULL;
	//FactoryMethod::AbstractSportProduct* product = NULL;
	//fac = new FactoryMethod::BasketballFactory;
	//product = fac->getSportProduct();
	//fac = new FactoryMethod::FootballFactory;
	//product = fac->getSportProduct();
	//fac = new FactoryMethod::VolleyballFactory;
	//product = fac->getSportProduct();


	// 抽象工厂
	//AbstractFactory::AbstractFactory* fac = NULL;
	//AbstractFactory::AbstractBall* ball = NULL;
	//AbstractFactory::AbstractShirt* shirt = NULL;
	//fac = new AbstractFactory::BasketballFactory();
	//ball = fac->getBall();
	//shirt = fac->getShirt();
	//fac = new AbstractFactory::FootballFactory();
	//ball = fac->getBall();
	//shirt = fac->getShirt();


	// 建造者
	//Builder::AbstractBuilder* builder;
	//Builder::Director* director = new Builder::Director();
	//Builder::House* house;
	//builder = new Builder::ConcreteBuilderA();
	//director->setBuilder(builder);
	//house = director->construct();
	//house->printfHouseInfo();
	//builder = new Builder::ConcreteBuilderB();
	//director->setBuilder(builder);
	//house = director->construct();
	//house->printfHouseInfo();


	// 原型
	//Prototype::ConcreteWork* singleWork = new Prototype::ConcreteWork("Single", 1001, "Single_Model");
	//singleWork->printWorkInfo();
	//Prototype::ConcreteWork* jungleWork;
	//if (false)
	//{
	//	// 浅拷贝
	//	jungleWork = singleWork;
	//}
	//else
	//{
	//	// 深拷贝
	//	jungleWork = singleWork->clone();
	//}
	//jungleWork->setName("jungle");
	//jungleWork->setIdNum(1002);
	//Prototype::WorkModel* jungleModel = new Prototype::WorkModel();
	//jungleModel->setWorkModelName("Jungle_Model");
	//jungleWork->setModel(jungleModel);
	//singleWork->printWorkInfo();
	//jungleWork->printWorkInfo();






	// 单例
	//Singleton::Singleton* s1 = Singleton::Singleton::getInstance();
	//Singleton::Singleton* s2 = Singleton::Singleton::getInstance();

	// 单例多线程
	//HANDLE  handle[THREAD_NUM];
	////线程编号
	//int threadNum = 0;
	//while (threadNum < THREAD_NUM)
	//{
	//	handle[threadNum] = (HANDLE)_beginthreadex(NULL, 0, CallSingleton, &threadNum, 0, NULL);
	//	//等子线程接收到参数时主线程可能改变了这个i的值
	//	threadNum++;
	//}
	////保证子线程已全部运行结束
	//WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);







	// 适配器
	//Adapter::Controller* controller = new Adapter::Adapter();
	//controller->pathPlanning();





	// 桥接
	//Bridge::Game* game;
	//Bridge::Phone* phone;
	////Jungle买了PhoneA品牌的手机，想玩游戏A
	//phone = new Bridge::PhoneA();
	//game = new Bridge::GameA();
	//phone->setupGame(game);
	//phone->play();
	////Jungle想在这个手机上玩游戏B
	//game = new Bridge::GameB();
	//phone->setupGame(game);
	//phone->play();




	// 组合
	//Component::Component* head, * sichuanBranch, * cdBranch, * myBranch, * office1, * office2, * office3, * office4, * office5, * office6, * office7, * office8;
	//
	//head = new Component::SubComponent("总部");
	//sichuanBranch = new Component::SubComponent("四川分部");
	//office1 = new Component::AdminOffice("行政办公室");
	//office2 = new Component::DeanOffice("教务办公室");
	//
	//cdBranch = new Component::SubComponent("成都分部");
	//myBranch = new Component::SubComponent("绵阳分部");
	//office3 = new Component::AdminOffice("行政办公室");
	//office4 = new Component::DeanOffice("教务办公室");
	//
	//office5 = new Component::AdminOffice("行政办公室");
	//office6 = new Component::DeanOffice("教务办公室");
	//
	//office7 = new Component::AdminOffice("行政办公室");
	//office8 = new Component::DeanOffice("教务办公室");
	//
	//cdBranch->add(office5);
	//cdBranch->add(office6);
	//
	//myBranch->add(office7);
	//myBranch->add(office8);
	//
	//sichuanBranch->add(office3);
	//sichuanBranch->add(office4);
	//sichuanBranch->add(cdBranch);
	//sichuanBranch->add(myBranch);
	//
	//head->add(office1);
	//head->add(office2);
	//head->add(sichuanBranch);
	//
	//head->operation();



	// 装饰
	//printf("\nJungle的第一个手机：\n");
	//Decorator::Component* c;
	//Decorator::Component* com_Shell;
	//c = new Decorator::Phone();
	//com_Shell = new Decorator::DecoratorShell(c);
	//com_Shell->operation();

	//printf("\nJungle的第二个手机：\n");
	//Decorator::Component* c2;
	//Decorator::Component* com_Shell2;
	//c2 = new Decorator::Phone();
	//com_Shell2 = new Decorator::DecoratorShell(c2);
	//Decorator::Component* com_Sticker;
	//com_Sticker = new Decorator::DecoratorSticker(com_Shell2);
	//com_Sticker->operation();

	//printf("\nJungle的第三个手机：\n");
	//Decorator::Component* c3;
	//Decorator::Component* com_Shell3;
	//c3 = new Decorator::Phone();
	//com_Shell3 = new Decorator::DecoratorShell(c3);
	//Decorator::Component* com_Sticker2;
	//com_Sticker2 = new Decorator::DecoratorSticker(com_Shell3);
	//Decorator::Component* com_Rope;
	//com_Rope = new Decorator::DecoratorRope(com_Sticker2);
	//com_Rope->operation();




	// 外观
	//Facade::Facade* facade = new Facade::Facade();
	//facade->powerOn();






	// 享元
	//Flyweight::NetDeviceFactory* factory = Flyweight::NetDeviceFactory::getFactory();
	//Flyweight::NetDevice* device1, * device2, * device3, * device4;
	//// 客户端1获取一个hub
	//device1 = factory->getNetDevice('H');
	//device1->print();
	//// 客户端2获取一个hub
	//device2 = factory->getNetDevice('H');
	//device2->print();
	//// 判断两个hub是否是同一个
	//printf("判断两个hub是否是同一个:\n");
	//printf("device1:%p\ndevice2:%p\n", device1, device2);

	//printf("\n\n\n\n");
	//// 客户端3获取一个switch
	//device3 = factory->getNetDevice('S');
	//device3->print();
	//// 客户端4获取一个switch
	//device4 = factory->getNetDevice('S');
	//device4->print();
	//// 判断两个switch是否是同一个
	//printf("判断两个switch是否是同一个:\n");
	//printf("device3:%p\ndevice4:%p\n", device3, device4);







	// 代理
	//Proxy::Subject* subject;
	//subject = new Proxy::Proxy();
	//subject->method();






	// 职责链
	// 请求处理者：组长，兵哥，春总，老板
	//ChainOfResponsibility::Approver* zuzhang, * bingge, * chunzong, * laoban;
	//zuzhang = new ChainOfResponsibility::GroupLeader("孙大哥");
	//bingge = new ChainOfResponsibility::Head("兵哥");
	//chunzong = new ChainOfResponsibility::Manager("春总");
	//laoban = new ChainOfResponsibility::Boss("张老板");
	//zuzhang->setSuperior(bingge);
	//bingge->setSuperior(chunzong);
	//chunzong->setSuperior(laoban);
	//// 创建报销单
	//ChainOfResponsibility::Bill* bill1 = new ChainOfResponsibility::Bill(1, "Jungle", 8);
	//ChainOfResponsibility::Bill* bill2 = new ChainOfResponsibility::Bill(2, "Lucy", 14.4);
	//ChainOfResponsibility::Bill* bill3 = new ChainOfResponsibility::Bill(3, "Jack", 32.9);
	//ChainOfResponsibility::Bill* bill4 = new ChainOfResponsibility::Bill(4, "Tom", 89);
	//// 全部先交给组长审批
	//zuzhang->handleRequest(bill1); printf("\n");
	//zuzhang->handleRequest(bill2); printf("\n");
	//zuzhang->handleRequest(bill3); printf("\n");
	//zuzhang->handleRequest(bill4);






	// 命令
	// 实例化调用者：按钮
	//Command::Button* button = new Command::Button();
	//Command::Command* lampCmd, * fanCmd;

	//// 按钮控制电灯
	//lampCmd = new Command::LampCommand();
	//button->setCommand(lampCmd);
	//button->touch();
	//button->touch();
	//button->touch();

	//printf("\n\n");
	//// 按钮控制风扇
	//fanCmd = new Command::FanCommand();
	//button->setCommand(fanCmd);
	//button->touch();
	//button->touch();
	//button->touch();

	// 命令队列
//#ifdef COMMAND_QUEUE
//	printf("\n\n***********************************\n");
//	Command::Button2* button2 = new Command::Button2();
//	Command::Command* lampCmd2, * fanCmd2;
//	Command::CommandQueue* cmdQueue = new Command::CommandQueue();
//
//	// 按钮控制电灯
//	lampCmd2 = new Command::LampCommand();
//	cmdQueue->addCommand(lampCmd2);
//
//	// 按钮控制风扇
//	fanCmd2 = new Command::FanCommand();
//	cmdQueue->addCommand(fanCmd2);
//
//	button2->setCommandQueue(cmdQueue);
//	button2->touch();
//#endif







	// 解释器
//Interpreter::Handler* handler = new Interpreter::Handler();
//
//string input_1 = "1 and 1";
//string input_2 = "1 and 0";
//string input_3 = "0 and 1";
//string input_4 = "0 and 0";
//string input_5 = "0 or 0";
//string input_6 = "0 or 1";
//string input_7 = "1 or 0";
//string input_8 = "1 or 1";
//string input_9 = "1 and 0 or 1";
//string input_10 = "0 or 0 and 1";
//string input_11 = "1 or 1 and 1 and 0";
//string input_12 = "0 and 1 and 1 and 1";
//string input_13 = "0 and 1 and 1 and 1 or 1 or 0 and 1";
//handler->setInput(input_1); handler->handle();
//handler->setInput(input_2); handler->handle();
//handler->setInput(input_3); handler->handle();
//handler->setInput(input_4); handler->handle();
//handler->setInput(input_5); handler->handle();
//handler->setInput(input_6); handler->handle();
//handler->setInput(input_7); handler->handle();
//handler->setInput(input_8); handler->handle();
//handler->setInput(input_9); handler->handle();
//handler->setInput(input_10); handler->handle();
//handler->setInput(input_11); handler->handle();
//handler->setInput(input_12); handler->handle();
//handler->setInput(input_13); handler->handle();






	//	迭代器
	//vector<string> channelList = { "新闻频道", "财经频道", "体育频道", "电影频道", "音乐频道", "农业频道", "四川卫视", "成都卫视" };
	//// 创建电视
	//Iterator::Television* tv = new Iterator::Television(channelList);
	//// 创建遥控器
	//Iterator::Iterator* remoteControl = tv->createIterator();

	//// 顺序遍历
	//printf("顺序遍历:\n");
	//remoteControl->first();
	//// 遍历电视所有频道
	//while (remoteControl->hasNext()) {
	//	remoteControl->currentChannel();
	//	remoteControl->next();
	//}

	//printf("\n\n");
	//// 逆序遍历
	//printf("逆序遍历:\n");
	//remoteControl->last();
	//// 遍历电视所有频道
	//while (remoteControl->hasPrevious()) {
	//	remoteControl->currentChannel();
	//	remoteControl->previous();
	//}







	// 中介者
	// 创建租房中介
	//Mediator::Agency* mediator = new Mediator::Agency();

	//// 创建3位房东
	//Mediator::Landlord* fangdong1 = new Mediator::Landlord("刘备", 1350, "成都市双流区", "1351025");
	//Mediator::Landlord* fangdong2 = new Mediator::Landlord("关羽", 1500, "成都市武侯区", "1378390");
	//Mediator::Landlord* fangdong3 = new Mediator::Landlord("张飞", 1000, "成都市龙泉驿", "1881166");
	//fangdong1->setMediator(mediator);
	//fangdong2->setMediator(mediator);
	//fangdong3->setMediator(mediator);
	//// 房东在中介处登记注册房源信息
	//mediator->registerMethod(fangdong1);
	//mediator->registerMethod(fangdong2);
	//mediator->registerMethod(fangdong3);

	//// 创建两位租客Jungle和贱萌兔
	//Mediator::Tenant* jungle = new Mediator::Tenant("Jungle");
	//Mediator::Tenant* jianmengtu = new Mediator::Tenant("贱萌兔");
	//jungle->setMediator(mediator);
	//jianmengtu->setMediator(mediator);
	//mediator->registerMethod(jungle);
	//mediator->registerMethod(jianmengtu);

	//jungle->ask();
	//printf("\n\n");
	//fangdong1->ask();







	// 备忘录
	//Memento::CodeManager* Jungle = new Memento::CodeManager();
	//Memento::CodeVersion* codeVer = new Memento::CodeVersion(1001, "2019-11-03", "Initial version");

	//// 提交初始版本
	//printf("提交初始版本:\n");
	//Jungle->commit(codeVer->save());

	//// 修改一个版本，增加了日志功能
	//printf("\n提交一个版本，增加了日志功能:\n");
	//codeVer->setVersion(1002);
	//codeVer->setDate("2019-11-04");
	//codeVer->setLabel("Add log funciton");
	//Jungle->commit(codeVer->save());

	//// 修改一个版本，增加了Qt图片浏览器
	//printf("\n提交一个版本，增加了Qt图片浏览器:\n");
	//codeVer->setVersion(1003);
	//codeVer->setDate("2019-11-05");
	//codeVer->setLabel("Add Qt Image Browser");
	//Jungle->commit(codeVer->save());

	//// 查看提交历史
	//printf("\n查看提交历史\n");
	//Jungle->codeLog();

	//// 回退到上一个版本
	//printf("\n回退到上一个版本\n");
	//codeVer->restore(Jungle->switchToPointedVersion(1));

	//// 查看提交历史
	//printf("\n查看提交历史\n");
	//Jungle->codeLog();






	// 观察者
	// 创建一个战队
	//Observer::AllyCenterController* controller = new Observer::AllyCenterController();

	//// 创建4个玩家，并加入战队
	//Observer::Player* Jungle = new Observer::Player("Jungle");
	//Observer::Player* Single = new Observer::Player("Single");
	//Observer::Player* Jianmengtu = new Observer::Player("贱萌兔");
	//Observer::Player* SillyDog = new Observer::Player("傻子狗");
	//controller->join(Jungle);
	//controller->join(Single);
	//controller->join(Jianmengtu);
	//controller->join(SillyDog);

	//printf("\n\n");

	//// Jungle发现物资，呼叫队友
	//Jungle->call(RESOURCE, controller);

	//printf("\n\n");

	//// 傻子狗遇到危险，求救队友
	//SillyDog->call(HELP, controller);






	// 状态
	//Level::GameAccount* jungle = new Level::GameAccount("Jungle");
	//for (int i = 0; i < 5; i++) {
	//	printf("第%d局：\n", i + 1);
	//	jungle->playCard();
	//}






	// 策略
	//Context::Context* ctx = new Context::Context();
	//int arr[] = { 10, 23, -1, 0, 300, 87, 28, 77, -32, 2 };
	//ctx->setInput(arr, sizeof(arr) / sizeof(int));
	//printf("输入：");
	//ctx->print();
	//
	//// 冒泡排序
	//ctx->setSortStrategy(new Context::BubbleSort());
	//ctx->sort();
	//
	//// 选择排序
	//ctx->setSortStrategy(new Context::SelectionSort());
	//ctx->sort();
	//
	//// 插入排序
	//ctx->setSortStrategy(new Context::InsertSort());
	//ctx->sort();











	// 模板方法
	// Fingerprint::FingerprintModule* fp = new Fingerprint::FingerprintModuleA();
	// fp->algorithm();
	// fp = new Fingerprint::FingerprintModuleB();
	// fp->algorithm();
	// fp = new Fingerprint::FingerprintModuleC();
	// fp->algorithm();









	// 访问者
	//Employees* e = new Employees();
	//e->Attach(new Employee("Tom", 25000.0, 14));
	//e->Attach(new Employee("Thomas", 35000.0, 16));
	//e->Attach(new Employee("Roy", 45000.0, 21));
	//// Create two visitors
	//IncomeVisitor* v1 = new IncomeVisitor();
	//VacationVisitor* v2 = new VacationVisitor();
	//// Employees are visited
	//e->Accept(v1);
	//e->Accept(v2);


	system("pause");
	return 0;
}