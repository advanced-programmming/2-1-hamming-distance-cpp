#include <iostream>
#include <vector>
#include <cstring>

int calculateHammingDistance(std::string a, std::string b);

int main() {
    std::vector<std::string> binaries;
    std::string binarie;
    while(std::cin>>binarie){
        if (binarie == "0") break;
        binaries.push_back(binarie);
    }

    int minimum = 9999;
    for(int i = 0; i < binaries.size(); i++)
        for (int j = (i + 1); j < binaries.size(); j++){
            int sum = calculateHammingDistance(binaries[i], binaries[j]);
            minimum = minimum > sum ? sum : minimum;
        }

    std::cout<<minimum<<std::endl;
    
    return 0;
}

int calculateHammingDistance(std::string a, std::string b){
    int count = 0;
    char newA[a.length()], newB[a.length()];
    std::strcpy(newA, a.c_str());
    std::strcpy(newB, b.c_str());

    for(int i = 0; i < a.length(); i++)
        if(newA[i] != newB[i])
            count++;

    return count;

}