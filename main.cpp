//Dylan
#include "calendar.h"
#include <iostream>
#include <string>




using namespace std;


void print_help_message();

int main (int argc, char *argv[]){
  Calendar *c = new Calendar();
  if ( argc > 0 && string(argv[1]) == "--help" ) {
    print_help_message();
  } else if(argc > 0 && string(argv[1]) == "--d") {
    string ret = c -> handleDCommand();
    cout << ret << endl;
// Alex
  } else if(argc > 0 && string(argv[1]) == "--a") {
    string ret = c -> handleACommand();
    cout << ret << endl;
  }
  delete c;
  return 0;
}

// Dylan
void print_help_message(){
  cout << "Welcome to the trivial date app for all your trivial date needs!" << endl;
  cout << "The following commands are available to you: " << endl;
  cout << "--d: enter a number (1 - 366) and a year. The app will display the date of this day!" << endl;
  cout << "Dates are formatted in the mm/dd/yy format." << endl;
  cout << "Try not to have too much fun with this app, we know its addicting!!" << endl;

}
