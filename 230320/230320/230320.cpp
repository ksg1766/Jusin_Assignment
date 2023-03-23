#include <iostream>
using namespace std;

class CObj			// Base 클래스
{
public:
	CObj()// : m_iA(100)
	{
		cout << "부모 생성자 호출" << endl;
	}
	CObj(const CObj& rhs)
	{
		m_iA = rhs.m_iA - 1;
		cout << "부모 복사 생성자 호출" << endl;
	}
	//CObj(int _iA) : m_iA(_iA) {}

	~CObj() { cout << "부모 소멸자 호출" << endl; }

public:
	int		m_iA;
};

class CPlayer : public CObj	// Derived 클래스
{
public:
	CPlayer()
	{
		a = 1;
		cout << "자식 생성자 호출" << endl;
	}
	CPlayer(const CPlayer& rhs)//:CObj(rhs)
	{
		m_iA = 5;
		cout << "자식 복사 생성자 호출" << endl;
	}
	~CPlayer() { cout << "자식 소멸자 호출" << endl; }

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
