/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_TS_Birth
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_TS_Birth

#include "type_iso.CCOLL_TS_Birth.h"


namespace AIMXML
{

namespace iso
{	

class CDSET_TS_Birth : public ::AIMXML::iso::CCOLL_TS_Birth
{
public:
	AIMXML_EXPORT CDSET_TS_Birth(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CDSET_TS_Birth(CDSET_TS_Birth const& init);
	void operator=(CDSET_TS_Birth const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CDSET_TS_Birth); }
	MemberElement<iso::CTS_Birth, _altova_mi_iso_altova_CDSET_TS_Birth_altova_item> item;
	struct item { typedef Iterator<iso::CTS_Birth> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_TS_Birth
