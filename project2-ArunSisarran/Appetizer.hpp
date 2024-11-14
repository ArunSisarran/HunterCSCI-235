/**
 * @file Appetizer.hpp
 * @brief This file contains the definitions of the Appetizer class
 * @date 9/30/24
 * @author Arun Sisarran
 */

#ifndef APPETIZER_HPP
#define APPETIZER_HPP

#include "Dish.hpp"
#include <string>

class Appetizer : public Dish
{
    public:
//Definition of the serving style enum
        enum ServingStyle { PLATED, FAMILY_STYLE, BUFFET };
//Default constructor 
        Appetizer();
//Paramatized constructor 
        Appetizer(const std::string& name, const std::vector<std::string>& ingredients, const int& prep_time, const double& price, const CuisineType& cuisine_type,
        const ServingStyle& serving_style, const int& spiciness_level, const bool& vegetarian);

//setter defintions for serving style, spiciness level, and vegetarian flag
        void setServingStyle(const ServingStyle& serving_style);
        void setSpicinessLevel(const int& spiciness_level);
        void setVegetarian(const bool& vegetarian);

//Getter definitions for serving style, spiciness level, and vegetarian flag 
        ServingStyle getServingStyle() const;
        int getSpicinessLevel() const;
        bool isVegetarian() const;

//Display function definition for testing
        void displayAPPs() const;

    private:
        ServingStyle serving_style_;
        int spiciness_level_;
        bool vegetarian_;
};

#endif 