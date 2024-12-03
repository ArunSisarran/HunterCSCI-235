/**
 * @file Kitchen.hpp
 * @brief This file contains the declaration of the Kitchen class.
 * 
 * The Kitchen header file contains the declarations that are used to manage dishes in the kitchen simulation
 * 
 * @date 10/14/2024
 * @author Arun Sisarran
 */

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "ArrayBag.hpp"
#include "Dish.hpp"
#include <string>

class Kitchen : public ArrayBag<Dish>
{
private:
    int total_prep_time;
    int count_elaborate;

public:
/**
 * Default constructor.
 * Default-initializes all private members.
 */
    Kitchen();

/**
 * @param : A reference to a `Dish` being added to the kitchen.
 * @return : Returns true if a `Dish` was successfully added to the
kitchen, false otherwise.
*/

bool newOrder(const Dish& dish);

/**
 * @param : A reference to a `Dish` leaving the kitchen.
 * @return : Returns true if a dish was successfully removed from the kitchen
*/

bool serveDish(const Dish& dish);

/**
 * @return : The integer sum of preparation times for all the dishes
currently in the kitchen.
*/

int getPrepTimeSum() const;

/**
 * @return : The average preparation time (int) of all the dishes in the
kitchen. The lowest possible average prep time should be 0.
*/

int calculateAvgPrepTime() const;

/**
 * @return : The integer count of the elaborate dishes in the kitchen.
 * */

int elaborateDishCount() const;

/**
 * @return : The percentage (double) of all the elaborate dishes in the
kitchen. The lowest possible percentage should be 0%.
*/

double calculateElaboratePercentage() const;

/**
 * @param : A reference to a string representing a cuisine type with a
value in
 ["ITALIAN", "MEXICAN", "CHINESE", "INDIAN", "AMERICAN",
"FRENCH", "OTHER"].
 * @return : An integer tally of the number of dishes in the kitchen of the
given cuisine type.
*/

int tallyCuisineTypes(const std::string& cuisineType) const;

/**
 * @param : A reference to an integer representing the preparation time
threshold of the dishes to be removed from the kitchen.
 * @return : The number of dishes removed from the kitchen.
*/

int releaseDishesBelowPrepTime(const int& prep);

/**
 * @param : A reference to a string representing a cuisine type with a
value in
 ["ITALIAN", "MEXICAN", "CHINESE", "INDIAN", "AMERICAN",
"FRENCH", "OTHER"].
 * @return : The number of dishes removed from the kitchen.
 */

int releaseDishesOfCuisineType(const std::string& cuisineType);

/**
 * @post : Outputs a report of the dishes currently in the kitchen
 * */

void kitchenReport() const;

};

#endif