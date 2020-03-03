#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <vector>
#include "sommet.h"

class Graphe
{
private:
    bool m_orient;
    std::vector<Sommet*> m_sommets;
public:
    Graphe(std::string);
    ~Graphe()=default;
    void afficher()const;


};

#endif // GRAPHE_H_INCLUDED
