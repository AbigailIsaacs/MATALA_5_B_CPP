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
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &copy):contaner(copy.contaner){
        contaner = copy.contaner; 
        big_ptr = copy.big_ptr ;
        small_ptr = copy.small_ptr;
        is_end_big=copy.is_end_big;
        is_end_small=copy.is_end_small;
        small_turn=true;
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magicalContainer): contaner(magicalContainer){
        if(contaner.size()==0){
            big_ptr = (contaner.AscendingElements.size());
            small_ptr = (contaner.AscendingElements.size());
            is_end_big=true;
            is_end_small=true;
            small_turn = false;
            return;
        }
        contaner = magicalContainer;
        big_ptr = contaner.AscendingElements.size()-1;
        small_ptr = 0;
        is_end_big=false;
        is_end_small=false;
        small_turn=true;

    }
    MagicalContainer::SideCrossIterator & MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other){
        if(&contaner!=&other.contaner){
            throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if (this == &other) {
            return *this;
        }
        this->contaner = other.contaner;
        this->is_end_big = other.is_end_big;
        this->is_end_small = other.is_end_small;
        big_ptr = other.big_ptr ;
        small_ptr = other.small_ptr;
        small_turn=other.small_turn;
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &iterator)const{
        if(&contaner!=&iterator.contaner){
            throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if((this->big_ptr)==(iterator.big_ptr)&& (this->small_ptr)==(iterator.small_ptr)&&(this->small_turn==iterator.small_turn)&&(is_end_small ==iterator.is_end_small)&&(is_end_big ==iterator.is_end_big)){
            return true;
        }
        return false;
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &iterator)const{
        if(&contaner!=&iterator.contaner){
            throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if(*this==iterator){
            return false;
        }
        return true;
    }
    bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &iterator)const{
        if(&contaner!=&iterator.contaner){
            throw runtime_error ("it is not leagle to use operators on iterators of differant containers");
        }
        if(*this==iterator){
            return false;
        }
        if(iterator.is_end_big && !this->is_end_big){
            
            return true;
        }
        if(iterator.is_end_small && !this->is_end_small){
            return true;
        }
        if(this->small_ptr < iterator.small_ptr ||  this->big_ptr > iterator.big_ptr){
            return true;
        }

        return false;
    }
    
    bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &iterator)const{
        
        if(!(*this<iterator)&&!(*this==iterator)){
            return true;
        }
        return false;
    }
    
    int MagicalContainer::SideCrossIterator::operator*()const{
        if(is_end_small && is_end_big){
            return -1;
        }
        if(this->small_turn){
            return contaner.elements[(size_t)(contaner.AscendingElements[(size_t)small_ptr])];
        }
        else {

            return contaner.elements[(size_t)(contaner.AscendingElements[(size_t)big_ptr])];
        }
        return -1;
    }
    MagicalContainer::SideCrossIterator & MagicalContainer::SideCrossIterator::operator++(){
        if(is_end_small && is_end_big){
            throw runtime_error ("Iterator is already pointing to the end");
        }
        if(big_ptr == small_ptr){
            big_ptr = (contaner.AscendingElements.size());
            small_ptr = (contaner.AscendingElements.size());
            is_end_small = true;
            is_end_big = true;
            small_turn= false;
            return *this;
        }
        
        if(this->small_turn){
            small_turn = false;
            small_ptr = small_ptr+1;
        }
        else{
            small_turn = true;
            big_ptr = big_ptr-1;
        }
        
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        
        SideCrossIterator to_return (contaner) ;
        return to_return;
        // big_ptr = contaner.AscendingElements.size()-1;
        // small_ptr = 0;
        // is_end_big=false;
        // is_end_small=false;
        // small_turn=true;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        SideCrossIterator to_return (contaner) ;
        to_return.big_ptr = (contaner.AscendingElements.size());
        to_return.small_ptr = (contaner.AscendingElements.size());
        to_return.is_end_big=true;
        to_return.is_end_small=true;
        to_return.small_turn = false;

        return to_return;
    }
}