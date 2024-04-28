#include "Cointainer.h"
int main()
{    
    IntArray array(10);   
    for (int i = 0; i < array.getLength(); ++i)
    {
        array[i] = i + 1;
    }    
    array.resize(8);    
    array.insertBefore(20, 5);   
    array.remove(3);   
    array.insertAtEnd(30);
    array.insertAtBeginning(40);
    for (int i=0; i < array.getLength(); ++i)
    {
        std::cout << array[i] << ' ';
    }

    std::cout << '\n';
    IntArray b;
    b = array;
    for (int i=0; i < b.getLength(); ++i)
    {
        std::cout << b[i] << ' ';
    }
    std::cout << '\n';
    try {
        for (int i = 0; i < b.getLength()+2; ++i)
        {
            b[i]+=i;
        }
    }
    catch (const std::out_of_range& s) {
        std::cout << s.what()<<std::endl;
    }
    try {
        IntArray arr(-1);
    }
    catch (const std::bad_array_new_length& s) {
        std::cout << s.what()<<std::endl;
    }
    try {
        int s = array[23];
    }
    catch (const std::out_of_range& s) {
        std::cout << s.what() << std::endl;
    }
    try {
        IntArray s(3);
        array.resize(-1);
        s = array;
    }
    catch (const std::bad_array_new_length& s) {
        std::cout << s.what()<<std::endl;
    }
    try {
        array.insertBefore(30, -1);
    }
    catch (const std::out_of_range& s) {
        std::cout << s.what() << std::endl;
    }
    try {
        array.insertBefore(30, 101);
    }
    catch (const std::out_of_range& s) {
        std::cout << s.what() << std::endl;
    }
    try {
        array.remove(-1);
    }
    catch (const std::out_of_range& s) {
        std::cout << s.what() << std::endl;
    }
    return 0;
}