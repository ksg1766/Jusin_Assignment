#include <iostream>
using namespace std;

void LoadData();

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	LoadData();
}

void LoadData()
{
	FILE* sourceFp = nullptr;
	FILE* copiedFp = nullptr;

	errno_t err = fopen_s(&sourceFp, "../Data/Image.jpg", "rb");
	errno_t err2 = fopen_s(&copiedFp, "../Data/CopiedImage.jpg", "wb");

	if (err == 0 && err2 == 0)
		while (feof(sourceFp) == 0)
			fputc(fgetc(sourceFp), copiedFp);
	else
		cout << "½ÇÆÐ\n";
		
	fclose(sourceFp);
	fclose(copiedFp);
}