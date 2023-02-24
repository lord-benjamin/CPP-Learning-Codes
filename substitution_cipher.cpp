/*Encrypt and then Decrypt a user given message*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string alphabet_number{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789_"};
    string key{"K8dS5pzAMg0tWkG24YnwCPiETab7mJUx9rZvqR3eXVfoIB1NljFy_hDs6OcHQuL "};
    
    string secret_message{};
    string encrypted_message{};
    cout << "Enter your secret message: ";
    getline(cin,secret_message);

    cout << "\nEncrypting message..." << endl;
    for(auto c : secret_message){
        size_t position{alphabet_number.find(c)};
        if(position != string::npos){
            char encrypt_char{key.at(position)};
            encrypted_message += encrypt_char;
        }
        else{
            encrypted_message += c;
        }
    }
    cout << "Encrypted message: " << encrypted_message << endl;

    string correct_password{"I love C++"};
    string password{};
    
    do{
        cout << "\nEnter the password to decrypt the secret message: ";
        getline(cin,password);
        
        if(password == correct_password){
            string decrypted_message{};
            cout << "\nDecrypting message..." << endl;
            for(auto c : encrypted_message){
                size_t position{key.find(c)};
                if(position != string::npos){
                    char decrypt_char{alphabet_number.at(position)};
                    decrypted_message += decrypt_char;
                }
                else{
                    decrypted_message += c;
                }
            }
            cout << "Decrypted message: " << decrypted_message << endl;       
        }
        else{
            cout << "\nWrong Password! Can't display the secret message... Try Again!" << endl;
        }
    }while(password != correct_password);

    return 0;
}