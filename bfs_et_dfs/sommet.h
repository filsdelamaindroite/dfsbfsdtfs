#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include<vector>
class Sommet
{
private:
    int m_id;
    std::vector<Sommet*> m_arrete;
public:
    Sommet(int a)
    {
        m_id=a;
    }
    ~Sommet()=default;
    int getID()const
    {
        return m_id;
    }
    std::vector<Sommet*> *getArretes()
    {
        return &m_arrete;
    }
    void setID(int a)
    {
        m_id=a;
    }

};

#endif // SOMMET_H_INCLUDED
