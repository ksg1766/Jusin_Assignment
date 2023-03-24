#include <iostream>
#include "MyString.h"
using namespace std;

void main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	//_CrtSetBreakAlloc(246);

	String sTest1 = "asdf";
	cout << sTest1.c_str() << '\n' << sTest1.size() << '\n' << sTest1.capacity() << "\n\n";

	String sTest2("qwert");
	cout << sTest2.c_str() << '\n' << sTest2.length() << '\n' << sTest2.capacity() << "\n\n";

	String sTest3;
	sTest3 = "zxcvbn";
	cout << sTest3.c_str() << '\n' << sTest3.length() << '\n' << sTest3.capacity() << "\n\n\n";

	String sTest4;
	cout << sTest4.c_str() << '\n' << sTest4.length() << '\n' << sTest4.capacity() << "\n\n";

	sTest1 += sTest2;
	cout << sTest1.c_str() << '\n' << sTest1.length() << '\n' << sTest1.capacity() << "\n\n";

	sTest1 += sTest3;
	cout << sTest1.c_str() << '\n' << sTest1.length() << '\n' << sTest1.capacity() << "\n\n";

	sTest1 = (sTest1 + sTest3);
	cout << sTest1.c_str() << '\n' << sTest1.length() << '\n' << sTest1.capacity() << "\n\n";

	sTest2 += sTest3;
	sTest1 += sTest2;
	sTest1 += sTest1 + sTest2 + sTest3;
	cout << sTest2.c_str() << '\n' << sTest2.length() << '\n' << sTest2.capacity() << "\n\n";
	cout << sTest1.c_str() << '\n' << sTest1.length() << '\n' << sTest1.capacity() << "\n\n";

	sTest1.reserve(100);
	cout << sTest1.c_str() << '\n' << sTest1.length() << '\n' << sTest1.capacity() << "\n\n";

	sTest1.resize(10);
	cout << sTest1.c_str() << '\n' << sTest1.length() << '\n' << sTest1.capacity() << "\n\n";

	sTest1 = sTest2;
	cout << sTest1.c_str() << '\n' << sTest1.length() << '\n' << sTest1.capacity() << "\n\n";

	sTest1.shrink_to_fit();
	cout << sTest1.c_str() << '\n' << sTest1.length() << '\n' << sTest1.capacity() << "\n\n";

	sTest1 = sTest3;
	if (sTest1 == sTest3)
		cout << "true\n";

	if (sTest2 != sTest3)
		cout << "true\n";
}