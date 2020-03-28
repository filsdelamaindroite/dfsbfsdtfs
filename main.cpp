#include <iostream>
#include "graphe.h"
int main()
{
    Graphe G("oui.txt");
    G.Reinitialisation_graphe();
    menu(G);
    return 0;
}
