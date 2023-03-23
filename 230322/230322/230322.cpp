#include <iostream>
using namespace std;

	class CObj
	{
	public:
		void	Render() { cout << "Render" << endl; }

	public:
		virtual ~CObj() {}
	};

	class CPlayer : public CObj
	{
	public:
		void	Draw() { cout << "player" << endl; }
	};
void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

CObj* pObj = new CObj;
CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);

if (nullptr == pPlayer)
	cout << "����" << endl;

pPlayer->Draw();
	// C��Ÿ�� ĳ������ ������ ŭ
	// �ٿ�ĳ����, ��ĳ����
	// ĳ������ ��� �״� �������� �ʴ�.
	// 
	// ĳ������ ����
	// 1. ���� �ӵ��� ���� ����
	// 2. ���� �������� ���� ���α׷��� ��û�� ���� ����
	// 
	// static_cast
	// ������ Ÿ�ӿ� �����ϴ� �� ��ȯ ���� ������(���� ĳ����), c��� ĳ���ð� ������ ����
	// �������� ����ȯ�� �ƴѰ�� ����
	// ���ô� ���� �ڵ忡
	// static_cast�� ������ ������ ����Ǵ� ĳ�����̴� ���� �� Ÿ�� �ÿ� ����Ǵ�  ~~
	// �׷��� �� �������� ������ �����ص� �װ��� �� �� �ִ� ������ ����.
	//
	// dynamic_cast
	// RTTI(��Ÿ�� ���� ����)
	// RTTI�� ��ǥ���� ������ dynamic_cast
	// rtti�� ���� �ѹ� �˾ƺ���
	// ���� : ����ƽ�� ���̳��� ĳ���� ������ ���̿� ���� ���� or rtti�� ���� ������ ���� ��� ��� �� ���� ���� ��
	// 
	// �ٿ�ĳ������ �� ��Ÿ�� �� ��������� ����ȯ�̶� �ǴܵǸ� nullptr ��ȯ
	// ���ô� ���� �ڵ忡
	// 
	// dynamic_cast�� ���� : �� Ÿ�� �� ������ �� ��ȯ�� ���� nullptr ��ȯ�� ���� �Ǵ����� ĳ������ �ӵ��� ������.
	// ������ ĳ������ ���� Ȯ�εǸ� static_cast�� �ٲٴ� ����� ����
	// 
	// const_cast
	// ������ �� ���۷��� �ڷ����� ��� �����ϸ�, �Ͻ������� const ������ ���ܳ���.
	// int iNumber = 10;
	// const int* p = &iNumber;	// �б� ���� ������
	// int* p2 = const_cast<int*>(p);
	// *p2 = 20;
	// cout << iNumber << endl;
	// 
	// reinterpret_cast
	// const �����͸� ������ ��� �����͵��� �� ��ȯ ���, ���������� ���� ���� �� ��ȯ�� ���
	// ������ �� ���� ����� �ʷ��ϱ� ������ ������ ����� �����Ѵ�.
	// void* ������ ����� �� �� �� �ֱ� ��.
	// 
	// int iNumber = 65;
	// char* ptr = reinterpret_cast<char*>(&iNumber);
	// cout << ptr << endl;
	// 
	// ���� : ť, ����, ����Ʈ�� ������ �����ϰ� �ڵ� �м��ϴ� ���θ� ���ݺ��� �غ���
	// 
	// c++ �� Ư�� : 1. OOP   2. �Ϲ�ȭ(generic)
	// �Ϲ�ȭ ���α׷����̶�
	// '���� ��Ȱ�� �Ǵ�'
	// ������ ���Ŀ� �������� �ʰ�, �ϳ��� ���� ���� �ٸ� ������ Ÿ�Ԥ����� ���� �� �ִ� ����� ������ �ξ� ���뼺�� ���� �� �ִ� ���α׷��� ���(from wikipedia)
	// 
	// �ζ��� �Լ� : �ڵ尡 �ٷ� ���ԵǴ� ġȯ ������ �Լ�
	// ���� �����Ϸ��� �����ؼ� �˾Ƽ� �ζ���ȭ �����ֱ� ��
	// �ζ��� �Լ��� �Ϲ� �Լ��� ����Ǵ� ���
	// 1. �ζ��� �Լ��� �Լ� �����͸� Ȱ���Ͽ� ȣ���ϴ� ���(�ζ��� �Լ��� �ּҰ� ���µ� �����͸� ����ϸ� �ּҸ� ���� �־���� �ϱ� ����)
	// 2. �ζ��� �Լ��� ��� ���·� ȣ���ϴ� ���
	// getset�� ����� �־��µ� ��״� �� �ζ���ȭ �ƴٰ� ���� ��
	// 

}