/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_ED_Signature
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_ED_Signature

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CLIST_ED_Signature : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CLIST_ED_Signature(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CLIST_ED_Signature(CLIST_ED_Signature const& init);
	void operator=(CLIST_ED_Signature const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CLIST_ED_Signature); }
	MemberElement<iso::CED_Signature, _altova_mi_iso_altova_CLIST_ED_Signature_altova_item> item;
	struct item { typedef Iterator<iso::CED_Signature> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_ED_Signature
