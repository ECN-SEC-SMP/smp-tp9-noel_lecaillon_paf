#ifndef CSV_HPP
#define CSV_HPP

#include <map>
#include <list>
#include <string>

class csv {
private:
    std::map<int, std::list<std::string>> data;

public:
    void ajoute_evenement(int date, const std::string& intitule);
    void affiche() const;
    void lire(const std::string& filename);
    void ecrire(const std::string& filename) const;
};

#endif