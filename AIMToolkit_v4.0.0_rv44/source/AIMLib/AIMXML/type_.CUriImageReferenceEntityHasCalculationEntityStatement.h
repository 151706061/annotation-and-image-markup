/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CUriImageReferenceEntityHasCalculationEntityStatement
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CUriImageReferenceEntityHasCalculationEntityStatement

#include "type_.CImageAnnotationStatement.h"


namespace AIMXML
{

class CUriImageReferenceEntityHasCalculationEntityStatement : public ::AIMXML::CImageAnnotationStatement
{
public:
	AIMXML_EXPORT CUriImageReferenceEntityHasCalculationEntityStatement(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CUriImageReferenceEntityHasCalculationEntityStatement(CUriImageReferenceEntityHasCalculationEntityStatement const& init);
	void operator=(CUriImageReferenceEntityHasCalculationEntityStatement const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CUriImageReferenceEntityHasCalculationEntityStatement); }
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CUriImageReferenceEntityHasCalculationEntityStatement
