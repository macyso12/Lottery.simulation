// Macy So
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std ;
int MAX_SIZE = 5 ;

void randomArray (int, int&);
void playerArray (int, int&);
bool isAlreadyIn(int,int, int);
void displayArray(int, int);
void showMatching(int, int, int);
void numbersInBoth(int, int, int);

bool isAlreadyIn(int arr1[],int elements, int n) { //: returns true if n is already in arr1.
    for (int i = 0; i< elements ;i++){
        if (arr1[i] == n){
            return true;
        }
    }
    return false ;
}
//an array of 5 integers named winningDigits, randomly generated number in the range of 0 through 9 for each element in the array
void randomArray (int WinningDigits[], int& ranNums){
    int number;
    int element = 0;
    cout << "Winning Digits: " ;
    for (int i = 0; i < MAX_SIZE; i++){
        //srand((unsigned) time(0)) ;
            number = rand() % 9  ;
            cout << number << " " ;
            // Call the function to check whether number no is available in arr1 or not
            if (!(isAlreadyIn(WinningDigits,element,number))){
                // Increase the index by one
                WinningDigits[i]=number ;
        }
        
    }
    cout << endl ;
}

//The program should ask the user to enter 5 digits and should store them in a second integer array named player
void playerArray (int player[], int& elements2){
    int number;
    cout << "Enter 5 integers separate with space: " ;
    for (int i = 0; i < MAX_SIZE ; i++){
        cin >> number ;
        // Call the function to check whether number no is available in arr2 or not
        if (!(isAlreadyIn(player,i,number))){
            // Increase the index by one
            player[i]=number ;
        }
        // Otherwise duplicate number
      else {
            cout << "Duplicate number, Try again!." ;
        }
    }
    cout << endl ;
}
 
//compare the corresponding elements in the two arrays and count how many digits match
void displayArray(int WinningDigits[], int n){ //:  prints the elements of the array
    cout << "Winning Digits: " ;
    for (int i = 0; i < MAX_SIZE; i++){
        cout << WinningDigits[i] << " ";
    }
    cout << endl ;
}

void showMatching(int WinningDigit[], int playerDigit[], int SIZE){ //: displayes the index/s of matching elements. There may not be any matching elements.
    cout << "Matching elements: " ;
    for (int i = 0; i < MAX_SIZE ;i++){
        if (WinningDigit[i] == playerDigit[i]){
            cout << i << " "  ;
        }
    }
    cout << endl ;
}

//compare the corresponding elements in the two arrays and count how many digits match
void numbersInBoth(int arr1[], int arr2[], int SIZE){ //: displayes the numbers that appear in both arrays.
    cout << "Numbers appearing in both arrays: " ;
    for(int i = 0 ; i< SIZE /*i need to change this*/;i++){
        for(int j = 0 ; j< SIZE /*i need to change this*/;j++){
            if(arr1[i]==arr2[j]){
                cout << arr1[i] << " ";
            }
        }
    }
    cout << endl << endl;
}


// Note: Both the winningDigits and the player arrays may not have duplicate numbers.

int main() {
    int elements1 = 0;
    srand((unsigned) time(0)) ;
    int WinningDigits[MAX_SIZE]; //array
    int player [MAX_SIZE] ;
    randomArray (WinningDigits,elements1 );
    playerArray (player, elements1 );
    
    displayArray(WinningDigits, elements1 );
    
    cout << "Player Digits: " ;
    for (int i = 0; i < MAX_SIZE; i++){
        cout << player[i] << " ";
    }
    cout << endl ;
    
    showMatching (WinningDigits, player, MAX_SIZE) ;
    numbersInBoth(WinningDigits, player, MAX_SIZE) ;
    return 0;
}
