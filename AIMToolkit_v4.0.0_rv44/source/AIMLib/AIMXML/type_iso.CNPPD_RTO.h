/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CNPPD_RTO
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CNPPD_RTO

#include "type_iso.CANY.h"


namespace AIMXML
{

namespace iso
{	

class CNPPD_RTO : public ::AIMXML::iso::CANY
{
public:
	AIMXML_EXPORT CNPPD_RTO(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CNPPD_RTO(CNPPD_RTO const& init);
	void operator=(CNPPD_RTO const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CNPPD_RTO); }
	MemberElement<iso::CUVP_RTO, _altova_mi_iso_altova_CNPPD_RTO_altova_item> item;
	struct item { typedef Iterator<iso::CUVP_RTO> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CNPPD_RTO
