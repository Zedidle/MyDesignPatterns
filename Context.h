/*
总结

优点：
	符合开闭原则，策略模式易于扩展，增加新的算法时只需继承抽象策略类，新设计实现一个具体策略类即可；
	客户端可以无差别地通过公共接口调用，利用里式替换原则，灵活使用不同的算法策略；
	提供了一个算法族管理机制和维护机制。

缺点：
	客户端必须要知道所有的策略，以便在使用时按需实例化具体策略；
	系统会产生很多单独的类，增加系统中类的数量；
	客户端在同一时间只能使用一种策略。

适用环境：
	系统需要在一个算法族中动态选择一种算法，可以将这些算法封装到多个具体算法类中，这些算法类都有共同的基类，即可以通过一个统一的接口调用任意一个算法，客户端可以使用任意一个算法；
	不希望客户端知道复杂的、与算法相关的数据结构，在具体策略类中封装与算法相关的数据结构，可以提高算法的安全性。
*/

#include <stdio.h>

namespace Context
{
#ifndef __CONTEXT_H__
#define __CONTEXT_H__

// 抽象策略类
class Strategy
{
public:
	Strategy() {}
	virtual void sort(int arr[], int N) = 0;
};


	// 上下文类
	class Context
	{
	public:
		Context() {
			arr = NULL;
			N = 0;
		}
		Context(int iArr[], int iN) {
			this->arr = iArr;
			this->N = iN;
		}
		void setSortStrategy(Strategy* iSortStrategy) {
			this->sortStrategy = iSortStrategy;
		}
		void sort() {
			this->sortStrategy->sort(arr, N);
			printf("输出： ");
			this->print();
		}
		void setInput(int iArr[], int iN) {
			this->arr = iArr;
			this->N = iN;
		}
		void print() {
			for (int i = 0; i < N; i++) {
				printf("%3d ", arr[i]);
			}
			printf("\n");
		}

	private:
		Strategy* sortStrategy;
		int* arr;
		int N;
	};

#endif // __CONTEXT_H__












	// 具体策略：冒泡排序
	class BubbleSort :public Strategy
	{
	public:
		BubbleSort() {
			printf("冒泡排序\n");
		}
		void sort(int arr[], int N) {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N - i - 1; j++)
				{
					if (arr[j] > arr[j + 1]) {
						int tmp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = tmp;
					}
				}
			}
		}
	};




	// 具体策略：选择排序
	class SelectionSort :public Strategy
	{
	public:
		SelectionSort() {
			printf("选择排序\n");
		}
		void sort(int arr[], int N) {
			int i, j, k;
			for (i = 0; i < N; i++)
			{
				k = i;
				for (j = i + 1; j < N; j++)
				{
					if (arr[j] < arr[k]) {
						k = j;
					}
				}
				int temp = arr[i];
				arr[i] = arr[k];
				arr[k] = temp;
			}
		}
	};


	// 具体策略：插入排序
	class InsertSort :public Strategy
	{
	public:
		InsertSort() {
			printf("插入排序\n");
		}
		void sort(int arr[], int N) {
			int i, j;
			for (i = 1; i < N; i++)
			{
				for (j = i - 1; j >= 0; j--)
				{
					if (arr[i] > arr[j]) {
						break;
					}
				}
				int temp = arr[i];
				for (int k = i - 1; k > j; k--) {
					arr[k + 1] = arr[k];
				}
				arr[j + 1] = temp;
			}
		}
	};
}