#include "bd.hh"

BD::BD()
{
}

BD::~BD()
{
}

void BD::setEditor(const std::string & editor)
{
    _editor = editor;
}

std::string BD::getEditor()
{
    return _editor;
}
