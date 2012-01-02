#include "bd.hh"

BD::BD()
{
}

BD::~BD()
{
}

///function setEditor who set the editor of a BD
void BD::setEditor(const std::string & editor)
{
    _editor = editor;
}

///function getEditor who return the editor of a BD
std::string BD::getEditor()
{
    return _editor;
}
