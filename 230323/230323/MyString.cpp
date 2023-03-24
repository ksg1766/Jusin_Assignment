#include "MyString.h"
#define MIN_ALOC(x) (16 * ((x) / 16 + 1) - 1)
#define CHECK_CAPACITY(x) if (m_iCapacity >= x)
#define STR_DEEP_CPY_ALOC char* szTemp = new char[m_iCapacity + 1]; \
                          for (int i = 0; i < m_iSize; ++i) { szTemp[i] = m_szStr[i]; } \
                          szTemp[m_iSize] = '\0'; \
                          delete m_szStr; m_szStr = szTemp;

MyString::MyString() : m_iCapacity(0), m_iSize(0) { reserve(); }

MyString::MyString(const MyString& rhs)
{
    reserve();
    *this = rhs;
    /*if (!rhs.m_iSize)
        return;

    CHECK_CAPACITY(rhs.m_iCapacity)
    {
        for (int i = 0; i < rhs.m_iSize + 1; ++i)
            m_szStr[i] = rhs.m_szStr[i];
        m_iSize = rhs.m_iSize;
        return;
    }

    reserve(rhs.m_iCapacity);
    for (int i = 0; i < rhs.m_iSize + 1; ++i)
        m_szStr[i] = rhs.m_szStr[i];
    m_iSize = rhs.m_iSize;
    return;*/
}

MyString::MyString(const char* _szRight) : m_iSize(0)
{
    size_t iTemp = 0;
    for (int i = 0; _szRight[i] != '\0'; ++i)
        ++iTemp;

    m_iCapacity = MIN_ALOC(iTemp);
    STR_DEEP_CPY_ALOC
    *this = _szRight;
}


const char* MyString::c_str() const
{
    return m_szStr;
}

size_t MyString::capacity()
{
    return size_t(m_iCapacity);
}

size_t MyString::size()
{
    return size_t(m_iSize);
}

size_t MyString::length()
{
    return size_t(m_iSize);
}

void MyString::resize(size_t _iSize)
{
    CHECK_CAPACITY(_iSize)
    {
        m_szStr[_iSize] = '\0';
        m_iSize = _iSize;
        return;
    }
    reserve(_iSize);
}

void MyString::reserve()
{
    size_t iNewSize = MIN_ALOC(m_iSize);
    CHECK_CAPACITY(iNewSize) return;

    m_iCapacity = iNewSize;
    STR_DEEP_CPY_ALOC
}

void MyString::reserve(size_t _iSize)
{
    CHECK_CAPACITY(_iSize) return;

    m_iCapacity = MIN_ALOC(_iSize);
    STR_DEEP_CPY_ALOC
}

void MyString::shrink_to_fit()
{
    m_iCapacity = MIN_ALOC(m_iSize);
    STR_DEEP_CPY_ALOC
}

void MyString::operator=(const MyString& _szRight)
{
    *this = _szRight.c_str();
    /*if (!_szRight.m_iSize)
        return;

    CHECK_CAPACITY(_szRight.m_iCapacity)
    {
        for (int i = 0; i < _szRight.m_iSize + 1; ++i)
            m_szStr[i] = _szRight.m_szStr[i];
        m_iSize = _szRight.m_iSize;
        return;
    }

    reserve(_szRight.m_iCapacity);
    for (int i = 0; i < _szRight.m_iSize + 1; ++i)
        m_szStr[i] = _szRight.m_szStr[i];
    m_iSize = _szRight.m_iSize;
    return;*/
}

void MyString::operator=(const char* _szRight)
{
    size_t iTemp = 0;
    for (int i = 0; _szRight[i] != '\0'; ++i)
        ++iTemp;

    CHECK_CAPACITY(iTemp)
    {
        for (int i = 0; i < iTemp + 1; ++i)
            m_szStr[i] = _szRight[i];
        m_iSize = iTemp;
        return;
    }

    reserve(iTemp);
    for (int i = 0; i < iTemp + 1; ++i)
        m_szStr[i] = _szRight[i];
    m_iSize = iTemp;
    return;
}

MyString& MyString::operator+=(const MyString& _szRight)
{
    size_t iTemp = m_iSize + _szRight.m_iSize;
    CHECK_CAPACITY(iTemp)
    {
        for (int i = m_iSize; i < iTemp + 1; ++i)
            m_szStr[i] = _szRight.m_szStr[i - m_iSize];
        m_iSize = iTemp;
        return *this;
    }

    m_iCapacity = MIN_ALOC(iTemp);
    STR_DEEP_CPY_ALOC
    for (int i = m_iSize; i < iTemp + 1; ++i)
        m_szStr[i] = _szRight.m_szStr[i - m_iSize];
    m_iSize = iTemp;
    return *this;
}

MyString MyString::operator+(const MyString& _szRight)
{
    MyString strTemp(*this);
    strTemp += _szRight;
    return strTemp;
}

bool MyString::operator==(const MyString& _szRight)
{
    if (m_iSize != _szRight.m_iSize)
        return false;

    for (int i = 0; i < m_iSize; ++i)
        if (m_szStr[i] != _szRight.m_szStr[i])
            return false;

    return true;
}

bool MyString::operator!=(const MyString& _szRight)
{
    return !(*this == _szRight);
}