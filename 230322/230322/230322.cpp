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
	cout << "에러" << endl;

pPlayer->Draw();
	// C스타일 캐스팅의 단점이 큼
	// 다운캐스팅, 업캐스팅
	// 캐스팅은 사실 그닥 안전하지 않다.
	// 
	// 캐스팅의 단점
	// 1. 동작 속도가 느린 문법
	// 2. 결코 안전하지 않은 프로그래머 요청에 따른 동작
	// 
	// static_cast
	// 컴파일 타임에 수행하는 형 변환 지원 연산자(정적 캐스팅), c언어 캐스팅과 동일한 동작
	// 논리적인 형변환이 아닌경우 에러
	// 예시는 수업 코드에
	// static_cast는 컴파일 시점에 수행되는 캐스팅이다 보니 런 타임 시에 수행되는  ~~
	// 그래서 비 논리적인 접근이 가능해도 그것을 알 수 있는 수단이 없다.
	//
	// dynamic_cast
	// RTTI(런타임 형식 정보)
	// RTTI의 대표적인 문법이 dynamic_cast
	// rtti에 대해 한번 알아보자
	// 면접 : 스태틱과 다이나믹 캐스팅 질문의 차이에 대해 설명 or rtti에 대해 설명해 봐라 라고 물어볼 수 있음 면접 때
	// 
	// 다운캐스팅할 때 런타임 시 비논리적인 형변환이라 판단되면 nullptr 반환
	// 예시는 수업 코드에
	// 
	// dynamic_cast의 단점 : 런 타임 시 논리적 형 변환에 따른 nullptr 반환한 여부 판단으로 캐스팅의 속도가 느리다.
	// 안전한 캐스팅인 것이 확인되면 static_cast로 바꾸는 방법도 있음
	// 
	// const_cast
	// 포인터 및 레퍼런스 자료형만 사용 가능하며, 일시적으로 const 성격을 벗겨낸다.
	// int iNumber = 10;
	// const int* p = &iNumber;	// 읽기 전용 포인터
	// int* p2 = const_cast<int*>(p);
	// *p2 = 20;
	// cout << iNumber << endl;
	// 
	// reinterpret_cast
	// const 포인터를 제외한 모든 포인터들의 형 변환 허용, 논리적으로 맞지 않은 형 변환도 허용
	// 예측할 수 없는 결과를 초래하기 때문에 가급적 사용을 자제한다.
	// void* 포인터 사용할 때 쓸 수 있긴 함.
	// 
	// int iNumber = 65;
	// char* ptr = reinterpret_cast<char*>(&iNumber);
	// cout << ptr << endl;
	// 
	// 숙제 : 큐, 스택, 리스트의 내용을 이해하고 코드 분석하는 공부를 지금부터 해보자
	// 
	// c++ 의 특성 : 1. OOP   2. 일반화(generic)
	// 일반화 프로그래밍이란
	// '쉽게 재활용 되다'
	// 데이터 형식에 의존하지 않고, 하나의 값이 여러 다른 데이터 타입ㅇ들을 가질 수 있는 기술에 중점을 두어 재사용성을 높일 수 있는 프로그래밍 방식(from wikipedia)
	// 
	// 인라인 함수 : 코드가 바로 삽입되는 치환 상태의 함수
	// 요즘엔 컴파일러가 발전해서 알아서 인라인화 시켜주긴 함
	// 인라인 함수가 일반 함수로 변경되는 경우
	// 1. 인라인 함수를 함수 포인터를 활용하여 호출하는 경우(인라인 함수는 주소가 없는데 포인터를 사용하면 주소를 만들어서 넣어줘야 하기 떄문)
	// 2. 인라인 함수를 재귀 형태로 호출하는 경우
	// getset을 헤더에 넣었는데 얘네는 다 인라인화 됐다고 보면 됨
	// 

}