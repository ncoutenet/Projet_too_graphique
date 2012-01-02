#ifndef ROMAN_HH
#define ROMAN_HH

#include "livre.hh"

///class Roman, inheriting of class Livre
class Roman : public Livre
{
public:
    Roman();
    ~Roman();
    void setEditor(const std::string &);
    std::string getEditor();
protected:
    std::string _editor;
};

#endif // ROMAN_HH
