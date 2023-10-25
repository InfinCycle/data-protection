#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <vector>


using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string message_1;
    getline(cin, message_1);
    string message_2;
    getline(cin, message_2);
    string message_3;
    getline(cin, message_3);

    vector <int> hexValuesM1;
    vector <int> hexValuesM2;
    vector <int> hexValuesM3;
    vector <int> Message;
    vector <char> MessageM;

    int a, b, c;

    for(int i = 1; i < message_1.length(); i += 2){
        if(!isalpha(message_1[i])){
            if(!isalpha(message_1[i-1])){
                a = message_1[i-1] - '0';
            }
            if(isalpha(message_1[i-1])){
                a = message_1[i-1] - 'W'; 
            }
            b = message_1[i] - '0';
            c = (a * 16) + (b * 1);
            hexValuesM1.push_back(c);
            
        }
        if(isalpha(message_1[i])){
            if(!isalpha(message_1[i-1])){
                a = message_1[i-1] - '0';
            }
            if(isalpha(message_1[i-1])){
                a = message_1[i-1] - 'W';
            }
            b = message_1[i] - 'W';
            c = (a * 16) + (b * 1);
            hexValuesM1.push_back(c);
        }
    }
    for(int i = 1; i < message_2.length(); i += 2){
        if(!isalpha(message_2[i])){
            if(!isalpha(message_2[i-1])){
                a = message_2[i-1] - '0';
            }
            if(isalpha(message_2[i-1])){
                a = message_2[i-1] - 'W'; 
            }
            b = message_2[i] - '0';
            c = (a * 16) + (b * 1);
            hexValuesM2.push_back(c);    
        }
        if(isalpha(message_2[i])){
            if(!isalpha(message_2[i-1])){
                a = message_2[i-1] - '0';
            }
            if(isalpha(message_2[i-1])){
                a = message_2[i-1] - 'W';
            }
            b = message_2[i] - 'W';
            c = (a * 16) + (b * 1);
            hexValuesM2.push_back(c);
        }
    }
    for(int i = 1; i < message_3.length(); i += 2){
        if(!isalpha(message_3[i])){
            if(!isalpha(message_3[i-1])){
                a = message_3[i-1] - '0';
            }
            if(isalpha(message_3[i-1])){
                a = message_3[i-1] - 'W'; 
            }
            b = message_3[i] - '0';
            c = (a * 16) + (b * 1);
            hexValuesM3.push_back(c);
        }
        if(isalpha(message_3[i])){
            if(!isalpha(message_3[i-1])){
                a = message_3[i-1] - '0';
            }
            if(isalpha(message_3[i-1])){
                a = message_3[i-1] - 'W';
            }
            b = message_3[i] - 'W';
            c = (a * 16) + (b * 1);
            hexValuesM3.push_back(c);
        }
    }
    for(int i = 0; i < (message_3.length()/2); i++){
        int ab = hexValuesM1[i] ^ hexValuesM2[i] ^ hexValuesM3[i];
        MessageM.push_back(ab);
    }
    for(const auto& num : MessageM){
        cout << num;
    }
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}