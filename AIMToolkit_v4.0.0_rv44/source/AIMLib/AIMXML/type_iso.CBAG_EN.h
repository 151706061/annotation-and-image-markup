/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CBAG_EN
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CBAG_EN

#include "type_iso.CCOLL_EN.h"


namespace AIMXML
{

namespace iso
{	

class CBAG_EN : public ::AIMXML::iso::CCOLL_EN
{
public:
	AIMXML_EXPORT CBAG_EN(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CBAG_EN(CBAG_EN const& init);
	void operator=(CBAG_EN const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CBAG_EN); }
	MemberElement<iso::CEN, _altova_mi_iso_altova_CBAG_EN_altova_item> item;
	struct item { typedef Iterator<iso::CEN> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CBAG_EN
