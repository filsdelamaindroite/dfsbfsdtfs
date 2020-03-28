#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include<vector>
class Sommet
{
private:
    int m_id;
    std::vector<Sommet*> m_arrete;
    char m_clr;
    int m_pred;
    int m_comp_con;
public:
    Sommet(int a)
    {
        m_id=a;
        m_clr='B';
        m_pred=-1;
        m_comp_con=0;
    }
    ~Sommet()=default;

    int getID()const
    {
        return m_id;
    }

    int getPred()const
    {
        return m_pred;
    }

    char getClr()const
    {
        return m_clr;
    }

    std::vector<Sommet*> *getArretes()
    {
        return &m_arrete;
    }
    void setID(int a)
    {
        m_id=a;
    }

    void setPred(int a)
    {
        m_pred=a;
    }

    void setClr(char a)
    {
        m_clr=a;
    }


    void setConn(int a)
    {
        m_comp_con=a;
    }


    int getConn()
    {
        return m_comp_con;
    }

};

#endif // SOMMET_H_INCLUDED
