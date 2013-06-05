/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImageAnnotationStatement
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImageAnnotationStatement

#include "type_.CAnnotationStatement.h"


namespace AIMXML
{

class CImageAnnotationStatement : public ::AIMXML::CAnnotationStatement
{
public:
	AIMXML_EXPORT CImageAnnotationStatement(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CImageAnnotationStatement(CImageAnnotationStatement const& init);
	void operator=(CImageAnnotationStatement const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CImageAnnotationStatement); }
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImageAnnotationStatement
