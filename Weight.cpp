///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Reid Lum <reidlum@hawaii.edu>
/// @date   03_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Weight.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <stdexcept>

using namespace std;
const char* unitName(Weight::UnitOfWeight unit)
{
    switch(unit){
        case 0:
            return "Pound";
        case 1:
            return "Kilo";
        case 2:
            return "Slug";
    }
    return "none";
}
const float Weight::UNKNOWN_WEIGHT = -1;
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;
const std::string Weight::POUND_LABEL = "Pound";
const std::string Weight::KILO_LABEL = "Kilo";
const std::string Weight::SLUG_LABEL = "Slug";
float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram/KILOS_IN_A_POUND;
}
float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound*KILOS_IN_A_POUND;
}
float Weight::fromSlugToPound(float slug) noexcept {
    return slug/SLUGS_IN_A_POUND;
}
float Weight::fromPoundToSlug(float pound) noexcept {
    return pound*SLUGS_IN_A_POUND;
}
float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    float commonValue;
    switch(fromUnit){
        case POUND : commonValue = fromWeight;
            break;
        case KILO  : commonValue = fromKilogramToPound(fromWeight);
            break;
        case SLUG  : commonValue = fromSlugToPound(fromWeight);
            break;
    }
    float toValue;
    switch(toUnit){
        case POUND : toValue = commonValue;
            break;
        case KILO  : toValue = fromPoundToKilogram(commonValue);
            break;
        case SLUG  : toValue = fromPoundToSlug(commonValue);
            break;
    }
    return toValue;
}

Weight::Weight() noexcept {
    Weight::bIsKnown = false;
    Weight::bHasMax = false;
    Weight::unitOfWeight = POUND;
    Weight::weight = UNKNOWN_WEIGHT;
    Weight::maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight) {
    setWeight(newWeight);
    Weight::bHasMax = false;
    Weight::unitOfWeight = POUND;
    Weight::maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(const Weight::UnitOfWeight newUnitOfWeight) noexcept {
    Weight::bIsKnown = false;
    Weight::bHasMax = false;
    Weight::unitOfWeight = newUnitOfWeight;
    Weight::weight = UNKNOWN_WEIGHT;
    Weight::maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, const Weight::UnitOfWeight newUnitOfWeight) {
    Weight::bHasMax = false;
    setWeight(newWeight, newUnitOfWeight);
    Weight::maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, float newMaxWeight) {
    setMaxWeight(newMaxWeight);
    setWeight(newWeight);
    Weight::unitOfWeight = POUND;
}

Weight::Weight(const UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    Weight::unitOfWeight = newUnitOfWeight;
    setMaxWeight(newMaxWeight);
    Weight::bIsKnown = false;
    Weight::weight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, const UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight(newWeight, newMaxWeight) {
    Weight::unitOfWeight = newUnitOfWeight;
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if (checkWeight > 0 && !bHasMax) {
        return true;
    }
    else if (checkWeight > 0 && checkWeight <= maxWeight) {
        return true;
    }
    else{
        return false;
    }
}


void Weight::setWeight(float newWeight) {
    if (isWeightValid(newWeight)) {
        Weight::weight = newWeight;
        Weight::bIsKnown = true;
    }
    else{
        throw std::out_of_range("Weight not good");
    }
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    if (isWeightValid(newWeight)) {
        Weight::weight = newWeight;
        Weight::bIsKnown = true;
        Weight::unitOfWeight = weightUnits;
    }
    else {
        throw std::out_of_range("Weight not good");
    }
}

void Weight::setMaxWeight(float newMaxWeight) {
    if (newMaxWeight > 0) {
        Weight::maxWeight = newMaxWeight;
        Weight::bHasMax = true;
    }
    else {
        throw std::out_of_range("Weight not good");
    }
}

bool Weight::isWeightKnown() const noexcept {
    return Weight::bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    return Weight::bHasMax;
}

float Weight::getWeight() const noexcept {
    return Weight::weight;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return convertWeight(Weight::weight, Weight::unitOfWeight, weightUnits);
}

float Weight::getMaxWeight() const noexcept {
    return Weight::maxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::unitOfWeight;
}

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
void Weight::dump() const noexcept{
    cout << setw(46) << setfill('=') << "" << endl;
    cout << setfill(' ') ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE("Weight","this") << &weight << endl;
    FORMAT_LINE("Weight","isKnown") << isWeightKnown() << endl;
    FORMAT_LINE("Weight","weight") << getWeight() << endl;
    FORMAT_LINE("Weight","unitOfWeight") << unitName(getWeightUnit()) << endl;
    FORMAT_LINE("Weight","hasMax") << hasMaxWeight() << endl;
    FORMAT_LINE("Weight","maxWeight") << getMaxWeight() << endl;
}
