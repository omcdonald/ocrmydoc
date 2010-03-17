/*
 * Header for template reader of OCR module.
 *
 * Author: Milosz Kosmider
 */

#include "sax.hpp"
/*
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
 
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
 
#include "ErnstSax2Handler.h" // your SAX2 handler
 
 *
 * The method that actually processes the region.
 *
void ErnstXmlLoader::loadXml( string xml_path )
{
    cout << xml_path << endl;
 
    SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();
    parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
 
    ErnstSax2Handler* handler = new ErnstSax2Handler();
 
    parser->setContentHandler(handler);
    parser->setErrorHandler(handler);
 
    try 
    {
        parser->parse( xml_path.c_str() );
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
    }
 
    delete parser;
    delete handler;
}

*/
