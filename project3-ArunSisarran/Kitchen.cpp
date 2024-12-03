/**
 * @file Kitchen.cpp
 * @brief This file contains the implementations of the Kitchen class.
 * 
 * The Kitchen file contains the implementations that are used to manage dishes in the kitchen simulation
 * 
 * @date 10/14/2024
 * @author Arun Sisarran
 */

#include "Kitchen.hpp"
#include "Dish.hpp"
#include "ArrayBag.hpp"
#include <string>
#include <cmath>

/**
 * Default constructor.
 * Default-initializes all private members.
 */
Kitchen::Kitchen(){
    total_prep_time = 0;
    count_elaborate = 0;
}

/**
 * @param : A reference to a `Dish` being added to the kitchen.
 * @post : If the given `Dish` is not already in the kitchen, adds the
`Dish` to the kitchen and updates the preparation time sum and elaborate
dish count if the dish is elaborate.
 * @return : Returns true if a `Dish` was successfully added to the
kitchen, false otherwise.
 Hint: Use the above definition of equality to help determine if a
`Dish` is already in the kitchen.
*/
bool Kitchen::newOrder(const Dish& dish){
    bool flag = false;
    // conditional that checks if the dish reference is already in the kitchen.
    if(Kitchen::contains(dish)){
        flag = false;
    }else{
        // if not alreayd in the kitchen, add the dish to the kitchen
        Kitchen::add(dish);
        total_prep_time += dish.getPrepTime();
        // conditional that checks if the dish is elaborate and adjusts elaborate counter
        if(dish.getIngredients().size() >= 5 && dish.getPrepTime() >= 60){
            count_elaborate++;
        }
        flag = true;
    }
    return flag;
}

/**
 * @param : A reference to a `Dish` leaving the kitchen.
 * @return : Returns true if a dish was successfully removed from the
kitchen (i.e.,
items_), false otherwise.
 * @post : Removes the dish from the kitchen and updates the preparation
time sum.
 If the `Dish` is elaborate, it also updates the elaborate count.
*/

bool Kitchen::serveDish(const Dish& dish) {
    // conditional that checks if the dish was removed then adjusts the total prep time
    if(Kitchen::remove(dish)){
        total_prep_time -= dish.getPrepTime();
        // conditional that checks if the dish was elaborate and adjust elaborate counter
        if(dish.getIngredients().size() >= 5 && dish.getPrepTime() >= 60){
            count_elaborate--;
        }
        return true;
    }
    return false;
}

/**
 * @return : The integer sum of preparation times for all the dishes
currently in the kitchen.
*/

int Kitchen::getPrepTimeSum() const{
    return total_prep_time;
}

/**
 * @return : The average preparation time (int) of all the dishes in the
kitchen. The lowest possible average prep time should be 0.
 * @post : Computes the average preparation time (double) of the kitchen
rounded to the NEAREST integer.
*/

int Kitchen::calculateAvgPrepTime() const{
    int lowest = 0;
    // conditional to check if there is anything in the kitchen and return 0 if there isnt
    if(Kitchen::getCurrentSize() == 0){
        return lowest;
    }
    double average = static_cast<double>(total_prep_time)/Kitchen::getCurrentSize();
     return static_cast<int>(std::round(average));
}

/**
 * @return : The integer count of the elaborate dishes in the kitchen.
 * */

int Kitchen::elaborateDishCount() const{
    return count_elaborate;
}

/**
 * @return : The percentage (double) of all the elaborate dishes in the
kitchen. The lowest possible percentage should be 0%.
 * @post : Computes the percentage of elaborate dishes in the kitchen
rounded up to 2 decimal places.
*/

double Kitchen::calculateElaboratePercentage() const{
    double lowest = 0.0;
    // conditional to check if there is anything in the kitchen and return 0 if there isnt
    if(Kitchen::getCurrentSize() == 0){
        return lowest;
    }
    double x = (static_cast<double>(count_elaborate)/Kitchen::getCurrentSize())*100;
    double percent = std::ceil(x * 100) / 100;
    return percent;
}

/**
 * @param : A reference to a string representing a cuisine type with a
value in
 ["ITALIAN", "MEXICAN", "CHINESE", "INDIAN", "AMERICAN",
"FRENCH", "OTHER"].
 * @return : An integer tally of the number of dishes in the kitchen of the
given cuisine type.
 If the argument string does not match one of the expected
cuisine types, the tally is zero.
 NOTE: No pre-processing of the input string necessary, only
uppercase input will match.
*/

