#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace std;
using namespace ariel;


TEST_CASE("Checking the correctness of MagicalContainer functions: size(), removeElement(), addElement()") {
    MagicalContainer container;
    CHECK_THROWS(container.removeElement(10));
    container.addElement(1);
    CHECK(container.size() == 1);
    CHECK_NOTHROW(container.removeElement(1));
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size() == 4);
    CHECK_THROWS(container.removeElement(10));
    
}

TEST_CASE("Checking the correctness of AscendingIterator functions: begin(), end(),++") {
    MagicalContainer container;
    MagicalContainer::AscendingIterator iterator(container);
    CHECK_EQ(*iterator.begin(),*iterator.end());
    container.addElement(-5);
    CHECK_EQ(*iterator.begin(),-5);
    container.addElement(5);
    container.addElement(2);
    container.addElement(4);
    container.addElement(3);
    container.addElement(-1);
    container.addElement(-4);
    container.addElement(0);

    CHECK(*iterator ==-5);
    ++iterator;
    CHECK(*iterator ==-4);
    ++iterator;
    CHECK(*iterator ==-1);
    ++iterator;
    CHECK(*iterator ==0);
    ++iterator;
    CHECK(*iterator ==2);
    ++iterator;
    CHECK(*iterator ==3);
    ++iterator;
    CHECK(*iterator ==4);
    ++iterator;
    CHECK(*iterator == 5);

    container.addElement(-6);
    ++iterator;
    CHECK(iterator==iterator.end());
    CHECK_THROWS(++iterator);
    
}


TEST_CASE("Checking the correctness of SideCrossIterator functions: begin(), end(),++") {
    MagicalContainer container;
    MagicalContainer::SideCrossIterator iterator(container);
    CHECK_EQ(*iterator.begin(),*iterator.end());

    container.addElement(-5);
    CHECK_EQ(*iterator.begin(),-5);

    container.addElement(5);
    container.addElement(2);
    container.addElement(4);
    container.addElement(3);
    container.addElement(-1);
    container.addElement(-4);
    container.addElement(0);

    CHECK(*iterator==-5);
    ++iterator;
    CHECK(*iterator == 5);
    ++iterator;
    CHECK(*iterator==-4);
    ++iterator;
    CHECK(*iterator ==4);
    ++iterator;
    CHECK(*iterator ==-1);
    ++iterator;
    CHECK(*iterator == 3);
    ++iterator;
    CHECK(*iterator == 0);
    ++iterator;
    CHECK(*iterator == 2);

    container.addElement(-6);
    ++iterator;
    CHECK(iterator==iterator.end());
    CHECK_THROWS(++iterator);
    
}

// Test case for the PrimeIterator
TEST_CASE("Checking the correctness of PrimeIterator functions: begin(), end(),++") {
    MagicalContainer container;
    ////no prime numbers
    container.addElement(-3);
    container.addElement(8);
    container.addElement(10);
    container.addElement(12);

    MagicalContainer::PrimeIterator iterator(container);
    CHECK_EQ(*iterator.begin(),*iterator.end());

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(-5);
    container.addElement(6);
    container.addElement(11);
   
    
    CHECK(*iterator == 2);
    ++iterator;
    CHECK(*iterator == 3);
    ++iterator;
    CHECK(*iterator == 5);
    ++iterator;
    CHECK(*iterator == 11);

    container.addElement(7);
    
    ++iterator;
    CHECK(iterator == iterator.end());
    CHECK_THROWS(++iterator);

}

