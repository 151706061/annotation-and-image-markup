/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionSpatialCoordinate
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionSpatialCoordinate

#include "type_.CSpatialCoordinate.h"


namespace AIMXML
{

class CThreeDimensionSpatialCoordinate : public ::AIMXML::CSpatialCoordinate
{
public:
	AIMXML_EXPORT CThreeDimensionSpatialCoordinate(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CThreeDimensionSpatialCoordinate(CThreeDimensionSpatialCoordinate const& init);
	void operator=(CThreeDimensionSpatialCoordinate const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CThreeDimensionSpatialCoordinate); }

	MemberAttribute<double,_altova_mi_altova_CThreeDimensionSpatialCoordinate_altova_x, 0, 0> x;	// x Cdouble

	MemberAttribute<double,_altova_mi_altova_CThreeDimensionSpatialCoordinate_altova_y, 0, 0> y;	// y Cdouble

	MemberAttribute<double,_altova_mi_altova_CThreeDimensionSpatialCoordinate_altova_z, 0, 0> z;	// z Cdouble

	MemberAttribute<string_type,_altova_mi_altova_CThreeDimensionSpatialCoordinate_altova_frameOfReferenceUID, 0, 0> frameOfReferenceUID;	// frameOfReferenceUID Cstring
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionSpatialCoordinate
