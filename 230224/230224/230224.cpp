#include <iostream>

using namespace std;

int Strlen(const string&);
string Strrev(const string&, const int);
void Swap(char*, char*);

typedef struct tagGrade
{
	int iKor = 0;
	int iEng = 0;
	int iMat = 0;
	float fAvg = 0.f;

	void InitGrade(int _kor, int _eng, int _mat);
}GRADE, *PGRADE;

typedef struct tagStudent
{
	string szName;
	GRADE tGrade;

	void InitInfo(string _name, int _kor, int _eng, int _mat);
}STUDENT, *PSTUDENT;

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	string iInput;
	cout << "���ڿ��� �Է��ϼ���: ";
	cin >> iInput;

	cout << Strlen(iInput) << '\n';
	cout << Strrev(iInput, Strlen(iInput)) << '\n';
	
	STUDENT tStudent = {};
	string szName("");
	int iKor(0), iEng(0), iMat(0);
	cout << "�л��� �̸��� ������ �Է��ϼ���: ";
	cin >> szName >> iKor >> iEng >> iMat;

	// ����
	// 1. ���ڿ��� �Է� �ް� null ���ڸ� ������ ������ ������ ������ ���� �Լ��� ���� �����϶�
	// 2. ���ڿ��� ������ �Լ��� ������
	// 3. ����ü�� �̿��Ͽ� 3���� �л��� ������ �Է� �ް� ����ǥ�� ����ϴ� ���α׷��� ����� ����.
}

int Strlen(const string& _input)
{
	int _iLen;
	for (_iLen = 0; _input[_iLen] != '\0'; ++_iLen);
	return _iLen;
}

string Strrev(const string& _input, const int _size)
{
	int _index = Strlen(_input);
	string szTemp = _input;
	
	for (int i = 0; i < _index / 2; ++i)
		Swap(&szTemp[i], &szTemp[_index - 1 - i]);
	return szTemp;
}

void Swap(char* left, char* right)
{
	char temp = *left;
	*left = *right;
	*right = temp;
}

void PrintGrade(string _name)
{

}

void PrintAll()
{

}

void tagStudent::InitInfo(string _name, int _kor, int _eng, int _mat)
{
	szName = _name;
	tGrade.InitGrade(_kor, _eng, _mat);
}

void tagGrade::InitGrade(int _kor, int _eng, int _mat)
{
	iKor = _kor; iEng = _eng; iMat = _mat;
}