TEST_CASE("Using operators on iterators of differant containers should throw error") {
    MagicalContainer container1;
    MagicalContainer container2;

    MagicalContainer::AscendingIterator iterator1(container1);
    MagicalContainer::AscendingIterator iterator2(container2);
    CHECK_THROWS(iterator1 = iterator2);
    CHECK_THROWS_AS(bool b = (iterator1 == iterator2), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator1 != iterator2), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator1 < iterator2), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator1 > iterator2), runtime_error);

    MagicalContainer::SideCrossIterator iterator3(container1);
    MagicalContainer::SideCrossIterator iterator4(container2);

    CHECK_THROWS(iterator3 = iterator4);
    CHECK_THROWS_AS(bool b = (iterator3 == iterator4), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator3 != iterator4), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator3 < iterator4), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator3 > iterator4), runtime_error);
 
    MagicalContainer::PrimeIterator iterator5(container1);
    MagicalContainer::PrimeIterator iterator6(container2);

    CHECK_THROWS(iterator5 = iterator6);
    CHECK_THROWS_AS(bool b = (iterator5 == iterator6), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator5 != iterator6), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator5 < iterator6), runtime_error);
    CHECK_THROWS_AS(bool b = (iterator5 > iterator6), runtime_error);
}

TEST_CASE("Checking the correctness of the operators: ==,!=, <, >") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::AscendingIterator iterator1(container);
    MagicalContainer::AscendingIterator iterator2(container);
    for(int i=0;i<5;i++){
        CHECK(iterator1 == iterator2);
        CHECK_FALSE((iterator1 != iterator2));
        CHECK_FALSE(iterator1 < iterator2);
        CHECK_FALSE(iterator1 > iterator2);
        ++iterator1;
        ++iterator2;
    }    

    MagicalContainer::SideCrossIterator iterator3(container);
    MagicalContainer::SideCrossIterator iterator4(container);
    for(int i=0;i<5;i++){
        CHECK(iterator3 == iterator4);
        CHECK_FALSE((iterator3 != iterator4));
        CHECK_FALSE(iterator3 < iterator4);
        CHECK_FALSE(iterator3 > iterator4);
        ++iterator3;
        ++iterator4;
    }
    
    MagicalContainer::PrimeIterator iterator5(container);
    MagicalContainer::PrimeIterator iterator6(container);
    for(int i=0;i<5;i++){
        CHECK(iterator5 == iterator6);
        CHECK_FALSE((iterator5 != iterator6));
        CHECK_FALSE(iterator5 < iterator6);
        CHECK_FALSE(iterator5 > iterator6);
        ++iterator5;
        ++iterator6;
    }
    
}

TEST_CASE("Checking the correctness of the operator = and that the irerators are independend") {
    MagicalContainer container1;
    MagicalContainer container2;
    container1.addElement(1);
    container1.addElement(2);
    container1.addElement(3);
    ///
    container2.addElement(4);
    container2.addElement(5);
    container2.addElement(6);

    MagicalContainer::AscendingIterator iterator1(container1);
    MagicalContainer::AscendingIterator iterator2(container2);
    CHECK(*iterator2 == 1);
    ++iterator2; 

    iterator1 = iterator2;

    CHECK(*iterator1 == 2);
    ++iterator1;
    CHECK(*iterator2 == 2);
    ++iterator2;
    CHECK(*iterator1 == 3);
    ++iterator1;
    CHECK(*iterator2 == 3);
    ++iterator2;


     
    MagicalContainer::SideCrossIterator iterator3(container2);
    MagicalContainer::SideCrossIterator iterator4(container2);

    CHECK(*iterator4 == 1);
    ++iterator4;

    iterator3 = iterator4;
    
    CHECK(*iterator3 == 2);
    ++iterator3;
    CHECK(*iterator4 == 2);
    ++iterator4;
    CHECK(*iterator3 == 3);
    ++iterator3;
    CHECK(*iterator4 == 3);
    ++iterator4;
    
    MagicalContainer container3; 
    MagicalContainer::PrimeIterator iterator5(container3);
    MagicalContainer::PrimeIterator iterator6(container3);
    CHECK(*iterator6 == 1);
    ++iterator6;
    iterator5 = iterator6;

    CHECK(*iterator5 == 2);
    ++iterator5;
    CHECK(*iterator6 == 2);
    ++iterator6;
    CHECK(*iterator5 == 3);
    ++iterator5;
    CHECK(*iterator6 == 3);
    ++iterator6;
   
}






