#include "article.hh"

Article::Article()
{
}

Article::~Article()
{
}

void Article::setTheme(const std::string & theme)
{
    _theme = theme;
}

std::string Article::getTheme()
{
    return _theme;
}

void Article::setDateParution(const std::string & dateParution)
{
    _dateParution = dateParution;
}

std::string Article::getDateParution()
{
    return _dateParution;
}
