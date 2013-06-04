/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CTwoDimensionCircle
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CTwoDimensionCircle

#include "type_.CTwoDimensionGeometricShapeEntity.h"


namespace AIMXML
{

class CTwoDimensionCircle : public ::AIMXML::CTwoDimensionGeometricShapeEntity
{
public:
	AIMXML_EXPORT CTwoDimensionCircle(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CTwoDimensionCircle(CTwoDimensionCircle const& init);
	void operator=(CTwoDimensionCircle const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CTwoDimensionCircle); }
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CTwoDimensionCircle
