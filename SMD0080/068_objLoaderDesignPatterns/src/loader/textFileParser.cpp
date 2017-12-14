#include <loader/textFileParser.h>

// --------------------------------------------------------------------------
// LineBasedParsingCommand
// --------------------------------------------------------------------------
LineBasedParsingCommand::LineBasedParsingCommand( const char* pref)
	: _prefix(pref)
{
}
// --------------------------------------------------------------------------
LineBasedParsingCommand::~LineBasedParsingCommand()
{
}
// --------------------------------------------------------------------------
bool LineBasedParsingCommand::acceptsLine(String& line)
{
	if( line.find( _prefix ) == 0 )
	{
		line.erase( 0, _prefix.size() );
		return true;
	}

	return false;
}
// --------------------------------------------------------------------------
// TexFileParser
// --------------------------------------------------------------------------
TextFileParser::TextFileParser(const String& fn)
	: filename(fn), is(fn), lineCommands()
{
}
// --------------------------------------------------------------------------
TextFileParser::~TextFileParser()
{
}
// --------------------------------------------------------------------------
void TextFileParser::trim(  String& str, const char* delims )
{
	// direita primeiro, para dar espaço
	size_t endpos = str.find_last_not_of(delims);
	if( String::npos != endpos )
	{
		str = str.substr( 0, endpos+1 );
	}

	// trim espaços à esquerda
	size_t startpos = str.find_first_not_of(delims);
	if( String::npos != startpos )
	{
		str = str.substr( startpos );
	}
}
// --------------------------------------------------------------------------
String TextFileParser::getBaseDir(void) const
{
	size_t pos = filename.find_last_of("\\/");
	if( pos != String::npos) return filename.substr( 0, pos+1);

	return String();
}
// --------------------------------------------------------------------------
bool TextFileParser::parse()
{
	if( !is.is_open() )
	{
		std::cerr << "[ERROR] cannot open \'" << filename << "\'";
		return true;
	}

	String line;
	line.reserve( 512 );



	// vai até o fim
	while( !is.eof() )
	{
		// lê a linha do arquivo
		std::getline( is, line );

		// remove caracteres vazios
		TextFileParser::trim( line );
		if( line.empty() || line[0] == '#' )
			continue;

		if( _processLine(line) )
		{
			std::cerr << "Erro na linha \n" <<line << std::endl;
			return true;
		}
	}
	return false;
}
// --------------------------------------------------------------------------
bool TextFileParser::_processLine( String& line )
{
	for( auto ptr: lineCommands )
	{
		LineBasedParsingCommand& pbcm = *ptr;

		String prev = line;
		if( pbcm.acceptsLine(line) )
		{
			//std::cout << "NHAM! " << prev << std::endl;
			return pbcm.processLine(*this, line);
		}
	}

	return false;
}
// --------------------------------------------------------------------------
