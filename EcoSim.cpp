#include <iostream>
/*
  Stephen Reese
  C++ Starter
  This program plots the rise and fall of the rabbit and fox population based on The Lotka-Volterra equation. The rabbit population is represented with an r and the foxes with an F.  The Charracters are the scaled number of blank spaces- 1 away from the begining.
 */
 using namespace std;
/*
helper method that updates the population of the rabbits and Foxes based on given equation.
 */
void updatePopulations(double g, double k, double p, double m, double c, double &numRabbits, double &numFoxes){
  using namespace std;
  double deltaRabbit;
  double deltaFoxes;

  deltaRabbit = g*numRabbits*(1-numRabbits/k)-p*numRabbits*numFoxes;
  deltaFoxes = c*p*numRabbits*numFoxes -m*numFoxes;
  numRabbits  = numRabbits + deltaRabbit;
  numFoxes  =  numFoxes  + deltaFoxes;
  }

/*
inctements the counter variable
*/

void incrementCounter(int &counter){
  counter ++;
}
/*
a helper function that outputs the character the appropriate number of spaces
*/
void plotCharacter(int space, string character){
  string stringSpace;
  while(space > 1){
    stringSpace = " " + stringSpace;
    space --;
  }
  cout << stringSpace << character;

}
/*
plot the character r and F based on the population. r represent rabbits and F represents Foxes.  r and f with be n - 1 spaces from the begining. n will be equal to the population scaled by a given scale.
 */

void chartCharacter (double numFoxes, double numRabbits, double scale)
{
 
  int countF;
  int countR;
  //the number of blank spaces needed
  string fSpace = "";
  string rSpace = "";
  //scaled number of Rabbits and Foxes
  int scaledR = numRabbits * scale;
  int scaledF = numFoxes * scale;
 
  
  if(scaledF > scaledR ){
    countF = scaledF- scaledR;
    countR = scaledR;
    plotCharacter(countR, "r");
    plotCharacter(countF, "F");
    cout << endl;
  }
       
  else if(scaledR > scaledF){
    countR = scaledR - scaledF;      ;
    countF = scaledF;
    plotCharacter(countF, "F");
    plotCharacter(countR, "r");
    cout << endl;
  }
  //if the numbers are equal
  else{
    countF = scaledF;
    plotCharacter(countF, "*");
    cout << endl;
  }
}

/*
main function runs the program
 */
int main(){

  double numRabbits;
  double numFoxes;
  int count = 0;
  double g = 0.2;
  double p = 0.002;
  double c =  0.6;
  double m = 0.2;
  double k =  1000.0;
  cout << "How many Rabbits and Foxes to begin with?" << endl; 
   
  if(cin >> numRabbits >> numFoxes){
     while(count < 500 && (numFoxes >= 1 && numRabbits >= 1) ){
       
       //plots the character on the terminal
       chartCharacter(numFoxes, numRabbits, .1);   
       //updates the population
       updatePopulations(g, k, p, m, c, numRabbits, numFoxes);
       //increment count obvously
       incrementCounter(count);
  }
  return 0;
  }
  else{
    cout << "an error occured when getting the population." << endl;
    return 0;
  }
 
}
