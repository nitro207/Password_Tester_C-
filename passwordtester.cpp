#include <iostream>
#include <string>
#include <cctype>

int main(){

    std::string password;

    std::cout << "What's your password:  ";

    std::getline(std::cin >> std::ws, password);

    int weight = 0;


    
    if(password.length() >= 12 && password.length() < 128){
        bool nums = false;
        bool specialchar = false;
        bool upper = false;
        bool lower = false;

        for(int i = 0; i < password.length(); i++){
            char currentchar = password[i];
            if(isupper(currentchar)){
                upper = true;
            }
            else if(islower(currentchar)){
                lower = true;
            }
            else if(isdigit(currentchar)){
                nums = true;
            }
            else if(currentchar >= 32 && currentchar <= 126){
                specialchar = true;
            }
        }
        if(!upper){
            std::cout << "Password has no uppercase letters" << "\n";
        }
        if(!lower){
            std::cout << "Password has no lowercase letters" << "\n";
        }
        if(!nums){
            std::cout << "Password has no numbers" << "\n";
        }
        if(!specialchar){
            std::cout << "Password has no special characters" << "\n";
        }

        if(upper){
            weight++;
        }
        if(lower){
            weight++;
        }
        if(nums){
            weight++;
        }
        if(specialchar){
            weight++;
        }


        /*
        for(int i = 0; i < password.length(); i++){
            if(isupper(password[i])){
                weight++;
                break;
            }
            if(i == (password.length() - 1) && isupper(password[i]) == false){
                std::cout << "Password has no uppercases letters" << "\n";
            }
        }
        for(int i = 0; i < password.length(); i++){
            if(isdigit(password[i])){
                weight++;
                break;
            }
            if(i == (password.length() - 1) && isdigit(password[i]) == false){
                std::cout << "Password has no numbers" << "\n";
            }
        }
        for(int i = 0; i < password.length(); i++){
            char currentchar = password[i];
            if(currentchar >= 32 && currentchar <= 126){
                weight++;
                break;
            }
            if(i == (password.length() - 1) && currentchar < 32 && currentchar > 126){
                std::cout << "Password has no special characters" << "\n";
            }
        }
        for(int i = 0; i < password.length(); i++){
            if(islower(password[i])){
                weight++;
                break;
            }
            if(i == (password.length() - 1) && islower(password[i]) == false){
                std::cout << "Password has no lowercase letters" << "\n";
            }
        }*/

        switch(weight){
            case 1:
                std::cout << "Password is weak";
                break;
            case 2:
                std::cout << "Password is poor";
                break;
            case 3:
                std::cout << "Password is fair";
                break;
            case 4:
                std::cout << "Password is great";
                break;
            default:
                std::cout << "Password is very weak";
        }
     
    }
    else if(password.length() >= 128){
        std::cout << "Password is too long";
    }
    else{
        std::cout << "Password is too short";
    }
    return 0;
}