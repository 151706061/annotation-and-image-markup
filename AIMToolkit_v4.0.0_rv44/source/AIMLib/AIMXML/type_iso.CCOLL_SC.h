/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_SC
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_SC

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CCOLL_SC : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CCOLL_SC(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CCOLL_SC(CCOLL_SC const& init);
	void operator=(CCOLL_SC const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CCOLL_SC); }
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCOLL_SC
