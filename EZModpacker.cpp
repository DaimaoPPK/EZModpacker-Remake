#include "headers/preprocessor.hpp"

int main(int argc, char const *argv[]){
    for (size_t i = 1; i < argc; i++)
    {
        std::ifstream file(argv[i]);
        while (std::getline(file, line)) {
            Interpret();
        }
        file.close();
        ProcessReport();
    }
}
