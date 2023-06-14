/*
	Title:    LAB6_lrivers42.cpp
	Author:   Liam Rivers
	Date:     6/8/2023
	Purpose:  superhero compatibility checker
*/

#include<iostream>
#include<string>
using namespace std;

//function prototypes
void getData(string& nameOne, string& nameTwo, string& petOne, string& petTwo, int& ageOne, int& ageTwo);
bool calculateResults(string nameOne, string nameTwo, string petOne, string petTwo, int ageOne, int ageTwo);

int main(){
    //declaring variables to pass to string
    string nameOne;
    string nameTwo;
    string petOne;
    string petTwo;
    int ageOne;
    int ageTwo;
    
    //formatting and calling getData
    cout << "Superhero Roommate Compatibility Check" << endl;
    cout << endl;
    getData(nameOne, nameTwo, petOne, petTwo, ageOne, ageTwo);
    
    cout << "***** RESULTS *****" << endl;
    //calling calculateResults, if it returns true it will say the two people are compatible
    if ( calculateResults(nameOne, nameTwo, petOne, petTwo, ageOne, ageTwo)){
        cout << nameOne << " and " << nameTwo << " are comaptible to be roommates!";
    }
    //if it returns false it says that the two people are NOT compatible
    else{
        cout << nameOne << " and " << nameTwo << " are not compatible to be roommates.";
    }
    
    return 0;
}

/***************************************************************************************
    function name:      getData
    function purpose:   gets the users data for two superheros
***************************************************************************************/
void getData(string& nameOne, string& nameTwo, string& petOne, string& petTwo, int& ageOne, int& ageTwo){
    cout << "Enter the data for the first super hero: " << endl;
    cout << "NAME: ";
    getline(cin, nameOne);
    cout << "AGE: ";
    cin >> ageOne;
    cin.ignore();
    cout << "PET (dog/cat/rabbit/guinea pig): ";
    getline(cin, petOne);
    cout << endl;

    cout << "Enter the data for the second super hero: "<< endl;
    cout << "NAME: ";
    getline(cin, nameTwo);
    cout << "AGE: ";
    cin >> ageTwo;
    cin.ignore();
    cout << "PET (dog/cat/rabbit/guinea pig): ";
    getline(cin, petTwo);
    cout << endl;
    
}

/***************************************************************************************
    function name:      calculateResults
    function purpose:   calculates if two people are compatible or not by checking 
                        three flags.
***************************************************************************************/
bool calculateResults(string nameOne, string nameTwo, string petOne, string petTwo, int ageOne, int ageTwo){
    bool checkOne;
    bool checkTwo;
    bool checkThree;
    char charName;
    int totalOne = 0;
    int totalTwo = 0;

    //getting the ASCII total for both names
    for (int i = 0; i < nameOne.length(); i++){
        charName = nameOne.at(i);
        static_cast<int>(charName);
        totalOne = totalOne + charName;
    }

    for (int i = 0; i < nameTwo.length(); i++){
        charName = nameTwo.at(i);
        static_cast<int>(charName);
        totalTwo = totalTwo + charName;
    }

    cout << "The added ASCII value of " << nameOne << " is " << totalOne << endl;
    cout << "The added ASCII value of " << nameTwo << " is " << totalTwo << endl;
        
    //checking if ASCII amount is within 50 of each other
    if (totalOne >= totalTwo){
        if((totalOne - totalTwo) < 50){
            checkOne = true;
            cout << "CHECK 1 is true." << endl;
        }
        else{
            checkOne = false;
            cout << "CHECK 1 is false." << endl;
        }
    }
    if (totalTwo > totalOne){
        if ((totalOne - totalTwo) < 50) {
            checkOne = true;
            cout << "CHECK 1 is true." << endl;
        }
        else{
            checkOne = false;
            cout << "CHECK 1 is false." << endl;
        }
    }


    //checking if age is within 10 years of each other
    if(ageOne >= ageTwo){
        if((ageOne - ageTwo) <= 10){
            checkTwo = true;
            cout << "CHECK 2 is true." << endl;
        }
        else{
            checkTwo = false;
            cout << "CHECK 2 is false." << endl;
        }
    }

    if(ageOne < ageTwo){
        if((ageTwo - ageOne) <= 10){
            checkTwo = true;
            cout << "CHECK 2 is true." << endl;
        }
        else{
            checkTwo = false;
            cout << "CHECK 2 is false." << endl;
        }
    }
    
    //checking if they have the same pet
    if (petOne == petTwo){
        checkThree = true;
        cout << "CHECK 3 is true." << endl;
    }
    else{
        checkThree = false;
        cout << "CHECK 3 is false." << endl;
    }
    
    //checking for if true or false return
    if((checkOne && checkTwo == true) || (checkOne && checkThree == true) || (checkTwo && checkThree == true)){
        return true;
    }
    else{
        return false;
    }
}