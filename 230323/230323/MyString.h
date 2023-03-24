#pragma once

typedef class MyString
{
public:
	explicit MyString();
	MyString(const MyString& rhs);
	MyString(const char* rhs);
	~MyString() { delete[] m_szStr; m_szStr = nullptr; }

public:
	const char* c_str() const;
	size_t capacity();
	size_t size();
	size_t length();
	void resize(size_t);
	void reserve();
	void reserve(size_t);
	void shrink_to_fit();

public:
	void operator=(const MyString& _szRight);
	void operator=(const char* _szRight);
	MyString& operator+=(const MyString& _szRight);
	MyString operator+(const MyString& _szRight);
	bool operator==(const MyString& _szRight);
	bool operator!=(const MyString& _szRight);

private:
	int m_iSize;
	int m_iCapacity;
	char* m_szStr;

}String;