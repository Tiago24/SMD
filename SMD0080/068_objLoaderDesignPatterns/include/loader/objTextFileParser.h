
#ifndef OBJFILEPARSER_CLASS_H__
#define OBJFILEPARSER_CLASS_H__

#include <loader/textFileParser.h>

struct ObjTextFileContext
{
	ObjTextFileContext();

	Scene* scene;
	//
	std::vector<Vec3> vertices;
	std::vector<Vec2> tcs; // coordenadas de textura
	std::vector<Vec3> normals;

	MaterialVector materials;
	FaceLayout fl;
};


/**
 * Leitor especializado para arquivos OBJ.
 */
class ObjTextFileParser : public TextFileParser
{
public:

	ObjTextFileParser (const String& filename);
	~ObjTextFileParser ();

	ObjTextFileParser (const ObjTextFileParser &) = delete;
	ObjTextFileParser & operator=(const ObjTextFileParser &) = delete;

	virtual bool parse() override;
	Scene* parseScene();

	ObjTextFileContext& getContext();

protected:

	ObjTextFileContext _context;
};


#endif /* TEXTFILEPARSER_INTERFACE_H__ */
