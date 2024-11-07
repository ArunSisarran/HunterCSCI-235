/*
Name: Arun Sisarran
Date: 9/16/2024
Email: arun.sisarran52@myhunter.cuny.edu
Description: Creates the instructions for the functions defined in the header file.
*/
#include "Dish.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/**
* Sets the name of the dish.
* @param name A reference to the new name of the dish.
* @post Sets the private member `name_` to the value of the parameter.
*/

void Dish::setName(string name_){
    this->name_ = name_;
}

/**
* @return The name of the dish.
*/

string Dish::getName(){
    return name_;
}

/**
* Sets the list of ingredients.
* @param ingredients A reference to the new list of ingredients.
* @post Sets the private member `ingredients_` to the value of the
parameter.
*/

void Dish::setIngredients(vector<string> ingredients){
    ingredients_.insert(ingredients_.end(), ingredients.begin(), ingredients.end());
}

/**
* @return The list of ingredients used in the dish.
*/

vector<string> Dish::getIngredients(){
    return ingredients_;
}

/**
* Sets the preparation time.
* @param prep_time The new preparation time in minutes.
* @post Sets the private member `prep_time_` to the value of the
parameter.
*/

void Dish::setPrepTime(int prep_time_){
    this->prep_time_ = prep_time_;
}

/**
* @return The preparation time in minutes.
*/

int Dish::getPrepTime(){
    return prep_time_;
}

/**
* Sets the price of the dish.
* @param price The new price of the dish.
* @post Sets the private member `price_` to the value of the parameter.
*/

void Dish::setPrice(double price_){
    this->price_ = price_;
}

/**
* @return The price of the dish.
*/

double Dish::getPrice(){
    return price_;
}

/**
* Sets the cuisine type of the dish.
* @param cuisine_type The new cuisine type of the dish (a CuisineType
enum).
* @post Sets the private member `cuisine_type_` to the value of the
parameter.
*/

void Dish::setCuisineType(string cuisine_type){
    if (cuisine_type == "ITALIAN") 
        cuisine_type_ = ITALIAN;
    else if (cuisine_type == "MEXICAN") 
        cuisine_type_ = MEXICAN;
    else if (cuisine_type == "CHINESE") 
        cuisine_type_ = CHINESE;
    else if (cuisine_type == "INDIAN") 
        cuisine_type_ = INDIAN;
    else if (cuisine_type == "AMERICAN") 
        cuisine_type_ = AMERICAN;
    else if (cuisine_type == "FRENCH") 
        cuisine_type_ = FRENCH;
    else cuisine_type_ = OTHER;
}

/**
* @return The cuisine type of the dish in string form.
*/

string Dish::getCuisineType(){
    switch (this->cuisine_type_) {
        case ITALIAN: 
            return "ITALIAN";
        case MEXICAN: 
            return "MEXICAN";
        case CHINESE: 
            return "CHINESE";
        case INDIAN: 
            return "INDIAN";
        case AMERICAN: 
            return "AMERICAN";
        case FRENCH: 
            return "FRENCH";
        case OTHER: 
            return "OTHER";
    }
    return 0;
}

/**
* Displays the details of the dish.
* @post Outputs the dish's details, including name, ingredients,
preparation time, price, and cuisine type, to the standard output.
* The information must be displayed in the following format:
*
* Dish Name: [Name of the dish]
* Ingredients: [Comma-separated list of ingredients]
* Preparation Time: [Preparation time] minutes
* Price: $[Price, formatted to two decimal places]
* Cuisine Type: [Cuisine type]
*/

void Dish::display(){
    string name = Dish::getName();
    vector<string> ingredients = Dish::getIngredients();
    int prepTime = Dish::getPrepTime();
    double price = Dish::getPrice();
    string cuisine = Dish::getCuisineType();

    cout<<"Dish Name: "<<name<<endl;
    cout<<"Ingredients: ";
    for(int i = 0; i < ingredients.size(); i++){
        cout<<ingredients[i];
        if(i < ingredients.size()-1){
            cout<<", ";
        }
        else{}
    }
    cout<<endl;
    cout<<"Preparation Time: "<<prepTime<<" minutes"<<endl;
    cout<<"Price: $"<<price<<endl;
    cout<<"Cuisine Type: "<<cuisine<<endl;

}