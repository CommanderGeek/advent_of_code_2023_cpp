#include <string>
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::string> fetchInput(std::string filename);
int getSum(std::vector<std::string> input);
int getFullSum(std::vector<std::string> input);

int main(int argc, char const *argv[])
{

   std::vector<std::string> input = fetchInput("file.txt");
   //part 1
   std::cout << getSum(input) << std::endl;
   //part 2
   std::vector<std::string> numbers {"one", "two", "three", "four", "five" , "six", "seven", "eight", "nine"};
    return 0;
}

std::vector<std::string> fetchInput(std::string filename){
    std::vector<std::string> input;
    std::string line;
    std::ifstream myfile (filename);
    if(myfile.is_open()){
        while ( getline (myfile,line) )
    {
      input.push_back(line);
    }
    myfile.close();
    }
    return input;
}

int getSum(std::vector<std::string> input){
    int sum=0;
    for(auto ele: input){
        int first = -1;
        int last = -1;
        for(int i = 0; i < ele.size(); i++){
            if (!std::isalpha(ele[i]))
            {
                if(first == -1){
                    first =  ele [i] - 48;
                }else{
                    last = ele[i] - 48;
                }
            }
            
        }
        std::cout << first <<" " << last << std::endl;
        if(last <= 0){
            last = first;
        }
        first *= 10;
        first += last;
         sum += first;
         std::cout<< "sum of "<< ele << " " << sum << std::endl;
    }
    return sum;
}

int getFullSum(std::vector<std::string> input){
    std::set<std::string> numbers {"one", "two", "three", "four", "five" , "six", "seven", "eight", "nine"};
    int sum=0;
    for(auto ele: input){
        int first = -1;
        int last = -1;
        std::string number= "";
        for(int i = 0; i < ele.size(); i++){
            if (!std::isalpha(ele[i]))
            {
                number = "";
                if(first == -1){
                    first =  ele [i] - 48;
                }else{
                    last = ele[i] - 48;
                }
            }else{
                if(number.size() > 5){
                    number = "";
                }
                if(numbers.find(number) != numbers.end()){
                    
                }
            }
            
        }
        std::cout << first <<" " << last << std::endl;
        if(last <= 0){
            last = first;
        }
        first *= 10;
        first += last;
         sum += first;
         std::cout<< "sum of "<< ele << " " << sum << std::endl;
    }
    return sum;
}

