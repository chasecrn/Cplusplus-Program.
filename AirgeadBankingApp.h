//
//  AirgeadBankingApp.h
//  AirgeadBankingApp
//
//  This application allows users to see how their investments will grow over time
//
//  Created by Chase Crnovich on 3/31/25.
//
#ifndef AIRGEAD_BANKING_APP_H
#define AIRGEAD_BANKING_APP_H

using namespace std;


class AirgeadBankingApp {
    
    public:
    
        AirgeadBankingApp(); // default constructor to initialize variables
    
        void SetInitialAmount(double initialAmount); // sets users starting balance
        void SetMonthlyDeposit(double monthlyDeposit); // sets users optional monthly recurring deposits
        void SetAnnualInterest(double annualInterest); // sets users annual interest rate
        void SetNumOfYears(int numOfYears); // sets the number of years user would like to invest
    
        double GetInitialAmount(); // getter for users starting balance
        double GetMonthlyDeposit(); // getter for users monthly recurring deposits
        double GetAnnualInterest(); // getter for users annual interest rate
        int GetNumOfYears(); // getter for number of years users will be investing
    
        string nCharToPrint(int nChar, char toPrint); // function that outputs a specific number of characters/helps center output
        void DisplayScreen(); // function that outputs the "Data Input" screen
        void UserInput(); // function that prompts/gets input values from user
        double ValidateInput(string inputRequest, int requestNum); // function that validates user input
        void YearEndReports(); // function that outputs both year end reports for following with/without functions
        void WithCalcReport(); // function that calculates and formats year end report WITH a monthly deposit
        void WithoutCalcReport(); // function that calculates and formats year end report WITHOUT a monthly deposit
        void ResetToDefault(); // funcation that reset previous variables if user wants to test new values 
    
    private:
    
        double initialAmount; // variable that holds the users starting balance
        double monthlyDeposit; // variable that holds the users optional recurring deposit
        double annualInterest; // variable that holds the users annual interest rate
        double endingBalance; // variable that holds the users final balance that updates after each year
        int numOfYears; // variable that holds the number of years the user will be investing
        int nChar; // variable that holds the number of characters in the nCharToPrint function
        char toPrint; // variable that holds the character to print in the nCharToPrint function
        int numOfTests; // variable that counts the number of times user has tested new values

};

#endif
