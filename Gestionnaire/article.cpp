#include "article.hh"

Article::Article()
{
}

Article::~Article()
{
}

///function setTheme who set the theme of an article
void Article::setTheme(const std::string & theme)
{
    _theme = theme;
}

///function getTheme who return the theme of an article
std::string Article::getTheme()
{
    return _theme;
}

///function setDateParution who set the date of parution of an article
void Article::setDateParution(const std::string & dateParution)
{
    _dateParution = dateParution;
}

///function getDateParution who return the date of parution of an article
std::string Article::getDateParution()
{
    return _dateParution;
}
