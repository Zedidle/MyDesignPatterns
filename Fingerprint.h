/*
总结

模板方法模式是基于类的继承的一种设计模式，使用非常频繁，被广泛应用于框架设计。

优点：
	在基类中定义算法的框架，并声明一些流程方法，由具体派生类实现细节，派生类中的实现并不会影响基类定义的算法的框架流程；
	公共行为在基类中提供实现，有利于代码复用；
	派生类可以覆盖基类的方法，重新实现某些方法，具有灵活性；
	可以很方便的扩展和更换派生类而不影响基类和其他派生类，符合开闭原则和单一职责原则。

缺点：
	模板方法模式要为每一个不同的基本方法提供一个派生类，如果基类中基本方法很多，那系统中会定义很多个派生类，导致类的个数很多，系统更加庞大。

适用环境：
	分割复杂算法，可以将算法的框架流程定义在基类中，设计为模板方法；而具体的细节由派生类设计实现；
	各个派生类的公共部分提取到基类中，以实现代码复用；
	派生类需要覆盖基类的某些方法。
*/


namespace Fingerprint
{

	// 基类
	class FingerprintModule
	{
	public:
		FingerprintModule() {}
		void getImage() {
			printf("采指纹图像\n");
		}
		void output() {
			printf("指纹图像处理完成!\n");
		}
		virtual bool isSafeMode() = 0;
		virtual void processImage() = 0;
		// 加解密
		virtual void encrypt() = 0;
		virtual void decrypt() = 0;

		// 模板方法
		void algorithm() {
			// 1.采图
			getImage();
			// 2.安全模式下加密和解密
			if (isSafeMode()) {
				// 2.1. 加密
				encrypt();
				// 2.2. 解密
				decrypt();
			}
			// 3.处理Image
			processImage();
			// 4.处理结果
			output();
		}
	};

	// 派生类
	class FingerprintModuleA :public FingerprintModule
	{
	public:
		FingerprintModuleA() {}
		void processImage() {
			printf("使用 第一代版本算法 处理指纹图像\n");
		}
		bool isSafeMode() {
			printf("安全模式\n");
			return true;
		}
		void encrypt() {
			printf("使用RSA密钥加密\n");
		}
		void decrypt() {
			printf("使用RSA密钥解密\n");
		}
	};

	// 派生类
	class FingerprintModuleB :public FingerprintModule
	{
	public:
		FingerprintModuleB() {}
		void processImage() {
			printf("使用 第二代版本算法 处理指纹图像\n");
		}
		bool isSafeMode() {
			printf("非安全模式\n");
			return false;
		}
		void encrypt() {}
		void decrypt() {}
	};

	// 派生类
	class FingerprintModuleC :public FingerprintModule
	{
	public:
		FingerprintModuleC() {}
		void processImage() {
			printf("使用 第一代版本算法 处理指纹图像\n");
		}
		bool isSafeMode() {
			printf("安全模式\n");
			return true;
		}
		void encrypt() {
			printf("使用DH密钥加密\n");
		}
		void decrypt() {
			printf("使用DH密钥解密\n");
		}
	};
}