#include "iostream"
#include "vector"
#include "mutex"
using namespace std;




namespace Iterator
{
	class Iterator;
	class Aggregate;
	class Television;



	// 抽象聚合类 Aggregate
	class Aggregate
	{
	public:
		Aggregate() {}
		virtual Iterator* createIterator() = 0;
	};

	// 抽象迭代器
	class Iterator
	{
	public:
		Iterator() {}
		// 声明抽象遍历方法
		virtual void first() = 0;
		virtual void last() = 0;
		virtual void next() = 0;
		virtual void previous() = 0;
		virtual bool hasNext() = 0;
		virtual bool hasPrevious() = 0;
		virtual void currentChannel() = 0;
	};

	// 具体聚合类 Television
	class Television :public Aggregate
	{
	public:
		Television();
		Television(vector<string> iChannelList);
		// 实现创建迭代器
		Iterator* createIterator();
		// 获取总的频道数目
		int getTotalChannelNum();
		void play(int i);
	private:
		vector<string> channelList;
	};
	Television::Television() {}

	Television::Television(vector<string> iChannelList) {
		this->channelList = iChannelList;
	}


	// 遥控器：具体迭代器
	class RemoteControl :public Iterator
	{
	public:
		RemoteControl() {}
		void setTV(Television* iTv) {
			this->tv = iTv;
			cursor = -1;
			totalNum = tv->getTotalChannelNum();
		}
		// 实现各个遍历方法
		void first() {
			cursor = 0;
		}
		void last() {
			cursor = totalNum - 1;
		}
		void next() {
			cursor++;
		}
		void previous() {
			cursor--;
		}
		bool hasNext() {
			return !(cursor == totalNum);
		}
		bool hasPrevious() {
			return !(cursor == -1);
		}
		void currentChannel() {
			tv->play(cursor);
		}
	private:
		// 游标
		int cursor;
		// 总的频道数目
		int totalNum;
		// 电视
		Television* tv;
	};

	// 前向声明，因为两个类互相引用





	Iterator* Television::createIterator() {
		RemoteControl* it = new RemoteControl();
		it->setTV(this);
		return (Iterator*)it;
	}

	int Television::getTotalChannelNum() {
		return channelList.size();
	}

	void Television::play(int i) {
		printf("现在播放：%s……\n", channelList[i].c_str());
	}




}
