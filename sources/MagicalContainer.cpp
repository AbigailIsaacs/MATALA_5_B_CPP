#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "MagicalContainer.hpp"
#include <cmath>
#include <algorithm>
using namespace std;
namespace ariel
{
    int MagicalContainer::size()
    {
        return elements.size();
    }

    void MagicalContainer::addElement(int element)
    {
        if (isNumberInContaner(element))
        {
            return;
        }
        elements.emplace_back(element);
        int index_element = elements.size()-1;
        insertIntoSortedVector(AscendingElements,element, index_element);
        if (isPrime(element))
        {
            insertIntoSortedVector(PrimeElements, element, index_element);
        }
    }

    void MagicalContainer::removeElement(int remove)
    {
        if(!(isNumberInContaner(remove))){
            throw runtime_error(" Removing a non-existing element");
        }
        int index =0;
        for(auto it = elements.begin(); it< elements.end(); it++){ // Pass the address of 'remove'
            if (*it ==  remove)
            {
                elements.erase(it);
                break;
            }
            index++;
        }

        for(auto it2 = AscendingElements.begin(); it2!=AscendingElements.end();it2++){
            if(*it2 > index){
               (*it2)--;
            }
            if (*it2 == index){
                AscendingElements.erase(it2);
            }
        } 
         for(auto it3 = PrimeElements.begin(); it3!=PrimeElements.end();it3++){
             if(*it3 > index){
               (*it3)--;
            }
            if (*it3 == index){
                PrimeElements.erase(it3);
            }
        } 

        

    }

    void MagicalContainer::insertIntoSortedVector(std::vector<int> &vec, int element, int index_element)
    {
        int it = 0;
        while (it != vec.size() && elements[(size_t)vec[(size_t)it]] < element)
        {
            ++it;
        }
        vec.insert(vec.begin()+it, index_element);
    }

    bool MagicalContainer::isPrime(int number)
    {
        if (number <= 1)
        {
            return false;
        }
        int sqrtNumber = std::sqrt(number);
        for (int i = 2; i <= sqrtNumber; ++i)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    bool MagicalContainer::isNumberInContaner(int new_element)
    {
        for (int element : elements)
        {
            if (element == new_element)
            {
                return true;
            }
        }
        return false;
    }
}