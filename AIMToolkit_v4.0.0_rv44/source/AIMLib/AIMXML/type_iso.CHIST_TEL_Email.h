/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CHIST_TEL_Email
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CHIST_TEL_Email

#include "type_iso.CLIST_TEL_Email.h"


namespace AIMXML
{

namespace iso
{	

class CHIST_TEL_Email : public ::AIMXML::iso::CLIST_TEL_Email
{
public:
	AIMXML_EXPORT CHIST_TEL_Email(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CHIST_TEL_Email(CHIST_TEL_Email const& init);
	void operator=(CHIST_TEL_Email const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CHIST_TEL_Email); }
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CHIST_TEL_Email
