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

    //testing
}
