#include <iostream>

using namespace std;

void main()
{
    // ����
    // 1. ����ǥ ����⿡��, ����� �������� ������ �ο��ϴ� ���α׷� �����.100 90 80 70 60 
    // 2. �Է� ���� ���ڰ� ������� �������� �Ǻ��ϴ� ���α׷� �����(����)

	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

    int iScore;
    cin >> iScore;

    if (iScore >= 90)
        cout << 'A' << endl;

    else if (iScore >= 80)
        cout << 'B' << endl;

    else if (iScore >= 70)
        cout << 'C' << endl;

    else if (iScore >= 60)
        cout << 'D' << endl;

    else
        cout << 'F' << endl;

    cout << endl;

    int iInput;
    cin >> iInput;
    iInput >= 0 ? cout << "���" : cout << "����";
}