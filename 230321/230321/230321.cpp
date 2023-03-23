#include <iostream>
using namespace std;

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	// 복습
	// 누구나 보편적으로 사용할 것 같은 함수는 오버라이딩, 클래스마다 개별적으로 갖고 있을것 같다면 캐스팅을 많이 쓴다
	// 오버라이딩: 은닉화 재정의 개념 두가지 다 소유
	// 재정의 : 부모가 갖고 있는 함수의 이름으로 호출하겠다~
	// virtual 은 하위 객체로 내려줄 수 있을 때만 동적 바인딩이 됨.
	// 실수들을 졸라게 많이 하니 그냥 상속을 받으면 그냥 자식이건 부모건 소멸자 앞에 virtual을 붙이자...
	// override 키워드
	// CPlayer2 Player
	// CObj* pObj = Player
	// pObj -> Render();
	// 결과 : 자식의 Render()호출
	// 전방선언은 부모타입으로 헤더파일은 자식으로
	// 다중상속하면 테이블은 하나만 생김
	// 내일은 캐스팅할 예정
	// 초중고급상점을 구현 : 각각 초중고급 무기방어구 : 가격, 옵션(공격력&체력)
}