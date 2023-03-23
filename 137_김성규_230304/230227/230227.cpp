#include "230227.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#pragma region
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;
#pragma endregion

	CreatePlayer();
}