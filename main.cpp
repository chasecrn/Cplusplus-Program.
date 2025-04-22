//
//  main.cpp
//  AirgeadBankingApp
//
//  This application allows users to see how their investments will grow over time
//
//  Created by Chase Crnovich on 3/31/25.
//

#include <iostream>
using namespace std;

#include "AirgeadBankingApp.h"

int main() {
    AirgeadBankingApp AirgeadBankingApp;
    
    bool userContinue = true; // boolean that controls the while loop that starts/stops program
    char continuePrompt = ' '; // variable for if user wants to start a new loop
    
    cout << "Welcome to The Airgead Banking App!" << endl;
    cout << "Below is the data we will need to start" << endl;
    
    while (userContinue != false){
        cout << endl;
        
        AirgeadBankingApp.DisplayScreen();
        AirgeadBankingApp.UserInput();
        AirgeadBankingApp.DisplayScreen();
        AirgeadBankingApp.YearEndReports();
        
    //
    // below is the section for new test option or to quit
    //
        cout << endl;
        cout << "to continue enter \"Y\"" << endl;
        cout << "to quit press any other key" << endl;
        cin >> continuePrompt;
        
        continuePrompt = toupper(continuePrompt); // if user enters y it changes it to uppercase Y
        
        if (continuePrompt == 'Y') {
            AirgeadBankingApp.ResetToDefault();
            continue;
        }
        else{
            userContinue = false;
        }
    }
    return 0;
}
