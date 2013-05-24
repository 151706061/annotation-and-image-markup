/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_ED_Image
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_ED_Image

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CLIST_ED_Image : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CLIST_ED_Image(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CLIST_ED_Image(CLIST_ED_Image const& init);
	void operator=(CLIST_ED_Image const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CLIST_ED_Image); }
	MemberElement<iso::CED_Image, _altova_mi_iso_altova_CLIST_ED_Image_altova_item> item;
	struct item { typedef Iterator<iso::CED_Image> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CLIST_ED_Image
