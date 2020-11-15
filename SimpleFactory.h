#include "iostream"
using namespace std;

// 简单工厂模式
namespace SimpleFactory
{
	//抽象产品类AbstractProduct
	class AbstractSportProduct
	{
	public:
		AbstractSportProduct() {

		}
		//抽象方法：
		virtual void printName() = 0;
		virtual void play() = 0;
	};


	//具体产品类Basketball
	class Basketball :public AbstractSportProduct
	{
	public:
		Basketball() {
			printName();
			play();
		}
		//具体实现方法
		virtual void printName() override {
			printf("Jungle get Basketball\n");
		}
		virtual void play() override {
			printf("Jungle play Basketball\n");
		}
	};

	//具体产品类Football
	class Football :public AbstractSportProduct
	{
	public:
		Football() {
			printName();
			play();
		}
		//具体实现方法
		void printName() {
			printf("Jungle get Football\n");
		}
		void play() {
			printf("Jungle play Football\n");
		}
	};

	//具体产品类Volleyball
	class Volleyball :public AbstractSportProduct
	{
	public:
		Volleyball() {
			printName();
			play();
		}
		//具体实现方法
		void printName() {
			cout << "Jungle get Volleyball" << endl;
		}
		void play() {
			printf("Jungle play Volleyball\n");
		}
	};


	class SimpleFactory
	{
	public:
		AbstractSportProduct* getSportProduct(string productName)
		{
			AbstractSportProduct* pro = NULL;
			if (productName == "Basketball") {
				pro = new Basketball();
			}
			else if (productName == "Football") {
				pro = new Football();
			}
			else if (productName == "Volleyball") {
				pro = new Volleyball();
			}
			return pro;
		}
	};
}

