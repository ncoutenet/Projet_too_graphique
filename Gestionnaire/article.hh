#ifndef ARTICLE_HH
#define ARTICLE_HH

#include "livre.hh"

///class Article, inheriting of class Livre
class Article : public Livre
{
public:
    Article();
    ~Article();
    void setTheme(const std::string &);
    std::string getTheme();
    void setDateParution(const std::string &);
    std::string getDateParution();
protected:
    std::string _theme;
    std::string _dateParution;
};

#endif // ARTICLE_HH
