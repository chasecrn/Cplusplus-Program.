//
//  AirgeadBankingApp.cpp
//  AirgeadBankingApp
//
//  This application allows users to see how their investments will grow over time
//
//  Created by Chase Crnovich on 3/31/25.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "AirgeadBankingApp.h"


AirgeadBankingApp::AirgeadBankingApp(){
    initialAmount = 0.00;
    monthlyDeposit = 0.00;
    annualInterest = 0.0;
    endingBalance = 0.0;
    numOfYears = 0;
    nChar = 0;
    toPrint = ' ';
    numOfTests = 0;
}

void AirgeadBankingApp::SetInitialAmount(double initialAmount){
    this->initialAmount = initialAmount;
}
void AirgeadBankingApp::SetMonthlyDeposit(double monthlyDeposit){
    this->monthlyDeposit = monthlyDeposit;
}
void AirgeadBankingApp::SetAnnualInterest(double annualInterest){
    this->annualInterest = annualInterest;
}
void AirgeadBankingApp::SetNumOfYears(int numOfYears){
    this->numOfYears = numOfYears;
}


double AirgeadBankingApp::GetInitialAmount(){
    return initialAmount;
}
double AirgeadBankingApp::GetMonthlyDeposit(){
    return monthlyDeposit;
}
double AirgeadBankingApp::GetAnnualInterest(){
    return annualInterest;
}
int AirgeadBankingApp::GetNumOfYears(){
    return numOfYears;
}

//
// this function resets all previous inputs so that
// new display does not show previous test values
// and adds to numOfTests variable
//
// **would love to hear thoughts if there is a
// better way for this to be done**
//
void AirgeadBankingApp:: ResetToDefault(){
    initialAmount = 0.00;
    monthlyDeposit = 0.00;
    annualInterest = 0.0;
    endingBalance = 0.0;
    numOfYears = 0;
    numOfTests += 1;
}

//
// this function uses a for loop that makes it faster
// and easier to output multiple characters or can be used
// to center text
//
string AirgeadBankingApp::nCharToPrint(int nChar, char toPrint){
    
    string output = ""; // variable that creates a string using specified character
    
    for (int i = 0; i < nChar; ++i)
        output = output + toPrint;
    return output;
}

//
// this function makes sure the user input is a positive real number
// using if-else, while, and try
//
// parameter inputRequest gets the prompt user is answering
// parameter requestNum tells the function which validation needs done
//
double AirgeadBankingApp::ValidateInput(string inputRequest, int requestNum = 0){
    double userInput = 0.0; // variable it hold the input from user
    bool validInput = false; // boolean to control while loop
    int error = 0; // variable for the try to throw if input is invalid
    
    if (requestNum == 2) { // if will be used if user input is for question 2 where input can be 0
        while (validInput != true){
            
            try{
                cout << inputRequest; // outputs question for user to answer
                cin >> userInput;
                
                if (userInput < 0) // makes sure input is positive number
                    throw error;
                else if (cin.fail()) // makes sure input is a number
                    throw error;
                else
                    validInput = true; // ends loop for next question or section
            }
            catch (...){
                cin.clear(); // clears error state from cin.fail()
                cout << "Please make sure input is a positve real number of at least 0." << endl;
                cout << "Examples using 1: \"1\" \"1.00\" \"1.01\"" << endl;
                cout << endl;
                continue; // requests new input from user if previous input was invalid
            }
        }
    } else { // else will be used if user input is for questions 1, 3, and 4 were input must be at least 1
        while (validInput != true){
            try{
                
                cout << inputRequest; // outputs question for user to answer
                cin >> userInput;
                
                if (userInput <= 0) // makes sure input is positive number greater than 0
                    throw error;
                else if (cin.fail()) // makes sure input is a number
                    throw error;
                else
                    validInput = true; // ends loop for next question or section
            }
            catch (...){
                cin.clear(); // clears error state from cin.fail()
                cout << "Please make sure input is a positve real number of at least 1." << endl;
                cout << "Examples: \"1\" \"1.00\" \"1.01\"" << endl;
                cout << endl;
                continue; // requests new input from user if previous input was invalid
            }
        }
    }
    return userInput;
}


