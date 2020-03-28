#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <vector>
#include "sommet.h"

class Graphe
{
private:
    bool m_orient;
    int m_ordre;
    std::vector<Sommet*> m_sommets;
public:
    Graphe(std::string);
    ~Graphe()=default;
    void afficher()const;
    Sommet*getSommet(int ID);
    void Coloration_DFS(int ID);
    void Coloration_BFS(int ID);
    void Parcour_BFS(int depart);
    void Parcour_DFS(int depart);
    void Composantes_Connexes();
    void Reinitialisation_graphe();
    void Eulerien();
    int getOrdre();

};


void Chemin(int target,Graphe G);
void menu(Graphe &G);

#endif // GRAPHE_H_INCLUDED
