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
    return slug/KILOS_IN_A_POUND;
}
float Weight::fromPoundToSlug(float pound) noexcept {
    return pound*SLUGS_IN_A_POUND;
}
float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    float commonValue;
    switch(fromUnit){
        case POUND : commonValue = fromWeight;
        case KILO  : commonValue = fromKilogramToPound(fromWeight);
        case SLUG  : commonValue = fromSlugToPound(fromWeight);
    }
    float toValue;
    switch(toUnit){
        case POUND : toValue = commonValue;
        case KILO  : toValue = fromPoundToKilogram(commonValue);
        case SLUG  : toValue = fromPoundToSlug(commonValue);
    }
    return toValue;
}






Weight::Weight() noexcept {}






