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
    string message;
    getline(cin, message);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    int n = 0, max = 0, a = 0;
    char maxlit;
    char v[1000] = {0};

    for (int i = 0; i < message.size(); i++)
    {
        if(message[i]>='A' && message[i]<='Z' || message[i]>='a' && message[i]<='z'){
            char s2 = message[i]; 
            for (int j = 0; j < message.size(); j++) 
            {
                if (message[j] == s2) 
                    n++; 
            }
            if (max <= n) { 
                max = n; 
                maxlit = s2;
            }
            n = 0; 
            
        }
    }
    if(maxlit >= 'a'&& maxlit <= 'z'){
        a = maxlit - 'e';
    }
    if(maxlit >= 'A'&& maxlit <= 'Z'){
        a = maxlit - 'E';
    }

    for(int i = 0; i < message.size(); i++){
        if(!isalpha(message[i])){
            v[i] = message[i];
        }
        else{
            if(message[i] >= 97 && message[i] <= 122){
                v[i] = message[i] - a;
                if(v[i] > 122){
                    int l = v[i] - '{';
                    v[i] = 'a' + l;
                }
                if(v[i]< 97 && v[i] > 0){
                    int l = v[i] - 'a';
                    v[i] = '{' + l;
                }
            }
            if(message[i] >= 65 && message[i] <= 90){
                v[i] = message[i] - a;
                if(v[i]< 65 && v[i] > 0){
                    int l = v[i] - 'a';
                    v[i] = '{' + l;
                }
            }
        }
    }
    cout << v<< endl;
}