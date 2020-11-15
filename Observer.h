/*
总结

优点：
	观察者模式实现了稳定的消息更新和传递的机制，通过引入抽象层可以扩展不同的具体观察者角色；
	支持广播通信，所有已注册的观察者（添加到目标列表中的对象）都会得到消息更新的通知，简化了一对多设计的难度；
	符合开闭原则，增加新的观察者无需修改已有代码，在具体观察者与观察目标之间不存在关联关系的情况下增加新的观察目标也很方便。

缺点：

	代码中观察者和观察目标相互引用，存在循环依赖，观察目标会触发二者循环调用，有引起系统崩溃的风险；
	如果一个观察目标对象有很多直接和简介观察者，将所有的观察者都通知到会耗费大量时间。


适用环境：
	一个对象的改变会引起其他对象的联动改变，但并不知道是哪些对象会产生改变以及产生什么样的改变；
	如果需要设计一个链式触发的系统，可是使用观察者模式；
	广播通信、消息更新通知等场景。

*/









#include "iostream"
#include "vector"
#include "string"
using namespace std;

enum INFO_TYPE {
	NONE,
	RESOURCE,
	HELP
};




namespace Observer
{
	class Observer;
	class AllyCenter;



	// 抽象观察者 Observer
	class Observer
	{
	public:
		Observer() {}
		// 声明抽象方法
		virtual void call(INFO_TYPE infoType, AllyCenter* ac) = 0;
		string getName() {
			return name;
		}
		void setName(string iName) {
			this->name = iName;
		}
	private:
		string name;
	};


	// 抽象目标：联盟中心
	class AllyCenter
	{
	public:
		AllyCenter();
		// 声明通知方法
		virtual void notify(INFO_TYPE infoType, std::string name) = 0;
		// 加入玩家
		void join(Observer* player);
		// 移除玩家
		void remove(Observer* player);
	protected:
		// 玩家列表
		std::vector<Observer*>playerList;
	};



	AllyCenter::AllyCenter() {
		printf("大吉大利，今晚吃鸡!\n");
	}

	// 加入玩家
	void AllyCenter::join(Observer* player) {
		if (playerList.size() == 4) {
			printf("玩家已满\n");
			return;
		}
		printf("玩家 %s 加入\n", player->getName().c_str());
		playerList.push_back(player);
		if (playerList.size() == 4) {
			printf("组队成功，不要怂，一起上！\n");
		}
	}
	// 移除玩家
	void AllyCenter::remove(Observer* player) {
		printf("玩家 %s 退出\n", player->getName().c_str());
		//playerList.remove(player);
	}







	// 具体观察者 
	class Player :public Observer
	{
	public:
		Player() {
			setName("none");
		}
		Player(string iName) {
			setName(iName);
		}
		// 实现
		void call(INFO_TYPE infoType, AllyCenter* ac) {
			switch (infoType) {
			case RESOURCE:
				printf("%s :我这里有物资\n", getName().c_str());
				break;
			case HELP:
				printf("%s :救救我\n", getName().c_str());
				break;
			default:
				printf("Nothing\n");
			}
			ac->notify(infoType, getName());
		}
		// 实现具体方法
		void help() {
			printf("%s:坚持住，我来救你！\n", getName().c_str());
		}
		void come() {
			printf("%s:好的，我来取物资\n", getName().c_str());
		}
	};













	// 具体目标
	class AllyCenterController :public AllyCenter
	{
	public:
		AllyCenterController();
		// 实现通知方法
		void notify(INFO_TYPE infoType, std::string name);
	};
	AllyCenterController::AllyCenterController() {}




	// 实现通知方法
	void AllyCenterController::notify(INFO_TYPE infoType, std::string name) {
		switch (infoType) {
		case RESOURCE:
			for (Observer * obs : playerList) {
				if (obs->getName() != name) {
					((Player*)obs)->come();
				}
			}
			break;
		case HELP:
			for (Observer * obs : playerList) {
				if (obs->getName() != name) {
					((Player*)obs)->help();
				}
			}
			break;
		default:
			printf("Nothing\n");
		}
	}
}