/**
 * @file Dessert.hpp
 * @brief This file contains the definitions of the Dessert class
 * @date 9/30/24
 * @author Arun Sisarran
 */


#ifndef DESSERT_HPP
#define DESSERT_HPP

#include "Dish.hpp"


class Dessert : public Dish
{

public:
//definitions of flavor profile enum
    enum FlavorProfile { SWEET, BITTER, SOUR, SALTY, UMAMI };

//definitions of the setter functions flavor profile, sweetness level, and contain nuts flag
    void setFlavorProfile(const FlavorProfile& flavor);
    void setSweetnessLevel(const int& sweetnessLevel);
    void setContainsNuts(const bool& containsNuts);

//definitions of the getter functions flavor profile, sweetness level, and contain nuts flag
    FlavorProfile getFlavorProfile() const;
    int getSweetnessLevel() const;
    bool containsNuts() const;

//default constructor
    Dessert();
//paramatized constructor 
    Dessert(const std::string& name, const std::vector<std::string>& ingredients, const int& prep_time, const double& price, const CuisineType& cuisine_type,
    const FlavorProfile& flavorProfile, const int& sweetnessLevel, const bool& containsNuts);

//display definition for testing 
    void displayDessert();
    
private:
    FlavorProfile flavor_profile_;
    int sweetness_level_;
    bool contains_nuts_;

};

#endif