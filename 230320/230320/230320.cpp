#include <iostream>
using namespace std;

class CObj			// Base Ŭ����
{
public:
	CObj()// : m_iA(100)
	{
		cout << "�θ� ������ ȣ��" << endl;
	}
	CObj(const CObj& rhs)
	{
		m_iA = rhs.m_iA - 1;
		cout << "�θ� ���� ������ ȣ��" << endl;
	}
	//CObj(int _iA) : m_iA(_iA) {}

	~CObj() { cout << "�θ� �Ҹ��� ȣ��" << endl; }

public:
	int		m_iA;
};

class CPlayer : public CObj	// Derived Ŭ����
{
public:
	CPlayer()
	{
		a = 1;
		cout << "�ڽ� ������ ȣ��" << endl;
	}
	CPlayer(const CPlayer& rhs)//:CObj(rhs)
	{
		m_iA = 5;
		cout << "�ڽ� ���� ������ ȣ��" << endl;
	}
	~CPlayer() { cout << "�ڽ� �Ҹ��� ȣ��" << endl; }

	int a = 0;
};


void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;
	CPlayer cp;
	CPlayer cp2(cp);
	//CPlayer* cp2 = new CPlayer(cp);
	cout << cp2.a << endl;
	cout << cp2.m_iA << endl;

}
