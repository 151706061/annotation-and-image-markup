/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_ED_Signature
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_ED_Signature

#include "type_iso.CCOLL_ED_Signature.h"


namespace AIMXML
{

namespace iso
{	

class CDSET_ED_Signature : public ::AIMXML::iso::CCOLL_ED_Signature
{
public:
	AIMXML_EXPORT CDSET_ED_Signature(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CDSET_ED_Signature(CDSET_ED_Signature const& init);
	void operator=(CDSET_ED_Signature const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CDSET_ED_Signature); }
	MemberElement<iso::CED_Signature, _altova_mi_iso_altova_CDSET_ED_Signature_altova_item> item;
	struct item { typedef Iterator<iso::CED_Signature> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_ED_Signature
