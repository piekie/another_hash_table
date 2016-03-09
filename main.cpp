#include <iostream>
#include "headers/hashtable.h"

int main()
{
    Hash h;

    //pushing 6 elements (when tableSize = 5)
    h.push("Johnny", "Cage");
    h.push("Sonya", "Blade");
    h.push("Liu", "Kang");
    h.push("Kung", "Lao");
    h.push("Kurtis", "Stryker");
    h.push("Jax", "Briggs");

    //keys and hashified analogs printing out
    show(h.getKeys(), h.getHashified());
    std::cout << std::endl;

    //Hindu coding. Due to security reasons :)
    std::cout << h.get("Johnny") << std::endl;
    std::cout << h.get("Sonya") << std::endl;
    std::cout << h.get("Liu") << std::endl;
    std::cout << h.get("Kung") << std::endl;
    std::cout << h.get("Kurtis") << std::endl;
    std::cout << h.get("Jax") << std::endl;
}
