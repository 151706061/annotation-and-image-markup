/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_TS_DateTime_Full
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_TS_DateTime_Full

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CCOLL_TS_DateTime_Full : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CCOLL_TS_DateTime_Full(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CCOLL_TS_DateTime_Full(CCOLL_TS_DateTime_Full const& init);
	void operator=(CCOLL_TS_DateTime_Full const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CCOLL_TS_DateTime_Full); }
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_TS_DateTime_Full
