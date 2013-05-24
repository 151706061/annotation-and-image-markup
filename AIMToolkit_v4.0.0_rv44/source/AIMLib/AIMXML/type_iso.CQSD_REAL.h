/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CQSD_REAL
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CQSD_REAL

#include "type_iso.CQSET_REAL.h"


namespace AIMXML
{

namespace iso
{	

class CQSD_REAL : public ::AIMXML::iso::CQSET_REAL
{
public:
	AIMXML_EXPORT CQSD_REAL(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CQSD_REAL(CQSD_REAL const& init);
	void operator=(CQSD_REAL const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CQSD_REAL); }
	MemberElement<iso::CQSET_REAL, _altova_mi_iso_altova_CQSD_REAL_altova_first> first;
	struct first { typedef Iterator<iso::CQSET_REAL> iterator; };
	MemberElement<iso::CQSET_REAL, _altova_mi_iso_altova_CQSD_REAL_altova_second> second;
	struct second { typedef Iterator<iso::CQSET_REAL> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CQSD_REAL
