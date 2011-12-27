#include "livre.hh"

Livre::Livre()
{
}

Livre::~Livre()
{
}

void Livre::setAuthor(const std::string & author)
{
    _author = author;
}
std::string Livre::getAuthor()
{
    return _author;
}
