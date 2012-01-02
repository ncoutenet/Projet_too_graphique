#include "manga.hh"

Manga::Manga()
{
}

Manga::~Manga()
{
}

///function setType who set the type of a Manga
void Manga::setType(const std::string & type)
{
    _type = type;
}

///function getType who return the type of a Manga
std::string Manga::getType()
{
    return _type;
}
