#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>
#include "utils.h"

void affiche(const std::vector<std::string>& v) {
    for (const auto& s : v) {
        std::cout << s << " ";
    }
    std::cout << "\n";
}

std::string concatene(const std::vector<std::string>& v) {
    std::string res;
    for (const auto& s : v) {
        res += s + " ";
    }
    return res;
}

struct AddComma {
    void operator()(std::string& s) {
        s += ",";
    }
};

void ajoute_evenement(std::map<int, std::list<std::string>>& m, int date, const std::string& intitule) {
    m[date].push_back(intitule);
}

void affiche_map(const std::map<int, std::list<std::string>>& m) {
    for (const auto& pair : m) {
        std::cout << pair.first << " : ";
        for (const auto& event : pair.second) {
            std::cout << event << " | ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<int> v1;
    v1.resize(3);
    v1[0] = 10;
    v1[1] = 20;
    v1[2] = 30;

    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n";

    for (int val : v1) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    v1.push_back(40);
    std::cout << v1.size() << "\n";

    std::vector<int> v2;
    v2.assign(v1.begin(), v1.end());

    std::vector<int> v3;
    std::copy(v1.begin(), v1.end(), std::back_inserter(v3));

    std::vector<std::string> vs;
    vs.push_back("Bonjour");
    vs.push_back("comment");
    vs.push_back("allez");
    vs.push_back("vous");
    vs.push_back("?");

    std::cout << vs.size() << "\n";
    std::cout << vs.capacity() << "\n";

    for (size_t i = 0; i < vs.size(); ++i) std::cout << vs[i] << " ";
    std::cout << "\n";

    for (const auto& s : vs) std::cout << s << " ";
    std::cout << "\n";

    for (auto it = vs.begin(); it != vs.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";

    std::swap(vs[1], vs[3]);
    affiche(vs);

    vs.insert(vs.begin() + 1, "a tous");
    affiche(vs);

    vs.back() = "???";
    affiche(vs);

    for (size_t i = 0; i < vs.size(); ++i) {
        std::cout << vs[i] << (i < vs.size() - 1 ? "," : "");
    }
    std::cout << "\n";

    std::sort(vs.begin(), vs.end());
    affiche(vs);

    std::cout << concatene(vs) << "\n";

    std::for_each(vs.begin(), vs.end(), AddComma());
    affiche(vs);

    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8};
    auto it_l = l.begin();
    std::advance(it_l, 2);
    l.erase(it_l);

    for (int val : l) std::cout << val << " ";
    std::cout << "\n";

    std::map<int, std::list<std::string>> m;
    ajoute_evenement(m, 1515, "Marignan");
    ajoute_evenement(m, 1789, "Revolution");
    ajoute_evenement(m, 1789, "Prise de la Bastille");
    affiche_map(m);

    csv mon_csv;
    mon_csv.ajoute_evenement(1998, "Coupe du monde");
    mon_csv.ajoute_evenement(1969, "Lune");
    mon_csv.ecrire("dates_test.csv");

    csv csv_lu;
    csv_lu.lire("dates_test.csv");
    csv_lu.affiche();

    return 0;
}