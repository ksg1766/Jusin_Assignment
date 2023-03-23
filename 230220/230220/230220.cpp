#include <iostream>
using namespace std;

void SetInput(int* iInput1, int* iInput2)
{
	cin >> *iInput1 >> *iInput2;
}

void SwapByReference(int* _iNum1, int* _iNum2)
{
	int iTemp = *_iNum1;
	*_iNum1 = *_iNum2;
	*_iNum2 = iTemp;
}

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	int iDst(0), iSrc(0);
	SetInput(&iDst, &iSrc);
	SwapByReference(&iDst, &iSrc);
	cout << iDst << '\t' << iSrc << '\n';
}