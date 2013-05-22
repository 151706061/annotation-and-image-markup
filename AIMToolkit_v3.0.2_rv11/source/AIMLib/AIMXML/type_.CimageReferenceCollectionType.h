/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageReferenceCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageReferenceCollectionType



namespace AIMXML
{

class CimageReferenceCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CimageReferenceCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CimageReferenceCollectionType(CimageReferenceCollectionType const& init);
	void operator=(CimageReferenceCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CimageReferenceCollectionType); }
	MemberElement<CImageReference, _altova_mi_altova_CimageReferenceCollectionType_altova_ImageReference> ImageReference;
	struct ImageReference { typedef Iterator<CImageReference> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CimageReferenceCollectionType
