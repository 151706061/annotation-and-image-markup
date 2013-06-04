/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_CO
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_CO

#include "type_iso.CCOLL_CO.h"


namespace AIMXML
{

namespace iso
{	

class CDSET_CO : public ::AIMXML::iso::CCOLL_CO
{
public:
	AIMXML_EXPORT CDSET_CO(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CDSET_CO(CDSET_CO const& init);
	void operator=(CDSET_CO const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CDSET_CO); }
	MemberElement<iso::CCO, _altova_mi_iso_altova_CDSET_CO_altova_item> item;
	struct item { typedef Iterator<iso::CCO> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_CO
