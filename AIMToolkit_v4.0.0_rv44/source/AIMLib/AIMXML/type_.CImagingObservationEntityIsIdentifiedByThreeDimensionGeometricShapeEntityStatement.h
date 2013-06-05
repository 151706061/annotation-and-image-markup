/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement

#include "type_.CImageAnnotationStatement.h"


namespace AIMXML
{

class CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement : public ::AIMXML::CImageAnnotationStatement
{
public:
	AIMXML_EXPORT CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement(CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement const& init);
	void operator=(CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement); }
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement
