#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <vector>
namespace ariel
{

    class MagicalContainer
    {
    private:  
        std::vector<int> elements;
        std::vector<int> AscendingElements;
        std::vector<int> PrimeElements;
    public:
        
        void addElement(int element);
        int size();
        void removeElement(int remove);
        void insertIntoSortedVector(std::vector<int> &vec, int element,int index_element );
        void insertSideCrossElements(int* element) ;
        bool isNumberInContaner(int element);
        bool isPrime(int number);
        class AscendingIterator
        {

        private:
            bool is_end = false;
            int current =0;
            MagicalContainer & contaner;
        public:
            
            AscendingIterator();
            AscendingIterator(const AscendingIterator &copy);
            AscendingIterator(MagicalContainer& magicalContainer);
            
            // AscendingIterator members and methods
            ~AscendingIterator() = default;
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &iterator)const;
            bool operator!=(const AscendingIterator &iterator)const;
            bool operator<(const AscendingIterator &iterator)const;
            bool operator>(const AscendingIterator &iterator)const;
            int operator*()const;
            
            AscendingIterator &operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator
        {
        private:
            int small_ptr ;
            int big_ptr;
            bool small_turn;
            bool is_end_big;
            bool is_end_small;
            
            MagicalContainer& contaner;
        public:
            SideCrossIterator();
            SideCrossIterator(const SideCrossIterator &copy);
            SideCrossIterator(MagicalContainer& magicalContainer);
           
           
            // AscendingIterator members and methods
            ~SideCrossIterator() = default;
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &iterator) const;
            bool operator!=(const SideCrossIterator &iterator)const;
            bool operator<(const SideCrossIterator &iterator)const;
            bool operator>(const SideCrossIterator &iterator)const;
            int operator*() const;
            
            SideCrossIterator &operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        class PrimeIterator
        {
        private:
            bool is_end = false;
            int current =0;
            MagicalContainer& contaner;
            
        public:
            PrimeIterator();
            PrimeIterator(const PrimeIterator &copy);
            PrimeIterator(MagicalContainer& magicalContainer);
            
            
            // AscendingIterator members and methods
            ~PrimeIterator() = default;
            PrimeIterator &operator=(const PrimeIterator &other) ;
            bool operator==(const PrimeIterator &iterator) const;
            bool operator!=(const PrimeIterator &iterator) const;
            bool operator<(const PrimeIterator &iterator) const;
            bool operator>(const PrimeIterator &iterator)const;
            int operator*() const;
            
            PrimeIterator &operator++();
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}