//
// this function displays the Data Input screen to user
// and then displays again when new values have been input
// it also ensures output is displayed as ".00" with fixed/setprecision
//
// also has if statement so that if user does a new test
// it will not display enter key to continue statement
// for faster investment testing
//
void AirgeadBankingApp::DisplayScreen(){
    
    
    
    cout << nCharToPrint(32, '*') << endl;
    cout << nCharToPrint(10, '*') << " Data Input " << nCharToPrint(10, '*') << endl;
    cout << "Initial Investment Amount: " << fixed << setprecision(2) << GetInitialAmount() << endl;
    cout << "Monthly Deposit: " << GetMonthlyDeposit() << endl;
    cout << "Annual Interest: " << GetAnnualInterest() << endl;
    cout << "Number of Years: " << GetNumOfYears() << endl;
    if (numOfTests == 0)
    cout << "Press any key to continue..." << endl;
    
    getchar(); // pauses the program until a key is entered
    
}

//
// this function is called to actually display the input request prompts
// by calling the validation functions which then
// returns the appropriate values to be set
//
void AirgeadBankingApp::UserInput(){
    
    initialAmount = ValidateInput("Enter initial amount: ");
    monthlyDeposit = ValidateInput("Enter monthly deposit: ", 2);
    annualInterest = ValidateInput("Enter annual interest rate: ");
    numOfYears = ValidateInput("Enter number of years: ");
}

//
// this function outputs the year end reports that
// display the year, the balance at the end of that
// year, and then the total interest earn in that specific year
//
// Both reports will print if there are monthly deposits
// to show how much the recurring deopsits helped,
// and only the "without" report will print if monthly
// there were not any monthly deposits
//
void AirgeadBankingApp::YearEndReports(){
    
    cout << endl << endl;
    cout << "  Balance and Interest Without Additional Monthly Deposit  " << endl;
    cout << nCharToPrint(59, '=') << endl;
    cout << "   Year  -  Year End balance  -  Year End Earned Interest " << endl;
    cout << nCharToPrint(59, '=') << endl;
    WithoutCalcReport();
    
    if (GetMonthlyDeposit() > 0){
        cout << endl;
        cout << "  Balance and Interest With Additional Monthly Deposit  " << endl;
        cout << nCharToPrint(58, '=') << endl;
        cout << "   Year - Year End balance - Year End Earned Interest " << endl;
        cout << nCharToPrint(58, '=') << endl;
        WithCalcReport();
    }
}

//
// this function is where the calculations are done
// for the report WITH monthly deposits
//
void AirgeadBankingApp::WithCalcReport(){
    
    endingBalance = initialAmount; // variable that is updated after each iteration of the for loop (updated after each year)
    double interestRate = ((GetAnnualInterest() / 100.0) / 12.0); // variable that converts the interest rate to decimal form
    double interestEarned = 0.0; // variable that holds the current interest earned in a specific MONTH
    double totalInterest = 0.0; // variable that holds the current interest earned in a specific YEAR
    
    
    for (int i = 1; i <= numOfYears; i++) { // for loop that iterates(i) for a specified number of years
        for (int i = 1; i <= 12; i++) { // nested for loop that iterates(i) 12 times for all 12 months in a year
            interestEarned = (endingBalance + GetMonthlyDeposit()) * interestRate;
            totalInterest += interestEarned;
            endingBalance += interestEarned + GetMonthlyDeposit();
        }
        interestEarned = 0.0; // resets the interest earned before next month loop is done
        
        cout << setfill(' ') << right << setw(7) << i;
        cout << setfill(' ') << right << setw(21) << endingBalance;
        cout << setfill(' ') << right << setw(29) << totalInterest << endl;
        totalInterest = 0.0; // resets the interest earned before next year loop is done
    }
}

//
// this function is where the calculations are done
// for the report WITHOUT monthly deposits
//
void AirgeadBankingApp::WithoutCalcReport(){
    
    endingBalance = initialAmount; // variable that is updated after each iteration of the for loop (updated after each year)
    double interestRate = ((GetAnnualInterest() / 100.0) / 12.0); // variable that converts the interest rate to decimal form
    double interestEarned = 0.0; // variable that holds the current interest earned in a specific MONTH
    double totalInterest = 0.0; // variable that holds the current interest earned in a specific YEAR
    
    
    for (int i = 1; i <= numOfYears; i++) { // for loop that iterates(i) for a specified number of years
        for (int i = 1; i <= 12; i++) { // nested for loop that iterates(i) 12 times for all 12 months in a year
            interestEarned = (endingBalance) * interestRate;
            totalInterest += interestEarned;
            endingBalance += interestEarned;
        }
        interestEarned = 0.0; // resets the interest earned before next month loop is done
        
        cout << setfill(' ') << right << setw(7) << i;
        cout << setfill(' ') << right << setw(21) << endingBalance;
        cout << setfill(' ') << right << setw(29) << totalInterest << endl;
        totalInterest = 0.0; // resets the interest earned before next year loop is done
    }
}
