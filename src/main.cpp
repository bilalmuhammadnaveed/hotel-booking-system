/*********************************************************************
* @file : main.cpp
* @project : Programming Fundamentals Lab Final Project
* @description : Hotel Booking System (C++)
* @author : Bilal M Naveed (FA25-BCE-014)
* @date : 2026-19-05
*********************************************************************/

// ======================================================
//        HOTEL BOOKING SYSTEM PROJECT
// ======================================================
// Concepts Used:
// 1. Arrays
// 2. Functions
// 3. Loops
// 4. Conditional Statements
// 5. Pointers
//
// Features:
// - Display room categories
// - Book rooms
// - Cancel booking
// - Estimate room cost
// - Calculate bill
// - Display occupancy summary
// ======================================================

#include <iostream>
#include <string>
using namespace std;

// Total rooms in hotel
const int TOTAL_ROOMS = 10;

// Arrays to store room data
bool roomBooked[TOTAL_ROOMS] = {false};

// Room categories
string roomType[TOTAL_ROOMS] =
{
    "Standard", "Standard",     // blank spaces inside strings are for formatting
    "Deluxe  ", "Deluxe  ",
    "Suite   ", "Suite   ",
    "Standard", "Deluxe  ",
    "Suite   ", "Standard"
};

// Room prices per night
int roomPrice[TOTAL_ROOMS] =
{
    5000, 5000,
    8000, 8000,
    12000, 12000,
    5000, 8000,
    12000, 5000
};

void displayRooms();	// Function to display all room categories
void printBill(int roomNo, int days);  // Helper function to print bill breakdown
void bookRoom();	// function to book a room
void resetRoom(bool *status);	// implementing pointers
void cancelBooking();		// fucntion to cancel room booking
void estimateCost();		
void occupancySummary();	

