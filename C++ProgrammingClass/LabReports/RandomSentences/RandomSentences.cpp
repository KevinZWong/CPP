//  C++RandomSentences  ---   create a series of random sentences
//
//  Updated by Dan McElroy on 11/12/18.
//  Updated by Kevin Wong on 6/25/2021

/*
RandomSentences
6/25/2021
Version 2
Kevin Wong
*/
#include <iostream>    // needed for printf
#include <cstdlib>     // needed for the random number generator
#include <ctime>       // needed to seed the random number generator
#include <cctype>      // needed for toupper()
#include <string>      // needed for C++ strings
using namespace std;

// Article, adjective, noun, verb, preposition, article, adjective, noun

const char * noun[] =
{ "desk", "chair", "envelope", "car", "train", "bus", "boat",
  "elephant", "dog", "cat", "moose", "rabbit"
};
const char * article[] = {
    "the", "a", "one", "some", "any"
};
const char * adjective[] = {
     "brave", "orange", "fast", "slow", "bored", "calm", "bright", "sad"
};
const char * verb[] = {
     "drove", "jumped", "ran", "walked", "skipped", "kicked"
};
const char * preposition [] = {
     "to", "from", "over", "under", "on", "in"
};

int nounCount = sizeof(noun)/sizeof(char*);
int artCount = sizeof(article)/sizeof(char*);
int adjCount = sizeof(adjective)/sizeof(char*);
int verbCount = sizeof(verb)/sizeof(char*);
int preCount = sizeof(preposition)/sizeof(char*);
int main(int argc, const char * argv[])
{
    // declare the variables
    string sentence;        // C++ string object
    int selection;

    srand( (unsigned int)time(0) );    // seed the random number generator
    
    for (int i=0; i<20; i++)     // create and display 5 sentences
    {
        // Article, adjective, noun, verb, preposition, article, adjective, noun
        //article
        selection = rand()%artCount; 
        sentence = article[selection];  
        sentence += " "; 
        //adjective
        selection = rand()%adjCount;
        sentence += adjective[selection]; 
        sentence += " ";           
        //noun
        selection = rand()%nounCount;  
        sentence += noun[selection];   
        sentence += " ";    
        //verb     
        selection = rand()%verbCount;
        sentence += verb[selection];  
        sentence += " ";    
        //preposition       
        selection = rand()%preCount;
        sentence += preposition[selection];  
        sentence += " "; 
        //article
        selection = rand()%artCount; 
        sentence += article[selection];  
        sentence += " "; 
        cout << sentence << endl;   
        //adjective    
        selection = rand()%adjCount;
        sentence += adjective[selection]; 
        sentence += " ";   
        //noun           
        selection = rand()%nounCount; 
        sentence += noun[selection]; 
        sentence += ".";   

        sentence[0] = toupper(sentence[0]);     // make 1st char capital letter
        cout << sentence << endl;               // display the sentence
    }

    return 0;
}
