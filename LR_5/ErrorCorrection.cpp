#include <string>
#include <vector>
#include <iostream>
using namespace std;


string encode(string text)
{
  vector<int> message;
  string encodeMessage;
  string bitString;
  int bit[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  int iterationOfBinaryCalculation = 0;
    for(int i = 0; i < text.length();i++){
      message.push_back(text[i]);
      for(int j = 0; message[i] > 0; j++){
          bit[j] = message[i] % 2;
          message[i] /= 2;
          encodeMessage += to_string(bit[j]);
          iterationOfBinaryCalculation++;
      }
      if(iterationOfBinaryCalculation == 6){
        encodeMessage += to_string(0);
        encodeMessage += to_string(0);
      }
      if(iterationOfBinaryCalculation == 7){
        encodeMessage += to_string(0);
      }
      iterationOfBinaryCalculation = 0;
    }
    for(int i = 1; i <= text.length();i++){
      int j = 8;
      reverse(encodeMessage.begin()+((i-1)*8), encodeMessage.begin()+(j * i));
      j + 8;
    }
    for(int i = 0; i < encodeMessage.length(); i++){
      if(encodeMessage[i] == '0'){
        bitString += "000";
      }
      else if(encodeMessage[i] == '1'){
        bitString += "111";
      }
    }
      return bitString;
}

string decode(string bits)
{
    string message;
    string bitString;
    vector <int> decimalNumbers; 
    vector<string> byteStrings;
    string asciiString;
    for(int i = 0; i < bits.length(); i++){
      message.push_back(bits[i]); 
    }
  for(int i = 0; i < message.length(); i+=3){
      if(message.substr(i,3) == "000"){
        bitString += "0";
      }
    if(message.substr(i,3) == "100"){
        bitString += "0";
      }
    if(message.substr(i,3) == "010"){
        bitString += "0";
      }
    if(message.substr(i,3) == "001"){
        bitString += "0";
      }
    if(message.substr(i,3) == "111"){
        bitString += "1";
      }
    if(message.substr(i,3) == "011"){
        bitString += "1";
      }
    if(message.substr(i,3) == "101"){
        bitString += "1";
      }
    if(message.substr(i,3) == "110"){
        bitString += "1";
      }
    cout << bitString << endl;
  }

    for (size_t i = 0; i < bitString.length(); i += 8) {
        string byte = bitString.substr(i, 8);
        byteStrings.push_back(byte);
    }
    for (const string& byte : byteStrings) {
        int decimalNumber = stoi(byte, nullptr, 2);  
        decimalNumbers.push_back(decimalNumber);
        char asciiChar = static_cast<char>(decimalNumber);
        asciiString += asciiChar;
    }
    return asciiString;
}