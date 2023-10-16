#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string operation;
    getline(cin, operation);
    int pseudo_random_number;
    cin >> pseudo_random_number; cin.ignore();
    vector<string> rotors;
    for (int i = 0; i < 3; i++) {
        string rotor;
        getline(cin, rotor);
        rotors.push_back(rotor);
    }
    string message;
    getline(cin, message);
    if(operation == "ENCODE"s){
        for (int i = 0; i < message.length(); i++){
            int landslide = message[i] + pseudo_random_number + i;
            if(landslide <'['){
                message[i] = landslide ;
            }
            if(landslide >='['){
                while(landslide >='['){
                    int a = landslide  - 'Z';
                    int c = '@' + a;
                    landslide  = c;
                    message[i] = c;
                }
            } 
        }
        for (int i = 0; i < message.length(); i++){\
            string FirstRotor = rotors[0];
            message[i] = FirstRotor[message[i] - 'A'];
        }
        for (int i = 0; i < message.length(); i++){\
            string SecondRotor = rotors[1];
            message[i] = SecondRotor[message[i] - 'A'];
        }
        for (int i = 0; i < message.length(); i++){\
            string ThirdRotor = rotors[2];
            message[i] = ThirdRotor[message[i] - 'A'];
        }
    }
    if(operation == "DECODE"s){
        for(int j = 0; j < message.length(); j++){
            for(int i = 0; i < rotors[2].length(); i++){
                    if(rotors[2][i] == message[j]){
                        message[j] = i + 'A';
                        break;
                    }   
            }
        }
        for(int j = 0; j < message.length(); j++){
            for(int i = 0; i < rotors[1].length(); i++){
                    if(rotors[1][i] == message[j]){
                        message[j] = i + 'A';
                        break;
                    }   
            }
        }
        for(int j = 0; j < message.length(); j++){
            for(int i = 0; i < rotors[0].length(); i++){
                    if(rotors[0][i] == message[j]){
                        message[j] = i + 'A';
                        break;
                    }   
            }
        }
        for(int i = 0; i < message.length(); i++){
            int landslide = message[i] - pseudo_random_number - i;
            if (landslide < 'A'){
                while(landslide < 'A'){
                    int b = 'A' - landslide;
                    int c = '[' - b;
                    landslide = c;
                    message[i] = c;
                }
            }
            if(landslide >= 'A'){
                message[i] = landslide;
            }
        }
    }
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;



    cout << message << endl;
}
