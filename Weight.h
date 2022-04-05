///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Reid Lum <reidlum@hawaii.edu>
/// @date   03_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <ostream>

class Weight {
public:
    //enum
    enum UnitOfWeight{POUND, KILO, SLUG};

private:
    //private member function
    void setMaxWeight(float newMaxWeight);

    //private attributes
    bool  bIsKnown;
    bool  bHasMax;
    enum  UnitOfWeight unitOfWeight;
    float weight {};
    float maxWeight {};

public:
    //static public attributes
    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

    //static public member functions
    static float fromKilogramToPound(float kilogram) noexcept;
    static float fromPoundToKilogram(float pound) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug(float pound) noexcept;
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

    //Public Member Functions
    Weight() noexcept;
    Weight(float newWeight);
    Weight(const UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, const UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(const UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, const UnitOfWeight newUnitOfWeight, float newMaxWeight);

    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnits);
    bool isWeightValid(float checkWeight) const noexcept;
    bool validate() const noexcept;
    void dump() const noexcept;
    bool operator== (const Weight &rhs_Weight) const;
    bool operator< (const Weight &rhs_Weight) const;
    Weight& operator+= (float rhs_addToWeight);

    bool isWeightKnown() const noexcept;
    bool hasMaxWeight () const noexcept;
    float getWeight() const noexcept;
    float getWeight(UnitOfWeight weightUnits) const noexcept;
    float getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit () const noexcept;

};


