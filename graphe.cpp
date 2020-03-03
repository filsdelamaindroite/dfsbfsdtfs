#include<iostream>
#include<fstream>
#include"graphe.h"
#include<string>
Graphe::Graphe(std::string a)
{
    std::ifstream ifs{a};
    if(!ifs)
    {
        std::cout<<"pb fichier";
        exit(0);
    }

    ifs >> m_orient;
    int ordre, taille;
    ifs >> ordre;
    for(int i=0; i<ordre; ++i)
        m_sommets.push_back(new Sommet(i));
    ifs >> taille;
    int pids, nids;
    for(int i=0; i<taille; ++i)
    {
        ifs >> pids;
        ifs >> nids;
        m_sommets[pids]->getArretes()->push_back(m_sommets[nids]);
        //std::cout<<m_sommets[pids]->getArretes()[0].getID();
        if(!m_orient)
            m_sommets[nids]->getArretes()->push_back(m_sommets[pids]);
    }
}

void Graphe::afficher()const
{
    if(m_orient)
        std::cout<<"Graphe oriente\n";
    else
        std::cout<<"Graphe non-oriente\n";
    std::cout<<"ordre="<<m_sommets.size()<<std::endl;
    std::cout<<"liste d'adjacence : \n";
    for(auto s : m_sommets)
    {
        std::cout<<"sommet "<<s->getID()<<" : ";
        for(size_t j=0; j<s->getArretes()->size(); ++j)
            std::cout<<((*(s->getArretes()))[j])->getID() <<" ";
        std::cout<<"\n";
    }
}
