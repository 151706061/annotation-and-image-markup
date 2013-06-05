/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_BL
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_BL

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CLIST_BL : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CLIST_BL(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CLIST_BL(CLIST_BL const& init);
	void operator=(CLIST_BL const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CLIST_BL); }
	MemberElement<iso::CBL, _altova_mi_iso_altova_CLIST_BL_altova_item> item;
	struct item { typedef Iterator<iso::CBL> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_BL
