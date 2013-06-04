/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CinferenceEntityCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CinferenceEntityCollectionType



namespace AIMXML
{

class CinferenceEntityCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CinferenceEntityCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CinferenceEntityCollectionType(CinferenceEntityCollectionType const& init);
	void operator=(CinferenceEntityCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CinferenceEntityCollectionType); }
	MemberElement<CInferenceEntity, _altova_mi_altova_CinferenceEntityCollectionType_altova_InferenceEntity> InferenceEntity;
	struct InferenceEntity { typedef Iterator<CInferenceEntity> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CinferenceEntityCollectionType
