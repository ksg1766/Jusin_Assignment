#include <iostream>

using namespace std;

void main()
{
    // 숙제
    // 1. 성적표 만들기에서, 평균을 기준으로 점수를 부여하는 프로그램 만들기.100 90 80 70 60 
    // 2. 입력 받은 숫자가 양수인지 음수인지 판별하는 프로그램 만들기(정수)

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
    iInput >= 0 ? cout << "양수" : cout << "음수";
}