#include "Cointainer.h"
IntArray::IntArray(int length):
    m_length(length)
{
    m_data = new int[length];   
}
IntArray::~IntArray()
{
    delete[] m_data;
}
IntArray::IntArray(const IntArray& a): IntArray(a.getLength()) 
{
    std::copy_n(a.m_data, m_length, m_data); 
}
IntArray& IntArray::operator=(const IntArray& a) 
{   
    if (&a == this)
        return *this;    
    reallocate(a.getLength());
    std::copy_n(a.m_data, m_length, m_data); 
    return *this;
}
void IntArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}
int& IntArray:: operator[](int index)
{
    if (index >= 0 && index < m_length) {
        return m_data[index];
    }
    else
    {
        throw std::out_of_range("bad_range");
    }
}
void IntArray::reallocate(int newLength)
{
    erase();
    if (newLength <= 0)
        return;   
    m_data = new int[newLength];
    m_length = newLength;
}
void IntArray::resize(int newLength)
{    
    if (newLength == m_length)
        return ;    
    if (newLength == 0)
    {
        erase();
        return ;
    }    
    int* data{ new int[newLength] };   
    if (m_length >= 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        std::copy_n(m_data, elementsToCopy, data); 
    }
    delete[] m_data;    
    m_data = data;
    m_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
    
    if (index >= 0 && index <= m_length) {       
        int* data{ new int[m_length + 1] };        
        std::copy_n(m_data, index, data);        
        data[index] = value;        
        std::copy_n(m_data + index, m_length - index, data + index + 1);        
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    else
    {
        throw std::out_of_range("bad_range");
    }
}

void IntArray::remove(int index)
{   
    if (index >= 0 && index < m_length) {        
        if (m_length == 1)
        {
            erase();
            return;
        }        
        int* data{ new int[m_length - 1] };       
        std::copy_n(m_data, index, data);        
        std::copy_n(m_data + index + 1, m_length - index - 1, data + index);        
        delete[] m_data;
        m_data = data;
        --m_length;
    }
    else
    {
        throw std::out_of_range("bad_range");
    }
}
void IntArray::insertAtBeginning(int value) { insertBefore(value, 0); }
void IntArray::insertAtEnd(int value) { insertBefore(value, m_length); }
int IntArray::getLength() const { return m_length; }