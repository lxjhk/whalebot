#include "htmlcxx_parser.h"

using namespace htmlcxx;

htmlcxx::Uri htmlcxx::gParseBase( const std::string& baseUrl )
{
    return htmlcxx::Uri(baseUrl);
}

TUrlParseResult htmlcxx::gParseRel( htmlcxx::Uri& baseUri, const std::string& relativeUrl )
{
    htmlcxx::Uri    tmp(relativeUrl);
    htmlcxx::Uri    relativeUri(tmp.absolute(baseUri));

    return TUrlParseResult(
                            relativeUri.hostname(),
                            htmlcxx::Uri::encode(relativeUri.path())
                            +
                            ( relativeUri.existsQuery()
                              ? "?" + htmlcxx::Uri::encode(relativeUri.query())
                              : "" )
                           );
}


void CParser::parseBase( const std::string& baseUri )
{
    m_tUri  =   gParseBase(baseUri);
}

void CParser::parseRel( const std::string& relUri )
{
    gParseRel(m_tUri, relUri);
}
