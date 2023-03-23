#include <iostream>

using namespace std;

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	// stdin : 표준 입력 스트림, 기본 키보드 대상
	// stdout : 표준 출력 스트림, 기본 모니터 대상
	// stderr : 표준 에러 스트림, 기본 모니터 대상, 우리가 볼 수는 없음

	// 텍스트 모드 입출력 함수

	// 아스키 코드 한 글자를 출력하는 함수(stdout으로 고정)
	// 함수 호출 실패 시 EOF를 반환

	// putchar(65); // 콘솔 입출력만 가능
	// fputc('S', stdout); // 콘솔 파일 소켓 등의 입출력 모두 가능

	// 아스키 코드 한 글자를 입력하는 함수(stdin으로 고정)
	
	// int iTemp = getchar();
	// putchar(iTemp);

	//int iTemp = fgetc(stdin);
	//fputc(iTemp, stdout);

	while (true)
	{
		char ch = getchar();

		if (EOF == ch)		// ctrl + z 키를 입력하면 콘솔 입출력에서 EOF가 삽입
			break;

		putchar(ch);
	}

}