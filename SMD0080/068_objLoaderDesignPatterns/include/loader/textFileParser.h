
/*
 * objLineParser.h
 *
 *  Created on: 29 de jan de 2017
 *      Author: gilvan
 */
#ifndef ITEXTFILEPARSER_INTERFACE_H__
#define ITEXTFILEPARSER_INTERFACE_H__

#include "triangleMesh.h"

/// Pré-declaração para uso antecipado.
class TextFileParser;

/**
 * Comando de parsing, que deve ser associado a uma linha de comando.
 */
class LineBasedParsingCommand
{
public:
	LineBasedParsingCommand( const LineBasedParsingCommand& ) = delete;
	LineBasedParsingCommand& operator=( const LineBasedParsingCommand& ) = delete;

	virtual ~LineBasedParsingCommand();

	virtual bool acceptsLine( String& line );
	virtual bool processLine(TextFileParser& tfp, const String& line) = 0;

protected:

	LineBasedParsingCommand(const char*);

	String _prefix;
};

typedef std::vector<LineBasedParsingCommand*> LineBasedParsingCommandVector;


/**
 * Leitor de arquivos baseado em linhas de texto.
 */
class TextFileParser
{
public:

	TextFileParser(const String& filename);
	virtual ~TextFileParser();

	TextFileParser(const TextFileParser&) = delete;
	TextFileParser& operator=(const TextFileParser&) = delete;

	static void trim( String& str, const char* delims = " \t" );
	String getBaseDir(void) const;

	/// Retorna [true] caso ocorra algum erro!
	virtual bool parse();


protected:

	/// Retorna [true] caso ocorra algum [erro]
	virtual bool _processLine( String& line );


	String filename;
	std::ifstream is;

	LineBasedParsingCommandVector lineCommands;
};


#endif /* ITEXTFILEPARSER_INTERFACE_H__ */
