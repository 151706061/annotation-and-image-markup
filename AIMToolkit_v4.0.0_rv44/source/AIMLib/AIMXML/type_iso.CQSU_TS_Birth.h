/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CQSU_TS_Birth
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CQSU_TS_Birth

#include "type_iso.CQSET_TS_Birth.h"


namespace AIMXML
{

namespace iso
{	

class CQSU_TS_Birth : public ::AIMXML::iso::CQSET_TS_Birth
{
public:
	AIMXML_EXPORT CQSU_TS_Birth(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CQSU_TS_Birth(CQSU_TS_Birth const& init);
	void operator=(CQSU_TS_Birth const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CQSU_TS_Birth); }
	MemberElement<iso::CQSET_TS_Birth, _altova_mi_iso_altova_CQSU_TS_Birth_altova_term> term;
	struct term { typedef Iterator<iso::CQSET_TS_Birth> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CQSU_TS_Birth
