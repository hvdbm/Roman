#include <iostream>

std::string romanUnit(int num) {
        std::string roman = "";
        if (num < 4) {
            for (size_t i = 0; i < num; i++) {
                roman += "I";
            }
        } else if (num == 4) {
            roman += "IV";
        } else if (num == 5) {
            roman += "V";
        } else if (num == 9) {
            roman += "IX";
        } else {
            roman += "V";
            for(size_t i = 0; i < num - 5; i++) {
                roman += "I";
            }
        }
        return roman;
}
    
std::string romanTens(int num) {
        std::string roman = "";
        if (num < 4) {
            for (size_t i = 0; i < num; i++) {
                roman += "X";
            }
        } else if (num == 4) {
            roman += "XL";
        } else if (num == 5) {
            roman += "L";
        } else if (num == 9) {
            roman += "XC";
        } else {
            roman += "L";
            for(size_t i = 0; i < num - 5; i++) {
                roman += "X";
            }
        }
        return roman;
}
    
std::string romanHundreds(int num) {
        std::string roman = "";
        if (num < 4) {
            for (size_t i = 0; i < num; i++) {
                roman += "C";
            }
        } else if (num == 4) {
            roman += "CD";
        } else if (num == 5) {
            roman += "D";
        } else if (num == 9) {
            roman += "CM";
        } else {
            roman += "D";
            for(size_t i = 0; i < num - 5; i++) {
                roman += "C";
            }
        }
        return roman;
}
    
std::string romanThousands(int num) {
        std::string roman = "";
        for(size_t i = 0; i < num; i++) {
            roman += "M";
        }
        return roman;
}
    
std::string intToRoman(int num) {
        if (num != 0) {
                int numThousands = num/1000;
                int numHundreds = (num - numThousands*1000)/100;
                int numTens = (num - numThousands*1000 - numHundreds*100)/10;
                int numUnit = num - numThousands*1000 - numHundreds*100 - numTens*10;
                return (romanThousands(numThousands) + romanHundreds(numHundreds) + romanTens(numTens) + romanUnit(numUnit));
        } else return "Error";
}

int romanToInt(std::string s) {
        int finalNumber = 0;
        
        for (size_t i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'I':
                    if (s[i+1] == 'V' ) {
                        finalNumber += 4;
                        i++;
                    } else if (s[i+1] == 'X') {
                        finalNumber += 9;
                        i++;
                    } else finalNumber++;
                    break;
                    
                case 'V': finalNumber += 5;
                    break;
                
                case 'X': 
                    if (s[i+1] == 'L' ) {
                        finalNumber += 40;
                        i++;
                    } else if (s[i+1] == 'C') {
                        finalNumber += 90;
                        i++;
                    } else finalNumber += 10;
                    break;
                    
                case 'L': finalNumber += 50;
                    break;
                    
                case 'C':
                    if(s[i+1] == 'D') {
                        finalNumber += 400;
                        i++;
                    } else if(s[i+1] == 'M') {
                        finalNumber += 900;
                        i++;
                    } else finalNumber += 100;
                    break;
                
                case 'D': finalNumber += 500;
                    break;
                
                case 'M': finalNumber += 1000;
                    break;
            }
        }
        return finalNumber;
}

int main() {
        bool useAgain = true;
        while (useAgain)
        {
                std::cout << std::endl << "What conversion do you want to make?" << std::endl
                << "1- Integer to Roman" << std::endl
                << "2- Roman to Integer" << std::endl
                << "3- Quit" << std::endl;

                int option;
                std::cin >> option;

                int integer;
                std::string roman;
                switch (option)
                {
                        case 1:
                                std::cout << std::endl << "Enter your integer: ";
                                std::cin >> integer;
                                std::cout << intToRoman(integer) << std::endl;
                                break;
                        case 2:
                                std::cout << std::endl << "Enter your roman: ";      
                                std::cin >> roman;
                                std::cout << romanToInt(roman) << std::endl;
                                break;
                        case 3: useAgain = false;
                                break;
                }
        }
}