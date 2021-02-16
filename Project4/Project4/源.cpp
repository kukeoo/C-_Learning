#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


class CPU
{
public:
	virtual void calculate() = 0;

	virtual ~CPU() = 0;
};
CPU::~CPU()
{
	cout << "CPU的虚析构函数调用" << endl;
};


class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	~Computer()
	{
		cout << "Computer的析构函数调用" << endl;
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}

		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;//cpu的零件指针
	VideoCard* m_vc;
	Memory* m_mem;
};

class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel cpu is calculating" << endl;
	}

	~IntelCPU()
	{
		cout << "IntelCPU的析构函数调用" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel VideoCard is displaying" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel Memory is storaging" << endl;
	}
};

class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo cpu is calculating" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo VideoCard is displaying" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo Memory is storaging" << endl;
	}
};

void test03() 
{
	CPU* intelCpu = new IntelCPU; 
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	Computer* computer1 = new Computer(intelCpu, new LenovoVideoCard, intelMem);
	computer1->work();
	delete computer1;
	computer1 = NULL;
}

int main()
{
	//test03();
	CPU* C = new IntelCPU();
	C->calculate();
	delete C;
	return 0;
}