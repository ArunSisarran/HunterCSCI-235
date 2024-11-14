/**
 * @file MainCourse.hpp
 * @brief This file contains the definitions of the MainCourse class
 * @date 9/30/24
 * @author Arun Sisarran
 */

#ifndef MAINCOURSE_HPP
#define MAINCOURSE_HPP

#include "Dish.hpp"
#include <string>
#include <vector>

class MainCourse : public Dish
{
    public:

//definition for the cooking method enum
       enum CookingMethod { GRILLED, BAKED, FRIED, STEAMED, RAW };
//definition for the category enum
       enum Category { GRAIN, PASTA, LEGUME, BREAD, SALAD, SOUP, STARCHES, VEGETABLE };

//side dish struct containing a name of type string and a category of type enum category 
        struct SideDish
        {
            std::string name;
            Category category;
        };

//definitions of the setter functions 
       void setCookingMethod(const CookingMethod& cookingMethod);
       void setProteinType(const std::string& protein);
       void setGlutenFree(const bool& gluten);
       void addSideDish(const SideDish& sidedish);

//definitions of the getter functions
       CookingMethod getCookingMethod() const;
       std::string getProteinType() const;
       bool isGlutenFree() const;
       std::vector<SideDish> getSideDishes() const;

//defualt constructor 
       MainCourse();

//paramatized constructor 
       MainCourse(const std::string& name, const std::vector<std::string>& ingredients, const int& prep_time, const double& price, const CuisineType& cuisine_type,
       const CookingMethod& cookingMethod, const std::string& proteinType, const std::vector<SideDish>& side_dishes, const bool& gluten_free );

//display definition for testing
       void displayMainCourse();

    private:
        CookingMethod cooking_method_;
        std::string protein_type_;
        std::vector<SideDish> side_dishes_;
        bool gluten_free_;

};

#endif