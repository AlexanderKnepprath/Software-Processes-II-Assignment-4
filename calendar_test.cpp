// Dylan
#include "calendar.h"
#include <gtest/gtest.h>


//Test if isLeapYear is functioning as expected
//author: Dylan Schultz
TEST(CalendarTest, isLeapYear){
  Calendar *c = new Calendar();
  EXPECT_TRUE(c -> isLeapYear(2000));
  EXPECT_TRUE(c -> isLeapYear(2016));
  EXPECT_FALSE(c -> isLeapYear(2021));
  EXPECT_FALSE(c -> isLeapYear(2001));
  delete c;
}

// Test if daysInMonth is returning the correct number of days in a month
// See isLeapYear test if having trouble finding source of error
// Author: Alexander Knepprath
TEST(CalendarTest, DaysInMonth) {
  Calendar *c = new Calendar();
  EXPECT_EQ(31, c -> daysInMonth(1, 2000)); // january has 31
  EXPECT_EQ(31, c -> daysInMonth(8, 2000)); // august also has 31
  EXPECT_EQ(30, c -> daysInMonth(6, 2000)); // june has 30
  EXPECT_EQ(28, c -> daysInMonth(2, 2019)); // february, normal non-leap lear
  EXPECT_EQ(29, c -> daysInMonth(2, 2020)); // febraury, normal leap year
  EXPECT_EQ(28, c -> daysInMonth(2, 1900)); // february, special non-leap year
  EXPECT_EQ(29, c -> daysInMonth(2, 2000)); // february, special leap year
  delete c;
}

//Test if dates are being built correctly to specification
//author: Dylan Schultz
TEST(CalendarTest, buildDate){
  Calendar *c = new Calendar();
  int *leap = c -> getLeap();
  int *nonLeap = c -> getnonLeap();
  EXPECT_EQ("01/01/21", c -> buildDate(1, 2021, nonLeap));
  EXPECT_EQ("02/29/16", c -> buildDate(60, 2016, leap));
  EXPECT_EQ("12/31/21", c -> buildDate(365, 2021, nonLeap));
  EXPECT_EQ("12/31/16", c -> buildDate(366, 2016, leap));
  EXPECT_EQ("There are not 366 days in a non leap year!", c -> buildDate(366, 2015, nonLeap));
  delete c;
}

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}