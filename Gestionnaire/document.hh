#ifndef DOCUMENT_HH
#define DOCUMENT_HH

#include <string>

///class Document, mother class of all document's type classes.
class Document
{
public:
    Document();
    ~Document();
    void setTitle(const std::string &);
    std::string getTitle();
protected:
    std::string _title;
};

#endif // DOCUMENT_HH
