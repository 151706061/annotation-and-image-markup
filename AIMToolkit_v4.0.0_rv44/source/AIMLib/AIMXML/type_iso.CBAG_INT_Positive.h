/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CBAG_INT_Positive
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CBAG_INT_Positive

#include "type_iso.CCOLL_INT_Positive.h"


namespace AIMXML
{

namespace iso
{	

class CBAG_INT_Positive : public ::AIMXML::iso::CCOLL_INT_Positive
{
public:
	AIMXML_EXPORT CBAG_INT_Positive(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CBAG_INT_Positive(CBAG_INT_Positive const& init);
	void operator=(CBAG_INT_Positive const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CBAG_INT_Positive); }
	MemberElement<iso::CINT_Positive, _altova_mi_iso_altova_CBAG_INT_Positive_altova_item> item;
	struct item { typedef Iterator<iso::CINT_Positive> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CBAG_INT_Positive
