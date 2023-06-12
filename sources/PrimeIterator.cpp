#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "MagicalContainer.hpp"
using namespace std;
namespace ariel
{
    
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &copy):contaner(copy.contaner){
        contaner = copy.contaner; 
        current = copy.current ;
    }
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magicalContainer):contaner(magicalContainer){
        contaner = magicalContainer;
        if(contaner.PrimeElements.size()==0){
            current = (contaner.PrimeElements.size()); 
            is_end=true;
        }
    }
    MagicalContainer::PrimeIterator & MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other){
        if(&contaner!=&other.contaner){
        throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if (this == &other) {
            return *this;
        }
        this->contaner = other.contaner;
        this->is_end = other.is_end;
        return *this;
    }
    bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator &iterator)const{
        if(&contaner!=&iterator.contaner){
        throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if((this->current)==(iterator.current)&& (this->is_end==iterator.is_end)){
            return true;
        }
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator &iterator)const{
        if(&contaner!=&iterator.contaner){
        throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if((this->current)!=(iterator.current)||(this->is_end!=iterator.is_end)){
            return true;
        }
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &iterator)const{
        if(&contaner!=&iterator.contaner){
            throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if (iterator.is_end && is_end==false){
            return false;
        }
        if(current < iterator.current){
            return true;
        }
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &iterator)const{
        if(&contaner!=&iterator.contaner){
        throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if(*this==iterator){
            return false;
        }
        if(*this<iterator){
            return false;
        }
        return true;
    }
    int MagicalContainer::PrimeIterator::operator*()const{
        if(this->is_end){
            return -1;
        }
        return contaner.elements[(size_t)(contaner.PrimeElements[(size_t)current])];
    }
    MagicalContainer::PrimeIterator & MagicalContainer::PrimeIterator::operator++(){
        if(this->is_end){
            throw runtime_error ("Iterator is already pointing to the end");
        }
        ++current;
        if(current==contaner.PrimeElements.size() ){
            this->is_end=true;
        }
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        PrimeIterator to_return (contaner) ;
        return to_return;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        PrimeIterator to_return (contaner) ;
        to_return.current = (contaner.PrimeElements.size()); //O(1)
        to_return.is_end=true;
        return to_return;
    }
 
}