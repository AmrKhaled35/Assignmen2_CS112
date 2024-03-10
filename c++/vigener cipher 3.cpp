#include<bits/stdc++.h>
#define Amr ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define endl "\n"
using namespace std;

string encrypt(string msg, string key) { // Function to encrypt the message using Vigenere cipher
    string cipher;
    for (int j = 0; j < msg.length(); j++) {
        if (isalpha(msg[j])) {
            char z = (msg[j] + key[j]) % 26;
            z += 'A';
            cipher.push_back(z); // add this charcter to cipher
        } else {
            cipher += msg[j];
        }
    }
    return cipher; // return the encrypted text
}

string decrypt(string msg, string key) { // Function to decrypt the message using Vigenere cipher
    string decrypted;
    for (int j = 0; j < msg.length(); j++) {
        if (isalpha(msg[j])) {
            char z = (msg[j] - key[j] + 26) % 26;
            z += 'A';
            decrypted.push_back(z);
        } else {
            decrypted += msg[j];
        }
    }
    return decrypted; // return the decrypted text
}

int main() {
    cout << "======================================" << endl;
    cout << "<<<<<<Welcome to Vigenere Cipher>>>>>> " << endl;
    cout <<"======================================" << endl;
    bool stop = true;
    while (stop==true) {
        cout<<"1) Encrypt Message "<<endl;
        cout<<"2) decrypt Message" <<endl;
        int choice;
        cout<< "Please enter your choice :  ";
        cin>>choice;
        if (cin.fail()) { // check if input have error or not
            cin.clear(); //  remove any error flags in the input
            cin.ignore(1000000,'\n'); //discard this character input
            cout << "Invalid input Please enter an integer." << endl;
            continue;
        }
        if (choice !=1 && choice !=2){ // if user enter other number
            cout<< " Please enter 1 or 2 only "<<endl;
            continue;
        }
        cin.ignore();
        string msg, key;
        bool check1 = false;
        cout << "Enter your Message : ";
        getline(cin, msg);   // enter your msg
        if (msg.length() > 80) {  // check if msg greater than 80 or not
            cout << "The Maximum characters in Message is 80. Please try again." << endl;
            continue;
        }
        for (int i = 0; i < msg.length(); i++) { // loop to convert msg to uppercase
            msg[i] = toupper(msg[i]);
        }
        cout << "Enter your Keyword : ";
        getline(cin, key);  // enter your keyword
        if (key.length() > 8) { // check if keyword greater than 8 or not
            cout << "The Maximum characters in Keyword is 8. Please try again." << endl;
            continue;
        }
        for (int i = 0; i < key.length(); i++) { // check if keyword is alphabetic or not
            if (isalpha(key[i])) {
                check1 = true;
            } else {
                check1 = false;
            }
        }
        if (check1 == false) {
            cout << "Keyword must contain only alphabetic characters" << endl;
            continue;
        }
        for (int i = 0; i < key.length(); i++) { // loop to convert keyword to uppercase
            key[i] = toupper(key[i]);
        }
        int i = 0;
        while (true) {  // keyword repeated added character by character to each letter the original message
            if (msg.size() == i) {
                i = 0;
            }
            if (key.size() == msg.size()) {
                break;
            }
            key.push_back(key[i]);
            i++;
        }
        if (key.length()>msg.length()){ // check if user enter key length greater than msg length
            key = key.substr(0,msg.length());
        }

        if (choice==1){ // if user choose encrypt message
            string cipher = encrypt(msg, key);
            cout << "Encrypted message: " << cipher << endl;
            cout << "========================================" << endl;
        }

        if(choice==2){ // if user choose decrypt message
            // if user want to the original message
            string decrypted = decrypt(msg, key);
            cout << "decrypted message: " << decrypted << endl;
        }
        while (true){
            cout<<"If you want to run the program again (Y)"<<endl;
            cout<<"If you want to Exist  the program (N)"<<endl;
            char choice2;
            cout<<"Please enter your choice : ";
            cin>>choice2;
            if (choice2=='y' or choice2=='Y'){ // If you want to run the program again
                stop = true;
                break;
            }
            else if (choice2=='n' or choice2=='N'){ // If you want to Exist  the program
                stop = false;
                cout<<"Existing from program."<<endl;
                break;
            }
            else{
                cout<<"Please choice from Y or N only "<<endl;
                continue;
            }
        }


    }
}
