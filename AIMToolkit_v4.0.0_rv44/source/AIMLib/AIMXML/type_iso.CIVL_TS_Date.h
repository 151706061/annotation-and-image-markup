/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CIVL_TS_Date
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CIVL_TS_Date

#include "type_iso.CQSET_TS_Date.h"


namespace AIMXML
{

namespace iso
{	

class CIVL_TS_Date : public ::AIMXML::iso::CQSET_TS_Date
{
public:
	AIMXML_EXPORT CIVL_TS_Date(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CIVL_TS_Date(CIVL_TS_Date const& init);
	void operator=(CIVL_TS_Date const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CIVL_TS_Date); }

	MemberAttribute<bool,_altova_mi_iso_altova_CIVL_TS_Date_altova_lowClosed, 0, 0> lowClosed;	// lowClosed Cboolean

	MemberAttribute<bool,_altova_mi_iso_altova_CIVL_TS_Date_altova_highClosed, 0, 0> highClosed;	// highClosed Cboolean
	MemberElement<iso::CTS_Date, _altova_mi_iso_altova_CIVL_TS_Date_altova_low> low;
	struct low { typedef Iterator<iso::CTS_Date> iterator; };
	MemberElement<iso::CTS_Date, _altova_mi_iso_altova_CIVL_TS_Date_altova_high> high;
	struct high { typedef Iterator<iso::CTS_Date> iterator; };
	MemberElement<iso::CQTY, _altova_mi_iso_altova_CIVL_TS_Date_altova_width> width;
	struct width { typedef Iterator<iso::CQTY> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CIVL_TS_Date
