#include<iostream>
#include<fstream>
#include"graphe.h"
#include<string>
#include <iterator>










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

    m_ordre=ordre;
}

int Graphe::getOrdre()
{
    return m_ordre;
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

Sommet*Graphe::getSommet(int ID)
{
     for(auto s : m_sommets)
        if (s->getID()==ID)
            return s;

     return NULL;
}

void Graphe::Coloration_DFS(int ID)
{



   std::vector<int> file;
   Sommet* S;
   file.push_back(ID);
    S=getSommet(*(file.rbegin()));
    S->setClr('N');
     S->setPred(-2);
   while(file.size()!= 0)
    {

       file.erase(file.end()-1);
           for(auto s : *(S->getArretes()))
          {
            if(s->getClr()=='B')
            {
                s->setClr('N');
                file.push_back(s->getID());
                s->setPred(S->getID());
            }
          }
      S=getSommet(*(file.rbegin()));
   }
}


void Graphe::Coloration_BFS(int ID)
{



   std::vector<int> file;
   Sommet* S;
   file.push_back(ID);
    S=getSommet(*(file.rbegin()));
    S->setClr('N');
    S->setPred(-2);
   while(file.size()!= 0)
    {

       file.erase(begin(file));
           for(auto s : *(S->getArretes()))
          {
            if(s->getClr()=='B')
            {
                s->setClr('N');
                file.push_back(s->getID());
                s->setPred(S->getID());
            }
          }
      S=getSommet((file[0]));
   }
}


void Graphe::Reinitialisation_graphe()
{
   Sommet* S;
   for(size_t i=0; i< m_sommets.size();++i)
   {
      S=getSommet(i);
      S->setClr('B');
      S->setPred(-1);
      S->setConn(0);
   }

}

void Graphe::Parcour_BFS(int depart)
{

    Coloration_BFS(depart);

    for(size_t i=0; i< m_sommets.size();++i)
    {
        if(getSommet(i)->getPred()!=-1 && getSommet(i)->getPred()!=-2 )
        {
            Chemin(i,*(this));
        }
    }

}

void Graphe::Parcour_DFS(int depart)
{
    Coloration_DFS(depart);
        for(size_t i=0; i< m_sommets.size();++i)
    {
        if(getSommet(i)->getPred()!=-1 && getSommet(i)->getPred()!=-2)
        {
            Chemin(i,*(this));
        }
    }
}


void Graphe::Composantes_Connexes()
{

  int cc=1;


     for(auto s : m_sommets)
     {
         if(s->getPred()==-1)
         {
             Coloration_BFS(s->getID());
             for(auto s2 : m_sommets)
                 if(s2->getPred()!=-1 && s2->getConn()==0)
                 {
                     s2->setConn(cc);
                 }

             ++cc;

         }
     }

    for(int i=1; i< cc;++i)
    {
         std::cout<<std::endl<<"Composante connexe "<<i<<" : ";
            for(auto s3 : m_sommets)
         {
             if(s3->getConn()== i)
                std::cout<<s3->getID()<<" ";
         }

    }


}

void Graphe::Eulerien()
{
    int x=-1,compteur_euler;

    for(auto s : m_sommets)
     {
         for(size_t i=0; i<(*s->getArretes()).size();++i)
         {
             x*=-1;
         }

         if(x == -1)
            ++compteur_euler;

     }

     if (compteur_euler == 0 || compteur_euler == 2)
        std::cout<<std::endl<<"Cycle Eulerien";
     else
        std::cout<<std::endl<< "Pas de cycle Eulerien";
}


void Chemin(int target,Graphe G)
{
  std::vector<int> ordre;
  Sommet* S=G.getSommet(target);


 while(S->getPred()!= -2)
 {
   S=G.getSommet(S->getPred());
   ordre.push_back(S->getID());
 }

 std::cout<<std::endl<<target;

  for(auto v : ordre )
    {
        std::cout<<" <-- "<<v;
    }

}

void menu(Graphe &G)
{
    int verif=0,ID=-1;
    char choix;
    std::string a;

    while(verif==0 )
    {

        std::cout<<std::endl<<std::endl<<"1- Afficher le graphe"<<std::endl<<"2- Parcour BFS"<<std::endl<<"3- Parcour DFS"<<std::endl<<"4- Composantes connexes  "<<std::endl<<"5- Test Eulerien"<<std::endl<<"6-Exit  "<<std::endl;
        std::cin>>choix;
        system("cls");
        switch(choix)
        {
              case'1':
                 G.afficher();
                  break;
              case'2':

                  G.Reinitialisation_graphe();
                   while( ID<0 || ID>G.getOrdre())
                   {
                       system("cls");
                       std::cout<<std::endl<<"Numero du sommet de depart:";
                        std::cin>>ID;
                   }
                   G.Parcour_BFS(ID);
                   ID=-1;
                   break;
              case'3':
                  G.Reinitialisation_graphe();
                   while( ID<0 || ID>G.getOrdre())
                   {
                       system("cls");
                       std::cout<<std::endl<<"Numero du sommet de depart:";
                        std::cin>>ID;
                   }
                   G.Parcour_DFS(ID);
                   ID=-1;
                   break;
              case'4':
                  G.Reinitialisation_graphe();
                  G.Composantes_Connexes();
                  G.Reinitialisation_graphe();
                   break;
              case'5':
                  G.Eulerien();
                  G.Reinitialisation_graphe();
                   break;
              case'6':
                  verif=1;
                   break;
              default:
                   break;
        }


    }



}



