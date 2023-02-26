// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    // Write your code here
    uint8_t lastDotIndex = 0;
    int decimal = 0;
    int validDecimals = 0;
    std::string decimalString = "";
    for(uint8_t index = 0; index < ip.size(); index++)
    {
        if(ip[index] == '.')
        {
            decimalString = ip.substr(lastDotIndex,index - lastDotIndex);
            decimal = std::stoi(decimalString);
            lastDotIndex = index+1;
            if(decimal > 255 || decimal < 0)
            {
                return false;
            }
            else
            {
                validDecimals++;
            }
        }
    }
    decimalString = ip.substr(lastDotIndex);
    decimal = std::stoi(decimalString);
    if(decimal >= 0 && decimal <= 255)
    {
        validDecimals++;
    }
    else
    {
        return false;
    }
    if(validDecimals == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
