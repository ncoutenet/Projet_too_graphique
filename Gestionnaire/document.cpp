#include "document.hh"

Document::Document()
{
}

Document::~Document()
{
}

///function setTitle who set the title of a Document
void Document::setTitle(const std::string & title)
{
    _title = title;
}

///function getTitle who return the title of a Document
std::string Document::getTitle()
{
    return _title;
}
