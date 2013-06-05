/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageReferenceEntityCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageReferenceEntityCollectionType



namespace AIMXML
{

class CimageReferenceEntityCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CimageReferenceEntityCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CimageReferenceEntityCollectionType(CimageReferenceEntityCollectionType const& init);
	void operator=(CimageReferenceEntityCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CimageReferenceEntityCollectionType); }
	MemberElement<CImageReferenceEntity, _altova_mi_altova_CimageReferenceEntityCollectionType_altova_ImageReferenceEntity> ImageReferenceEntity;
	struct ImageReferenceEntity { typedef Iterator<CImageReferenceEntity> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageReferenceEntityCollectionType
