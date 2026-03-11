#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

void csv::ajoute_evenement(int date, const std::string& intitule) {
    data[date].push_back(intitule);
}

void csv::affiche() const {
    for (const auto& pair : data) {
        std::cout << pair.first << " : ";
        for (const auto& event : pair.second) {
            std::cout << event << " | ";
        }
        std::cout << "\n";
    }
}

void csv::lire(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date_str, desc;
        if (std::getline(ss, date_str, ';') && std::getline(ss, desc)) {
            ajoute_evenement(std::stoi(date_str), desc);
        }
    }
}

void csv::ecrire(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& pair : data) {
        for (const auto& event : pair.second) {
            file << pair.first << ";" << event << "\n";
        }
    }
}