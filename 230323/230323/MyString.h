#pragma once

typedef class MyString
{
public:
	explicit MyString();
	MyString(const MyString& rhs);
	MyString(const char* rhs);

	void operator=(const MyString& _szRight);
	void operator=(const char* _szRight);
	MyString& operator+=(const MyString& _szRight);
	MyString operator+(const MyString& _szRight);
	bool operator==(const MyString& _szRight);
	bool operator!=(const MyString& _szRight);
	
	const char* c_str() const;
	size_t capacity();
	size_t size();
	size_t length();
	void resize(size_t);
	void reserve();
	void reserve(size_t);
	void shrink_to_fit();
	

private:
	int m_iSize;
	int m_iCapacity;
	char* m_szStr;

	// (=, +, == 오버로딩)
}String;