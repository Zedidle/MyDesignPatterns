/*
总结 - 状态模式

优点：
	状态模式封装了状态转换的规则，只给外界暴露了统一的接口，客户端可以无差别地调用该接口（如上述实例的客户端代码）
	状态模式将所有与具体状态有关的行为放到一个类（具体状态类）中，只需要注入（依赖）不同的状态类对象到上下文类中，即可使上下文中拥有不同的行为

缺点：
	状态模式增加了系统中类的个数（不同的具体状态类）
	结构相对复杂（如前述实例的UML图），代码逻辑也较复杂
	如果要增加新的状态，需要修改负责状态转换的代码，不符合开闭原则（如上述实例，如果增加了一个中间级别，是不是得修改很多状态转换的逻辑？）

适用环境：
	对象的行为根据它的状态的改变而不同
	代码中含有大量与对象状态有关的判断逻辑（if……else……或switch……case……）
*/


#include <Windows.h>
#include <time.h>
#include <iostream>
using namespace std;



namespace Level
{
	//头文件
#ifndef __GAMEACCOUNT_H__
#define __GAMEACCOUNT_H__

	// 前向声明
	class Level;
	class Primary;
	class Final;
	class Professional;
	class Secondary;


	class GameAccount
	{
	public:
		GameAccount();
		GameAccount(string iName);
		string getName();
		void win();
		void lose();
		void playCard();
		void setLevel(Level*);
		int getScore();
		void setScore(int);

	private:
		Level* level;
		int score;
		string name;
	};

#endif
	class Level
	{
	public:
		Level();
		// 声明方法
		void playCard();
		void play();
		virtual void doubleScore() = 0;
		virtual void changeCards() = 0;
		virtual void peekCards() = 0;
		// 升级
		virtual void upgradeLevel() = 0;
		GameAccount* getGameAccount();
		void setGameAccount(GameAccount* iGameAccount);
	private:
		GameAccount* gameAccount;
	};
	class Final :public Level
	{
	public:
		Final();
		Final(Level* level);
		void doubleScore();
		void changeCards();
		void peekCards();
		// 升级
		void upgradeLevel();
	};

	class Professional :public Level
	{
	public:
		Professional();
		Professional(Level* level);
		void doubleScore();
		void changeCards();
		void peekCards();
		// 升级
		void upgradeLevel();
	};
	class Primary :public Level
	{
	public:
		Primary();
		Primary(Level* level);
		Primary(GameAccount* ga);
		void doubleScore();
		void changeCards();
		void peekCards();
		// 升级
		void upgradeLevel();
	};


	//源文件
#define  random(x) (rand()%x)


	GameAccount::GameAccount() {
		printf("创立游戏角色，积分：100，级别：PRIMARY\n");
		score = 100;
		name = "none";
		setLevel(new Primary(this));
	}

	GameAccount::GameAccount(string iName) {
		printf("创立游戏角色，积分：100，级别：PRIMARY\n");
		score = 100;
		name = iName;
		setLevel(new Primary(this));
	}

	void GameAccount::setLevel(Level* iLevel) {
		this->level = iLevel;
	}

	string GameAccount::getName() {
		return name;
	}

	void GameAccount::playCard() {
		this->level->playCard();

		Sleep(100);
		srand((int)time(0));
		int res = random(2);
		if (res % 2 == 0) {
			this->win();
		}
		else {
			this->lose();
		}

		this->level->upgradeLevel();
	}

	void GameAccount::win() {
		if (this->getScore() < 200) {
			setScore(getScore() + 50);
		}
		else {
			setScore(getScore() + 100);
		}
		printf("\n\t胜利，最新积分为 %d\n", score);
	}

	void GameAccount::lose() {
		setScore(getScore() + 30);
		printf("\n\t输牌，最新积分为 %d\n", score);
	}

	int GameAccount::getScore() {
		return this->score;
	}

	void GameAccount::setScore(int iScore) {
		this->score = iScore;
	}








	class Secondary :public Level
	{
	public:
		Secondary();
		Secondary(Level* level);
		void doubleScore();
		void changeCards();
		void peekCards();
		// 升级
		void upgradeLevel();
	};




	Level::Level() {}

	void Level::playCard() {
		this->play();
		this->doubleScore();
		this->changeCards();
		this->peekCards();
	}

	void Level::play() {
		printf("\t使用基本技能,");
	}

	void Level::setGameAccount(GameAccount* iGameAccount) {
		this->gameAccount = iGameAccount;
	}

	GameAccount* Level::getGameAccount() {
		return gameAccount;
	}





	Primary::Primary() {}

	Primary::Primary(GameAccount* iGameAccount) {
		this->setGameAccount(iGameAccount);
	}

	Primary::Primary(Level* level) {
		getGameAccount()->setLevel(level);
	}

	void Primary::doubleScore() {
		return;
	}

	void Primary::changeCards() {
		return;
	}

	void Primary::peekCards() {
		return;
	}

	void Primary::upgradeLevel() {
		if (this->getGameAccount()->getScore() > 150) {
			this->getGameAccount()->setLevel(new Secondary(this));
			printf("\t升级！ 级别：SECONDARY\n\n");
		}
		else {
			printf("\n");
		}
	}





	Secondary::Secondary() {

	}

	Secondary::Secondary(Level* level) {
		this->setGameAccount(level->getGameAccount());
		getGameAccount()->setLevel(level);
	}

	void Secondary::doubleScore() {
		printf("使用胜利双倍积分技能");
	}

	void Secondary::changeCards() {
		return;
	}

	void Secondary::peekCards() {
		return;
	}

	void Secondary::upgradeLevel() {
		if (this->getGameAccount()->getScore() < 150) {
			this->getGameAccount()->setLevel(new Primary(this));
			printf("\t降级！ 级别：PRIMARY\n\n");
		}
		else if (this->getGameAccount()->getScore() > 200) {
			this->getGameAccount()->setLevel(new Professional(this));
			printf("\t升级！ 级别：PROFESSIONAL\n\n");
		}
	}




	Professional::Professional() {

	}

	Professional::Professional(Level* level) {
		this->setGameAccount(level->getGameAccount());
		getGameAccount()->setLevel(level);
	}

	void Professional::doubleScore() {
		printf("使用胜利双倍积分技能,");
	}

	void Professional::changeCards() {
		printf("使用换牌技能");
	}

	void Professional::peekCards() {
		return;
	}

	void Professional::upgradeLevel() {
		if (this->getGameAccount()->getScore() < 200) {
			this->getGameAccount()->setLevel(new Secondary(this));
			printf("\t降级！ 级别：SECONDARY\n\n");
		}
		else if (this->getGameAccount()->getScore() > 250) {
			this->getGameAccount()->setLevel(new Final(this));
			printf("\t升级！ 级别：FINAL\n\n");
		}
	}




	Final::Final() {

	}

	Final::Final(Level* level) {
		this->setGameAccount(level->getGameAccount());
		getGameAccount()->setLevel(level);
	}

	void Final::doubleScore() {
		printf("使用胜利双倍积分技能,");
	}

	void Final::changeCards() {
		printf("使用换牌技能,");
	}

	void Final::peekCards() {
		printf("使用偷看卡牌技能");
	}

	void Final::upgradeLevel() {
		if (this->getGameAccount()->getScore() < 250) {
			this->getGameAccount()->setLevel(new Professional(this));
			printf("\t降级！ 级别：PROFESSIONAL\n\n");
		}
		else {
			printf("\t%s 已经是最高级\n\n", this->getGameAccount()->getName().c_str());
		}
	}




	
}