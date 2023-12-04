#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

std::vector<std::string> split_by(std::string line, char del);

int main() {
    std::ifstream myfile("input.txt");
    int sum = 0;

    if (myfile.is_open()) {
        std::string line;
        while (getline(myfile, line)) {
            std::map<std::string, int> amount_of_colors;
            amount_of_colors["green"] = 0;
            amount_of_colors["red"] = 0;
            amount_of_colors["blue"] = 0;

            std::vector<std::string> game_line = split_by(line, ':');
            int game_id = stoi(split_by(game_line[0], ' ')[1]);
            std::vector<std::string> each_game = split_by(game_line[1], ';');

            bool valid = true; // Assume game is valid until proven otherwise

            for (const std::string& cubes : each_game) {
                std::vector<std::string> drawn_cube = split_by(cubes, ',');
                
                for (const std::string& cube : drawn_cube) {
                    std::vector<std::string> cube_values = split_by(cube, ' ');
                    int count = std::stoi(cube_values[1]);
                    std::string color = cube_values[2];

                    amount_of_colors[color] += count;

                    // Check if counts exceed the allowed maximum
                    if (amount_of_colors["red"] > 12 || amount_of_colors["green"] > 13 || amount_of_colors["blue"] > 14) {
                        valid = false;
                        break;
                    }
                }
                
                if (!valid) {
                    break;
                }
            }

            if (valid) {
                sum += game_id;
                std::cout << "Possible Game ID: " << game_id << std::endl;
            }
        }

        myfile.close();
        std::cout << "Sum of IDs of possible games: " << sum << std::endl;
    } else {
        std::cout << "Unable to open file." << std::endl;
    }

    return 0;
}

std::vector<std::string> split_by(std::string line, char del) {
    std::vector<std::string> separator;
    std::stringstream ss(line);
    std::string word;

    while (getline(ss, word, del)) {
        separator.push_back(word);
    }

    return separator;
}
