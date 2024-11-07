/*
Name: Arun Sisarran
Date: 9/16/2024
Email: arun.sisarran52@myhunter.cuny.edu
Description: Header file for the Dish class, definitions for the getter and setter functions for the five dish catergories along with 
the default constructor and the parameterized constructor are in this file.
*/


#ifndef DISH_HPP
#define DISH_HPP
#include <vector>
#include <string>

using namespace std;

class Dish
{
//Declaration of the enum CuisineType that holds the types of food that can be used.
enum CuisineType{
    ITALIAN = 1, 
    MEXICAN, 
    CHINESE, 
    INDIAN,
    AMERICAN, 
    FRENCH, 
    OTHER
};

private:
//String name variable of the dish 
    string name_;

//An empty vector of the ingredients used in the dish
    vector<string> ingredients_;

//Int prep time variable of the dish     
    int prep_time_;

//double price variable for the cost of the dish
    double price_;
    
//cuisine type variable to assign enum values to the dish
    CuisineType cuisine_type_;
    
public:

//Declaration of the setName function @param name 
    void setName(string name_);

//Declaration of the getName function
    string getName();

//Declaration of the setIngredients function @param ingredients
    void setIngredients(vector<string> ingredients);

//Declaration of the getIngredients function
    vector<string> getIngredients();

//Declaration of the setPrepTime function @param prep time
    void setPrepTime(int prep_time_);

//Declaration of the getPrepTime function
    int getPrepTime();

//Declaration of the setPrice function @param price
    void setPrice(double price_);

//Declaration of the getPrice function
    double getPrice();

//Declaration of the setCuisineType function @param cuisine type
    void setCuisineType(string cuisineType);

//Declaration of the getCuisineType function
    string getCuisineType();

//Declaration of the display function
    void display();

/**
* Default constructor.
* Initializes all private members with default values:
* - name: "UNKNOWN"
* - ingredients: Empty list
* - prep_time: 0
* - price: 0.0
* - cuisine_type: OTHER
*/

    Dish(){
        name_ = "UNKNOWN";
        ingredients_ = {};
        prep_time_ = 0;
        price_ = 0.0;
        cuisine_type_ = OTHER;
    }

/**
* Parameterized constructor.
* @param name A reference to the name of the dish.
* @param ingredients A reference to a list of ingredients (default is
empty list).
* @param prep_time The preparation time in minutes (default is 0).
* @param price The price of the dish (default is 0.0).
* @param cuisine_type The cuisine type of the dish (a CuisineType enum)
with default value OTHER.
* @post The private members are set to the values of the corresponding
parameters.
*/
    Dish(string name_){
        this->name_ = name_;
        ingredients_ = {};
        prep_time_ = 0;
        price_ = 0.0;
        cuisine_type_ = OTHER;
    }


};

#endif