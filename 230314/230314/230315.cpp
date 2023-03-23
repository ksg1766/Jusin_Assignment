#include <iostream>
using namespace std;

class CObj
{
public:
	CObj() {}

public:
	static int		m_iA;// = 0;
	//int				m_iB;

public:
	void	Render()
	{
		m_iA++;
		cout << m_iA << endl;
	}

	static void	Draw()
	{
		static int		iTemp = 300;

		cout << iTemp << endl;
		//cout << _iA << endl;
		cout << m_iA << endl;
		//cout << m_iB << endl;		// 클래스의 정적 함수 내부에서는 같은 클래스의 멤버 변수 사용이 불가능
		//Render();
	}
};

int CObj::m_iA = 24;

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	//CObj	Obj;
	//CObj	ObjArr[3];

	//Obj.Render();
	//Obj.Render();
	//Obj.Render();

	//ObjArr[0].Render();
	//ObjArr[1].Render();
	//ObjArr[2].Render();
	
	//cout << Obj[0].m_iA << endl;
	//cout << CObj::m_iA << endl;

	CObj	Obj;
	Obj.Draw();
	CObj::Draw();

	// static 멤버 변수
	// 멤버변수로 선언된 static 변수는 멤버변수라고 하지 않는다. 성질 자체가 다름. 객체와 static변수의 생성시점이 다름.
	// 클래스 내부에서는 초기화가 불가능하고 namespace를 통해서만 초기화 가능 ex) CObj::m_iA = 0;
	// static 변수는 클래스 내부에 세들어 사는 느낌. 구성 요소라 볼 순 없음. 따라서 서용할 때는 위처럼 출신 성분을 반드시 밝혀야함.
	// 그리고 객체 생성을 하지 않아도 바로 접근 가능. 따라서 은닉성을 파괴할 수 있기 때문에 일반적으로 private으로 선언함.
	// 데이터영역의 bss영역에 저장되므로 초기화하지 않으면 bss에 들어가서 0으로 초기화 된 후 데이터 영역으로 옮겨감(물론 직접해주는게 좋긴 함).
	// 객체의 소유가 아니기 때문에 여러 객체를 생성해도 하나의 static 멤버변수에 접근한다.
	// static 멤버 함수를 통해서도 static 멤버변수에 접근할 수 있다. Obj.Draw(); CObj::Draw();와 같이도 호출할 수 있음.
	// 언제 사용하는냐: 객체의 특성과 상관없이 함수만 만들어서 제공하는 기능성 클래스일 때 (ex. 그리기 클래스 계산기 클래스 등)
	// 근데 이 static 멤버함수 내에서 일반적인 멤버변수를 사용할 수 없다.(읽기가 가능했던 const와 다르게 아예 사용 자체가 불가능. 메모리와 관련된 문제임.)
	// static은 컴파일 타임에 Data영역에 바로 저장하며 보통 컴파일러가 먼저 처리하는 편.
	// 하지만 클래스와 같은 사용자 정의 타입은 메모리 공간 확보 등 처리해야할 일들이 좀 많기 때문에 같은 Data영역이라도 나중에 등록되는 편.
	// 
	// 복사 생성자
	// 그냥 객체를 생성할 때는 멤버변수를 일대일로 초기화 되지만 복사 생성자를 이용하면 메모리블럭 대 메모리블럭으로 복사를 하기 때문에 더 빠름
	// 객체가 생성될 때 자동으로 생성 되는 것. 디폴트 생성자, 복사 생성자, 복사 대입연산자 (디폴트 생성자는 명시적으로 구현한 생성자가 하나라도 있다면 호출되지 않음)
	// const CObj& rhs : rhs는 right hand side의 약자로 그냥 많이 쓰는 이름임.
	// 1. 원본 객체를 매개변수로 복사하여 객체를 생성하는 경우
	// 2. (함수의 매개변수는 항상 call by value이기 때문에) 함수의 매개변수가 객체 자룡형인 경우
	// 3. 함수의 반환 타입이 객체 자료형인 경우(반환 할 떄는 반환값이 항상 임시객체에 복사되기 때문에
	// 깊은 복사 체크 : 멤버변수가 포인터인지 확인, 생성자에서 동적할당을 하는지 or 소멸자 내에서 메모리를 해제하는지, 
	// string을 memcpy하면 터짐. string은 char*를 반환함. 고로 주소대 주소로 복사됨(char*도 마찬가지?). 따라서 메모리대 메모리로 복사하는 memcpy는 터뜨림.
	// 그래서 구조체 안에서 웬만하면 stl쓰지말고 문자열은 char배열 쓰자. 정 쓰려면 깊은 복사해야함
	// 숙제: TextRPG에 그냥 한번 static이나 복사 생성자 구현해보자. static은.... Render함수 같은 곳에나 쓰든가 해보자.


}