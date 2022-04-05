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
    cout << Weight::fromKilogramToPound(1) << " " << Weight::convertWeight(1, Weight::KILO, Weight::POUND) << endl;
    cout << Weight::fromPoundToKilogram(1) << " " <<Weight::convertWeight(1, Weight::POUND, Weight::KILO) << endl;
    cout << Weight::fromSlugToPound(1) << " " << Weight::convertWeight(1, Weight::SLUG, Weight::POUND) << endl;
    cout << Weight::Weight::fromPoundToSlug(1) << " " << Weight::convertWeight(1, Weight::POUND, Weight::SLUG) << endl;
    cout << endl;

}
