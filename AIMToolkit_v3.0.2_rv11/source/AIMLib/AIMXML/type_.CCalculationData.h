/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CCalculationData
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CCalculationData



namespace AIMXML
{

class CCalculationData : public TypeBase
{
public:
	AIMXML_EXPORT CCalculationData(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CCalculationData(CCalculationData const& init);
	void operator=(CCalculationData const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CCalculationData); }

	MemberAttribute<__int64,_altova_mi_altova_CCalculationData_altova_cagridId, 0, 0> cagridId;	// cagridId Cinteger

	MemberAttribute<double,_altova_mi_altova_CCalculationData_altova_value2, 0, 0> dataValue;	// value Cdouble
	MemberElement<CcoordinateCollectionType, _altova_mi_altova_CCalculationData_altova_coordinateCollection> coordinateCollection;
	struct coordinateCollection { typedef Iterator<CcoordinateCollectionType> iterator; };
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CCalculationData
