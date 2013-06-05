/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CNPPD_INT_Positive
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CNPPD_INT_Positive

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CNPPD_INT_Positive : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CNPPD_INT_Positive(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CNPPD_INT_Positive(CNPPD_INT_Positive const& init);
	void operator=(CNPPD_INT_Positive const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CNPPD_INT_Positive); }
	MemberElement<iso::CUVP_INT_Positive, _altova_mi_iso_altova_CNPPD_INT_Positive_altova_item> item;
	struct item { typedef Iterator<iso::CUVP_INT_Positive> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CNPPD_INT_Positive
