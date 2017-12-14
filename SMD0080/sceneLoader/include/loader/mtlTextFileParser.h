
#ifndef MATERIALTEXTFILEPARSER_CLASS_H__
#define MATERIALTEXTFILEPARSER_CLASS_H__

#include <loader/objTextFileParser.h>

class MaterialTextFileParser : public TextFileParser
{
public:
	MaterialTextFileParser (const String& filename, ObjTextFileParser& owner);
	~MaterialTextFileParser ();

	MaterialTextFileParser (const MaterialTextFileParser &) = delete;
	MaterialTextFileParser & operator=(const MaterialTextFileParser &) = delete;

	ObjTextFileParser& getOwner();

protected:

	ObjTextFileParser& _owner;
};


#endif /* MATERIALTEXTFILEPARSER_CLASS_H__ */
