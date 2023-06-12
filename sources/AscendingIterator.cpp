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

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator& copy):contaner(copy.contaner){
    contaner = copy.contaner; 
    current = copy.current ;
   
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magicalContainer):contaner(magicalContainer) {
    contaner = magicalContainer;
    if(contaner.size()==0){
        current = (contaner.elements.size());
        is_end=true;
    }
}

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &iterator) const{
    if(&contaner!=&iterator.contaner){
        throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
    }
    if((this->current)==(iterator.current)&& (this->is_end==iterator.is_end)){
        return true;
    }
    return false;
    
}
bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &iterator)const {
    if(&contaner!=&iterator.contaner){
        throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
    }
    if((this->current)!=(iterator.current)||(this->is_end!=iterator.is_end)){
        return true;
    }
    return false;
}
bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &iterator) const{
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
bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &iterator) const{
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
int MagicalContainer::AscendingIterator::operator*() const {
    if(current==contaner.AscendingElements.size()){
            return -1;
        }
    int index_ans = contaner.AscendingElements[(size_t)current];
    return contaner.elements[(size_t)index_ans];
}

MagicalContainer::AscendingIterator & MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
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
MagicalContainer::AscendingIterator & MagicalContainer::AscendingIterator::operator++() {
    if(this->is_end){
        throw runtime_error ("Iterator is already pointing to the end");
    }
    ++current;
    if(current==contaner.elements.size() ){
        this->is_end=true;
        

    }
    return *this;
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    AscendingIterator to_return (contaner) ;
    return to_return;
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator to_return (contaner) ;
    to_return.current = (contaner.elements.size()); //O(1)
    to_return.is_end=true;
    return to_return;
}
}