#include "roman.hh"

Roman::Roman()
{
}

Roman::~Roman()
{
}

///function setEditor who set the Editor of a Roman
void Roman::setEditor(const std::string & editor)
{
    _editor = editor;
}

///function getEditor who return the editor of a Roman
std::string Roman::getEditor()
{
    return _editor;
}
