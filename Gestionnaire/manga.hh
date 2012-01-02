#ifndef MANGA_HH
#define MANGA_HH

#include "bd.hh"

///class Manga, inheriting of class BD
class Manga : public BD
{
public:
    Manga();
    ~Manga();
    void setType(const std::string &);
    std::string getType();
protected:
    std::string _type;
};

#endif // MANGA_HH
