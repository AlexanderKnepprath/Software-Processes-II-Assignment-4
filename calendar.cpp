// Dylan
#include "calendar.h"
#include <iostream>
#include <string>

using namespace std;


// Method builds a date out of the day entered, year entered, and array of days for leap or non leap year
//author: Dylan Schultz
string Calendar::buildDate(int day, int year, int *days){
  if(day == 366 && !this -> isLeapYear(year)){
    return "There are not 366 days in a non leap year!";
  }
  int month = 0;
  while(day > days[month]){
    month++;
  }
  int extraDays;
  if(month > 0){
    extraDays = days[month - 1];
  } else {
    extraDays = 0;
  }
  day = day - extraDays;
  return dateMaker(month, day, year);
}

//Method formats a given date into the date format specificed by user stories
//author Dylan Schultz
string Calendar::dateMaker(int month, int day, int year){
  string yearS = to_string(year);
  string monthS = to_string(month + 1);
  string dayS = to_string(day);
  if(day < 10){
    dayS = "0" + dayS;
  }
  if(month < 9){
    monthS = "0" + monthS;
  }
  return monthS + "/" + dayS + "/" + yearS[2] + yearS[3];
}

// author: Dylan Schultz
bool Calendar::isLeapYear(int year){
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
    return true;
  } else{
    return false;
  }
}

// author: Alexander Knepprath
int Calendar::daysInMonth(int month, int year) {
  if (month == 2) { // february
    if (isLeapYear(year)) {return 29;} // 29 days in leap year
    else {return 28;} // 28 days in non-leap year
  } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) { // months with 31 days
    return 31;
  } else {return 30;} // other months
}

// Method handles the --d flag, takes a day and year from user and passes to helper methods
//author: Dylan Schultz
string Calendar::handleDCommand(){
  int day = 0;
  int year;
  string ret;
  while(day < 1 || day > 366) {
    day = 0;
    cout << "Enter a day (1 - 366): " << endl;
    cin >> day;
  }
  cout << "Enter a year: " << endl;
  cin >> year;
  bool leap = isLeapYear(year);
  if(leap == true){
    ret = buildDate(day, year, this -> leap);
  } else {
      ret = buildDate(day, year, this -> nonLeap);
  }
  return ret;
}

// Method handles the --a flag, takes a year, month, day, and number of days to add.
// Returns the date that number of days in advance.
// author: Alexander Knepprath
string Calendar::handleACommand () {
  int year = 0;
  int month = 0;
  int day = 0;
  int daysToAdd = 0;
  while (year < 1) { // year to start from
    year = 0;
    cout << "Enter the starting year (after 0 AD)" << endl;
    cin >> year;
  }
  while (month < 1 || month > 12) { // month to start from
    month = 0;
    cout << "Enter the month from that year (1 - 12)" << endl;
    cin >> month;
  }
  while (day < 1 || day > daysInMonth(month, year)) {
    day = 0;
    cout << "Enter the day from that month (1 - " << daysInMonth(month, year) << ")" << endl;
    cin >> day;
  }
  while (daysToAdd < 1) {
    daysToAdd = 0;
    cout << "Enter the number of days to add" << endl;
    cin >> daysToAdd;
  }

  int updatedDay = day;
  int updatedMonth = month;
  int updatedYear = year;

  while (daysToAdd > 0) {
    ++updatedDay;
    if (updatedDay > daysInMonth(updatedMonth, updatedYear)) { // if there are no days left in this month
      ++updatedMonth; // increment the month
      updatedDay = 1; // and set the day to the 1st of said month
    }
    if (updatedMonth > 12) { // similarly, if there are no months left in the year
      ++updatedYear; // increment the year
      updatedMonth = 1; // and set the month to January
    }
    --daysToAdd; // apparently this was important
  }

  return dateMaker(updatedMonth, updatedDay, updatedYear);
}
