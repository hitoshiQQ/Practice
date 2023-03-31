#include <string>
#include "Source.h"


bool check_symbol_TwoHalf(std::string str) {
    std::string symbol{ ".@" };
    for (int j = 0; j < str.length();) {
        if (str[j] >= 65 && str[j] <= 90
            || str[j] >= 97 && str[j] <= 122) {
            ++j;
        }
        else {
            int i{ 0 };
            while (str[j] != symbol[i]) {
                i++;
                if (i == symbol.length()) {
                    return false;
                }
            }
            return true;
        }
    }
}
bool check_symbol(std::string str) {
    std::string symbol{ ".!#$%&'*+-/=?^_`{|}~" };

    for (int j = 0; j < str.length();) {
       if( str[j] >= 65 && str[j] <= 90
            || str[j] >= 97 && str[j] <= 122){
           ++j; 
       }
       else {
           int i{ 0 };
           while (str[j] != symbol[i]) {
               i++;
               if (i == symbol.length()) {
                   return false;
               }          
           }
           return true;
       }
    }
}
bool check_Dog(std::string str) {
    int count{ 0 };
    for (int j = 0; j < str.length(); ++j) {
        if (str[j ] == '@') {
            count++;
        }
    }
    if (count != 1) {
        return false;
    }
    
}
bool check_two_Dat(std::string str) {
    for (int j = 1; j < str.length(); ++j) {
        if (str[j - 1] == '.' && str[j] == '.') {
            return false;
            break;
        }
    }
    return true;
}
bool is_correct_firsthalf(std::string str) {
    std::string strHalf;
    int j{ 0 };
    while (str[j] != '@') {
        strHalf = strHalf + str[j];
        ++j;
        if (j == str.length()) {
            return false;
        }      
    }
    if (!(check_Dog(str))) {
        return false;
    }

    if (strHalf.length() < 0 || strHalf.length() > 63) {
        return false;
    }
    if (strHalf[0] == '.' || strHalf[strHalf.length() - 1] == '.') {
        return false;
    }
    if (!(check_two_Dat(strHalf))) {
        return false;
    }
   
    if (!(check_symbol(strHalf))) {
        return false; 
    }
  
    return true;
}
bool is_correct_secondhalf(std::string str) {
    std::string strHalf;
    int startIndex{ 0 };
    for (int j = 0; j < str.length(); ++j) {
        if (str[j] == '@') {
            startIndex = j+1;
            break;
        }
    }
    for (startIndex; startIndex < str.length(); ++startIndex) {
        strHalf = strHalf + str[startIndex];
    }

    if (!check_symbol_TwoHalf(strHalf)) {
        return false;
    }

    return true;
}
bool is_correct_email(std::string str) {
    if (is_correct_firsthalf(str) && is_correct_secondhalf(str)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
	cout << "\t\tChecking that the email address is correct\n\n";
 
    while (true) {
        std::string email;
        cout << "Enter email:" << endl;
        cin >> email;


        if (is_correct_email(email)) {
            cout << "\nYes\n\n";
        }
        else {
            cout << "\nNo\n\n";
        }
    }
   
    return 0;
}