/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement

#include "type_.CImageAnnotationStatement.h"


namespace AIMXML
{

class CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement : public ::AIMXML::CImageAnnotationStatement
{
public:
	AIMXML_EXPORT CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement(CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement const& init);
	void operator=(CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement); }
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement
