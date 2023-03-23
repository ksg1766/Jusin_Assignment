#include <iostream>

using namespace std;

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	// 멤버 변수 앞에는 사실 this가 숨겨져 있다고 볼 수 있다. 따라서 다른 객체에서도 각자의 멤버변수를 잘 찾아 쓸 수 있는 것
	// this는 상수 포인터로 만들어져서 내,외부에서 모두 사용 가능 또한 힙으로 할당해도 
	// 
	// 
	// extern키워드가 붙은 변수는 존재 유무만 알려줄 뿐 실제 메모리에 할당되지 않음. 따라서 선언과 동시에 초기화 불가.
	// 1. 원본 전역 변수가 있어야 함.
	// 2. 원본의 자료형, 변수 이름까지 완전히 일치해야함.
	// 3. cpp에 만들어도 되고 헤더파일에 extern하나 만들어 주고 헤더파일을 포함시키는 식으로도 쓸 수 있음
	//		(사용하는 시점 마다 extern을 써야하는데 그럴거면 헤더에 넣고 헤더를 포함하는게 낫지 않나 해서 헤더에 만든 것)
	// C++에서는 static과 클래스를 이용한 방법이 더 권장됨.
	// extern

	// friend
	// friend를 사용하면 다른 클래스의 private 멤버에도 접근할 수 있게 됨.- 외부 클래스에서 멤버 변수의 접근 권한을 허가받는 문법
	// friend void CMonster::Func();
	// friend class CMonster;	// 특정 클래스에게 private 멤버 접근을 모두 허용
	// 잠깐 가져다 쓸 떄야 쓸 수 있지만 되도록 지양하도록 하자
}