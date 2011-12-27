#include "document.hh"

Document::Document()
{
}

Document::~Document()
{
}

void Document::setTitle(const std::string & title)
{
    _title = title;
}

std::string Document::getTitle()
{
    return _title;
}
