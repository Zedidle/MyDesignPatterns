#include "iostream"
using namespace std;


namespace Builder
{
	//产品类House
	class House
	{
	private:
		string floor;
		string wall;
		string roof;
	public:
		House() {}
		void setFloor(string iFloor) {
			floor = iFloor;
		}
		void setWall(string iWall) {
			wall = iWall;
		}
		void setRoof(string iRoof) {
			roof = iRoof;
		}
		//打印House信息
		void printfHouseInfo() {
			printf("Floor:%s\t\n", floor.c_str());
			printf("Wall:%s\t\n", wall.c_str());
			printf("Roof:%s\t\n", roof.c_str());
		}
	};

	//抽象建造者AbstractBall
	class AbstractBuilder
	{
	public:
		AbstractBuilder() {
			house = new House();
		}
		House* house;

		//抽象方法：
		virtual void buildFloor() = 0;
		virtual void buildWall() = 0;
		virtual void buildRoof() = 0;

		House* construct() {
			buildFloor();
			buildWall();
			buildRoof();
			return house;
		}

	};


	//具体建造者ConcreteBuilderA
	class ConcreteBuilderA :public AbstractBuilder
	{
	public:
		ConcreteBuilderA() {
			printf("ConcreteBuilderA\n");
		}
		//具体实现方法
		void buildFloor() {
			this->house->setFloor("Floor_A");
		}
		void buildWall() {
			this->house->setWall("Wall_A");
		}
		void buildRoof() {
			this->house->setRoof("Roof_A");
		}
	};

	//具体建造者ConcreteBuilderB
	class ConcreteBuilderB :public AbstractBuilder
	{
	public:
		ConcreteBuilderB() {
			printf("ConcreteBuilderB\n");
		}
		//具体实现方法
		void buildFloor() {
			this->house->setFloor("Floor_B");
		}
		void buildWall() {
			this->house->setWall("Wall_B");
		}
		void buildRoof() {
			this->house->setRoof("Roof_B");
		}
	};

	//指挥者Director
	class Director
	{
	public:
		Director() {}
		//具体实现方法
		void setBuilder(AbstractBuilder* iBuilder) {
			this->builder = iBuilder;
		}
		//封装组装流程，返回建造结果
		House* construct() {
			return builder->construct();
		}
	private:
		AbstractBuilder* builder;
	};

}