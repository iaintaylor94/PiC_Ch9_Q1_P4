// Program to determine tomorrows date

#include <stdio.h>
#include <stdbool.h>

// Define Structs
struct date {
int month;
int day;
int year;
};

// Declare Functions
bool isLeapYear (struct date);
int numberOfDays (struct date);
struct date dateUpdate (struct date);

int main(void) {

  // Declare constants
  struct date thisDay, nextDay;

  // Get input
  printf ("Enter today's date (mm/dd/yyyy): ");
  scanf ("%d %d %d", &thisDay.month, &thisDay.day, &thisDay.year);

  // Calculate nextDay
  nextDay = dateUpdate (thisDay);

  // Print output 
  printf ("Tomorrows date is %d/%d/%.2d.\n", nextDay.month, nextDay.day, nextDay.year % 100);
  
  return 0;
}

// Define Functions
bool isLeapYear (struct date d) {
  bool leapYearFlag;

  if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
    leapYearFlag = true; // It is a leap year
  }
  else {
    leapYearFlag = false; // It is not a leap year
  }

  return leapYearFlag;
}

int numberOfDays (struct date d) {
  int days;
  const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (isLeapYear (d) && d.month == 2) {
    days = 29;
  }
  else {
    days = daysPerMonth[d.month - 1];
  }

  return days;
}

struct date dateUpdate (struct date today) {
  struct date tomorrow;

  if (today.day != numberOfDays (today)) {
    tomorrow.day = today.day + 1;
    tomorrow.month = today.month;
    tomorrow.year = today.year;
  }
  else if (today.month == 12) { // End of Year
    tomorrow.day = 1;
    tomorrow.month = 1;
    tomorrow.year = today.year + 1;
  }
  else {
    tomorrow.day = 1;
    tomorrow.month = today.month + 1;
    tomorrow.year = today.year;
  }

  return tomorrow;
}