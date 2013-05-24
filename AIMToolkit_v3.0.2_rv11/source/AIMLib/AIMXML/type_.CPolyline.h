/*
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CPolyline
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CPolyline

#include "type_.CGeometricShape.h"


namespace AIMXML
{

class CPolyline : public ::AIMXML::CGeometricShape
{
public:
	AIMXML_EXPORT CPolyline(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CPolyline(CPolyline const& init);
	void operator=(CPolyline const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CPolyline); }
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CPolyline
