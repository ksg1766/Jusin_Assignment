#include <iostream>

using namespace std;

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	// stdin : ǥ�� �Է� ��Ʈ��, �⺻ Ű���� ���
	// stdout : ǥ�� ��� ��Ʈ��, �⺻ ����� ���
	// stderr : ǥ�� ���� ��Ʈ��, �⺻ ����� ���, �츮�� �� ���� ����

	// �ؽ�Ʈ ��� ����� �Լ�

	// �ƽ�Ű �ڵ� �� ���ڸ� ����ϴ� �Լ�(stdout���� ����)
	// �Լ� ȣ�� ���� �� EOF�� ��ȯ

	// putchar(65); // �ܼ� ����¸� ����
	// fputc('S', stdout); // �ܼ� ���� ���� ���� ����� ��� ����

	// �ƽ�Ű �ڵ� �� ���ڸ� �Է��ϴ� �Լ�(stdin���� ����)
	
	// int iTemp = getchar();
	// putchar(iTemp);

	//int iTemp = fgetc(stdin);
	//fputc(iTemp, stdout);

	while (true)
	{
		char ch = getchar();

		if (EOF == ch)		// ctrl + z Ű�� �Է��ϸ� �ܼ� ����¿��� EOF�� ����
			break;

		putchar(ch);
	}

}