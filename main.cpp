#include "Board.h"
#include "Game.h"
#include "AI.h"
#include <cstdlib>  

bool is_number(const std::string s){
    if(s.empty()){ return false; }

    return std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end(); 
    //i copied this from some random stack overflow thread and this code is impossible to parse holy shit
}


int main(int argc, char **argv) {
    int size = MAX_BOARDSIZE;
    int iter = 2;

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-size") { 
            if(i + 1 == argc){
                std::cerr << "Error: -size requires an argument" << std::endl;
            }
            else{
                std::string arg = std::string(argv[i+1]);
                if(!is_number(arg)){
                    std::cerr << "Error: argument to -size must be a positive integer " << std::endl;
                }
                size = std::atoi(argv[i+1]); //TODO: add check that size is valid (cant be < 5 or > 19 and must be odd
            }
        }
        else if (std::string(argv[i]) == "-iter") { //iter for minimax
            if(i + 1 == argc){
                std::cerr << "Error: -iter requires an argument" << std::endl;
            }
            else{
                std::string arg = std::string(argv[i+1]);
                if(!is_number(arg)){
                    std::cerr << "Error: argument to -size must be a positive integer " << std::endl;
                }
                iter = std::atoi(argv[i+1]); 
            }
        }

    }


    srand(0);
    Game x = Game(size);
    int i = 0;
    while (x.ongoing()) {
        int best_move = bestMove(x, iter);
        printf("%d\n", best_move);
        if (x.move(best_move)) {
            i++;
            x.print();
        }
        else{
            break;
        }
    }

    return 0;
}
