///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Reid Lum <reidlum@hawaii.edu>
/// @date   03_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include "Weight.h"

using namespace std;

int main() {
    //testing static methods
    cout << Weight::fromKilogramToPound(1) << " " << Weight::convertWeight(1, Weight::KILO, Weight::POUND) << endl;
    cout << Weight::fromPoundToKilogram(1) << " " <<Weight::convertWeight(1, Weight::POUND, Weight::KILO) << endl;
    cout << Weight::fromSlugToPound(1) << " " << Weight::convertWeight(1, Weight::SLUG, Weight::POUND) << endl;
    cout << Weight::Weight::fromPoundToSlug(1) << " " << Weight::convertWeight(1, Weight::POUND, Weight::SLUG) << endl;
    cout << endl;

    //testing 7 constructors
    Weight noWeight = Weight();
    noWeight.dump();
    Weight testWeight1 = Weight(1);
    testWeight1.dump();
    Weight testWeight2 = Weight(Weight::KILO);
    testWeight2.dump();
    Weight testWeight3 = Weight(3, Weight::SLUG);
    testWeight3.dump();
    Weight testWeight4 = Weight(4,10);
    testWeight4.dump();
    Weight testWeight5 = Weight(Weight::KILO, 10);
    testWeight5.dump();
    Weight testWeight6 = Weight(6, Weight::SLUG, 10);
    testWeight6.dump();
    cout << endl;

    //testing misc function
    cout << testWeight1.getWeight(Weight::SLUG) << endl;
    cout << testWeight1.getWeight(Weight::KILO) << endl;
    cout << testWeight6.getWeight(Weight::SLUG) << endl;
    cout << endl;

    //testing errors for constructors... All throw exceptions
    //Weight badWeight1 = Weight(-3); //tests negative weight
    //Weight badWeight2 = Weight(-3, Weight::SLUG); //tests negative weight with units
    //Weight badWeight3 = Weight(10, 5); //tests weight larger than max weight
    //Weight badWeight4 = Weight(Weight::SLUG, -5); //test negative max weight with units
    //Weight badWeight5 = Weight(20,Weight::SLUG, 10); //tests weight larger than max weight with units

    //testing setWeights
    Weight testWeight = Weight(1, Weight::KILO, 100); //sets max to 100 kilos
    try{
        testWeight.setWeight(80, Weight::SLUG); //tries to set weight to 80 slugs (more than 100 kilos)
        assert(false);
    } catch (exception const &e) {}
    try{
        testWeight.setWeight(-1);
        assert(false);
    } catch (exception const &e) {}

    try{
        testWeight.setWeight(-1,Weight::KILO);
        assert(false);
    } catch (exception const &e) {}

    Weight opWeight1 = Weight(3);
    Weight opWeight2 = Weight(3);
    bool answer1 = opWeight1 == opWeight2;
    cout<< answer1 << endl;
/*
    Weight opWeight2 = Weight(2);
    Weight answer2 = opWeight2 += 3;
    cout << answer2.getWeight() << endl;
*/
    Weight opWeight5 = Weight(5);
    Weight opWeight6 = Weight(6);
    bool answer3 = opWeight5 < opWeight6;
    cout<< answer3 << endl;

}
