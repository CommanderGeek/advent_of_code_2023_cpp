#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::string> fetchInput(std::string filename);
int get_sum(std::vector<std::string> input);
int get_full_sum(std::vector<std::string> input);

int main(int argc, char const *argv[])
{

   std::vector<std::string> input = fetchInput("file.txt");
   //part 1
   std::cout << get_sum(input) << std::endl;
   //part 2
   std::cout << get_full_sum(input) << std::endl;
    return 0;
}

std::vector<std::string> fetchInput(std::string filename){
    std::vector<std::string> input;
    std::string line;
    std::ifstream myfile (filename);
    if(myfile.is_open()){
        while (getline (myfile,line))
    {
      input.push_back(line);
    }
    myfile.close();
    }
    return input;
}

int get_sum(std::vector<std::string> input){
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
        if(last <= 0){
            last = first;
        }
        first *= 10;
        first += last;
        sum += first;
    }
    return sum;
}

int get_full_sum(std::vector<std::string> input){
    std::vector<std::string> numbers {"one", "two", "three", "four", "five" , "six", "seven", "eight", "nine"};
    int sum=0;
    for(auto ele: input){
        int first = -1;
        int last = -1;
        std::vector<int> digits;
        std::string number= "";
        for(int i = 0; i < ele.size(); i++){
            const auto c = ele[i];
            if (c >= '0' && c <= '9') {
             digits.push_back(c - '0');
            }
            for (int j = 0; j < numbers.size(); j++) {
            const auto& n = numbers[j];
            if (ele.size() >= i + n.size()) {
                if (ele.substr(i, n.size()) == n) {
                    digits.push_back(j+1);
                }
            }
        }
        }
        sum += digits [0] * 10 + digits.back();
    }
    return sum;
}

