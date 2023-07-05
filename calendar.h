#include <string>
using namespace std;

class Calendar
{
private:
  //nonLeap array is total days by end of each month nonLeap[0] is January nonLeap[11] is December nonLeap[13] is total days
  //leap is the same only for leap years
  int nonLeap[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
  int leap[12] = { 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };



public:
  Calendar(){}
  bool isLeapYear(int year);
  int daysInMonth(int month, int year);
  string dateMaker(int month, int day, int year);
  string buildDate(int day, int year, int *days);
  string handleDCommand();
  string handleACommand();
  int* getnonLeap(){return nonLeap;}
  int* getLeap(){return leap;}
};
