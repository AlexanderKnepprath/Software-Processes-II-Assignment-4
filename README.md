# SE3800date_kneppratha_schultzd
**Authors**   
- Alexander Kneppratha
- Dylan Schultz  
___
**Build Directions**  
The project has the following dependencies:  
 - c++ 14
 - g++ 9.3.0

In the project directory enter the following commands:  
 - make  
 - ./calendar {"--flag"}  
 flags tell the program what functionality you want to use "--help" prints the welcome message and all available functionality
___
**Test Directions**  
  Testing is done through unit tests with Google Test.  
  Tests are dependent to run with docker.  
In the project directory enter the following command:  
  - docker build ./  
  This will execute all tests showing whether or not each test passes or fails.
