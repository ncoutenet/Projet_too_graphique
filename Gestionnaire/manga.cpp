#include "manga.hh"

Manga::Manga()
{
}

Manga::~Manga()
{
}

void Manga::setType(const std::string & type)
{
    _type = type;
}

std::string Manga::getType()
{
    return _type;
}
