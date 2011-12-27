#ifndef LIVRE_HH
#define LIVRE_HH

#include "document.hh"

class Livre : public Document
{
public:
    Livre();
    ~Livre();
    void setAuthor(const std::string &);
    std::string getAuthor();
protected:
    std::string _author;
};

#endif // LIVRE_HH
