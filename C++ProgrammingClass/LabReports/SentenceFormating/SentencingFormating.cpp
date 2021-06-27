
/*
SentenceFormatting
6/25/2021
Version 1
Kevin Wong
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {


    char sentence[200];
    int i;
    cout << "Enter a sentence:" << endl;
    cin.getline(sentence, 200);

    for (i = 0; sentence[i]; i++){
        if (isspace(sentence[i]))
            sentence[i] = ' ';
    }
    i = 0;
    while (sentence[i] != '\0'){
        if (sentence[i] == ' ' && sentence[i+1]== ' '){
            for (int j = i; sentence[j]; j++){
                sentence[j] = sentence[j+1];
            }
        }
        else {
            i++;
        }
    }

    for (i=0;sentence[i]; i++){
        sentence[i] = tolower(sentence[i]);
    }
    sentence[0] = toupper(sentence[0]);
    cout << sentence << endl;


    return 0;
}