int Kitchen::tallyCuisineTypes(const std::string& cuisineType) const{
    int count = 0;
    // for loop that iterates through all the dishes in the kitchen
    for(int i = 0; i < Kitchen::getCurrentSize(); i++){
        Dish dish = Kitchen::items_[i];
        // conditional that checks if the dishes cuisine type matches the reference cuisine type passed by the param
        if(dish.getCuisineType() == cuisineType){
            count++;
        }
    }
    return count;
}

/**
 * @param : A reference to an integer representing the preparation time
threshold of the dishes to be removed from the kitchen.
 * @post : Removes all dishes from the kitchen whose preparation time is
less than the given time.
 * @return : The number of dishes removed from the kitchen.
*/

int Kitchen::releaseDishesBelowPrepTime(const int& prep){
    int removedCounter = 0;
    // loops through all the dishes in the kitchen
    for(int i = 0; i < Kitchen::getCurrentSize(); i++){
        Dish dish = Kitchen::items_[i];
        // conditional that checks if the prep time of the dish is under the prep time passed by the param
        if(dish.getPrepTime() < prep){
            // conditional that checks if the dish was removed from the kitchen
            if(Kitchen::remove(dish)){
                removedCounter++;
                total_prep_time -= dish.getPrepTime();
                // conditional that checks if the dish was elaborate and adjusts the elaborate count
                if(dish.getIngredients().size() >= 5 && dish.getPrepTime() >= 60){
                    count_elaborate--;
                }
                i--;
            }
        }
    }
    return removedCounter;
}

/**
 * @param : A reference to a string representing a cuisine type with a
value in
 ["ITALIAN", "MEXICAN", "CHINESE", "INDIAN", "AMERICAN",
"FRENCH", "OTHER"].
 * @post : Removes all dishes from the kitchen whose cuisine type matches
the given type.
 * @return : The number of dishes removed from the kitchen.
 NOTE: No pre-processing of the input string necessary, only
 uppercase input will match.
 If the input string does not match one of the expected cuisine
types, do not remove any dishes.
*/

int Kitchen::releaseDishesOfCuisineType(const std::string& cuisineType){
    int removedCounter = 0;

    // loop through all the dishes in the kitchen
    for(int i = 0; i < Kitchen::getCurrentSize(); i++){
        Dish dish = Kitchen::items_[i];
        // conditional that checks if the param cuisine type is the same as the dishes cuisine type
        if(cuisineType == dish.getCuisineType()){
            // conditional that checks if the dish was removed from the kitchen
            if(Kitchen::remove(dish)){
                removedCounter++;
                i--;
            }
        }
    }
    return removedCounter;
}

/**
 * @post : Outputs a report of the dishes currently in the kitchen in the
form:
 "ITALIAN: {x}\nMEXICAN: {x}\nCHINESE: {x}\nINDIAN:
{x}\nAMERICAN: {x}\nFRENCH: {x}\nOTHER: {x}\n\n
 AVERAGE PREP TIME: {x}\ELABORATE: {x}%\n"
 Note that the average preparation time should be rounded to the
NEAREST integer, and the
 percentage of elaborate dishes in the kitchen should be rounded
to 2 decimal places.

 Example output:
 ITALIAN: 2
 MEXICAN: 3
 CHINESE: 2
 INDIAN: 1
 AMERICAN: 1
 FRENCH: 2
 OTHER: 2

 AVERAGE PREP TIME: 62
 ELABORATE DISHES: 53.85%
*/

void Kitchen::kitchenReport() const{
    std::cout<<"ITALIAN: "<<Kitchen::tallyCuisineTypes("ITALIAN")<<std::endl;
    std::cout<<"MEXICAN: "<<Kitchen::tallyCuisineTypes("MEXICAN")<<std::endl;
    std::cout<<"CHINESE: "<<Kitchen::tallyCuisineTypes("CHINESE")<<std::endl;
    std::cout<<"INDIAN: "<<Kitchen::tallyCuisineTypes("INDIAN")<<std::endl;
    std::cout<<"AMERICAN: "<<Kitchen::tallyCuisineTypes("AMERICAN")<<std::endl;
    std::cout<<"FRENCH: "<<Kitchen::tallyCuisineTypes("FRENCH")<<std::endl;
    std::cout<<"OTHER: "<<Kitchen::tallyCuisineTypes("OTHER")<<std::endl;
    std::cout<<std::endl;
    std::cout<<"AVERAGE PREP TIME: "<<Kitchen::calculateAvgPrepTime()<<std::endl;
    std::cout<<"ELABORATE DISHES: "<<Kitchen::calculateElaboratePercentage()<<"%"<<std::endl;

}
