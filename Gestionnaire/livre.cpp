#include "livre.hh"

Livre::Livre()
{
}

Livre::~Livre()
{
}

///function setAuthor who set the author of a Livre
void Livre::setAuthor(const std::string & author)
{
    _author = author;
}

///function getAuthor who return the author of a Livre
std::string Livre::getAuthor()
{
    return _author;
}