// ======================================================
// Main Function
// ======================================================
int main()
{
    int choice;
    cout << "\n\n=====================================\n";
    cout << "      HOTEL BOOKING SYSTEM\n";
    cout << "=====================================\n";

    do
    {
        cout << "\n\n" << endl;
        cout << "1. Display Room Categories\n";
        cout << "2. Book Available Room\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Estimate Room Cost\n";
        cout << "5. Display Occupancy Summary\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayRooms();
                break;

            case 2:
                bookRoom();
                break;

            case 3:
                cancelBooking();
                break;

            case 4:
                estimateCost();
                break;

            case 5:
                occupancySummary();
                break;

            case 6:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while(choice != 6);


    return 0;
}


// ------------------------------------------------------
// Function to display all room categories
// ------------------------------------------------------
void displayRooms()
{
    cout << "\n-------------------------- ROOM DETAILS -------------------------- \n" << endl;

    cout << "Room Number\tRoomType\t Price/day(Rs.)\t\tStatus" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for(int i = 0; i < TOTAL_ROOMS; i++)
    {
        cout << i + 1 << "\t\t";
        cout << roomType[i] << "\t\t";
        cout << roomPrice[i] << "\t\t";

        if(roomBooked[i] == true)
            cout << "Booked";
        else
            cout << "Available";

        cout << endl;
    }
}

// ------------------------------------------------------ 
// Helper function to print bill breakdown
// ------------------------------------------------------
void printBill(int roomNo, int days)
{
    int billBeforeTax = roomPrice[roomNo] * days;
    float gst = billBeforeTax * 0.16;
    int totalBill = billBeforeTax + (int)gst;

    cout << "\n========== BILL ==========\n";
    cout << "Room Type : " << roomType[roomNo] << endl;
    cout << "Room Price: Rs." << roomPrice[roomNo] << "/day" << endl;
    cout << "Days      : " << days << endl;
    cout << "Bill before tax : Rs." << billBeforeTax << endl;
    cout << "16% GST         : Rs." << gst << endl;
    cout << "Total Bill      : Rs." << totalBill << endl;
}

// ------------------------------------------------------
// Function to book a room
// ------------------------------------------------------
void bookRoom()
{
    int roomNo, days;

    displayRooms();

    // --- Room number input loop ---
    while(true)
    {
        cout << "\nEnter room number to book (0 to go back): ";
        cin >> roomNo;

        if(roomNo == 0)
        {
            cout << "Returning to main menu.\n";
            return;
        }

        if(roomNo < 1 || roomNo > TOTAL_ROOMS)
        {
            cout << "Invalid room number! Please enter a number between 1 and "
                 << TOTAL_ROOMS << ".\n";
            continue;   // ask again
        }

        if(roomBooked[roomNo - 1] == true)
        {
            cout << "Room " << roomNo << " is already booked! Please choose another room.\n";
            continue;   // ask again
        }

        break;  // valid and available room chosen
    }

    // --- Days input loop ---
    while(true)
    {
        cout << "Enter number of days (1-30, or 0 to go back): ";
        cin >> days;

        if(days == 0)
        {
            cout << "Returning to main menu.\n";
            return;
        }

        if(days < 1 || days > 30)
        {
            cout << "Invalid number of days! Please enter a value between 1 and 30.\n";
            continue;   // ask again
        }

        break;  // valid days entered
    }

    roomBooked[roomNo - 1] = true;
    cout << "\nRoom " << roomNo << " booked successfully!\n";
    printBill(roomNo - 1, days);
}

//------------------------------------------------------
// function for meeting requriment of pointer implementatin
//------------------------------------------------------
void resetRoom(bool *status)
{
    *status = false; 	// * for changing the value status points to
}

// ------------------------------------------------------
// Cancel booking function
// ------------------------------------------------------
void cancelBooking()
{
    int roomNo;

    // --- Room number input loop ---
    while(true)
    {
        cout << "\nEnter room number to cancel booking (0 to go back): ";
        cin >> roomNo;

        if(roomNo == 0)
        {
            cout << "Returning to main menu.\n";
            return;
        }

        if(roomNo < 1 || roomNo > TOTAL_ROOMS)
        {
            cout << "Invalid room number! Please enter a number between 1 and "
                 << TOTAL_ROOMS << ".\n";
            continue;   // ask again
        }

        if(roomBooked[roomNo - 1] == false)
        {
            cout << "Room " << roomNo << " is not booked! Please enter a booked room number.\n";
            continue;   // ask again
        }

        break;  // valid booked room chosen
    }

    resetRoom(&roomBooked[roomNo - 1]);		// pointer implementation function
    
    cout << "Booking for room " << roomNo << " cancelled successfully!\n";
}

// ------------------------------------------------------
// Function to estimate room cost
// shows cost without making a booking
// ------------------------------------------------------
void estimateCost()
{
    int roomNo, days;

    displayRooms();
    cout << "\n[Estimate only - no booking will be made]\n";

    // --- Room number input loop ---
    while(true)
    {
        cout << "\nEnter room number to estimate (0 to go back): ";
        cin >> roomNo;

        if(roomNo == 0)
        {
            cout << "Returning to main menu.\n";
            return;
        }

        if(roomNo < 1 || roomNo > TOTAL_ROOMS)
        {
            cout << "Invalid room number! Please enter a number between 1 and "
                 << TOTAL_ROOMS << ".\n";
            continue;   // ask again
        }

        break;  // valid room chosen (booked status doesn't matter for estimates)
    }

    // --- Days input loop ---
    while(true)
    {
        cout << "Enter number of days (1-30, or 0 to go back): ";
        cin >> days;

        if(days == 0)
        {
            cout << "Returning to main menu.\n";
            return;
        }

        if(days < 1 || days > 30)
        {
            cout << "Invalid number of days! Please enter a value between 1 and 30.\n";
            continue;   // ask again
        }

        break;  // valid days entered
    }

    printBill(roomNo - 1, days);
}

// ------------------------------------------------------
// Function to display occupancy summary
// ------------------------------------------------------
void occupancySummary()
{
    int booked = 0;
    int available = 0;

    for(int i = 0; i < TOTAL_ROOMS; i++)
    {
        if(roomBooked[i] == true)
            booked++;
        else
            available++;
    }

    cout << "\n========== OCCUPANCY SUMMARY ==========\n";
    cout << "Total Rooms     : " << TOTAL_ROOMS << endl;
    cout << "Booked Rooms    : " << booked << endl;
    cout << "Available Rooms : " << available << endl;
}