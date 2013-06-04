/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionGeometricShapeEntity
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionGeometricShapeEntity

#include "type_.CGeometricShapeEntity.h"


namespace AIMXML
{

class CThreeDimensionGeometricShapeEntity : public ::AIMXML::CGeometricShapeEntity
{
public:
	AIMXML_EXPORT CThreeDimensionGeometricShapeEntity(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CThreeDimensionGeometricShapeEntity(CThreeDimensionGeometricShapeEntity const& init);
	void operator=(CThreeDimensionGeometricShapeEntity const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CThreeDimensionGeometricShapeEntity); }
	MemberElement<iso::CII, _altova_mi_altova_CThreeDimensionGeometricShapeEntity_altova_frameOfReferenceUid> frameOfReferenceUid;
	struct frameOfReferenceUid { typedef Iterator<iso::CII> iterator; };
	MemberElement<iso::CII, _altova_mi_altova_CThreeDimensionGeometricShapeEntity_altova_fiducialUid> fiducialUid;
	struct fiducialUid { typedef Iterator<iso::CII> iterator; };
	MemberElement<CthreeDimensionSpatialCoordinateCollectionType, _altova_mi_altova_CThreeDimensionGeometricShapeEntity_altova_threeDimensionSpatialCoordinateCollection> threeDimensionSpatialCoordinateCollection;
	struct threeDimensionSpatialCoordinateCollection { typedef Iterator<CthreeDimensionSpatialCoordinateCollectionType> iterator; };
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CThreeDimensionGeometricShapeEntity
