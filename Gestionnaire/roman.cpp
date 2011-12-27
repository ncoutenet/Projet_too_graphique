#include "roman.hh"

Roman::Roman()
{
}

Roman::~Roman()
{
}

void Roman::setEditor(const std::string & editor)
{
    _editor = editor;
}

std::string Roman::getEditor()
{
    return _editor;
}
