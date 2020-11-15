#include <iostream>
#include <string>
#include <list>
using namespace std;

// https://www.cnblogs.com/onlycxue/p/3507112.html


class Element;

// 访问者
class Visitor
{
public:
	virtual void Visit(Element* element) {};
};

// "Element"
class Element
{
public:
	// Methods
	virtual void Accept(Visitor* visitor) {};
};


// "ConcreteElement"
class Employee : public Element
{
public:
	string name;
	double income;
	int vacationDays;

public:
	Employee(string name, double income,
		int vacationDays)
	{
		this->name = name;
		this->income = income;
		this->vacationDays = vacationDays;
	}

	void Accept(Visitor* visitor)
	{
		visitor->Visit(this);
	}
};

class IncomeVisitor : public Visitor
{
public:
	void Visit(Element* element)
	{
		Employee* employee = ((Employee*)element);
		employee->income *= 1.10;
		cout << employee->name << " 's new income: " << employee->income << endl;

	}
};

class VacationVisitor : public Visitor
{
public:
	void Visit(Element* element)
	{
		Employee* employee = ((Employee*)element);
		// Provide 3 extra vacation days
		employee->vacationDays += 3;
		cout << employee->name << " 's new vacation days: " << employee->income << endl;
	}
};

// "ObjectStructure"
class Employees
{
private:
	list< Employee*> employees;

public:

	void Attach(Employee* employee)
	{
		employees.push_back(employee);
	}

	void Detach(Employee* employee)
	{
		employees.remove(employee);
	}

	void Accept(Visitor* visitor)
	{
		// 这里应该可以灵活处理，是执行关键
		for (std::list<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it)
			(*it)->Accept(visitor);
	}
};