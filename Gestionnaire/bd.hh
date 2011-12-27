#ifndef BD_HH
#define BD_HH

#include "livre.hh"

class BD : public Livre
{
public:
    BD();
    ~BD();
    void setEditor(const std::string &);
    std::string getEditor();
protected:
    std::string _editor;
};

#endif // BD_HH
