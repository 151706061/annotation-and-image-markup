/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#include "StdAfx.h"
#include <string.h>
#include "AIMXML.h"
#include <algorithm>


#include "../AltovaXML/XercesString.h"




// turn off warning: "this" used in base initializer list
#pragma warning(disable:4355)


namespace AIMXML
{


xercesc::DOMNode* TypeBase::GetElementNth(const altova::MemberInfo* member, unsigned index)
{
	for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
	{
		if (index-- == 0)
			return *it;
	}
	return 0;
}

xercesc::DOMNode* TypeBase::GetElementLast(const altova::MemberInfo* member)
{
	xercesc::DOMNode* p;
	for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
	{
		p = *it;
	}
	return p;
}

unsigned TypeBase::CountElement(const altova::MemberInfo* member)
{
	unsigned count = 0;
	for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
	{
		++count;
	}
	return count;
}

void TypeBase::RemoveElement(const altova::MemberInfo* member)
{
	XercesTreeOperations::RemoveElements(m_node, member);
}

int TypeBase::GetEnumerationIndex( const string_type sValue, const unsigned enumOffset, const unsigned enumCount)
{
	unsigned enumIndex = enumOffset;

	while( enumIndex < (enumOffset + enumCount) )
	{
		const FacetInfo* facet = GetTableEntry(facets, enumIndex);

		if( facet->StringValue == sValue)
			return enumIndex - enumOffset;
		enumIndex++;
	}
	return -1; //Invalid
}

string_type TypeBase::GetEnumerationValue( const int index, const unsigned enumOffset, const unsigned enumCount)
{
	unsigned enumIndex = enumOffset + index;

	if( enumIndex >= enumOffset && enumIndex < (enumOffset + enumCount) )
	{
		const FacetInfo* facet = GetTableEntry(facets, enumIndex);
		return facet->StringValue;
	}
	else
		throw altova::ConversionException( _T("Enumeration index out of range.") );
}


CAdjudicationObservation::CAdjudicationObservation(xercesc::DOMNode* const& node)
: TypeBase(node)
, observationUid(*this)	// "observationUid"
, observationScope(*this)	// "observationScope"
, personObserversRoleInThisProcedure(*this)	// "personObserversRoleInThisProcedure"
, identifierWithinAcceptedPersonObserversRole(*this)	// "identifierWithinAcceptedPersonObserversRole"
, identifierWithinRejectedPersonObserversRole(*this)	// "identifierWithinRejectedPersonObserversRole"
, reasonForChoice(*this)	// "reasonForChoice"
, reasonForDiscordance(*this)	// "reasonForDiscordance"
, comment(*this)	// "comment"
, imageQualityIssuesDiscordance(*this)	// "imageQualityIssuesDiscordance"
{
}

CAdjudicationObservation::CAdjudicationObservation(CAdjudicationObservation const& other)
: TypeBase(other.GetNode())
, observationUid(*this)	// "observationUid"
, observationScope(*this)	// "observationScope"
, personObserversRoleInThisProcedure(*this)	// "personObserversRoleInThisProcedure"
, identifierWithinAcceptedPersonObserversRole(*this)	// "identifierWithinAcceptedPersonObserversRole"
, identifierWithinRejectedPersonObserversRole(*this)	// "identifierWithinRejectedPersonObserversRole"
, reasonForChoice(*this)	// "reasonForChoice"
, reasonForDiscordance(*this)	// "reasonForDiscordance"
, comment(*this)	// "comment"
, imageQualityIssuesDiscordance(*this)	// "imageQualityIssuesDiscordance"
{
}

void CAdjudicationObservation::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AdjudicationObservation"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAimVersion::CAimVersion(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CAimVersion::CAimVersion(CAimVersion const& other)
: TypeBase(other.GetNode())
{
}


CAlgorithm::CAlgorithm(xercesc::DOMNode* const& node)
: TypeBase(node)
, name(*this)	// "name"
, type(*this)	// "type"
, uniqueIdentifier(*this)	// "uniqueIdentifier"
, version(*this)	// "version"
, description(*this)	// "description"
, parameterCollection(*this)	// "parameterCollection"
{
}

CAlgorithm::CAlgorithm(CAlgorithm const& other)
: TypeBase(other.GetNode())
, name(*this)	// "name"
, type(*this)	// "type"
, uniqueIdentifier(*this)	// "uniqueIdentifier"
, version(*this)	// "version"
, description(*this)	// "description"
, parameterCollection(*this)	// "parameterCollection"
{
}

void CAlgorithm::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Algorithm"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationCollection::CAnnotationCollection(xercesc::DOMNode* const& node)
: TypeBase(node)
, aimVersion(*this)	// "@aimVersion"
, uniqueIdentifier(*this)	// "uniqueIdentifier"
, description(*this)	// "description"
, dateTime(*this)	// "dateTime"
, user(*this)	// "user"
, equipment(*this)	// "equipment"
{
}

CAnnotationCollection::CAnnotationCollection(CAnnotationCollection const& other)
: TypeBase(other.GetNode())
, aimVersion(*this)	// "@aimVersion"
, uniqueIdentifier(*this)	// "uniqueIdentifier"
, description(*this)	// "description"
, dateTime(*this)	// "dateTime"
, user(*this)	// "user"
, equipment(*this)	// "equipment"
{
}

void CAnnotationCollection::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationCollection"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationEntity::CAnnotationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
, typeCode(*this)	// "typeCode"
, dateTime(*this)	// "dateTime"
, name(*this)	// "name"
, comment(*this)	// "comment"
, precedentReferencedAnnotationUid(*this)	// "precedentReferencedAnnotationUid"
, templateUid(*this)	// "templateUid"
, auditTrailCollection(*this)	// "auditTrailCollection"
, imagingPhysicalEntityCollection(*this)	// "imagingPhysicalEntityCollection"
, calculationEntityCollection(*this)	// "calculationEntityCollection"
, inferenceEntityCollection(*this)	// "inferenceEntityCollection"
, annotationRoleEntityCollection(*this)	// "annotationRoleEntityCollection"
, lesionObservationEntityCollection(*this)	// "lesionObservationEntityCollection"
, imagingObservationEntityCollection(*this)	// "imagingObservationEntityCollection"
, taskContextEntityCollection(*this)	// "taskContextEntityCollection"
{
}

CAnnotationEntity::CAnnotationEntity(CAnnotationEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
, typeCode(*this)	// "typeCode"
, dateTime(*this)	// "dateTime"
, name(*this)	// "name"
, comment(*this)	// "comment"
, precedentReferencedAnnotationUid(*this)	// "precedentReferencedAnnotationUid"
, templateUid(*this)	// "templateUid"
, auditTrailCollection(*this)	// "auditTrailCollection"
, imagingPhysicalEntityCollection(*this)	// "imagingPhysicalEntityCollection"
, calculationEntityCollection(*this)	// "calculationEntityCollection"
, inferenceEntityCollection(*this)	// "inferenceEntityCollection"
, annotationRoleEntityCollection(*this)	// "annotationRoleEntityCollection"
, lesionObservationEntityCollection(*this)	// "lesionObservationEntityCollection"
, imagingObservationEntityCollection(*this)	// "imagingObservationEntityCollection"
, taskContextEntityCollection(*this)	// "taskContextEntityCollection"
{
}

void CAnnotationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationEntityHasPerformedTaskContextEntityStatement::CAnnotationEntityHasPerformedTaskContextEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CAnnotationEntityHasPerformedTaskContextEntityStatement::CAnnotationEntityHasPerformedTaskContextEntityStatement(CAnnotationEntityHasPerformedTaskContextEntityStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CAnnotationEntityHasPerformedTaskContextEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationEntityHasPerformedTaskContextEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationEntityHasPlannedTaskContextEntityStatement::CAnnotationEntityHasPlannedTaskContextEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CAnnotationEntityHasPlannedTaskContextEntityStatement::CAnnotationEntityHasPlannedTaskContextEntityStatement(CAnnotationEntityHasPlannedTaskContextEntityStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CAnnotationEntityHasPlannedTaskContextEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationEntityHasPlannedTaskContextEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotation::CAnnotationOfAnnotation(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationEntity(node)
, adjudicationObservation(*this)	// "adjudicationObservation"
, annotationOfAnnotationStatementCollection(*this)	// "annotationOfAnnotationStatementCollection"
{
}

CAnnotationOfAnnotation::CAnnotationOfAnnotation(CAnnotationOfAnnotation const& other)
: ::AIMXML::CAnnotationEntity(other.GetNode())
, adjudicationObservation(*this)	// "adjudicationObservation"
, annotationOfAnnotationStatementCollection(*this)	// "annotationOfAnnotationStatementCollection"
{
}

void CAnnotationOfAnnotation::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotation"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationCollection::CAnnotationOfAnnotationCollection(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationCollection(node)
, annotationOfAnnotations(*this)	// "annotationOfAnnotations"
{
}

CAnnotationOfAnnotationCollection::CAnnotationOfAnnotationCollection(CAnnotationOfAnnotationCollection const& other)
: ::AIMXML::CAnnotationCollection(other.GetNode())
, annotationOfAnnotations(*this)	// "annotationOfAnnotations"
{
}

void CAnnotationOfAnnotationCollection::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationCollection"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasAnnotationOfAnnotationStatement::CAnnotationOfAnnotationHasAnnotationOfAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasAnnotationOfAnnotationStatement::CAnnotationOfAnnotationHasAnnotationOfAnnotationStatement(CAnnotationOfAnnotationHasAnnotationOfAnnotationStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasAnnotationOfAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasAnnotationOfAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasAnnotationRoleEntityStatement::CAnnotationOfAnnotationHasAnnotationRoleEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasAnnotationRoleEntityStatement::CAnnotationOfAnnotationHasAnnotationRoleEntityStatement(CAnnotationOfAnnotationHasAnnotationRoleEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasAnnotationRoleEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasAnnotationRoleEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasCalculationEntityStatement::CAnnotationOfAnnotationHasCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasCalculationEntityStatement::CAnnotationOfAnnotationHasCalculationEntityStatement(CAnnotationOfAnnotationHasCalculationEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasGeneralLesionObservationEntityStatement::CAnnotationOfAnnotationHasGeneralLesionObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasGeneralLesionObservationEntityStatement::CAnnotationOfAnnotationHasGeneralLesionObservationEntityStatement(CAnnotationOfAnnotationHasGeneralLesionObservationEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasGeneralLesionObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasGeneralLesionObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasImageAnnotationStatement::CAnnotationOfAnnotationHasImageAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasImageAnnotationStatement::CAnnotationOfAnnotationHasImageAnnotationStatement(CAnnotationOfAnnotationHasImageAnnotationStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasImageAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasImageAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasImagingObservationEntityStatement::CAnnotationOfAnnotationHasImagingObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasImagingObservationEntityStatement::CAnnotationOfAnnotationHasImagingObservationEntityStatement(CAnnotationOfAnnotationHasImagingObservationEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasImagingObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasImagingObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasImagingPhysicalEntityStatement::CAnnotationOfAnnotationHasImagingPhysicalEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasImagingPhysicalEntityStatement::CAnnotationOfAnnotationHasImagingPhysicalEntityStatement(CAnnotationOfAnnotationHasImagingPhysicalEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasImagingPhysicalEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasImagingPhysicalEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasInferenceEntityStatement::CAnnotationOfAnnotationHasInferenceEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasInferenceEntityStatement::CAnnotationOfAnnotationHasInferenceEntityStatement(CAnnotationOfAnnotationHasInferenceEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasInferenceEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasInferenceEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationHasTimePointLesionObservationEntityStatement::CAnnotationOfAnnotationHasTimePointLesionObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationHasTimePointLesionObservationEntityStatement::CAnnotationOfAnnotationHasTimePointLesionObservationEntityStatement(CAnnotationOfAnnotationHasTimePointLesionObservationEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationHasTimePointLesionObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationHasTimePointLesionObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationIsComparedWithAnnotationOfAnnotationStatement::CAnnotationOfAnnotationIsComparedWithAnnotationOfAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CAnnotationOfAnnotationIsComparedWithAnnotationOfAnnotationStatement::CAnnotationOfAnnotationIsComparedWithAnnotationOfAnnotationStatement(CAnnotationOfAnnotationIsComparedWithAnnotationOfAnnotationStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationIsComparedWithAnnotationOfAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationIsComparedWithAnnotationOfAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationIsComparedWithImageAnnotationStatement::CAnnotationOfAnnotationIsComparedWithImageAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CAnnotationOfAnnotationIsComparedWithImageAnnotationStatement::CAnnotationOfAnnotationIsComparedWithImageAnnotationStatement(CAnnotationOfAnnotationIsComparedWithImageAnnotationStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationIsComparedWithImageAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationIsComparedWithImageAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationOfAnnotationStatement::CAnnotationOfAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CAnnotationOfAnnotationStatement::CAnnotationOfAnnotationStatement(CAnnotationOfAnnotationStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CAnnotationOfAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationOfAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationRoleEntity::CAnnotationRoleEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
, roleCode(*this)	// "roleCode"
, questionTypeCode(*this)	// "questionTypeCode"
, roleSequenceNumber(*this)	// "roleSequenceNumber"
{
}

CAnnotationRoleEntity::CAnnotationRoleEntity(CAnnotationRoleEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
, roleCode(*this)	// "roleCode"
, questionTypeCode(*this)	// "questionTypeCode"
, roleSequenceNumber(*this)	// "roleSequenceNumber"
{
}

void CAnnotationRoleEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationRoleEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAnnotationStatement::CAnnotationStatement(xercesc::DOMNode* const& node)
: TypeBase(node)
, subjectUniqueIdentifier(*this)	// "subjectUniqueIdentifier"
, objectUniqueIdentifier(*this)	// "objectUniqueIdentifier"
{
}

CAnnotationStatement::CAnnotationStatement(CAnnotationStatement const& other)
: TypeBase(other.GetNode())
, subjectUniqueIdentifier(*this)	// "subjectUniqueIdentifier"
, objectUniqueIdentifier(*this)	// "objectUniqueIdentifier"
{
}

void CAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAuditTrail::CAuditTrail(xercesc::DOMNode* const& node)
: TypeBase(node)
, statusCode(*this)	// "statusCode"
, dateTime(*this)	// "dateTime"
, changeReason(*this)	// "changeReason"
, worklistSubtaskUid(*this)	// "worklistSubtaskUid"
, comment(*this)	// "comment"
{
}

CAuditTrail::CAuditTrail(CAuditTrail const& other)
: TypeBase(other.GetNode())
, statusCode(*this)	// "statusCode"
, dateTime(*this)	// "dateTime"
, changeReason(*this)	// "changeReason"
, worklistSubtaskUid(*this)	// "worklistSubtaskUid"
, comment(*this)	// "comment"
{
}

void CAuditTrail::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AuditTrail"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CCalculationData::CCalculationData(xercesc::DOMNode* const& node)
: TypeBase(node)
, value2(*this)	// "value"
, coordinateCollection(*this)	// "coordinateCollection"
{
}

CCalculationData::CCalculationData(CCalculationData const& other)
: TypeBase(other.GetNode())
, value2(*this)	// "value"
, coordinateCollection(*this)	// "coordinateCollection"
{
}

void CCalculationData::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CalculationData"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CCalculationEntity::CCalculationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, description(*this)	// "description"
, mathML(*this)	// "mathML"
, questionIndex(*this)	// "questionIndex"
, calculationResultCollection(*this)	// "calculationResultCollection"
, algorithm(*this)	// "algorithm"
{
}

CCalculationEntity::CCalculationEntity(CCalculationEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, description(*this)	// "description"
, mathML(*this)	// "mathML"
, questionIndex(*this)	// "questionIndex"
, calculationResultCollection(*this)	// "calculationResultCollection"
, algorithm(*this)	// "algorithm"
{
}

void CCalculationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CalculationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CCalculationEntityIsComparedWithCalculationEntityStatement::CCalculationEntityIsComparedWithCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CCalculationEntityIsComparedWithCalculationEntityStatement::CCalculationEntityIsComparedWithCalculationEntityStatement(CCalculationEntityIsComparedWithCalculationEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CCalculationEntityIsComparedWithCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CalculationEntityIsComparedWithCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CCalculationEntityReferencesCalculationEntityStatement::CCalculationEntityReferencesCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CCalculationEntityReferencesCalculationEntityStatement::CCalculationEntityReferencesCalculationEntityStatement(CCalculationEntityReferencesCalculationEntityStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CCalculationEntityReferencesCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CalculationEntityReferencesCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CCalculationEntityUsesCalculationEntityStatement::CCalculationEntityUsesCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CCalculationEntityUsesCalculationEntityStatement::CCalculationEntityUsesCalculationEntityStatement(CCalculationEntityUsesCalculationEntityStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CCalculationEntityUsesCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CalculationEntityUsesCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CCalculationResult::CCalculationResult(xercesc::DOMNode* const& node)
: TypeBase(node)
, type(*this)	// "@type"
, unitOfMeasure(*this)	// "unitOfMeasure"
, dataType(*this)	// "dataType"
, dimensionCollection(*this)	// "dimensionCollection"
{
}

CCalculationResult::CCalculationResult(CCalculationResult const& other)
: TypeBase(other.GetNode())
, type(*this)	// "@type"
, unitOfMeasure(*this)	// "unitOfMeasure"
, dataType(*this)	// "dataType"
, dimensionCollection(*this)	// "dimensionCollection"
{
}

void CCalculationResult::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CalculationResult"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CCalculationResultIdentifier::CCalculationResultIdentifier(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CCalculationResultIdentifier::CCalculationResultIdentifier(CCalculationResultIdentifier const& other)
: TypeBase(other.GetNode())
{
}


CCharacteristicQuantification::CCharacteristicQuantification(xercesc::DOMNode* const& node)
: TypeBase(node)
, annotatorConfidence(*this)	// "annotatorConfidence"
, characteristicQuantificationIndex(*this)	// "characteristicQuantificationIndex"
, label(*this)	// "label"
, valueLabel(*this)	// "valueLabel"
, valueDescription(*this)	// "valueDescription"
, comment(*this)	// "comment"
{
}

CCharacteristicQuantification::CCharacteristicQuantification(CCharacteristicQuantification const& other)
: TypeBase(other.GetNode())
, annotatorConfidence(*this)	// "annotatorConfidence"
, characteristicQuantificationIndex(*this)	// "characteristicQuantificationIndex"
, label(*this)	// "label"
, valueLabel(*this)	// "valueLabel"
, valueDescription(*this)	// "valueDescription"
, comment(*this)	// "comment"
{
}

void CCharacteristicQuantification::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CharacteristicQuantification"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CCompactCalculationResult::CCompactCalculationResult(xercesc::DOMNode* const& node)
: ::AIMXML::CCalculationResult(node)
, value2(*this)	// "value"
, encoding(*this)	// "encoding"
, compression(*this)	// "compression"
{
}

CCompactCalculationResult::CCompactCalculationResult(CCompactCalculationResult const& other)
: ::AIMXML::CCalculationResult(other.GetNode())
, value2(*this)	// "value"
, encoding(*this)	// "encoding"
, compression(*this)	// "compression"
{
}

void CCompactCalculationResult::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CompactCalculationResult"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CComparisonOperator::CComparisonOperator(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CComparisonOperator::CComparisonOperator(CComparisonOperator const& other)
: TypeBase(other.GetNode())
{
}


CCoordinate::CCoordinate(xercesc::DOMNode* const& node)
: TypeBase(node)
, dimensionIndex(*this)	// "dimensionIndex"
, position(*this)	// "position"
{
}

CCoordinate::CCoordinate(CCoordinate const& other)
: TypeBase(other.GetNode())
, dimensionIndex(*this)	// "dimensionIndex"
, position(*this)	// "position"
{
}

void CCoordinate::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Coordinate"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CDicomImageReferenceEntity::CDicomImageReferenceEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CImageReferenceEntity(node)
, imageStudy(*this)	// "imageStudy"
{
}

CDicomImageReferenceEntity::CDicomImageReferenceEntity(CDicomImageReferenceEntity const& other)
: ::AIMXML::CImageReferenceEntity(other.GetNode())
, imageStudy(*this)	// "imageStudy"
{
}

void CDicomImageReferenceEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DicomImageReferenceEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CDicomImageReferenceEntityHasCalculationEntityStatement::CDicomImageReferenceEntityHasCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CDicomImageReferenceEntityHasCalculationEntityStatement::CDicomImageReferenceEntityHasCalculationEntityStatement(CDicomImageReferenceEntityHasCalculationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CDicomImageReferenceEntityHasCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DicomImageReferenceEntityHasCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CDicomImageReferenceEntityHasImagingObservationEntityStatement::CDicomImageReferenceEntityHasImagingObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CDicomImageReferenceEntityHasImagingObservationEntityStatement::CDicomImageReferenceEntityHasImagingObservationEntityStatement(CDicomImageReferenceEntityHasImagingObservationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CDicomImageReferenceEntityHasImagingObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DicomImageReferenceEntityHasImagingObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CDicomImageReferenceEntityHasImagingPhysicalEntityStatement::CDicomImageReferenceEntityHasImagingPhysicalEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CDicomImageReferenceEntityHasImagingPhysicalEntityStatement::CDicomImageReferenceEntityHasImagingPhysicalEntityStatement(CDicomImageReferenceEntityHasImagingPhysicalEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CDicomImageReferenceEntityHasImagingPhysicalEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DicomImageReferenceEntityHasImagingPhysicalEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CDicomSegmentationEntity::CDicomSegmentationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CSegmentationEntity(node)
, sopInstanceUid(*this)	// "sopInstanceUid"
, sopClassUid(*this)	// "sopClassUid"
, referencedSopInstanceUid(*this)	// "referencedSopInstanceUid"
, segmentNumber(*this)	// "segmentNumber"
{
}

CDicomSegmentationEntity::CDicomSegmentationEntity(CDicomSegmentationEntity const& other)
: ::AIMXML::CSegmentationEntity(other.GetNode())
, sopInstanceUid(*this)	// "sopInstanceUid"
, sopClassUid(*this)	// "sopClassUid"
, referencedSopInstanceUid(*this)	// "referencedSopInstanceUid"
, segmentNumber(*this)	// "segmentNumber"
{
}

void CDicomSegmentationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DicomSegmentationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CDicomSegmentationEntityHasImagingObservationEntityStatement::CDicomSegmentationEntityHasImagingObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CDicomSegmentationEntityHasImagingObservationEntityStatement::CDicomSegmentationEntityHasImagingObservationEntityStatement(CDicomSegmentationEntityHasImagingObservationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CDicomSegmentationEntityHasImagingObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DicomSegmentationEntityHasImagingObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CDimension::CDimension(xercesc::DOMNode* const& node)
: TypeBase(node)
, index(*this)	// "index"
, size(*this)	// "size"
, label(*this)	// "label"
{
}

CDimension::CDimension(CDimension const& other)
: TypeBase(other.GetNode())
, index(*this)	// "index"
, size(*this)	// "size"
, label(*this)	// "label"
{
}

void CDimension::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Dimension"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CEntity::CEntity(xercesc::DOMNode* const& node)
: TypeBase(node)
, uniqueIdentifier(*this)	// "uniqueIdentifier"
{
}

CEntity::CEntity(CEntity const& other)
: TypeBase(other.GetNode())
, uniqueIdentifier(*this)	// "uniqueIdentifier"
{
}

void CEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Entity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CEquipment::CEquipment(xercesc::DOMNode* const& node)
: TypeBase(node)
, manufacturerName(*this)	// "manufacturerName"
, manufacturerModelName(*this)	// "manufacturerModelName"
, deviceSerialNumber(*this)	// "deviceSerialNumber"
, softwareVersion(*this)	// "softwareVersion"
{
}

CEquipment::CEquipment(CEquipment const& other)
: TypeBase(other.GetNode())
, manufacturerName(*this)	// "manufacturerName"
, manufacturerModelName(*this)	// "manufacturerModelName"
, deviceSerialNumber(*this)	// "deviceSerialNumber"
, softwareVersion(*this)	// "softwareVersion"
{
}

void CEquipment::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Equipment"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CExtendedCalculationResult::CExtendedCalculationResult(xercesc::DOMNode* const& node)
: ::AIMXML::CCalculationResult(node)
, calculationDataCollection(*this)	// "calculationDataCollection"
{
}

CExtendedCalculationResult::CExtendedCalculationResult(CExtendedCalculationResult const& other)
: ::AIMXML::CCalculationResult(other.GetNode())
, calculationDataCollection(*this)	// "calculationDataCollection"
{
}

void CExtendedCalculationResult::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ExtendedCalculationResult"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CGeneralImage::CGeneralImage(xercesc::DOMNode* const& node)
: TypeBase(node)
, patientOrientationColumn(*this)	// "patientOrientationColumn"
, patientOrientationRow(*this)	// "patientOrientationRow"
{
}

CGeneralImage::CGeneralImage(CGeneralImage const& other)
: TypeBase(other.GetNode())
, patientOrientationColumn(*this)	// "patientOrientationColumn"
, patientOrientationRow(*this)	// "patientOrientationRow"
{
}

void CGeneralImage::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GeneralImage"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CGeneralLesionObservationEntity::CGeneralLesionObservationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CLesionObservationEntity(node)
, trackingIdentifier(*this)	// "trackingIdentifier"
, lesionType(*this)	// "lesionType"
, reconstructionInterval(*this)	// "reconstructionInterval"
, laterality(*this)	// "laterality"
{
}

CGeneralLesionObservationEntity::CGeneralLesionObservationEntity(CGeneralLesionObservationEntity const& other)
: ::AIMXML::CLesionObservationEntity(other.GetNode())
, trackingIdentifier(*this)	// "trackingIdentifier"
, lesionType(*this)	// "lesionType"
, reconstructionInterval(*this)	// "reconstructionInterval"
, laterality(*this)	// "laterality"
{
}

void CGeneralLesionObservationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GeneralLesionObservationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CGeneralLesionObservationEntityHasImagingPhysicalEntityStatement::CGeneralLesionObservationEntityHasImagingPhysicalEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CGeneralLesionObservationEntityHasImagingPhysicalEntityStatement::CGeneralLesionObservationEntityHasImagingPhysicalEntityStatement(CGeneralLesionObservationEntityHasImagingPhysicalEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CGeneralLesionObservationEntityHasImagingPhysicalEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GeneralLesionObservationEntityHasImagingPhysicalEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CGeometricShapeEntity::CGeometricShapeEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CMarkupEntity(node)
, questionTypeCode(*this)	// "questionTypeCode"
, shapeIdentifier(*this)	// "shapeIdentifier"
, label(*this)	// "label"
, description(*this)	// "description"
, includeFlag(*this)	// "includeFlag"
, comment(*this)	// "comment"
, lineColor(*this)	// "lineColor"
, lineOpacity(*this)	// "lineOpacity"
, lineStyle(*this)	// "lineStyle"
, lineThickness(*this)	// "lineThickness"
, questionIndex(*this)	// "questionIndex"
, interpolationMethod(*this)	// "interpolationMethod"
{
}

CGeometricShapeEntity::CGeometricShapeEntity(CGeometricShapeEntity const& other)
: ::AIMXML::CMarkupEntity(other.GetNode())
, questionTypeCode(*this)	// "questionTypeCode"
, shapeIdentifier(*this)	// "shapeIdentifier"
, label(*this)	// "label"
, description(*this)	// "description"
, includeFlag(*this)	// "includeFlag"
, comment(*this)	// "comment"
, lineColor(*this)	// "lineColor"
, lineOpacity(*this)	// "lineOpacity"
, lineStyle(*this)	// "lineStyle"
, lineThickness(*this)	// "lineThickness"
, questionIndex(*this)	// "questionIndex"
, interpolationMethod(*this)	// "interpolationMethod"
{
}

void CGeometricShapeEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GeometricShapeEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImage::CImage(xercesc::DOMNode* const& node)
: TypeBase(node)
, sopClassUid(*this)	// "sopClassUid"
, sopInstanceUid(*this)	// "sopInstanceUid"
, imagePlane(*this)	// "imagePlane"
, generalImage(*this)	// "generalImage"
{
}

CImage::CImage(CImage const& other)
: TypeBase(other.GetNode())
, sopClassUid(*this)	// "sopClassUid"
, sopInstanceUid(*this)	// "sopInstanceUid"
, imagePlane(*this)	// "imagePlane"
, generalImage(*this)	// "generalImage"
{
}

void CImage::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Image"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotation::CImageAnnotation(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationEntity(node)
, segmentationEntityCollection(*this)	// "segmentationEntityCollection"
, markupEntityCollection(*this)	// "markupEntityCollection"
, imageAnnotationStatementCollection(*this)	// "imageAnnotationStatementCollection"
, imageReferenceEntityCollection(*this)	// "imageReferenceEntityCollection"
{
}

CImageAnnotation::CImageAnnotation(CImageAnnotation const& other)
: ::AIMXML::CAnnotationEntity(other.GetNode())
, segmentationEntityCollection(*this)	// "segmentationEntityCollection"
, markupEntityCollection(*this)	// "markupEntityCollection"
, imageAnnotationStatementCollection(*this)	// "imageAnnotationStatementCollection"
, imageReferenceEntityCollection(*this)	// "imageReferenceEntityCollection"
{
}

void CImageAnnotation::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotation"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationCollection::CImageAnnotationCollection(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationCollection(node)
, person(*this)	// "person"
, imageAnnotations(*this)	// "imageAnnotations"
{
}

CImageAnnotationCollection::CImageAnnotationCollection(CImageAnnotationCollection const& other)
: ::AIMXML::CAnnotationCollection(other.GetNode())
, person(*this)	// "person"
, imageAnnotations(*this)	// "imageAnnotations"
{
}

void CImageAnnotationCollection::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationCollection"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasAnnotationRoleEntityStatement::CImageAnnotationHasAnnotationRoleEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CImageAnnotationHasAnnotationRoleEntityStatement::CImageAnnotationHasAnnotationRoleEntityStatement(CImageAnnotationHasAnnotationRoleEntityStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasAnnotationRoleEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasAnnotationRoleEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasCalculationEntityStatement::CImageAnnotationHasCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasCalculationEntityStatement::CImageAnnotationHasCalculationEntityStatement(CImageAnnotationHasCalculationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasChildImageAnnotationStatement::CImageAnnotationHasChildImageAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasChildImageAnnotationStatement::CImageAnnotationHasChildImageAnnotationStatement(CImageAnnotationHasChildImageAnnotationStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasChildImageAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasChildImageAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasDicomImageReferenceEntityStatement::CImageAnnotationHasDicomImageReferenceEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasDicomImageReferenceEntityStatement::CImageAnnotationHasDicomImageReferenceEntityStatement(CImageAnnotationHasDicomImageReferenceEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasDicomImageReferenceEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasDicomImageReferenceEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasDicomSegmentationEntityStatement::CImageAnnotationHasDicomSegmentationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasDicomSegmentationEntityStatement::CImageAnnotationHasDicomSegmentationEntityStatement(CImageAnnotationHasDicomSegmentationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasDicomSegmentationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasDicomSegmentationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasGeneralLesionObservationEntityStatement::CImageAnnotationHasGeneralLesionObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasGeneralLesionObservationEntityStatement::CImageAnnotationHasGeneralLesionObservationEntityStatement(CImageAnnotationHasGeneralLesionObservationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasGeneralLesionObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasGeneralLesionObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasImagingObservationEntityStatement::CImageAnnotationHasImagingObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasImagingObservationEntityStatement::CImageAnnotationHasImagingObservationEntityStatement(CImageAnnotationHasImagingObservationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasImagingObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasImagingObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasImagingPhysicalEntityStatement::CImageAnnotationHasImagingPhysicalEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasImagingPhysicalEntityStatement::CImageAnnotationHasImagingPhysicalEntityStatement(CImageAnnotationHasImagingPhysicalEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasImagingPhysicalEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasImagingPhysicalEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasInferenceEntityStatement::CImageAnnotationHasInferenceEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasInferenceEntityStatement::CImageAnnotationHasInferenceEntityStatement(CImageAnnotationHasInferenceEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasInferenceEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasInferenceEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasTextAnnotationEntityStatement::CImageAnnotationHasTextAnnotationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasTextAnnotationEntityStatement::CImageAnnotationHasTextAnnotationEntityStatement(CImageAnnotationHasTextAnnotationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasTextAnnotationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasTextAnnotationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasThreeDimensionGeometricShapeEntityStatement::CImageAnnotationHasThreeDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasThreeDimensionGeometricShapeEntityStatement::CImageAnnotationHasThreeDimensionGeometricShapeEntityStatement(CImageAnnotationHasThreeDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasThreeDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasThreeDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasTimePointLesionObservationEntityStatement::CImageAnnotationHasTimePointLesionObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasTimePointLesionObservationEntityStatement::CImageAnnotationHasTimePointLesionObservationEntityStatement(CImageAnnotationHasTimePointLesionObservationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasTimePointLesionObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasTimePointLesionObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasTwoDimensionGeometricShapeEntityStatement::CImageAnnotationHasTwoDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasTwoDimensionGeometricShapeEntityStatement::CImageAnnotationHasTwoDimensionGeometricShapeEntityStatement(CImageAnnotationHasTwoDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasTwoDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasTwoDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationHasUriImageReferenceEntityStatement::CImageAnnotationHasUriImageReferenceEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImageAnnotationHasUriImageReferenceEntityStatement::CImageAnnotationHasUriImageReferenceEntityStatement(CImageAnnotationHasUriImageReferenceEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationHasUriImageReferenceEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationHasUriImageReferenceEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationIsComparedWithAnnotationOfAnnotationStatement::CImageAnnotationIsComparedWithAnnotationOfAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CImageAnnotationIsComparedWithAnnotationOfAnnotationStatement::CImageAnnotationIsComparedWithAnnotationOfAnnotationStatement(CImageAnnotationIsComparedWithAnnotationOfAnnotationStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationIsComparedWithAnnotationOfAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationIsComparedWithAnnotationOfAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationIsComparedWithImageAnnotationStatement::CImageAnnotationIsComparedWithImageAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationOfAnnotationStatement(node)
{
}

CImageAnnotationIsComparedWithImageAnnotationStatement::CImageAnnotationIsComparedWithImageAnnotationStatement(CImageAnnotationIsComparedWithImageAnnotationStatement const& other)
: ::AIMXML::CAnnotationOfAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationIsComparedWithImageAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationIsComparedWithImageAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageAnnotationStatement::CImageAnnotationStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CImageAnnotationStatement::CImageAnnotationStatement(CImageAnnotationStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CImageAnnotationStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageAnnotationStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagePlane::CImagePlane(xercesc::DOMNode* const& node)
: TypeBase(node)
, rowImageOrientationX(*this)	// "rowImageOrientationX"
, rowImageOrientationY(*this)	// "rowImageOrientationY"
, rowImageOrientationZ(*this)	// "rowImageOrientationZ"
, columnImageOrientationX(*this)	// "columnImageOrientationX"
, columnImageOrientationY(*this)	// "columnImageOrientationY"
, columnImageOrientationZ(*this)	// "columnImageOrientationZ"
, verticalPixelSpacing(*this)	// "verticalPixelSpacing"
, horizontalPixelSpacing(*this)	// "horizontalPixelSpacing"
, sliceThickness(*this)	// "sliceThickness"
, imagePositionX(*this)	// "imagePositionX"
, imagePositionY(*this)	// "imagePositionY"
, imagePositionZ(*this)	// "imagePositionZ"
{
}

CImagePlane::CImagePlane(CImagePlane const& other)
: TypeBase(other.GetNode())
, rowImageOrientationX(*this)	// "rowImageOrientationX"
, rowImageOrientationY(*this)	// "rowImageOrientationY"
, rowImageOrientationZ(*this)	// "rowImageOrientationZ"
, columnImageOrientationX(*this)	// "columnImageOrientationX"
, columnImageOrientationY(*this)	// "columnImageOrientationY"
, columnImageOrientationZ(*this)	// "columnImageOrientationZ"
, verticalPixelSpacing(*this)	// "verticalPixelSpacing"
, horizontalPixelSpacing(*this)	// "horizontalPixelSpacing"
, sliceThickness(*this)	// "sliceThickness"
, imagePositionX(*this)	// "imagePositionX"
, imagePositionY(*this)	// "imagePositionY"
, imagePositionZ(*this)	// "imagePositionZ"
{
}

void CImagePlane::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagePlane"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageReferenceEntity::CImageReferenceEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
{
}

CImageReferenceEntity::CImageReferenceEntity(CImageReferenceEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
{
}

void CImageReferenceEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageReferenceEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageSeries::CImageSeries(xercesc::DOMNode* const& node)
: TypeBase(node)
, instanceUid(*this)	// "instanceUid"
, modality(*this)	// "modality"
, imageCollection(*this)	// "imageCollection"
{
}

CImageSeries::CImageSeries(CImageSeries const& other)
: TypeBase(other.GetNode())
, instanceUid(*this)	// "instanceUid"
, modality(*this)	// "modality"
, imageCollection(*this)	// "imageCollection"
{
}

void CImageSeries::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageSeries"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImageStudy::CImageStudy(xercesc::DOMNode* const& node)
: TypeBase(node)
, instanceUid(*this)	// "instanceUid"
, startDate(*this)	// "startDate"
, startTime(*this)	// "startTime"
, procedureDescription(*this)	// "procedureDescription"
, imageSeries(*this)	// "imageSeries"
, referencedDicomObjectCollection(*this)	// "referencedDicomObjectCollection"
{
}

CImageStudy::CImageStudy(CImageStudy const& other)
: TypeBase(other.GetNode())
, instanceUid(*this)	// "instanceUid"
, startDate(*this)	// "startDate"
, startTime(*this)	// "startTime"
, procedureDescription(*this)	// "procedureDescription"
, imageSeries(*this)	// "imageSeries"
, referencedDicomObjectCollection(*this)	// "referencedDicomObjectCollection"
{
}

void CImageStudy::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImageStudy"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingObservationCharacteristic::CImagingObservationCharacteristic(xercesc::DOMNode* const& node)
: TypeBase(node)
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, annotatorConfidence(*this)	// "annotatorConfidence"
, label(*this)	// "label"
, comment(*this)	// "comment"
, questionIndex(*this)	// "questionIndex"
, characteristicQuantificationCollection(*this)	// "characteristicQuantificationCollection"
{
}

CImagingObservationCharacteristic::CImagingObservationCharacteristic(CImagingObservationCharacteristic const& other)
: TypeBase(other.GetNode())
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, annotatorConfidence(*this)	// "annotatorConfidence"
, label(*this)	// "label"
, comment(*this)	// "comment"
, questionIndex(*this)	// "questionIndex"
, characteristicQuantificationCollection(*this)	// "characteristicQuantificationCollection"
{
}

void CImagingObservationCharacteristic::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingObservationCharacteristic"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingObservationEntity::CImagingObservationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, annotatorConfidence(*this)	// "annotatorConfidence"
, label(*this)	// "label"
, comment(*this)	// "comment"
, isPresent(*this)	// "isPresent"
, questionIndex(*this)	// "questionIndex"
, imagingObservationCharacteristicCollection(*this)	// "imagingObservationCharacteristicCollection"
{
}

CImagingObservationEntity::CImagingObservationEntity(CImagingObservationEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, annotatorConfidence(*this)	// "annotatorConfidence"
, label(*this)	// "label"
, comment(*this)	// "comment"
, isPresent(*this)	// "isPresent"
, questionIndex(*this)	// "questionIndex"
, imagingObservationCharacteristicCollection(*this)	// "imagingObservationCharacteristicCollection"
{
}

void CImagingObservationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingObservationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingObservationEntityHasCalculationEntityStatement::CImagingObservationEntityHasCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CImagingObservationEntityHasCalculationEntityStatement::CImagingObservationEntityHasCalculationEntityStatement(CImagingObservationEntityHasCalculationEntityStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CImagingObservationEntityHasCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingObservationEntityHasCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingObservationEntityIsFoundInImagingPhysicalEntityStatement::CImagingObservationEntityIsFoundInImagingPhysicalEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CImagingObservationEntityIsFoundInImagingPhysicalEntityStatement::CImagingObservationEntityIsFoundInImagingPhysicalEntityStatement(CImagingObservationEntityIsFoundInImagingPhysicalEntityStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CImagingObservationEntityIsFoundInImagingPhysicalEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingObservationEntityIsFoundInImagingPhysicalEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingObservationEntityIsIdentifiedByTextAnnotationEntityStatement::CImagingObservationEntityIsIdentifiedByTextAnnotationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImagingObservationEntityIsIdentifiedByTextAnnotationEntityStatement::CImagingObservationEntityIsIdentifiedByTextAnnotationEntityStatement(CImagingObservationEntityIsIdentifiedByTextAnnotationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImagingObservationEntityIsIdentifiedByTextAnnotationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingObservationEntityIsIdentifiedByTextAnnotationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement::CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement::CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement(CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingObservationEntityIsIdentifiedByThreeDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingObservationEntityIsIdentifiedByTwoDimensionGeometricShapeEntityStatement::CImagingObservationEntityIsIdentifiedByTwoDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImagingObservationEntityIsIdentifiedByTwoDimensionGeometricShapeEntityStatement::CImagingObservationEntityIsIdentifiedByTwoDimensionGeometricShapeEntityStatement(CImagingObservationEntityIsIdentifiedByTwoDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImagingObservationEntityIsIdentifiedByTwoDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingObservationEntityIsIdentifiedByTwoDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingPhysicalEntity::CImagingPhysicalEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, isPresent(*this)	// "isPresent"
, annotatorConfidence(*this)	// "annotatorConfidence"
, label(*this)	// "label"
, questionIndex(*this)	// "questionIndex"
, comment(*this)	// "comment"
, imagingPhysicalEntityCharacteristicCollection(*this)	// "imagingPhysicalEntityCharacteristicCollection"
, imagingObservationCharacteristicCollection(*this)	// "imagingObservationCharacteristicCollection"
{
}

CImagingPhysicalEntity::CImagingPhysicalEntity(CImagingPhysicalEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, isPresent(*this)	// "isPresent"
, annotatorConfidence(*this)	// "annotatorConfidence"
, label(*this)	// "label"
, questionIndex(*this)	// "questionIndex"
, comment(*this)	// "comment"
, imagingPhysicalEntityCharacteristicCollection(*this)	// "imagingPhysicalEntityCharacteristicCollection"
, imagingObservationCharacteristicCollection(*this)	// "imagingObservationCharacteristicCollection"
{
}

void CImagingPhysicalEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingPhysicalEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingPhysicalEntityCharacteristic::CImagingPhysicalEntityCharacteristic(xercesc::DOMNode* const& node)
: TypeBase(node)
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, annotatorConfidence(*this)	// "annotatorConfidence"
, label(*this)	// "label"
, questionIndex(*this)	// "questionIndex"
, comment(*this)	// "comment"
, characteristicQuantificationCollection(*this)	// "characteristicQuantificationCollection"
{
}

CImagingPhysicalEntityCharacteristic::CImagingPhysicalEntityCharacteristic(CImagingPhysicalEntityCharacteristic const& other)
: TypeBase(other.GetNode())
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, annotatorConfidence(*this)	// "annotatorConfidence"
, label(*this)	// "label"
, questionIndex(*this)	// "questionIndex"
, comment(*this)	// "comment"
, characteristicQuantificationCollection(*this)	// "characteristicQuantificationCollection"
{
}

void CImagingPhysicalEntityCharacteristic::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingPhysicalEntityCharacteristic"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingPhysicalEntityHasCalculationEntityStatement::CImagingPhysicalEntityHasCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CImagingPhysicalEntityHasCalculationEntityStatement::CImagingPhysicalEntityHasCalculationEntityStatement(CImagingPhysicalEntityHasCalculationEntityStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CImagingPhysicalEntityHasCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingPhysicalEntityHasCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingPhysicalEntityHasImagingObservationEntityStatement::CImagingPhysicalEntityHasImagingObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CAnnotationStatement(node)
{
}

CImagingPhysicalEntityHasImagingObservationEntityStatement::CImagingPhysicalEntityHasImagingObservationEntityStatement(CImagingPhysicalEntityHasImagingObservationEntityStatement const& other)
: ::AIMXML::CAnnotationStatement(other.GetNode())
{
}

void CImagingPhysicalEntityHasImagingObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingPhysicalEntityHasImagingObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingPhysicalEntityHasTextAnnotationEntityStatement::CImagingPhysicalEntityHasTextAnnotationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImagingPhysicalEntityHasTextAnnotationEntityStatement::CImagingPhysicalEntityHasTextAnnotationEntityStatement(CImagingPhysicalEntityHasTextAnnotationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImagingPhysicalEntityHasTextAnnotationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingPhysicalEntityHasTextAnnotationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingPhysicalEntityHasThreeDimensionGeometricShapeEntityStatement::CImagingPhysicalEntityHasThreeDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImagingPhysicalEntityHasThreeDimensionGeometricShapeEntityStatement::CImagingPhysicalEntityHasThreeDimensionGeometricShapeEntityStatement(CImagingPhysicalEntityHasThreeDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImagingPhysicalEntityHasThreeDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingPhysicalEntityHasThreeDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CImagingPhysicalEntityHasTwoDimensionGeometricShapeEntityStatement::CImagingPhysicalEntityHasTwoDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CImagingPhysicalEntityHasTwoDimensionGeometricShapeEntityStatement::CImagingPhysicalEntityHasTwoDimensionGeometricShapeEntityStatement(CImagingPhysicalEntityHasTwoDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CImagingPhysicalEntityHasTwoDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ImagingPhysicalEntityHasTwoDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CInferenceEntity::CInferenceEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
, imageEvidence(*this)	// "imageEvidence"
, isPresent(*this)	// "isPresent"
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, annotatorConfidence(*this)	// "annotatorConfidence"
, description(*this)	// "description"
, label(*this)	// "label"
, questionIndex(*this)	// "questionIndex"
, comment(*this)	// "comment"
{
}

CInferenceEntity::CInferenceEntity(CInferenceEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
, imageEvidence(*this)	// "imageEvidence"
, isPresent(*this)	// "isPresent"
, typeCode(*this)	// "typeCode"
, questionTypeCode(*this)	// "questionTypeCode"
, annotatorConfidence(*this)	// "annotatorConfidence"
, description(*this)	// "description"
, label(*this)	// "label"
, questionIndex(*this)	// "questionIndex"
, comment(*this)	// "comment"
{
}

void CInferenceEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("InferenceEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CInterval::CInterval(xercesc::DOMNode* const& node)
: ::AIMXML::CCharacteristicQuantification(node)
, minOperator(*this)	// "@minOperator"
, maxOperator(*this)	// "@maxOperator"
, minValue(*this)	// "minValue"
, maxValue(*this)	// "maxValue"
, ucumString(*this)	// "ucumString"
{
}

CInterval::CInterval(CInterval const& other)
: ::AIMXML::CCharacteristicQuantification(other.GetNode())
, minOperator(*this)	// "@minOperator"
, maxOperator(*this)	// "@maxOperator"
, minValue(*this)	// "minValue"
, maxValue(*this)	// "maxValue"
, ucumString(*this)	// "ucumString"
{
}

void CInterval::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Interval"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CLesionObservationEntity::CLesionObservationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
, lesionUniqueIdentifier(*this)	// "lesionUniqueIdentifier"
, isAdditionalObservation(*this)	// "isAdditionalObservation"
{
}

CLesionObservationEntity::CLesionObservationEntity(CLesionObservationEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
, lesionUniqueIdentifier(*this)	// "lesionUniqueIdentifier"
, isAdditionalObservation(*this)	// "isAdditionalObservation"
{
}

void CLesionObservationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LesionObservationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CMarkupEntity::CMarkupEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
{
}

CMarkupEntity::CMarkupEntity(CMarkupEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
{
}

void CMarkupEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("MarkupEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CNonQuantifiable::CNonQuantifiable(xercesc::DOMNode* const& node)
: ::AIMXML::CCharacteristicQuantification(node)
, typeCode(*this)	// "typeCode"
{
}

CNonQuantifiable::CNonQuantifiable(CNonQuantifiable const& other)
: ::AIMXML::CCharacteristicQuantification(other.GetNode())
, typeCode(*this)	// "typeCode"
{
}

void CNonQuantifiable::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NonQuantifiable"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CNumerical::CNumerical(xercesc::DOMNode* const& node)
: ::AIMXML::CCharacteristicQuantification(node)
, operator2(*this)	// "@operator"
, ucumString(*this)	// "ucumString"
, value2(*this)	// "value"
{
}

CNumerical::CNumerical(CNumerical const& other)
: ::AIMXML::CCharacteristicQuantification(other.GetNode())
, operator2(*this)	// "@operator"
, ucumString(*this)	// "ucumString"
, value2(*this)	// "value"
{
}

void CNumerical::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Numerical"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CParameter::CParameter(xercesc::DOMNode* const& node)
: TypeBase(node)
, name(*this)	// "name"
, value2(*this)	// "value"
, dataType(*this)	// "dataType"
{
}

CParameter::CParameter(CParameter const& other)
: TypeBase(other.GetNode())
, name(*this)	// "name"
, value2(*this)	// "value"
, dataType(*this)	// "dataType"
{
}

void CParameter::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Parameter"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CPerson::CPerson(xercesc::DOMNode* const& node)
: TypeBase(node)
, name(*this)	// "name"
, id(*this)	// "id"
, birthDate(*this)	// "birthDate"
, sex(*this)	// "sex"
, ethnicGroup(*this)	// "ethnicGroup"
{
}

CPerson::CPerson(CPerson const& other)
: TypeBase(other.GetNode())
, name(*this)	// "name"
, id(*this)	// "id"
, birthDate(*this)	// "birthDate"
, sex(*this)	// "sex"
, ethnicGroup(*this)	// "ethnicGroup"
{
}

void CPerson::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Person"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CQuantile::CQuantile(xercesc::DOMNode* const& node)
: ::AIMXML::CCharacteristicQuantification(node)
, bins(*this)	// "bins"
, selectedBin(*this)	// "selectedBin"
, minValue(*this)	// "minValue"
, maxValue(*this)	// "maxValue"
{
}

CQuantile::CQuantile(CQuantile const& other)
: ::AIMXML::CCharacteristicQuantification(other.GetNode())
, bins(*this)	// "bins"
, selectedBin(*this)	// "selectedBin"
, minValue(*this)	// "minValue"
, maxValue(*this)	// "maxValue"
{
}

void CQuantile::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Quantile"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CReferencedDicomObject::CReferencedDicomObject(xercesc::DOMNode* const& node)
: TypeBase(node)
, modality(*this)	// "modality"
, sopInstanceUid(*this)	// "sopInstanceUid"
{
}

CReferencedDicomObject::CReferencedDicomObject(CReferencedDicomObject const& other)
: TypeBase(other.GetNode())
, modality(*this)	// "modality"
, sopInstanceUid(*this)	// "sopInstanceUid"
{
}

void CReferencedDicomObject::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ReferencedDicomObject"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CScale::CScale(xercesc::DOMNode* const& node)
: ::AIMXML::CCharacteristicQuantification(node)
, type(*this)	// "@type"
, value2(*this)	// "value"
{
}

CScale::CScale(CScale const& other)
: ::AIMXML::CCharacteristicQuantification(other.GetNode())
, type(*this)	// "@type"
, value2(*this)	// "value"
{
}

void CScale::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Scale"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CScaleType::CScaleType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CScaleType::CScaleType(CScaleType const& other)
: TypeBase(other.GetNode())
{
}


CSegmentationEntity::CSegmentationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
{
}

CSegmentationEntity::CSegmentationEntity(CSegmentationEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
{
}

void CSegmentationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SegmentationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTaskContextEntity::CTaskContextEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CEntity(node)
, worklistTaskUid(*this)	// "worklistTaskUid"
, worklistTaskName(*this)	// "worklistTaskName"
, worklistTaskDescription(*this)	// "worklistTaskDescription"
, worklistTaskCategory(*this)	// "worklistTaskCategory"
, worklistTaskLevel(*this)	// "worklistTaskLevel"
, worklistTaskType(*this)	// "worklistTaskType"
, worklistTaskRepeatType(*this)	// "worklistTaskRepeatType"
, worklistTaskVariabilityType(*this)	// "worklistTaskVariabilityType"
, worklistTaskVersion(*this)	// "worklistTaskVersion"
, worklistSubtaskUid(*this)	// "worklistSubtaskUid"
, worklistSubtaskName(*this)	// "worklistSubtaskName"
, worklistSubtaskStartDateTime(*this)	// "worklistSubtaskStartDateTime"
, worklistSubtaskClosedDateTime(*this)	// "worklistSubtaskClosedDateTime"
, taskContextEntityCollection(*this)	// "taskContextEntityCollection"
{
}

CTaskContextEntity::CTaskContextEntity(CTaskContextEntity const& other)
: ::AIMXML::CEntity(other.GetNode())
, worklistTaskUid(*this)	// "worklistTaskUid"
, worklistTaskName(*this)	// "worklistTaskName"
, worklistTaskDescription(*this)	// "worklistTaskDescription"
, worklistTaskCategory(*this)	// "worklistTaskCategory"
, worklistTaskLevel(*this)	// "worklistTaskLevel"
, worklistTaskType(*this)	// "worklistTaskType"
, worklistTaskRepeatType(*this)	// "worklistTaskRepeatType"
, worklistTaskVariabilityType(*this)	// "worklistTaskVariabilityType"
, worklistTaskVersion(*this)	// "worklistTaskVersion"
, worklistSubtaskUid(*this)	// "worklistSubtaskUid"
, worklistSubtaskName(*this)	// "worklistSubtaskName"
, worklistSubtaskStartDateTime(*this)	// "worklistSubtaskStartDateTime"
, worklistSubtaskClosedDateTime(*this)	// "worklistSubtaskClosedDateTime"
, taskContextEntityCollection(*this)	// "taskContextEntityCollection"
{
}

void CTaskContextEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TaskContextEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTextAnnotationEntity::CTextAnnotationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CMarkupEntity(node)
, text(*this)	// "text"
, font(*this)	// "font"
, fontColor(*this)	// "fontColor"
, fontEffect(*this)	// "fontEffect"
, fontSize(*this)	// "fontSize"
, fontStyle(*this)	// "fontStyle"
, textJustify(*this)	// "textJustify"
, fontOpacity(*this)	// "fontOpacity"
, geometricShapeEntity(*this)	// "geometricShapeEntity"
{
}

CTextAnnotationEntity::CTextAnnotationEntity(CTextAnnotationEntity const& other)
: ::AIMXML::CMarkupEntity(other.GetNode())
, text(*this)	// "text"
, font(*this)	// "font"
, fontColor(*this)	// "fontColor"
, fontEffect(*this)	// "fontEffect"
, fontSize(*this)	// "fontSize"
, fontStyle(*this)	// "fontStyle"
, textJustify(*this)	// "textJustify"
, fontOpacity(*this)	// "fontOpacity"
, geometricShapeEntity(*this)	// "geometricShapeEntity"
{
}

void CTextAnnotationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TextAnnotationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionEllipse::CThreeDimensionEllipse(xercesc::DOMNode* const& node)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(node)
{
}

CThreeDimensionEllipse::CThreeDimensionEllipse(CThreeDimensionEllipse const& other)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(other.GetNode())
{
}

void CThreeDimensionEllipse::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionEllipse"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionEllipsoid::CThreeDimensionEllipsoid(xercesc::DOMNode* const& node)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(node)
{
}

CThreeDimensionEllipsoid::CThreeDimensionEllipsoid(CThreeDimensionEllipsoid const& other)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(other.GetNode())
{
}

void CThreeDimensionEllipsoid::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionEllipsoid"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionGeometricShapeEntity::CThreeDimensionGeometricShapeEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CGeometricShapeEntity(node)
, frameOfReferenceUid(*this)	// "frameOfReferenceUid"
, fiducialUid(*this)	// "fiducialUid"
, threeDimensionSpatialCoordinateCollection(*this)	// "threeDimensionSpatialCoordinateCollection"
{
}

CThreeDimensionGeometricShapeEntity::CThreeDimensionGeometricShapeEntity(CThreeDimensionGeometricShapeEntity const& other)
: ::AIMXML::CGeometricShapeEntity(other.GetNode())
, frameOfReferenceUid(*this)	// "frameOfReferenceUid"
, fiducialUid(*this)	// "fiducialUid"
, threeDimensionSpatialCoordinateCollection(*this)	// "threeDimensionSpatialCoordinateCollection"
{
}

void CThreeDimensionGeometricShapeEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionGeometricShapeEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement::CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement::CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement(CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionGeometricShapeEntityExcludesThreeDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionGeometricShapeEntityIsComprisedOfThreeDimensionGeometricShapeEntityStatement::CThreeDimensionGeometricShapeEntityIsComprisedOfThreeDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CThreeDimensionGeometricShapeEntityIsComprisedOfThreeDimensionGeometricShapeEntityStatement::CThreeDimensionGeometricShapeEntityIsComprisedOfThreeDimensionGeometricShapeEntityStatement(CThreeDimensionGeometricShapeEntityIsComprisedOfThreeDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CThreeDimensionGeometricShapeEntityIsComprisedOfThreeDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionGeometricShapeEntityIsComprisedOfThreeDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionMultiPoint::CThreeDimensionMultiPoint(xercesc::DOMNode* const& node)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(node)
{
}

CThreeDimensionMultiPoint::CThreeDimensionMultiPoint(CThreeDimensionMultiPoint const& other)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(other.GetNode())
{
}

void CThreeDimensionMultiPoint::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionMultiPoint"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionPoint::CThreeDimensionPoint(xercesc::DOMNode* const& node)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(node)
{
}

CThreeDimensionPoint::CThreeDimensionPoint(CThreeDimensionPoint const& other)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(other.GetNode())
{
}

void CThreeDimensionPoint::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionPoint"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionPolygon::CThreeDimensionPolygon(xercesc::DOMNode* const& node)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(node)
{
}

CThreeDimensionPolygon::CThreeDimensionPolygon(CThreeDimensionPolygon const& other)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(other.GetNode())
{
}

void CThreeDimensionPolygon::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionPolygon"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionPolyline::CThreeDimensionPolyline(xercesc::DOMNode* const& node)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(node)
{
}

CThreeDimensionPolyline::CThreeDimensionPolyline(CThreeDimensionPolyline const& other)
: ::AIMXML::CThreeDimensionGeometricShapeEntity(other.GetNode())
{
}

void CThreeDimensionPolyline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionPolyline"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CThreeDimensionSpatialCoordinate::CThreeDimensionSpatialCoordinate(xercesc::DOMNode* const& node)
: TypeBase(node)
, coordinateIndex(*this)	// "coordinateIndex"
, x(*this)	// "x"
, y(*this)	// "y"
, z(*this)	// "z"
{
}

CThreeDimensionSpatialCoordinate::CThreeDimensionSpatialCoordinate(CThreeDimensionSpatialCoordinate const& other)
: TypeBase(other.GetNode())
, coordinateIndex(*this)	// "coordinateIndex"
, x(*this)	// "x"
, y(*this)	// "y"
, z(*this)	// "z"
{
}

void CThreeDimensionSpatialCoordinate::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ThreeDimensionSpatialCoordinate"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTimePointLesionObservationEntityHasImagingPhysicalEntityStatement::CTimePointLesionObservationEntityHasImagingPhysicalEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CTimePointLesionObservationEntityHasImagingPhysicalEntityStatement::CTimePointLesionObservationEntityHasImagingPhysicalEntityStatement(CTimePointLesionObservationEntityHasImagingPhysicalEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CTimePointLesionObservationEntityHasImagingPhysicalEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TimePointLesionObservationEntityHasImagingPhysicalEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTimePointLesionObservationEntity::CTimePointLesionObservationEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CLesionObservationEntity(node)
, calibration(*this)	// "calibration"
, predecessorLesionTrackingUid(*this)	// "predecessorLesionTrackingUid"
, comment(*this)	// "comment"
, therapeuticResponse(*this)	// "therapeuticResponse"
, qualitativeAssessment(*this)	// "qualitativeAssessment"
, canEvaluateLesion(*this)	// "canEvaluateLesion"
, reasonUnableToEvaluate(*this)	// "reasonUnableToEvaluate"
, canMeasureLesion(*this)	// "canMeasureLesion"
, reasonUnableToMeasure(*this)	// "reasonUnableToMeasure"
, isUnequivocalProgression(*this)	// "isUnequivocalProgression"
{
}

CTimePointLesionObservationEntity::CTimePointLesionObservationEntity(CTimePointLesionObservationEntity const& other)
: ::AIMXML::CLesionObservationEntity(other.GetNode())
, calibration(*this)	// "calibration"
, predecessorLesionTrackingUid(*this)	// "predecessorLesionTrackingUid"
, comment(*this)	// "comment"
, therapeuticResponse(*this)	// "therapeuticResponse"
, qualitativeAssessment(*this)	// "qualitativeAssessment"
, canEvaluateLesion(*this)	// "canEvaluateLesion"
, reasonUnableToEvaluate(*this)	// "reasonUnableToEvaluate"
, canMeasureLesion(*this)	// "canMeasureLesion"
, reasonUnableToMeasure(*this)	// "reasonUnableToMeasure"
, isUnequivocalProgression(*this)	// "isUnequivocalProgression"
{
}

void CTimePointLesionObservationEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TimePointLesionObservationEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionCircle::CTwoDimensionCircle(xercesc::DOMNode* const& node)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(node)
{
}

CTwoDimensionCircle::CTwoDimensionCircle(CTwoDimensionCircle const& other)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(other.GetNode())
{
}

void CTwoDimensionCircle::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionCircle"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionEllipse::CTwoDimensionEllipse(xercesc::DOMNode* const& node)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(node)
{
}

CTwoDimensionEllipse::CTwoDimensionEllipse(CTwoDimensionEllipse const& other)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(other.GetNode())
{
}

void CTwoDimensionEllipse::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionEllipse"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionGeometricShapeEntity::CTwoDimensionGeometricShapeEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CGeometricShapeEntity(node)
, imageReferenceUid(*this)	// "imageReferenceUid"
, referencedFrameNumber(*this)	// "referencedFrameNumber"
, uri(*this)	// "uri"
, twoDimensionSpatialCoordinateCollection(*this)	// "twoDimensionSpatialCoordinateCollection"
{
}

CTwoDimensionGeometricShapeEntity::CTwoDimensionGeometricShapeEntity(CTwoDimensionGeometricShapeEntity const& other)
: ::AIMXML::CGeometricShapeEntity(other.GetNode())
, imageReferenceUid(*this)	// "imageReferenceUid"
, referencedFrameNumber(*this)	// "referencedFrameNumber"
, uri(*this)	// "uri"
, twoDimensionSpatialCoordinateCollection(*this)	// "twoDimensionSpatialCoordinateCollection"
{
}

void CTwoDimensionGeometricShapeEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionGeometricShapeEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionGeometricShapeEntityExcludesTwoDimensionGeometricShapeEntityStatement::CTwoDimensionGeometricShapeEntityExcludesTwoDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CTwoDimensionGeometricShapeEntityExcludesTwoDimensionGeometricShapeEntityStatement::CTwoDimensionGeometricShapeEntityExcludesTwoDimensionGeometricShapeEntityStatement(CTwoDimensionGeometricShapeEntityExcludesTwoDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CTwoDimensionGeometricShapeEntityExcludesTwoDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionGeometricShapeEntityExcludesTwoDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionGeometricShapeEntityIsComprisedOfTwoDimensionGeometricShapeEntityStatement::CTwoDimensionGeometricShapeEntityIsComprisedOfTwoDimensionGeometricShapeEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CTwoDimensionGeometricShapeEntityIsComprisedOfTwoDimensionGeometricShapeEntityStatement::CTwoDimensionGeometricShapeEntityIsComprisedOfTwoDimensionGeometricShapeEntityStatement(CTwoDimensionGeometricShapeEntityIsComprisedOfTwoDimensionGeometricShapeEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CTwoDimensionGeometricShapeEntityIsComprisedOfTwoDimensionGeometricShapeEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionGeometricShapeEntityIsComprisedOfTwoDimensionGeometricShapeEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionMultiPoint::CTwoDimensionMultiPoint(xercesc::DOMNode* const& node)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(node)
{
}

CTwoDimensionMultiPoint::CTwoDimensionMultiPoint(CTwoDimensionMultiPoint const& other)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(other.GetNode())
{
}

void CTwoDimensionMultiPoint::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionMultiPoint"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionPoint::CTwoDimensionPoint(xercesc::DOMNode* const& node)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(node)
{
}

CTwoDimensionPoint::CTwoDimensionPoint(CTwoDimensionPoint const& other)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(other.GetNode())
{
}

void CTwoDimensionPoint::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionPoint"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionPolyline::CTwoDimensionPolyline(xercesc::DOMNode* const& node)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(node)
{
}

CTwoDimensionPolyline::CTwoDimensionPolyline(CTwoDimensionPolyline const& other)
: ::AIMXML::CTwoDimensionGeometricShapeEntity(other.GetNode())
{
}

void CTwoDimensionPolyline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionPolyline"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CTwoDimensionSpatialCoordinate::CTwoDimensionSpatialCoordinate(xercesc::DOMNode* const& node)
: TypeBase(node)
, coordinateIndex(*this)	// "coordinateIndex"
, x(*this)	// "x"
, y(*this)	// "y"
{
}

CTwoDimensionSpatialCoordinate::CTwoDimensionSpatialCoordinate(CTwoDimensionSpatialCoordinate const& other)
: TypeBase(other.GetNode())
, coordinateIndex(*this)	// "coordinateIndex"
, x(*this)	// "x"
, y(*this)	// "y"
{
}

void CTwoDimensionSpatialCoordinate::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TwoDimensionSpatialCoordinate"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CUriImageReferenceEntity::CUriImageReferenceEntity(xercesc::DOMNode* const& node)
: ::AIMXML::CImageReferenceEntity(node)
, uri(*this)	// "uri"
, mimeType(*this)	// "mimeType"
{
}

CUriImageReferenceEntity::CUriImageReferenceEntity(CUriImageReferenceEntity const& other)
: ::AIMXML::CImageReferenceEntity(other.GetNode())
, uri(*this)	// "uri"
, mimeType(*this)	// "mimeType"
{
}

void CUriImageReferenceEntity::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UriImageReferenceEntity"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CUriImageReferenceEntityHasCalculationEntityStatement::CUriImageReferenceEntityHasCalculationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CUriImageReferenceEntityHasCalculationEntityStatement::CUriImageReferenceEntityHasCalculationEntityStatement(CUriImageReferenceEntityHasCalculationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CUriImageReferenceEntityHasCalculationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UriImageReferenceEntityHasCalculationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CUriImageReferenceEntityHasImagingObservationEntityStatement::CUriImageReferenceEntityHasImagingObservationEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CUriImageReferenceEntityHasImagingObservationEntityStatement::CUriImageReferenceEntityHasImagingObservationEntityStatement(CUriImageReferenceEntityHasImagingObservationEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CUriImageReferenceEntityHasImagingObservationEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UriImageReferenceEntityHasImagingObservationEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CUriImageReferenceEntityHasImagingPhysicalEntityStatement::CUriImageReferenceEntityHasImagingPhysicalEntityStatement(xercesc::DOMNode* const& node)
: ::AIMXML::CImageAnnotationStatement(node)
{
}

CUriImageReferenceEntityHasImagingPhysicalEntityStatement::CUriImageReferenceEntityHasImagingPhysicalEntityStatement(CUriImageReferenceEntityHasImagingPhysicalEntityStatement const& other)
: ::AIMXML::CImageAnnotationStatement(other.GetNode())
{
}

void CUriImageReferenceEntityHasImagingPhysicalEntityStatement::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UriImageReferenceEntityHasImagingPhysicalEntityStatement"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CUser::CUser(xercesc::DOMNode* const& node)
: TypeBase(node)
, name(*this)	// "name"
, loginName(*this)	// "loginName"
, roleInTrial(*this)	// "roleInTrial"
, numberWithinRoleOfClinicalTrial(*this)	// "numberWithinRoleOfClinicalTrial"
{
}

CUser::CUser(CUser const& other)
: TypeBase(other.GetNode())
, name(*this)	// "name"
, loginName(*this)	// "loginName"
, roleInTrial(*this)	// "roleInTrial"
, numberWithinRoleOfClinicalTrial(*this)	// "numberWithinRoleOfClinicalTrial"
{
}

void CUser::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("User"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAIMXML::CAIMXML(xercesc::DOMNode* const& node)
: TypeBase(node)
, AnnotationOfAnnotationCollection(*this)	// "AnnotationOfAnnotationCollection"
, ImageAnnotationCollection(*this)	// "ImageAnnotationCollection"
, br(*this)	// "br"
, caption(*this)	// "caption"
, col(*this)	// "col"
, colgroup(*this)	// "colgroup"
, content(*this)	// "content"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, item(*this)	// "item"
, linkHtml(*this)	// "linkHtml"
, list(*this)	// "list"
, paragraph(*this)	// "paragraph"
, renderMultiMedia(*this)	// "renderMultiMedia"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, table(*this)	// "table"
, tbody(*this)	// "tbody"
, td(*this)	// "td"
, text(*this)	// "text"
, tfoot(*this)	// "tfoot"
, th(*this)	// "th"
, thead(*this)	// "thead"
, tr(*this)	// "tr"
{
}

CAIMXML::CAIMXML(CAIMXML const& other)
: TypeBase(other.GetNode())
, AnnotationOfAnnotationCollection(*this)	// "AnnotationOfAnnotationCollection"
, ImageAnnotationCollection(*this)	// "ImageAnnotationCollection"
, br(*this)	// "br"
, caption(*this)	// "caption"
, col(*this)	// "col"
, colgroup(*this)	// "colgroup"
, content(*this)	// "content"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, item(*this)	// "item"
, linkHtml(*this)	// "linkHtml"
, list(*this)	// "list"
, paragraph(*this)	// "paragraph"
, renderMultiMedia(*this)	// "renderMultiMedia"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, table(*this)	// "table"
, tbody(*this)	// "tbody"
, td(*this)	// "td"
, text(*this)	// "text"
, tfoot(*this)	// "tfoot"
, th(*this)	// "th"
, thead(*this)	// "thead"
, tr(*this)	// "tr"
{
}

void CAIMXML::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AIMXML"), _T("gme://caCORE.caCORE/4.4/edu.northwestern.radiology.AIM"));
}

CAIMXML CAIMXML::LoadFromFile(const string_type& fileName)
{
	return CAIMXML(XercesTreeOperations::LoadDocument(fileName));
}

CAIMXML CAIMXML::LoadFromString(const string_type& text)
{
	return CAIMXML(XercesTreeOperations::LoadXml(text));
}

void CAIMXML::SaveToFile(const string_type& fileName, bool prettyPrint)
{
	XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, _T("UTF-8"), false, false);
}

void CAIMXML::SaveToFile(const string_type& fileName, bool prettyPrint, const string_type& encoding)
{
	std::vector<unsigned char> result;
    string_type sTmpEnc( encoding);
    std::transform( sTmpEnc.begin(), sTmpEnc.end(), sTmpEnc.begin(), _totupper);
	XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, encoding, _tcscmp(sTmpEnc.c_str(), _T("UTF-16BE")) == 0, _tcscmp(sTmpEnc.c_str(), _T("UTF-16")) == 0);
}

void CAIMXML::SaveToFile(const string_type& fileName, bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM)
{
	XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, encoding, bBigEndian, bBOM);
}

string_type CAIMXML::SaveToString(bool prettyPrint)
{
	return XercesTreeOperations::SaveXml(GetDocumentNode(), prettyPrint);
}

CAIMXML CAIMXML::CreateDocument()
{
	return XercesTreeOperations::CreateDocument();
}

void CAIMXML::DestroyDocument()
{
	XercesTreeOperations::DocumentType doc = GetDocumentNode();
	XercesTreeOperations::FreeDocument(doc);
	m_node = 0;
}

void CAIMXML::SetDTDLocation(const string_type& dtdLocation)
{

	xercesc::DOMDocument* document = (xercesc::DOMDocument*)GetNode();
	xercesc::DOMDocumentType* doctype = document->getDoctype();
	if (doctype != 0)
	{
		document->removeChild(doctype);
	}

	xercesc::DOMElement* rootElement = document->getDocumentElement();
	if (rootElement == 0)
		throw altova::InvalidOperationException(_T("You have to add a root element before setting DTD location."));

	doctype = document->createDocumentType(rootElement->getNodeName(), XercesStringTemp(_T("")), XercesStringTemp(dtdLocation));
	document->insertBefore(doctype, rootElement);

}

void CAIMXML::SetSchemaLocation(const string_type& schemaLocation)
{

	xercesc::DOMDocument* document = (xercesc::DOMDocument*)GetNode();
	xercesc::DOMElement* rootElement = document->getDocumentElement();
	if (rootElement == 0)
		throw altova::InvalidOperationException(_T("You have to add a root element before setting schema location."));

	string_type namespaceURI = XercesUnstringTemp(rootElement->getNamespaceURI());
	
	
	if (namespaceURI.empty())
		XercesTreeOperations::SetAttribute(rootElement, _T("xsi:noNamespaceSchemaLocation"), _T("http://www.w3.org/2001/XMLSchema-instance"), schemaLocation);
	else
		XercesTreeOperations::SetAttribute(rootElement, _T("xsi:schemaLocation"), _T("http://www.w3.org/2001/XMLSchema-instance"), namespaceURI + _T(" ") + schemaLocation);

}

CAIMXML CAIMXML::LoadFromBinary(const std::vector<unsigned char>& data)
{
	return XercesTreeOperations::LoadFromBinary(data);
}

std::vector<unsigned char> CAIMXML::SaveToBinary(bool prettyPrint)
{
	return XercesTreeOperations::SaveToBinary((XercesTreeOperations::DocumentType)GetNode(), prettyPrint);
}

std::vector<unsigned char> CAIMXML::SaveToBinary(bool prettyPrint, const string_type& encoding)
{
	std::vector<unsigned char> result;
    string_type sTmpEnc( encoding);
    std::transform( sTmpEnc.begin(), sTmpEnc.end(), sTmpEnc.begin(), _totupper);
	XercesTreeOperations::SaveToBinary(result, (XercesTreeOperations::DocumentType)GetNode(), prettyPrint, encoding, _tcscmp(sTmpEnc.c_str(), _T("UTF-16BE")) == 0, _tcscmp(sTmpEnc.c_str(), _T("UTF-16")) == 0);
	return result;
}

std::vector<unsigned char> CAIMXML::SaveToBinary(bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM)
{
	std::vector<unsigned char> result;
	XercesTreeOperations::SaveToBinary(result, (XercesTreeOperations::DocumentType)GetNode(), prettyPrint, encoding, bBigEndian, bBOM);
	return result;
}




CbrType::CbrType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CbrType::CbrType(CbrType const& other)
: TypeBase(other.GetNode())
{
}


CcaptionType::CcaptionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
{
}

CcaptionType::CcaptionType(CcaptionType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
{
}

void CcaptionType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
}

ClinkHtmlType::ClinkHtmlType(xercesc::DOMNode* const& node)
: TypeBase(node)
, name(*this)	// "@name"
, href(*this)	// "@href"
, rel(*this)	// "@rel"
, rev(*this)	// "@rev"
, title(*this)	// "@title"
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
{
}

ClinkHtmlType::ClinkHtmlType(ClinkHtmlType const& other)
: TypeBase(other.GetNode())
, name(*this)	// "@name"
, href(*this)	// "@href"
, rel(*this)	// "@rel"
, rev(*this)	// "@rev"
, title(*this)	// "@title"
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
{
}

void ClinkHtmlType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
}

CfootnoteType::CfootnoteType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, renderMultiMedia(*this)	// "renderMultiMedia"
, paragraph(*this)	// "paragraph"
, list(*this)	// "list"
, table(*this)	// "table"
{
}

CfootnoteType::CfootnoteType(CfootnoteType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, renderMultiMedia(*this)	// "renderMultiMedia"
, paragraph(*this)	// "paragraph"
, list(*this)	// "list"
, table(*this)	// "table"
{
}

void CfootnoteType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
}

CfootnoteRefType::CfootnoteRefType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, IDREF(*this)	// "@IDREF"
{
}

CfootnoteRefType::CfootnoteRefType(CfootnoteRefType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, IDREF(*this)	// "@IDREF"
{
}


CcolType::CcolType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, span(*this)	// "@span"
, width(*this)	// "@width"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
{
}

CcolType::CcolType(CcolType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, span(*this)	// "@span"
, width(*this)	// "@width"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
{
}


CalignType::CalignType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CalignType::CalignType(CalignType const& other)
: TypeBase(other.GetNode())
{
}


CvalignType::CvalignType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CvalignType::CvalignType(CvalignType const& other)
: TypeBase(other.GetNode())
{
}


CcolgroupType::CcolgroupType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, span(*this)	// "@span"
, width(*this)	// "@width"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, col(*this)	// "col"
{
}

CcolgroupType::CcolgroupType(CcolgroupType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, span(*this)	// "@span"
, width(*this)	// "@width"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, col(*this)	// "col"
{
}


CalignType2::CalignType2(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CalignType2::CalignType2(CalignType2 const& other)
: TypeBase(other.GetNode())
{
}


CvalignType2::CvalignType2(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CvalignType2::CvalignType2(CvalignType2 const& other)
: TypeBase(other.GetNode())
{
}


CcontentType::CcontentType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, revised(*this)	// "@revised"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
{
}

CcontentType::CcontentType(CcontentType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, revised(*this)	// "@revised"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
{
}

void CcontentType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
}

CrevisedType::CrevisedType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CrevisedType::CrevisedType(CrevisedType const& other)
: TypeBase(other.GetNode())
{
}


CrenderMultiMediaType::CrenderMultiMediaType(xercesc::DOMNode* const& node)
: TypeBase(node)
, referencedObject(*this)	// "@referencedObject"
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, caption(*this)	// "caption"
{
}

CrenderMultiMediaType::CrenderMultiMediaType(CrenderMultiMediaType const& other)
: TypeBase(other.GetNode())
, referencedObject(*this)	// "@referencedObject"
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, caption(*this)	// "caption"
{
}


CitemType::CitemType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, caption(*this)	// "caption"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
, paragraph(*this)	// "paragraph"
, list(*this)	// "list"
, table(*this)	// "table"
{
}

CitemType::CitemType(CitemType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, caption(*this)	// "caption"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
, paragraph(*this)	// "paragraph"
, list(*this)	// "list"
, table(*this)	// "table"
{
}

void CitemType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
}

CparagraphType::CparagraphType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, caption(*this)	// "caption"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
{
}

CparagraphType::CparagraphType(CparagraphType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, caption(*this)	// "caption"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
{
}

void CparagraphType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
}

ClistType::ClistType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, listType(*this)	// "@listType"
, caption(*this)	// "caption"
, item(*this)	// "item"
{
}

ClistType::ClistType(ClistType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, listType(*this)	// "@listType"
, caption(*this)	// "caption"
, item(*this)	// "item"
{
}


CtableType::CtableType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, summary(*this)	// "@summary"
, width(*this)	// "@width"
, border(*this)	// "@border"
, frame(*this)	// "@frame"
, rules(*this)	// "@rules"
, cellspacing(*this)	// "@cellspacing"
, cellpadding(*this)	// "@cellpadding"
, caption(*this)	// "caption"
, col(*this)	// "col"
, colgroup(*this)	// "colgroup"
, thead(*this)	// "thead"
, tfoot(*this)	// "tfoot"
, tbody(*this)	// "tbody"
{
}

CtableType::CtableType(CtableType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, summary(*this)	// "@summary"
, width(*this)	// "@width"
, border(*this)	// "@border"
, frame(*this)	// "@frame"
, rules(*this)	// "@rules"
, cellspacing(*this)	// "@cellspacing"
, cellpadding(*this)	// "@cellpadding"
, caption(*this)	// "caption"
, col(*this)	// "col"
, colgroup(*this)	// "colgroup"
, thead(*this)	// "thead"
, tfoot(*this)	// "tfoot"
, tbody(*this)	// "tbody"
{
}


CtbodyType::CtbodyType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, tr(*this)	// "tr"
{
}

CtbodyType::CtbodyType(CtbodyType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, tr(*this)	// "tr"
{
}


CalignType3::CalignType3(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CalignType3::CalignType3(CalignType3 const& other)
: TypeBase(other.GetNode())
{
}


CvalignType3::CvalignType3(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CvalignType3::CvalignType3(CvalignType3 const& other)
: TypeBase(other.GetNode())
{
}


CtrType::CtrType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, th(*this)	// "th"
, td(*this)	// "td"
{
}

CtrType::CtrType(CtrType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, th(*this)	// "th"
, td(*this)	// "td"
{
}


CtdType::CtdType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, abbr(*this)	// "@abbr"
, axis(*this)	// "@axis"
, headers(*this)	// "@headers"
, scope(*this)	// "@scope"
, rowspan(*this)	// "@rowspan"
, colspan(*this)	// "@colspan"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
, paragraph(*this)	// "paragraph"
, list(*this)	// "list"
{
}

CtdType::CtdType(CtdType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, abbr(*this)	// "@abbr"
, axis(*this)	// "@axis"
, headers(*this)	// "@headers"
, scope(*this)	// "@scope"
, rowspan(*this)	// "@rowspan"
, colspan(*this)	// "@colspan"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
, paragraph(*this)	// "paragraph"
, list(*this)	// "list"
{
}

void CtdType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
}

CscopeType::CscopeType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CscopeType::CscopeType(CscopeType const& other)
: TypeBase(other.GetNode())
{
}


CalignType4::CalignType4(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CalignType4::CalignType4(CalignType4 const& other)
: TypeBase(other.GetNode())
{
}


CvalignType4::CvalignType4(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CvalignType4::CvalignType4(CvalignType4 const& other)
: TypeBase(other.GetNode())
{
}


CtfootType::CtfootType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, tr(*this)	// "tr"
{
}

CtfootType::CtfootType(CtfootType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, tr(*this)	// "tr"
{
}


CalignType5::CalignType5(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CalignType5::CalignType5(CalignType5 const& other)
: TypeBase(other.GetNode())
{
}


CvalignType5::CvalignType5(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CvalignType5::CvalignType5(CvalignType5 const& other)
: TypeBase(other.GetNode())
{
}


CthType::CthType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, abbr(*this)	// "@abbr"
, axis(*this)	// "@axis"
, headers(*this)	// "@headers"
, scope(*this)	// "@scope"
, rowspan(*this)	// "@rowspan"
, colspan(*this)	// "@colspan"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
{
}

CthType::CthType(CthType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, abbr(*this)	// "@abbr"
, axis(*this)	// "@axis"
, headers(*this)	// "@headers"
, scope(*this)	// "@scope"
, rowspan(*this)	// "@rowspan"
, colspan(*this)	// "@colspan"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
{
}

void CthType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
}

CscopeType2::CscopeType2(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CscopeType2::CscopeType2(CscopeType2 const& other)
: TypeBase(other.GetNode())
{
}


CalignType6::CalignType6(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CalignType6::CalignType6(CalignType6 const& other)
: TypeBase(other.GetNode())
{
}


CvalignType6::CvalignType6(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CvalignType6::CvalignType6(CvalignType6 const& other)
: TypeBase(other.GetNode())
{
}


CtheadType::CtheadType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, tr(*this)	// "tr"
{
}

CtheadType::CtheadType(CtheadType const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, language(*this)	// "@language"
, styleCode(*this)	// "@styleCode"
, align(*this)	// "@align"
, char2(*this)	// "@char"
, charoff(*this)	// "@charoff"
, valign(*this)	// "@valign"
, tr(*this)	// "tr"
{
}


CalignType7::CalignType7(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CalignType7::CalignType7(CalignType7 const& other)
: TypeBase(other.GetNode())
{
}


CvalignType7::CvalignType7(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CvalignType7::CvalignType7(CvalignType7 const& other)
: TypeBase(other.GetNode())
{
}


CparameterCollectionType::CparameterCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, Parameter(*this)	// "Parameter"
{
}

CparameterCollectionType::CparameterCollectionType(CparameterCollectionType const& other)
: TypeBase(other.GetNode())
, Parameter(*this)	// "Parameter"
{
}


CauditTrailCollectionType::CauditTrailCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, AuditTrail(*this)	// "AuditTrail"
{
}

CauditTrailCollectionType::CauditTrailCollectionType(CauditTrailCollectionType const& other)
: TypeBase(other.GetNode())
, AuditTrail(*this)	// "AuditTrail"
{
}


CimagingPhysicalEntityCollectionType::CimagingPhysicalEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ImagingPhysicalEntity(*this)	// "ImagingPhysicalEntity"
{
}

CimagingPhysicalEntityCollectionType::CimagingPhysicalEntityCollectionType(CimagingPhysicalEntityCollectionType const& other)
: TypeBase(other.GetNode())
, ImagingPhysicalEntity(*this)	// "ImagingPhysicalEntity"
{
}


CcalculationEntityCollectionType::CcalculationEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, CalculationEntity(*this)	// "CalculationEntity"
{
}

CcalculationEntityCollectionType::CcalculationEntityCollectionType(CcalculationEntityCollectionType const& other)
: TypeBase(other.GetNode())
, CalculationEntity(*this)	// "CalculationEntity"
{
}


CinferenceEntityCollectionType::CinferenceEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, InferenceEntity(*this)	// "InferenceEntity"
{
}

CinferenceEntityCollectionType::CinferenceEntityCollectionType(CinferenceEntityCollectionType const& other)
: TypeBase(other.GetNode())
, InferenceEntity(*this)	// "InferenceEntity"
{
}


CannotationRoleEntityCollectionType::CannotationRoleEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, AnnotationRoleEntity(*this)	// "AnnotationRoleEntity"
{
}

CannotationRoleEntityCollectionType::CannotationRoleEntityCollectionType(CannotationRoleEntityCollectionType const& other)
: TypeBase(other.GetNode())
, AnnotationRoleEntity(*this)	// "AnnotationRoleEntity"
{
}


ClesionObservationEntityCollectionType::ClesionObservationEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, LesionObservationEntity(*this)	// "LesionObservationEntity"
{
}

ClesionObservationEntityCollectionType::ClesionObservationEntityCollectionType(ClesionObservationEntityCollectionType const& other)
: TypeBase(other.GetNode())
, LesionObservationEntity(*this)	// "LesionObservationEntity"
{
}


CimagingObservationEntityCollectionType::CimagingObservationEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ImagingObservationEntity(*this)	// "ImagingObservationEntity"
{
}

CimagingObservationEntityCollectionType::CimagingObservationEntityCollectionType(CimagingObservationEntityCollectionType const& other)
: TypeBase(other.GetNode())
, ImagingObservationEntity(*this)	// "ImagingObservationEntity"
{
}


CtaskContextEntityCollectionType::CtaskContextEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, TaskContextEntity(*this)	// "TaskContextEntity"
{
}

CtaskContextEntityCollectionType::CtaskContextEntityCollectionType(CtaskContextEntityCollectionType const& other)
: TypeBase(other.GetNode())
, TaskContextEntity(*this)	// "TaskContextEntity"
{
}


CannotationOfAnnotationStatementCollectionType::CannotationOfAnnotationStatementCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, AnnotationOfAnnotationStatement(*this)	// "AnnotationOfAnnotationStatement"
{
}

CannotationOfAnnotationStatementCollectionType::CannotationOfAnnotationStatementCollectionType(CannotationOfAnnotationStatementCollectionType const& other)
: TypeBase(other.GetNode())
, AnnotationOfAnnotationStatement(*this)	// "AnnotationOfAnnotationStatement"
{
}


CannotationOfAnnotationsType::CannotationOfAnnotationsType(xercesc::DOMNode* const& node)
: TypeBase(node)
, AnnotationOfAnnotation(*this)	// "AnnotationOfAnnotation"
{
}

CannotationOfAnnotationsType::CannotationOfAnnotationsType(CannotationOfAnnotationsType const& other)
: TypeBase(other.GetNode())
, AnnotationOfAnnotation(*this)	// "AnnotationOfAnnotation"
{
}


CcoordinateCollectionType::CcoordinateCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, Coordinate(*this)	// "Coordinate"
{
}

CcoordinateCollectionType::CcoordinateCollectionType(CcoordinateCollectionType const& other)
: TypeBase(other.GetNode())
, Coordinate(*this)	// "Coordinate"
{
}


CcalculationResultCollectionType::CcalculationResultCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, CalculationResult(*this)	// "CalculationResult"
{
}

CcalculationResultCollectionType::CcalculationResultCollectionType(CcalculationResultCollectionType const& other)
: TypeBase(other.GetNode())
, CalculationResult(*this)	// "CalculationResult"
{
}


CdimensionCollectionType::CdimensionCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, Dimension(*this)	// "Dimension"
{
}

CdimensionCollectionType::CdimensionCollectionType(CdimensionCollectionType const& other)
: TypeBase(other.GetNode())
, Dimension(*this)	// "Dimension"
{
}


CcalculationDataCollectionType::CcalculationDataCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, CalculationData(*this)	// "CalculationData"
{
}

CcalculationDataCollectionType::CcalculationDataCollectionType(CcalculationDataCollectionType const& other)
: TypeBase(other.GetNode())
, CalculationData(*this)	// "CalculationData"
{
}


CsegmentationEntityCollectionType::CsegmentationEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, SegmentationEntity(*this)	// "SegmentationEntity"
{
}

CsegmentationEntityCollectionType::CsegmentationEntityCollectionType(CsegmentationEntityCollectionType const& other)
: TypeBase(other.GetNode())
, SegmentationEntity(*this)	// "SegmentationEntity"
{
}


CmarkupEntityCollectionType::CmarkupEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, MarkupEntity(*this)	// "MarkupEntity"
{
}

CmarkupEntityCollectionType::CmarkupEntityCollectionType(CmarkupEntityCollectionType const& other)
: TypeBase(other.GetNode())
, MarkupEntity(*this)	// "MarkupEntity"
{
}


CimageAnnotationStatementCollectionType::CimageAnnotationStatementCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ImageAnnotationStatement(*this)	// "ImageAnnotationStatement"
{
}

CimageAnnotationStatementCollectionType::CimageAnnotationStatementCollectionType(CimageAnnotationStatementCollectionType const& other)
: TypeBase(other.GetNode())
, ImageAnnotationStatement(*this)	// "ImageAnnotationStatement"
{
}


CimageReferenceEntityCollectionType::CimageReferenceEntityCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ImageReferenceEntity(*this)	// "ImageReferenceEntity"
{
}

CimageReferenceEntityCollectionType::CimageReferenceEntityCollectionType(CimageReferenceEntityCollectionType const& other)
: TypeBase(other.GetNode())
, ImageReferenceEntity(*this)	// "ImageReferenceEntity"
{
}


CimageAnnotationsType::CimageAnnotationsType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ImageAnnotation(*this)	// "ImageAnnotation"
{
}

CimageAnnotationsType::CimageAnnotationsType(CimageAnnotationsType const& other)
: TypeBase(other.GetNode())
, ImageAnnotation(*this)	// "ImageAnnotation"
{
}


CimageCollectionType::CimageCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, Image(*this)	// "Image"
{
}

CimageCollectionType::CimageCollectionType(CimageCollectionType const& other)
: TypeBase(other.GetNode())
, Image(*this)	// "Image"
{
}


CreferencedDicomObjectCollectionType::CreferencedDicomObjectCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ReferencedDicomObject(*this)	// "ReferencedDicomObject"
{
}

CreferencedDicomObjectCollectionType::CreferencedDicomObjectCollectionType(CreferencedDicomObjectCollectionType const& other)
: TypeBase(other.GetNode())
, ReferencedDicomObject(*this)	// "ReferencedDicomObject"
{
}


CcharacteristicQuantificationCollectionType::CcharacteristicQuantificationCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, CharacteristicQuantification(*this)	// "CharacteristicQuantification"
{
}

CcharacteristicQuantificationCollectionType::CcharacteristicQuantificationCollectionType(CcharacteristicQuantificationCollectionType const& other)
: TypeBase(other.GetNode())
, CharacteristicQuantification(*this)	// "CharacteristicQuantification"
{
}


CimagingObservationCharacteristicCollectionType::CimagingObservationCharacteristicCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ImagingObservationCharacteristic(*this)	// "ImagingObservationCharacteristic"
{
}

CimagingObservationCharacteristicCollectionType::CimagingObservationCharacteristicCollectionType(CimagingObservationCharacteristicCollectionType const& other)
: TypeBase(other.GetNode())
, ImagingObservationCharacteristic(*this)	// "ImagingObservationCharacteristic"
{
}


CimagingPhysicalEntityCharacteristicCollectionType::CimagingPhysicalEntityCharacteristicCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ImagingPhysicalEntityCharacteristic(*this)	// "ImagingPhysicalEntityCharacteristic"
{
}

CimagingPhysicalEntityCharacteristicCollectionType::CimagingPhysicalEntityCharacteristicCollectionType(CimagingPhysicalEntityCharacteristicCollectionType const& other)
: TypeBase(other.GetNode())
, ImagingPhysicalEntityCharacteristic(*this)	// "ImagingPhysicalEntityCharacteristic"
{
}


CimagingObservationCharacteristicCollectionType2::CimagingObservationCharacteristicCollectionType2(xercesc::DOMNode* const& node)
: TypeBase(node)
, ImagingObservationCharacteristic(*this)	// "ImagingObservationCharacteristic"
{
}

CimagingObservationCharacteristicCollectionType2::CimagingObservationCharacteristicCollectionType2(CimagingObservationCharacteristicCollectionType2 const& other)
: TypeBase(other.GetNode())
, ImagingObservationCharacteristic(*this)	// "ImagingObservationCharacteristic"
{
}


CcharacteristicQuantificationCollectionType2::CcharacteristicQuantificationCollectionType2(xercesc::DOMNode* const& node)
: TypeBase(node)
, CharacteristicQuantification(*this)	// "CharacteristicQuantification"
{
}

CcharacteristicQuantificationCollectionType2::CcharacteristicQuantificationCollectionType2(CcharacteristicQuantificationCollectionType2 const& other)
: TypeBase(other.GetNode())
, CharacteristicQuantification(*this)	// "CharacteristicQuantification"
{
}


CtaskContextEntityCollectionType2::CtaskContextEntityCollectionType2(xercesc::DOMNode* const& node)
: TypeBase(node)
, TaskContextEntity(*this)	// "TaskContextEntity"
{
}

CtaskContextEntityCollectionType2::CtaskContextEntityCollectionType2(CtaskContextEntityCollectionType2 const& other)
: TypeBase(other.GetNode())
, TaskContextEntity(*this)	// "TaskContextEntity"
{
}


CthreeDimensionSpatialCoordinateCollectionType::CthreeDimensionSpatialCoordinateCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, ThreeDimensionSpatialCoordinate(*this)	// "ThreeDimensionSpatialCoordinate"
{
}

CthreeDimensionSpatialCoordinateCollectionType::CthreeDimensionSpatialCoordinateCollectionType(CthreeDimensionSpatialCoordinateCollectionType const& other)
: TypeBase(other.GetNode())
, ThreeDimensionSpatialCoordinate(*this)	// "ThreeDimensionSpatialCoordinate"
{
}


CtwoDimensionSpatialCoordinateCollectionType::CtwoDimensionSpatialCoordinateCollectionType(xercesc::DOMNode* const& node)
: TypeBase(node)
, TwoDimensionSpatialCoordinate(*this)	// "TwoDimensionSpatialCoordinate"
{
}

CtwoDimensionSpatialCoordinateCollectionType::CtwoDimensionSpatialCoordinateCollectionType(CtwoDimensionSpatialCoordinateCollectionType const& other)
: TypeBase(other.GetNode())
, TwoDimensionSpatialCoordinate(*this)	// "TwoDimensionSpatialCoordinate"
{
}


ClistTypeType::ClistTypeType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

ClistTypeType::ClistTypeType(ClistTypeType const& other)
: TypeBase(other.GetNode())
{
}


CframeType::CframeType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CframeType::CframeType(CframeType const& other)
: TypeBase(other.GetNode())
{
}


CrulesType::CrulesType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CrulesType::CrulesType(CrulesType const& other)
: TypeBase(other.GetNode())
{
}


CalignType8::CalignType8(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CalignType8::CalignType8(CalignType8 const& other)
: TypeBase(other.GetNode())
{
}


CvalignType8::CvalignType8(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CvalignType8::CvalignType8(CvalignType8 const& other)
: TypeBase(other.GetNode())
{
}


namespace xs
{	

CENTITIES::CENTITIES(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CENTITIES::CENTITIES(CENTITIES const& other)
: TypeBase(other.GetNode())
{
}


CENTITY::CENTITY(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CENTITY::CENTITY(CENTITY const& other)
: TypeBase(other.GetNode())
{
}


CID::CID(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CID::CID(CID const& other)
: TypeBase(other.GetNode())
{
}


CIDREF::CIDREF(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CIDREF::CIDREF(CIDREF const& other)
: TypeBase(other.GetNode())
{
}


CIDREFS::CIDREFS(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CIDREFS::CIDREFS(CIDREFS const& other)
: TypeBase(other.GetNode())
{
}


CNCName::CNCName(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CNCName::CNCName(CNCName const& other)
: TypeBase(other.GetNode())
{
}


CNMTOKEN::CNMTOKEN(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CNMTOKEN::CNMTOKEN(CNMTOKEN const& other)
: TypeBase(other.GetNode())
{
}


CNMTOKENS::CNMTOKENS(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CNMTOKENS::CNMTOKENS(CNMTOKENS const& other)
: TypeBase(other.GetNode())
{
}


CNOTATION::CNOTATION(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CNOTATION::CNOTATION(CNOTATION const& other)
: TypeBase(other.GetNode())
{
}


CName::CName(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CName::CName(CName const& other)
: TypeBase(other.GetNode())
{
}


CQName::CQName(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CQName::CQName(CQName const& other)
: TypeBase(other.GetNode())
{
}


CanySimpleType::CanySimpleType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CanySimpleType::CanySimpleType(CanySimpleType const& other)
: TypeBase(other.GetNode())
{
}


CanyType::CanyType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CanyType::CanyType(CanyType const& other)
: TypeBase(other.GetNode())
{
}

void CanyType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("anyType"), _T("http://www.w3.org/2001/XMLSchema"));
}

CanyURI::CanyURI(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CanyURI::CanyURI(CanyURI const& other)
: TypeBase(other.GetNode())
{
}


Cbase64Binary::Cbase64Binary(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cbase64Binary::Cbase64Binary(Cbase64Binary const& other)
: TypeBase(other.GetNode())
{
}


Cboolean::Cboolean(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cboolean::Cboolean(Cboolean const& other)
: TypeBase(other.GetNode())
{
}


Cbyte::Cbyte(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cbyte::Cbyte(Cbyte const& other)
: TypeBase(other.GetNode())
{
}


Cdate::Cdate(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cdate::Cdate(Cdate const& other)
: TypeBase(other.GetNode())
{
}


CdateTime::CdateTime(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CdateTime::CdateTime(CdateTime const& other)
: TypeBase(other.GetNode())
{
}


Cdecimal::Cdecimal(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cdecimal::Cdecimal(Cdecimal const& other)
: TypeBase(other.GetNode())
{
}


Cdouble::Cdouble(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cdouble::Cdouble(Cdouble const& other)
: TypeBase(other.GetNode())
{
}


Cduration::Cduration(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cduration::Cduration(Cduration const& other)
: TypeBase(other.GetNode())
{
}


Cfloat::Cfloat(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cfloat::Cfloat(Cfloat const& other)
: TypeBase(other.GetNode())
{
}


CgDay::CgDay(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CgDay::CgDay(CgDay const& other)
: TypeBase(other.GetNode())
{
}


CgMonth::CgMonth(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CgMonth::CgMonth(CgMonth const& other)
: TypeBase(other.GetNode())
{
}


CgMonthDay::CgMonthDay(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CgMonthDay::CgMonthDay(CgMonthDay const& other)
: TypeBase(other.GetNode())
{
}


CgYear::CgYear(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CgYear::CgYear(CgYear const& other)
: TypeBase(other.GetNode())
{
}


CgYearMonth::CgYearMonth(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CgYearMonth::CgYearMonth(CgYearMonth const& other)
: TypeBase(other.GetNode())
{
}


ChexBinary::ChexBinary(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

ChexBinary::ChexBinary(ChexBinary const& other)
: TypeBase(other.GetNode())
{
}


Cint::Cint(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cint::Cint(Cint const& other)
: TypeBase(other.GetNode())
{
}


Cinteger::Cinteger(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cinteger::Cinteger(Cinteger const& other)
: TypeBase(other.GetNode())
{
}


Clanguage::Clanguage(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Clanguage::Clanguage(Clanguage const& other)
: TypeBase(other.GetNode())
{
}


Clong::Clong(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Clong::Clong(Clong const& other)
: TypeBase(other.GetNode())
{
}


CnegativeInteger::CnegativeInteger(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CnegativeInteger::CnegativeInteger(CnegativeInteger const& other)
: TypeBase(other.GetNode())
{
}


CnonNegativeInteger::CnonNegativeInteger(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CnonNegativeInteger::CnonNegativeInteger(CnonNegativeInteger const& other)
: TypeBase(other.GetNode())
{
}


CnonPositiveInteger::CnonPositiveInteger(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CnonPositiveInteger::CnonPositiveInteger(CnonPositiveInteger const& other)
: TypeBase(other.GetNode())
{
}


CnormalizedString::CnormalizedString(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CnormalizedString::CnormalizedString(CnormalizedString const& other)
: TypeBase(other.GetNode())
{
}


CpositiveInteger::CpositiveInteger(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CpositiveInteger::CpositiveInteger(CpositiveInteger const& other)
: TypeBase(other.GetNode())
{
}


Cshort::Cshort(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cshort::Cshort(Cshort const& other)
: TypeBase(other.GetNode())
{
}


Cstring::Cstring(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cstring::Cstring(Cstring const& other)
: TypeBase(other.GetNode())
{
}


Ctime::Ctime(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Ctime::Ctime(Ctime const& other)
: TypeBase(other.GetNode())
{
}


Ctoken::Ctoken(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Ctoken::Ctoken(Ctoken const& other)
: TypeBase(other.GetNode())
{
}


CunsignedByte::CunsignedByte(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CunsignedByte::CunsignedByte(CunsignedByte const& other)
: TypeBase(other.GetNode())
{
}


CunsignedInt::CunsignedInt(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CunsignedInt::CunsignedInt(CunsignedInt const& other)
: TypeBase(other.GetNode())
{
}


CunsignedLong::CunsignedLong(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CunsignedLong::CunsignedLong(CunsignedLong const& other)
: TypeBase(other.GetNode())
{
}


CunsignedShort::CunsignedShort(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CunsignedShort::CunsignedShort(CunsignedShort const& other)
: TypeBase(other.GetNode())
{
}


CstringType::CstringType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CstringType::CstringType(CstringType const& other)
: TypeBase(other.GetNode())
{
}

void CstringType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("string"), _T("http://www.w3.org/2001/XMLSchema"));
}

Cbase64BinaryType::Cbase64BinaryType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cbase64BinaryType::Cbase64BinaryType(Cbase64BinaryType const& other)
: TypeBase(other.GetNode())
{
}

void Cbase64BinaryType::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("base64Binary"), _T("http://www.w3.org/2001/XMLSchema"));
}

} // namespace xs


namespace iso
{	

CAD::CAD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, use(*this)	// "@use"
, isNotOrdered(*this)	// "@isNotOrdered"
, part(*this)	// "part"
, useablePeriod(*this)	// "useablePeriod"
{
}

CAD::CAD(CAD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, use(*this)	// "@use"
, isNotOrdered(*this)	// "@isNotOrdered"
, part(*this)	// "part"
, useablePeriod(*this)	// "useablePeriod"
{
}

void CAD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("AD"), _T("uri:iso.org:21090"));
}

CADXP::CADXP(xercesc::DOMNode* const& node)
: TypeBase(node)
, value2(*this)	// "@value"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, type(*this)	// "@type"
{
}

CADXP::CADXP(CADXP const& other)
: TypeBase(other.GetNode())
, value2(*this)	// "@value"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, type(*this)	// "@type"
{
}

void CADXP::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ADXP"), _T("uri:iso.org:21090"));
}

CANY::CANY(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CHXIT(node)
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
{
}

CANY::CANY(CANY const& other)
: ::AIMXML::iso::CHXIT(other.GetNode())
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
{
}

void CANY::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ANY"), _T("uri:iso.org:21090"));
}

CAddressPartType::CAddressPartType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CAddressPartType::CAddressPartType(CAddressPartType const& other)
: TypeBase(other.GetNode())
{
}


CBAG_AD::CBAG_AD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_AD(node)
, item(*this)	// "item"
{
}

CBAG_AD::CBAG_AD(CBAG_AD const& other)
: ::AIMXML::iso::CCOLL_AD(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_AD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_AD"), _T("uri:iso.org:21090"));
}

CBAG_BL::CBAG_BL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_BL(node)
, item(*this)	// "item"
{
}

CBAG_BL::CBAG_BL(CBAG_BL const& other)
: ::AIMXML::iso::CCOLL_BL(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_BL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_BL"), _T("uri:iso.org:21090"));
}

CBAG_BL_NonNull::CBAG_BL_NonNull(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_BL_NonNull(node)
, item(*this)	// "item"
{
}

CBAG_BL_NonNull::CBAG_BL_NonNull(CBAG_BL_NonNull const& other)
: ::AIMXML::iso::CCOLL_BL_NonNull(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_BL_NonNull::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_BL.NonNull"), _T("uri:iso.org:21090"));
}

CBAG_CD::CBAG_CD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CD(node)
, item(*this)	// "item"
{
}

CBAG_CD::CBAG_CD(CBAG_CD const& other)
: ::AIMXML::iso::CCOLL_CD(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_CD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_CD"), _T("uri:iso.org:21090"));
}

CBAG_CD_CE::CBAG_CD_CE(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CD_CE(node)
, item(*this)	// "item"
{
}

CBAG_CD_CE::CBAG_CD_CE(CBAG_CD_CE const& other)
: ::AIMXML::iso::CCOLL_CD_CE(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_CD_CE::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_CD.CE"), _T("uri:iso.org:21090"));
}

CBAG_CD_CE_None::CBAG_CD_CE_None(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CD_CE_None(node)
, item(*this)	// "item"
{
}

CBAG_CD_CE_None::CBAG_CD_CE_None(CBAG_CD_CE_None const& other)
: ::AIMXML::iso::CCOLL_CD_CE_None(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_CD_CE_None::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_CD.CE.None"), _T("uri:iso.org:21090"));
}

CBAG_CD_CV::CBAG_CD_CV(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CD_CV(node)
, item(*this)	// "item"
{
}

CBAG_CD_CV::CBAG_CD_CV(CBAG_CD_CV const& other)
: ::AIMXML::iso::CCOLL_CD_CV(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_CD_CV::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_CD.CV"), _T("uri:iso.org:21090"));
}

CBAG_CO::CBAG_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CO(node)
, item(*this)	// "item"
{
}

CBAG_CO::CBAG_CO(CBAG_CO const& other)
: ::AIMXML::iso::CCOLL_CO(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_CO"), _T("uri:iso.org:21090"));
}

CBAG_CS::CBAG_CS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CS(node)
, item(*this)	// "item"
{
}

CBAG_CS::CBAG_CS(CBAG_CS const& other)
: ::AIMXML::iso::CCOLL_CS(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_CS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_CS"), _T("uri:iso.org:21090"));
}

CBAG_ED::CBAG_ED(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED(node)
, item(*this)	// "item"
{
}

CBAG_ED::CBAG_ED(CBAG_ED const& other)
: ::AIMXML::iso::CCOLL_ED(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ED::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ED"), _T("uri:iso.org:21090"));
}

CBAG_ED_Doc::CBAG_ED_Doc(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Doc(node)
, item(*this)	// "item"
{
}

CBAG_ED_Doc::CBAG_ED_Doc(CBAG_ED_Doc const& other)
: ::AIMXML::iso::CCOLL_ED_Doc(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ED_Doc::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ED.Doc"), _T("uri:iso.org:21090"));
}

CBAG_ED_Doc_Inline::CBAG_ED_Doc_Inline(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Doc_Inline(node)
, item(*this)	// "item"
{
}

CBAG_ED_Doc_Inline::CBAG_ED_Doc_Inline(CBAG_ED_Doc_Inline const& other)
: ::AIMXML::iso::CCOLL_ED_Doc_Inline(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ED_Doc_Inline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ED.Doc.Inline"), _T("uri:iso.org:21090"));
}

CBAG_ED_Doc_Ref::CBAG_ED_Doc_Ref(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Doc_Ref(node)
, item(*this)	// "item"
{
}

CBAG_ED_Doc_Ref::CBAG_ED_Doc_Ref(CBAG_ED_Doc_Ref const& other)
: ::AIMXML::iso::CCOLL_ED_Doc_Ref(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ED_Doc_Ref::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ED.Doc.Ref"), _T("uri:iso.org:21090"));
}

CBAG_ED_Image::CBAG_ED_Image(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Image(node)
, item(*this)	// "item"
{
}

CBAG_ED_Image::CBAG_ED_Image(CBAG_ED_Image const& other)
: ::AIMXML::iso::CCOLL_ED_Image(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ED_Image::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ED.Image"), _T("uri:iso.org:21090"));
}

CBAG_ED_Narrative::CBAG_ED_Narrative(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Narrative(node)
, item(*this)	// "item"
{
}

CBAG_ED_Narrative::CBAG_ED_Narrative(CBAG_ED_Narrative const& other)
: ::AIMXML::iso::CCOLL_ED_Narrative(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ED_Narrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ED.Narrative"), _T("uri:iso.org:21090"));
}

CBAG_ED_Signature::CBAG_ED_Signature(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Signature(node)
, item(*this)	// "item"
{
}

CBAG_ED_Signature::CBAG_ED_Signature(CBAG_ED_Signature const& other)
: ::AIMXML::iso::CCOLL_ED_Signature(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ED_Signature::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ED.Signature"), _T("uri:iso.org:21090"));
}

CBAG_ED_Text::CBAG_ED_Text(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Text(node)
, item(*this)	// "item"
{
}

CBAG_ED_Text::CBAG_ED_Text(CBAG_ED_Text const& other)
: ::AIMXML::iso::CCOLL_ED_Text(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ED_Text::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ED.Text"), _T("uri:iso.org:21090"));
}

CBAG_EN::CBAG_EN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_EN(node)
, item(*this)	// "item"
{
}

CBAG_EN::CBAG_EN(CBAG_EN const& other)
: ::AIMXML::iso::CCOLL_EN(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_EN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_EN"), _T("uri:iso.org:21090"));
}

CBAG_EN_ON::CBAG_EN_ON(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_EN_ON(node)
, item(*this)	// "item"
{
}

CBAG_EN_ON::CBAG_EN_ON(CBAG_EN_ON const& other)
: ::AIMXML::iso::CCOLL_EN_ON(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_EN_ON::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_EN.ON"), _T("uri:iso.org:21090"));
}

CBAG_EN_PN::CBAG_EN_PN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_EN_PN(node)
, item(*this)	// "item"
{
}

CBAG_EN_PN::CBAG_EN_PN(CBAG_EN_PN const& other)
: ::AIMXML::iso::CCOLL_EN_PN(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_EN_PN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_EN.PN"), _T("uri:iso.org:21090"));
}

CBAG_EN_TN::CBAG_EN_TN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_EN_TN(node)
, item(*this)	// "item"
{
}

CBAG_EN_TN::CBAG_EN_TN(CBAG_EN_TN const& other)
: ::AIMXML::iso::CCOLL_EN_TN(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_EN_TN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_EN.TN"), _T("uri:iso.org:21090"));
}

CBAG_II::CBAG_II(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_II(node)
, item(*this)	// "item"
{
}

CBAG_II::CBAG_II(CBAG_II const& other)
: ::AIMXML::iso::CCOLL_II(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_II::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_II"), _T("uri:iso.org:21090"));
}

CBAG_INT::CBAG_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_INT(node)
, item(*this)	// "item"
{
}

CBAG_INT::CBAG_INT(CBAG_INT const& other)
: ::AIMXML::iso::CCOLL_INT(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_INT"), _T("uri:iso.org:21090"));
}

CBAG_INT_NonNeg::CBAG_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_INT_NonNeg(node)
, item(*this)	// "item"
{
}

CBAG_INT_NonNeg::CBAG_INT_NonNeg(CBAG_INT_NonNeg const& other)
: ::AIMXML::iso::CCOLL_INT_NonNeg(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CBAG_INT_Positive::CBAG_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_INT_Positive(node)
, item(*this)	// "item"
{
}

CBAG_INT_Positive::CBAG_INT_Positive(CBAG_INT_Positive const& other)
: ::AIMXML::iso::CCOLL_INT_Positive(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_INT.Positive"), _T("uri:iso.org:21090"));
}

CBAG_MO::CBAG_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_MO(node)
, item(*this)	// "item"
{
}

CBAG_MO::CBAG_MO(CBAG_MO const& other)
: ::AIMXML::iso::CCOLL_MO(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_MO"), _T("uri:iso.org:21090"));
}

CBAG_PQ::CBAG_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_PQ(node)
, item(*this)	// "item"
{
}

CBAG_PQ::CBAG_PQ(CBAG_PQ const& other)
: ::AIMXML::iso::CCOLL_PQ(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_PQ"), _T("uri:iso.org:21090"));
}

CBAG_PQ_Time::CBAG_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_PQ_Time(node)
, item(*this)	// "item"
{
}

CBAG_PQ_Time::CBAG_PQ_Time(CBAG_PQ_Time const& other)
: ::AIMXML::iso::CCOLL_PQ_Time(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_PQ.Time"), _T("uri:iso.org:21090"));
}

CBAG_REAL::CBAG_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_REAL(node)
, item(*this)	// "item"
{
}

CBAG_REAL::CBAG_REAL(CBAG_REAL const& other)
: ::AIMXML::iso::CCOLL_REAL(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_REAL"), _T("uri:iso.org:21090"));
}

CBAG_RTO::CBAG_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_RTO(node)
, item(*this)	// "item"
{
}

CBAG_RTO::CBAG_RTO(CBAG_RTO const& other)
: ::AIMXML::iso::CCOLL_RTO(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_RTO"), _T("uri:iso.org:21090"));
}

CBAG_SC::CBAG_SC(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_SC(node)
, item(*this)	// "item"
{
}

CBAG_SC::CBAG_SC(CBAG_SC const& other)
: ::AIMXML::iso::CCOLL_SC(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_SC::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_SC"), _T("uri:iso.org:21090"));
}

CBAG_SC_NT::CBAG_SC_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_SC_NT(node)
, item(*this)	// "item"
{
}

CBAG_SC_NT::CBAG_SC_NT(CBAG_SC_NT const& other)
: ::AIMXML::iso::CCOLL_SC_NT(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_SC_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_SC.NT"), _T("uri:iso.org:21090"));
}

CBAG_ST::CBAG_ST(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ST(node)
, item(*this)	// "item"
{
}

CBAG_ST::CBAG_ST(CBAG_ST const& other)
: ::AIMXML::iso::CCOLL_ST(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ST::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ST"), _T("uri:iso.org:21090"));
}

CBAG_ST_NT::CBAG_ST_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ST_NT(node)
, item(*this)	// "item"
{
}

CBAG_ST_NT::CBAG_ST_NT(CBAG_ST_NT const& other)
: ::AIMXML::iso::CCOLL_ST_NT(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_ST_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_ST.NT"), _T("uri:iso.org:21090"));
}

CBAG_TEL::CBAG_TEL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL(node)
, item(*this)	// "item"
{
}

CBAG_TEL::CBAG_TEL(CBAG_TEL const& other)
: ::AIMXML::iso::CCOLL_TEL(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TEL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TEL"), _T("uri:iso.org:21090"));
}

CBAG_TEL_Email::CBAG_TEL_Email(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL_Email(node)
, item(*this)	// "item"
{
}

CBAG_TEL_Email::CBAG_TEL_Email(CBAG_TEL_Email const& other)
: ::AIMXML::iso::CCOLL_TEL_Email(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TEL_Email::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TEL.Email"), _T("uri:iso.org:21090"));
}

CBAG_TEL_Person::CBAG_TEL_Person(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL_Person(node)
, item(*this)	// "item"
{
}

CBAG_TEL_Person::CBAG_TEL_Person(CBAG_TEL_Person const& other)
: ::AIMXML::iso::CCOLL_TEL_Person(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TEL_Person::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TEL.Person"), _T("uri:iso.org:21090"));
}

CBAG_TEL_Phone::CBAG_TEL_Phone(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL_Phone(node)
, item(*this)	// "item"
{
}

CBAG_TEL_Phone::CBAG_TEL_Phone(CBAG_TEL_Phone const& other)
: ::AIMXML::iso::CCOLL_TEL_Phone(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TEL_Phone::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TEL.Phone"), _T("uri:iso.org:21090"));
}

CBAG_TEL_Url::CBAG_TEL_Url(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL_Url(node)
, item(*this)	// "item"
{
}

CBAG_TEL_Url::CBAG_TEL_Url(CBAG_TEL_Url const& other)
: ::AIMXML::iso::CCOLL_TEL_Url(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TEL_Url::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TEL.Url"), _T("uri:iso.org:21090"));
}

CBAG_TS::CBAG_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS(node)
, item(*this)	// "item"
{
}

CBAG_TS::CBAG_TS(CBAG_TS const& other)
: ::AIMXML::iso::CCOLL_TS(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TS"), _T("uri:iso.org:21090"));
}

CBAG_TS_Birth::CBAG_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_Birth(node)
, item(*this)	// "item"
{
}

CBAG_TS_Birth::CBAG_TS_Birth(CBAG_TS_Birth const& other)
: ::AIMXML::iso::CCOLL_TS_Birth(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TS.Birth"), _T("uri:iso.org:21090"));
}

CBAG_TS_Date::CBAG_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_Date(node)
, item(*this)	// "item"
{
}

CBAG_TS_Date::CBAG_TS_Date(CBAG_TS_Date const& other)
: ::AIMXML::iso::CCOLL_TS_Date(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TS.Date"), _T("uri:iso.org:21090"));
}

CBAG_TS_Date_Full::CBAG_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_Date_Full(node)
, item(*this)	// "item"
{
}

CBAG_TS_Date_Full::CBAG_TS_Date_Full(CBAG_TS_Date_Full const& other)
: ::AIMXML::iso::CCOLL_TS_Date_Full(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CBAG_TS_DateTime::CBAG_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_DateTime(node)
, item(*this)	// "item"
{
}

CBAG_TS_DateTime::CBAG_TS_DateTime(CBAG_TS_DateTime const& other)
: ::AIMXML::iso::CCOLL_TS_DateTime(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TS.DateTime"), _T("uri:iso.org:21090"));
}

CBAG_TS_DateTime_Full::CBAG_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_DateTime_Full(node)
, item(*this)	// "item"
{
}

CBAG_TS_DateTime_Full::CBAG_TS_DateTime_Full(CBAG_TS_DateTime_Full const& other)
: ::AIMXML::iso::CCOLL_TS_DateTime_Full(other.GetNode())
, item(*this)	// "item"
{
}

void CBAG_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BAG_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CBL::CBL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, value2(*this)	// "@value"
{
}

CBL::CBL(CBL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, value2(*this)	// "@value"
{
}

void CBL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BL"), _T("uri:iso.org:21090"));
}

CBL_NonNull::CBL_NonNull(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
{
}

CBL_NonNull::CBL_NonNull(CBL_NonNull const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
{
}

void CBL_NonNull::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("BL.NonNull"), _T("uri:iso.org:21090"));
}

CCD::CCD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemName(*this)	// "@codeSystemName"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, valueSet(*this)	// "@valueSet"
, valueSetVersion(*this)	// "@valueSetVersion"
, id(*this)	// "@id"
, codingRationale(*this)	// "@codingRationale"
, displayName(*this)	// "displayName"
, originalText(*this)	// "originalText"
, qualifier(*this)	// "qualifier"
, group(*this)	// "group"
, translation(*this)	// "translation"
, source(*this)	// "source"
{
}

CCD::CCD(CCD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemName(*this)	// "@codeSystemName"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, valueSet(*this)	// "@valueSet"
, valueSetVersion(*this)	// "@valueSetVersion"
, id(*this)	// "@id"
, codingRationale(*this)	// "@codingRationale"
, displayName(*this)	// "displayName"
, originalText(*this)	// "originalText"
, qualifier(*this)	// "qualifier"
, group(*this)	// "group"
, translation(*this)	// "translation"
, source(*this)	// "source"
{
}

void CCD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CD"), _T("uri:iso.org:21090"));
}

CCD_CE::CCD_CE(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemName(*this)	// "@codeSystemName"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, valueSet(*this)	// "@valueSet"
, valueSetVersion(*this)	// "@valueSetVersion"
, id(*this)	// "@id"
, codingRationale(*this)	// "@codingRationale"
, displayName(*this)	// "displayName"
, originalText(*this)	// "originalText"
, qualifier(*this)	// "qualifier"
, group(*this)	// "group"
, translation(*this)	// "translation"
, source(*this)	// "source"
{
}

CCD_CE::CCD_CE(CCD_CE const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemName(*this)	// "@codeSystemName"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, valueSet(*this)	// "@valueSet"
, valueSetVersion(*this)	// "@valueSetVersion"
, id(*this)	// "@id"
, codingRationale(*this)	// "@codingRationale"
, displayName(*this)	// "displayName"
, originalText(*this)	// "originalText"
, qualifier(*this)	// "qualifier"
, group(*this)	// "group"
, translation(*this)	// "translation"
, source(*this)	// "source"
{
}

void CCD_CE::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CD.CE"), _T("uri:iso.org:21090"));
}

CCD_CE_None::CCD_CE_None(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemName(*this)	// "@codeSystemName"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, valueSet(*this)	// "@valueSet"
, valueSetVersion(*this)	// "@valueSetVersion"
, id(*this)	// "@id"
, codingRationale(*this)	// "@codingRationale"
, displayName(*this)	// "displayName"
, originalText(*this)	// "originalText"
, qualifier(*this)	// "qualifier"
, group(*this)	// "group"
, translation(*this)	// "translation"
, source(*this)	// "source"
{
}

CCD_CE_None::CCD_CE_None(CCD_CE_None const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemName(*this)	// "@codeSystemName"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, valueSet(*this)	// "@valueSet"
, valueSetVersion(*this)	// "@valueSetVersion"
, id(*this)	// "@id"
, codingRationale(*this)	// "@codingRationale"
, displayName(*this)	// "displayName"
, originalText(*this)	// "originalText"
, qualifier(*this)	// "qualifier"
, group(*this)	// "group"
, translation(*this)	// "translation"
, source(*this)	// "source"
{
}

void CCD_CE_None::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CD.CE.None"), _T("uri:iso.org:21090"));
}

CCD_CV::CCD_CV(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemName(*this)	// "@codeSystemName"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, valueSet(*this)	// "@valueSet"
, valueSetVersion(*this)	// "@valueSetVersion"
, id(*this)	// "@id"
, codingRationale(*this)	// "@codingRationale"
, displayName(*this)	// "displayName"
, originalText(*this)	// "originalText"
, qualifier(*this)	// "qualifier"
, group(*this)	// "group"
, translation(*this)	// "translation"
, source(*this)	// "source"
{
}

CCD_CV::CCD_CV(CCD_CV const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemName(*this)	// "@codeSystemName"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, valueSet(*this)	// "@valueSet"
, valueSetVersion(*this)	// "@valueSetVersion"
, id(*this)	// "@id"
, codingRationale(*this)	// "@codingRationale"
, displayName(*this)	// "displayName"
, originalText(*this)	// "originalText"
, qualifier(*this)	// "qualifier"
, group(*this)	// "group"
, translation(*this)	// "translation"
, source(*this)	// "source"
{
}

void CCD_CV::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CD.CV"), _T("uri:iso.org:21090"));
}

CCDGroup::CCDGroup(xercesc::DOMNode* const& node)
: TypeBase(node)
, qualifier(*this)	// "qualifier"
{
}

CCDGroup::CCDGroup(CCDGroup const& other)
: TypeBase(other.GetNode())
, qualifier(*this)	// "qualifier"
{
}

void CCDGroup::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CDGroup"), _T("uri:iso.org:21090"));
}

CCO::CCO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQTY(node)
, value2(*this)	// "@value"
, code(*this)	// "code"
{
}

CCO::CCO(CCO const& other)
: ::AIMXML::iso::CQTY(other.GetNode())
, value2(*this)	// "@value"
, code(*this)	// "code"
{
}

void CCO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CO"), _T("uri:iso.org:21090"));
}

CCOLL_AD::CCOLL_AD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_AD::CCOLL_AD(CCOLL_AD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_AD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_AD"), _T("uri:iso.org:21090"));
}

CCOLL_BL::CCOLL_BL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_BL::CCOLL_BL(CCOLL_BL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_BL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_BL"), _T("uri:iso.org:21090"));
}

CCOLL_BL_NonNull::CCOLL_BL_NonNull(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_BL_NonNull::CCOLL_BL_NonNull(CCOLL_BL_NonNull const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_BL_NonNull::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_BL.NonNull"), _T("uri:iso.org:21090"));
}

CCOLL_CD::CCOLL_CD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_CD::CCOLL_CD(CCOLL_CD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_CD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_CD"), _T("uri:iso.org:21090"));
}

CCOLL_CD_CE::CCOLL_CD_CE(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_CD_CE::CCOLL_CD_CE(CCOLL_CD_CE const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_CD_CE::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_CD.CE"), _T("uri:iso.org:21090"));
}

CCOLL_CD_CE_None::CCOLL_CD_CE_None(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_CD_CE_None::CCOLL_CD_CE_None(CCOLL_CD_CE_None const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_CD_CE_None::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_CD.CE.None"), _T("uri:iso.org:21090"));
}

CCOLL_CD_CV::CCOLL_CD_CV(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_CD_CV::CCOLL_CD_CV(CCOLL_CD_CV const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_CD_CV::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_CD.CV"), _T("uri:iso.org:21090"));
}

CCOLL_CO::CCOLL_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_CO::CCOLL_CO(CCOLL_CO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_CO"), _T("uri:iso.org:21090"));
}

CCOLL_CS::CCOLL_CS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_CS::CCOLL_CS(CCOLL_CS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_CS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_CS"), _T("uri:iso.org:21090"));
}

CCOLL_ED::CCOLL_ED(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ED::CCOLL_ED(CCOLL_ED const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ED::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ED"), _T("uri:iso.org:21090"));
}

CCOLL_ED_Doc::CCOLL_ED_Doc(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ED_Doc::CCOLL_ED_Doc(CCOLL_ED_Doc const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ED_Doc::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ED.Doc"), _T("uri:iso.org:21090"));
}

CCOLL_ED_Doc_Inline::CCOLL_ED_Doc_Inline(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ED_Doc_Inline::CCOLL_ED_Doc_Inline(CCOLL_ED_Doc_Inline const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ED_Doc_Inline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ED.Doc.Inline"), _T("uri:iso.org:21090"));
}

CCOLL_ED_Doc_Ref::CCOLL_ED_Doc_Ref(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ED_Doc_Ref::CCOLL_ED_Doc_Ref(CCOLL_ED_Doc_Ref const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ED_Doc_Ref::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ED.Doc.Ref"), _T("uri:iso.org:21090"));
}

CCOLL_ED_Image::CCOLL_ED_Image(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ED_Image::CCOLL_ED_Image(CCOLL_ED_Image const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ED_Image::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ED.Image"), _T("uri:iso.org:21090"));
}

CCOLL_ED_Narrative::CCOLL_ED_Narrative(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ED_Narrative::CCOLL_ED_Narrative(CCOLL_ED_Narrative const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ED_Narrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ED.Narrative"), _T("uri:iso.org:21090"));
}

CCOLL_ED_Signature::CCOLL_ED_Signature(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ED_Signature::CCOLL_ED_Signature(CCOLL_ED_Signature const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ED_Signature::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ED.Signature"), _T("uri:iso.org:21090"));
}

CCOLL_ED_Text::CCOLL_ED_Text(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ED_Text::CCOLL_ED_Text(CCOLL_ED_Text const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ED_Text::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ED.Text"), _T("uri:iso.org:21090"));
}

CCOLL_EN::CCOLL_EN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_EN::CCOLL_EN(CCOLL_EN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_EN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_EN"), _T("uri:iso.org:21090"));
}

CCOLL_EN_ON::CCOLL_EN_ON(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_EN_ON::CCOLL_EN_ON(CCOLL_EN_ON const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_EN_ON::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_EN.ON"), _T("uri:iso.org:21090"));
}

CCOLL_EN_PN::CCOLL_EN_PN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_EN_PN::CCOLL_EN_PN(CCOLL_EN_PN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_EN_PN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_EN.PN"), _T("uri:iso.org:21090"));
}

CCOLL_EN_TN::CCOLL_EN_TN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_EN_TN::CCOLL_EN_TN(CCOLL_EN_TN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_EN_TN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_EN.TN"), _T("uri:iso.org:21090"));
}

CCOLL_II::CCOLL_II(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_II::CCOLL_II(CCOLL_II const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_II::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_II"), _T("uri:iso.org:21090"));
}

CCOLL_INT::CCOLL_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_INT::CCOLL_INT(CCOLL_INT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_INT"), _T("uri:iso.org:21090"));
}

CCOLL_INT_NonNeg::CCOLL_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_INT_NonNeg::CCOLL_INT_NonNeg(CCOLL_INT_NonNeg const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CCOLL_INT_Positive::CCOLL_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_INT_Positive::CCOLL_INT_Positive(CCOLL_INT_Positive const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_INT.Positive"), _T("uri:iso.org:21090"));
}

CCOLL_MO::CCOLL_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_MO::CCOLL_MO(CCOLL_MO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_MO"), _T("uri:iso.org:21090"));
}

CCOLL_PQ::CCOLL_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_PQ::CCOLL_PQ(CCOLL_PQ const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_PQ"), _T("uri:iso.org:21090"));
}

CCOLL_PQ_Time::CCOLL_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_PQ_Time::CCOLL_PQ_Time(CCOLL_PQ_Time const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_PQ.Time"), _T("uri:iso.org:21090"));
}

CCOLL_REAL::CCOLL_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_REAL::CCOLL_REAL(CCOLL_REAL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_REAL"), _T("uri:iso.org:21090"));
}

CCOLL_RTO::CCOLL_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_RTO::CCOLL_RTO(CCOLL_RTO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_RTO"), _T("uri:iso.org:21090"));
}

CCOLL_SC::CCOLL_SC(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_SC::CCOLL_SC(CCOLL_SC const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_SC::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_SC"), _T("uri:iso.org:21090"));
}

CCOLL_SC_NT::CCOLL_SC_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_SC_NT::CCOLL_SC_NT(CCOLL_SC_NT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_SC_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_SC.NT"), _T("uri:iso.org:21090"));
}

CCOLL_ST::CCOLL_ST(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ST::CCOLL_ST(CCOLL_ST const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ST::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ST"), _T("uri:iso.org:21090"));
}

CCOLL_ST_NT::CCOLL_ST_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_ST_NT::CCOLL_ST_NT(CCOLL_ST_NT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_ST_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_ST.NT"), _T("uri:iso.org:21090"));
}

CCOLL_TEL::CCOLL_TEL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TEL::CCOLL_TEL(CCOLL_TEL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TEL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TEL"), _T("uri:iso.org:21090"));
}

CCOLL_TEL_Email::CCOLL_TEL_Email(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TEL_Email::CCOLL_TEL_Email(CCOLL_TEL_Email const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TEL_Email::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TEL.Email"), _T("uri:iso.org:21090"));
}

CCOLL_TEL_Person::CCOLL_TEL_Person(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TEL_Person::CCOLL_TEL_Person(CCOLL_TEL_Person const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TEL_Person::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TEL.Person"), _T("uri:iso.org:21090"));
}

CCOLL_TEL_Phone::CCOLL_TEL_Phone(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TEL_Phone::CCOLL_TEL_Phone(CCOLL_TEL_Phone const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TEL_Phone::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TEL.Phone"), _T("uri:iso.org:21090"));
}

CCOLL_TEL_Url::CCOLL_TEL_Url(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TEL_Url::CCOLL_TEL_Url(CCOLL_TEL_Url const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TEL_Url::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TEL.Url"), _T("uri:iso.org:21090"));
}

CCOLL_TS::CCOLL_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TS::CCOLL_TS(CCOLL_TS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TS"), _T("uri:iso.org:21090"));
}

CCOLL_TS_Birth::CCOLL_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TS_Birth::CCOLL_TS_Birth(CCOLL_TS_Birth const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TS.Birth"), _T("uri:iso.org:21090"));
}

CCOLL_TS_Date::CCOLL_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TS_Date::CCOLL_TS_Date(CCOLL_TS_Date const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TS.Date"), _T("uri:iso.org:21090"));
}

CCOLL_TS_Date_Full::CCOLL_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TS_Date_Full::CCOLL_TS_Date_Full(CCOLL_TS_Date_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CCOLL_TS_DateTime::CCOLL_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TS_DateTime::CCOLL_TS_DateTime(CCOLL_TS_DateTime const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TS.DateTime"), _T("uri:iso.org:21090"));
}

CCOLL_TS_DateTime_Full::CCOLL_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
{
}

CCOLL_TS_DateTime_Full::CCOLL_TS_DateTime_Full(CCOLL_TS_DateTime_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
{
}

void CCOLL_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("COLL_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CCR::CCR(xercesc::DOMNode* const& node)
: TypeBase(node)
, inverted(*this)	// "@inverted"
, name(*this)	// "name"
, value2(*this)	// "value"
{
}

CCR::CCR(CCR const& other)
: TypeBase(other.GetNode())
, inverted(*this)	// "@inverted"
, name(*this)	// "name"
, value2(*this)	// "value"
{
}

void CCR::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CR"), _T("uri:iso.org:21090"));
}

CCS::CCS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, code(*this)	// "@code"
{
}

CCS::CCS(CCS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, code(*this)	// "@code"
{
}

void CCS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("CS"), _T("uri:iso.org:21090"));
}

CCalendarCycle::CCalendarCycle(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CCalendarCycle::CCalendarCycle(CCalendarCycle const& other)
: TypeBase(other.GetNode())
{
}


CCode::CCode(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CCode::CCode(CCode const& other)
: TypeBase(other.GetNode())
{
}


CCodingRationale::CCodingRationale(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CCodingRationale::CCodingRationale(CCodingRationale const& other)
: TypeBase(other.GetNode())
{
}


CCompression::CCompression(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CCompression::CCompression(CCompression const& other)
: TypeBase(other.GetNode())
{
}


CDSET_AD::CDSET_AD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_AD(node)
, item(*this)	// "item"
{
}

CDSET_AD::CDSET_AD(CDSET_AD const& other)
: ::AIMXML::iso::CCOLL_AD(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_AD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_AD"), _T("uri:iso.org:21090"));
}

CDSET_BL::CDSET_BL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_BL(node)
, item(*this)	// "item"
{
}

CDSET_BL::CDSET_BL(CDSET_BL const& other)
: ::AIMXML::iso::CCOLL_BL(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_BL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_BL"), _T("uri:iso.org:21090"));
}

CDSET_BL_NonNull::CDSET_BL_NonNull(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_BL_NonNull(node)
, item(*this)	// "item"
{
}

CDSET_BL_NonNull::CDSET_BL_NonNull(CDSET_BL_NonNull const& other)
: ::AIMXML::iso::CCOLL_BL_NonNull(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_BL_NonNull::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_BL.NonNull"), _T("uri:iso.org:21090"));
}

CDSET_CD::CDSET_CD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CD(node)
, item(*this)	// "item"
{
}

CDSET_CD::CDSET_CD(CDSET_CD const& other)
: ::AIMXML::iso::CCOLL_CD(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_CD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_CD"), _T("uri:iso.org:21090"));
}

CDSET_CD_CE::CDSET_CD_CE(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CD_CE(node)
, item(*this)	// "item"
{
}

CDSET_CD_CE::CDSET_CD_CE(CDSET_CD_CE const& other)
: ::AIMXML::iso::CCOLL_CD_CE(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_CD_CE::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_CD.CE"), _T("uri:iso.org:21090"));
}

CDSET_CD_CE_None::CDSET_CD_CE_None(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CD_CE_None(node)
, item(*this)	// "item"
{
}

CDSET_CD_CE_None::CDSET_CD_CE_None(CDSET_CD_CE_None const& other)
: ::AIMXML::iso::CCOLL_CD_CE_None(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_CD_CE_None::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_CD.CE.None"), _T("uri:iso.org:21090"));
}

CDSET_CD_CV::CDSET_CD_CV(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CD_CV(node)
, item(*this)	// "item"
{
}

CDSET_CD_CV::CDSET_CD_CV(CDSET_CD_CV const& other)
: ::AIMXML::iso::CCOLL_CD_CV(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_CD_CV::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_CD.CV"), _T("uri:iso.org:21090"));
}

CDSET_CO::CDSET_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CO(node)
, item(*this)	// "item"
{
}

CDSET_CO::CDSET_CO(CDSET_CO const& other)
: ::AIMXML::iso::CCOLL_CO(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_CO"), _T("uri:iso.org:21090"));
}

CDSET_CS::CDSET_CS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_CS(node)
, item(*this)	// "item"
{
}

CDSET_CS::CDSET_CS(CDSET_CS const& other)
: ::AIMXML::iso::CCOLL_CS(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_CS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_CS"), _T("uri:iso.org:21090"));
}

CDSET_ED::CDSET_ED(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED(node)
, item(*this)	// "item"
{
}

CDSET_ED::CDSET_ED(CDSET_ED const& other)
: ::AIMXML::iso::CCOLL_ED(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ED::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ED"), _T("uri:iso.org:21090"));
}

CDSET_ED_Doc::CDSET_ED_Doc(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Doc(node)
, item(*this)	// "item"
{
}

CDSET_ED_Doc::CDSET_ED_Doc(CDSET_ED_Doc const& other)
: ::AIMXML::iso::CCOLL_ED_Doc(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ED_Doc::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ED.Doc"), _T("uri:iso.org:21090"));
}

CDSET_ED_Doc_Inline::CDSET_ED_Doc_Inline(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Doc_Inline(node)
, item(*this)	// "item"
{
}

CDSET_ED_Doc_Inline::CDSET_ED_Doc_Inline(CDSET_ED_Doc_Inline const& other)
: ::AIMXML::iso::CCOLL_ED_Doc_Inline(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ED_Doc_Inline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ED.Doc.Inline"), _T("uri:iso.org:21090"));
}

CDSET_ED_Doc_Ref::CDSET_ED_Doc_Ref(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Doc_Ref(node)
, item(*this)	// "item"
{
}

CDSET_ED_Doc_Ref::CDSET_ED_Doc_Ref(CDSET_ED_Doc_Ref const& other)
: ::AIMXML::iso::CCOLL_ED_Doc_Ref(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ED_Doc_Ref::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ED.Doc.Ref"), _T("uri:iso.org:21090"));
}

CDSET_ED_Image::CDSET_ED_Image(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Image(node)
, item(*this)	// "item"
{
}

CDSET_ED_Image::CDSET_ED_Image(CDSET_ED_Image const& other)
: ::AIMXML::iso::CCOLL_ED_Image(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ED_Image::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ED.Image"), _T("uri:iso.org:21090"));
}

CDSET_ED_Narrative::CDSET_ED_Narrative(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Narrative(node)
, item(*this)	// "item"
{
}

CDSET_ED_Narrative::CDSET_ED_Narrative(CDSET_ED_Narrative const& other)
: ::AIMXML::iso::CCOLL_ED_Narrative(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ED_Narrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ED.Narrative"), _T("uri:iso.org:21090"));
}

CDSET_ED_Signature::CDSET_ED_Signature(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Signature(node)
, item(*this)	// "item"
{
}

CDSET_ED_Signature::CDSET_ED_Signature(CDSET_ED_Signature const& other)
: ::AIMXML::iso::CCOLL_ED_Signature(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ED_Signature::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ED.Signature"), _T("uri:iso.org:21090"));
}

CDSET_ED_Text::CDSET_ED_Text(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ED_Text(node)
, item(*this)	// "item"
{
}

CDSET_ED_Text::CDSET_ED_Text(CDSET_ED_Text const& other)
: ::AIMXML::iso::CCOLL_ED_Text(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ED_Text::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ED.Text"), _T("uri:iso.org:21090"));
}

CDSET_EN::CDSET_EN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_EN(node)
, item(*this)	// "item"
{
}

CDSET_EN::CDSET_EN(CDSET_EN const& other)
: ::AIMXML::iso::CCOLL_EN(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_EN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_EN"), _T("uri:iso.org:21090"));
}

CDSET_EN_ON::CDSET_EN_ON(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_EN_ON(node)
, item(*this)	// "item"
{
}

CDSET_EN_ON::CDSET_EN_ON(CDSET_EN_ON const& other)
: ::AIMXML::iso::CCOLL_EN_ON(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_EN_ON::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_EN.ON"), _T("uri:iso.org:21090"));
}

CDSET_EN_PN::CDSET_EN_PN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_EN_PN(node)
, item(*this)	// "item"
{
}

CDSET_EN_PN::CDSET_EN_PN(CDSET_EN_PN const& other)
: ::AIMXML::iso::CCOLL_EN_PN(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_EN_PN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_EN.PN"), _T("uri:iso.org:21090"));
}

CDSET_EN_TN::CDSET_EN_TN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_EN_TN(node)
, item(*this)	// "item"
{
}

CDSET_EN_TN::CDSET_EN_TN(CDSET_EN_TN const& other)
: ::AIMXML::iso::CCOLL_EN_TN(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_EN_TN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_EN.TN"), _T("uri:iso.org:21090"));
}

CDSET_II::CDSET_II(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_II(node)
, item(*this)	// "item"
{
}

CDSET_II::CDSET_II(CDSET_II const& other)
: ::AIMXML::iso::CCOLL_II(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_II::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_II"), _T("uri:iso.org:21090"));
}

CDSET_INT::CDSET_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_INT(node)
, item(*this)	// "item"
{
}

CDSET_INT::CDSET_INT(CDSET_INT const& other)
: ::AIMXML::iso::CCOLL_INT(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_INT"), _T("uri:iso.org:21090"));
}

CDSET_INT_NonNeg::CDSET_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_INT_NonNeg(node)
, item(*this)	// "item"
{
}

CDSET_INT_NonNeg::CDSET_INT_NonNeg(CDSET_INT_NonNeg const& other)
: ::AIMXML::iso::CCOLL_INT_NonNeg(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CDSET_INT_Positive::CDSET_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_INT_Positive(node)
, item(*this)	// "item"
{
}

CDSET_INT_Positive::CDSET_INT_Positive(CDSET_INT_Positive const& other)
: ::AIMXML::iso::CCOLL_INT_Positive(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_INT.Positive"), _T("uri:iso.org:21090"));
}

CDSET_MO::CDSET_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_MO(node)
, item(*this)	// "item"
{
}

CDSET_MO::CDSET_MO(CDSET_MO const& other)
: ::AIMXML::iso::CCOLL_MO(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_MO"), _T("uri:iso.org:21090"));
}

CDSET_PQ::CDSET_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_PQ(node)
, item(*this)	// "item"
{
}

CDSET_PQ::CDSET_PQ(CDSET_PQ const& other)
: ::AIMXML::iso::CCOLL_PQ(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_PQ"), _T("uri:iso.org:21090"));
}

CDSET_PQ_Time::CDSET_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_PQ_Time(node)
, item(*this)	// "item"
{
}

CDSET_PQ_Time::CDSET_PQ_Time(CDSET_PQ_Time const& other)
: ::AIMXML::iso::CCOLL_PQ_Time(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_PQ.Time"), _T("uri:iso.org:21090"));
}

CDSET_REAL::CDSET_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_REAL(node)
, item(*this)	// "item"
{
}

CDSET_REAL::CDSET_REAL(CDSET_REAL const& other)
: ::AIMXML::iso::CCOLL_REAL(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_REAL"), _T("uri:iso.org:21090"));
}

CDSET_RTO::CDSET_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_RTO(node)
, item(*this)	// "item"
{
}

CDSET_RTO::CDSET_RTO(CDSET_RTO const& other)
: ::AIMXML::iso::CCOLL_RTO(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_RTO"), _T("uri:iso.org:21090"));
}

CDSET_SC::CDSET_SC(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_SC(node)
, item(*this)	// "item"
{
}

CDSET_SC::CDSET_SC(CDSET_SC const& other)
: ::AIMXML::iso::CCOLL_SC(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_SC::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_SC"), _T("uri:iso.org:21090"));
}

CDSET_SC_NT::CDSET_SC_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_SC_NT(node)
, item(*this)	// "item"
{
}

CDSET_SC_NT::CDSET_SC_NT(CDSET_SC_NT const& other)
: ::AIMXML::iso::CCOLL_SC_NT(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_SC_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_SC.NT"), _T("uri:iso.org:21090"));
}

CDSET_ST::CDSET_ST(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ST(node)
, item(*this)	// "item"
{
}

CDSET_ST::CDSET_ST(CDSET_ST const& other)
: ::AIMXML::iso::CCOLL_ST(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ST::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ST"), _T("uri:iso.org:21090"));
}

CDSET_ST_NT::CDSET_ST_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_ST_NT(node)
, item(*this)	// "item"
{
}

CDSET_ST_NT::CDSET_ST_NT(CDSET_ST_NT const& other)
: ::AIMXML::iso::CCOLL_ST_NT(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_ST_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_ST.NT"), _T("uri:iso.org:21090"));
}

CDSET_TEL::CDSET_TEL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL(node)
, item(*this)	// "item"
{
}

CDSET_TEL::CDSET_TEL(CDSET_TEL const& other)
: ::AIMXML::iso::CCOLL_TEL(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TEL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TEL"), _T("uri:iso.org:21090"));
}

CDSET_TEL_Email::CDSET_TEL_Email(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL_Email(node)
, item(*this)	// "item"
{
}

CDSET_TEL_Email::CDSET_TEL_Email(CDSET_TEL_Email const& other)
: ::AIMXML::iso::CCOLL_TEL_Email(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TEL_Email::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TEL.Email"), _T("uri:iso.org:21090"));
}

CDSET_TEL_Person::CDSET_TEL_Person(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL_Person(node)
, item(*this)	// "item"
{
}

CDSET_TEL_Person::CDSET_TEL_Person(CDSET_TEL_Person const& other)
: ::AIMXML::iso::CCOLL_TEL_Person(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TEL_Person::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TEL.Person"), _T("uri:iso.org:21090"));
}

CDSET_TEL_Phone::CDSET_TEL_Phone(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL_Phone(node)
, item(*this)	// "item"
{
}

CDSET_TEL_Phone::CDSET_TEL_Phone(CDSET_TEL_Phone const& other)
: ::AIMXML::iso::CCOLL_TEL_Phone(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TEL_Phone::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TEL.Phone"), _T("uri:iso.org:21090"));
}

CDSET_TEL_Url::CDSET_TEL_Url(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TEL_Url(node)
, item(*this)	// "item"
{
}

CDSET_TEL_Url::CDSET_TEL_Url(CDSET_TEL_Url const& other)
: ::AIMXML::iso::CCOLL_TEL_Url(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TEL_Url::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TEL.Url"), _T("uri:iso.org:21090"));
}

CDSET_TS::CDSET_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS(node)
, item(*this)	// "item"
{
}

CDSET_TS::CDSET_TS(CDSET_TS const& other)
: ::AIMXML::iso::CCOLL_TS(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TS"), _T("uri:iso.org:21090"));
}

CDSET_TS_Birth::CDSET_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_Birth(node)
, item(*this)	// "item"
{
}

CDSET_TS_Birth::CDSET_TS_Birth(CDSET_TS_Birth const& other)
: ::AIMXML::iso::CCOLL_TS_Birth(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TS.Birth"), _T("uri:iso.org:21090"));
}

CDSET_TS_Date::CDSET_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_Date(node)
, item(*this)	// "item"
{
}

CDSET_TS_Date::CDSET_TS_Date(CDSET_TS_Date const& other)
: ::AIMXML::iso::CCOLL_TS_Date(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TS.Date"), _T("uri:iso.org:21090"));
}

CDSET_TS_Date_Full::CDSET_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_Date_Full(node)
, item(*this)	// "item"
{
}

CDSET_TS_Date_Full::CDSET_TS_Date_Full(CDSET_TS_Date_Full const& other)
: ::AIMXML::iso::CCOLL_TS_Date_Full(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CDSET_TS_DateTime::CDSET_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_DateTime(node)
, item(*this)	// "item"
{
}

CDSET_TS_DateTime::CDSET_TS_DateTime(CDSET_TS_DateTime const& other)
: ::AIMXML::iso::CCOLL_TS_DateTime(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TS.DateTime"), _T("uri:iso.org:21090"));
}

CDSET_TS_DateTime_Full::CDSET_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCOLL_TS_DateTime_Full(node)
, item(*this)	// "item"
{
}

CDSET_TS_DateTime_Full::CDSET_TS_DateTime_Full(CDSET_TS_DateTime_Full const& other)
: ::AIMXML::iso::CCOLL_TS_DateTime_Full(other.GetNode())
, item(*this)	// "item"
{
}

void CDSET_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("DSET_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CED::CED(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

CED::CED(CED const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

void CED::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ED"), _T("uri:iso.org:21090"));
}

CED_Doc::CED_Doc(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

CED_Doc::CED_Doc(CED_Doc const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

void CED_Doc::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ED.Doc"), _T("uri:iso.org:21090"));
}

CED_Doc_Inline::CED_Doc_Inline(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

CED_Doc_Inline::CED_Doc_Inline(CED_Doc_Inline const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

void CED_Doc_Inline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ED.Doc.Inline"), _T("uri:iso.org:21090"));
}

CED_Doc_Ref::CED_Doc_Ref(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

CED_Doc_Ref::CED_Doc_Ref(CED_Doc_Ref const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

void CED_Doc_Ref::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ED.Doc.Ref"), _T("uri:iso.org:21090"));
}

CED_Image::CED_Image(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

CED_Image::CED_Image(CED_Image const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

void CED_Image::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ED.Image"), _T("uri:iso.org:21090"));
}

CED_Narrative::CED_Narrative(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

CED_Narrative::CED_Narrative(CED_Narrative const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

void CED_Narrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ED.Narrative"), _T("uri:iso.org:21090"));
}

CED_Signature::CED_Signature(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

CED_Signature::CED_Signature(CED_Signature const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

void CED_Signature::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ED.Signature"), _T("uri:iso.org:21090"));
}

CED_Text::CED_Text(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

CED_Text::CED_Text(CED_Text const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, mediaType(*this)	// "@mediaType"
, charset(*this)	// "@charset"
, language(*this)	// "@language"
, compression(*this)	// "@compression"
, integrityCheckAlgorithm(*this)	// "@integrityCheckAlgorithm"
, data(*this)	// "data"
, xml(*this)	// "xml"
, reference(*this)	// "reference"
, integrityCheck(*this)	// "integrityCheck"
, thumbnail(*this)	// "thumbnail"
, translation(*this)	// "translation"
{
}

void CED_Text::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ED.Text"), _T("uri:iso.org:21090"));
}

CEIVL_TS::CEIVL_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS(node)
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

CEIVL_TS::CEIVL_TS(CEIVL_TS const& other)
: ::AIMXML::iso::CQSET_TS(other.GetNode())
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

void CEIVL_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EIVL_TS"), _T("uri:iso.org:21090"));
}

CEIVL_TS_Birth::CEIVL_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Birth(node)
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

CEIVL_TS_Birth::CEIVL_TS_Birth(CEIVL_TS_Birth const& other)
: ::AIMXML::iso::CQSET_TS_Birth(other.GetNode())
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

void CEIVL_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EIVL_TS.Birth"), _T("uri:iso.org:21090"));
}

CEIVL_TS_Date::CEIVL_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date(node)
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

CEIVL_TS_Date::CEIVL_TS_Date(CEIVL_TS_Date const& other)
: ::AIMXML::iso::CQSET_TS_Date(other.GetNode())
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

void CEIVL_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EIVL_TS.Date"), _T("uri:iso.org:21090"));
}

CEIVL_TS_Date_Full::CEIVL_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date_Full(node)
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

CEIVL_TS_Date_Full::CEIVL_TS_Date_Full(CEIVL_TS_Date_Full const& other)
: ::AIMXML::iso::CQSET_TS_Date_Full(other.GetNode())
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

void CEIVL_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EIVL_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CEIVL_TS_DateTime::CEIVL_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime(node)
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

CEIVL_TS_DateTime::CEIVL_TS_DateTime(CEIVL_TS_DateTime const& other)
: ::AIMXML::iso::CQSET_TS_DateTime(other.GetNode())
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

void CEIVL_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EIVL_TS.DateTime"), _T("uri:iso.org:21090"));
}

CEIVL_TS_DateTime_Full::CEIVL_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(node)
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

CEIVL_TS_DateTime_Full::CEIVL_TS_DateTime_Full(CEIVL_TS_DateTime_Full const& other)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(other.GetNode())
, event(*this)	// "@event"
, offset(*this)	// "offset"
{
}

void CEIVL_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EIVL_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CEN::CEN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, use(*this)	// "@use"
, part(*this)	// "part"
{
}

CEN::CEN(CEN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, use(*this)	// "@use"
, part(*this)	// "part"
{
}

void CEN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EN"), _T("uri:iso.org:21090"));
}

CEN_ON::CEN_ON(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CEN(node)
{
}

CEN_ON::CEN_ON(CEN_ON const& other)
: ::AIMXML::iso::CEN(other.GetNode())
{
}

void CEN_ON::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EN.ON"), _T("uri:iso.org:21090"));
}

CEN_PN::CEN_PN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CEN(node)
{
}

CEN_PN::CEN_PN(CEN_PN const& other)
: ::AIMXML::iso::CEN(other.GetNode())
{
}

void CEN_PN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EN.PN"), _T("uri:iso.org:21090"));
}

CEN_TN::CEN_TN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CEN(node)
{
}

CEN_TN::CEN_TN(CEN_TN const& other)
: ::AIMXML::iso::CEN(other.GetNode())
{
}

void CEN_TN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("EN.TN"), _T("uri:iso.org:21090"));
}

CENXP::CENXP(xercesc::DOMNode* const& node)
: TypeBase(node)
, value2(*this)	// "@value"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, type(*this)	// "@type"
, qualifier(*this)	// "@qualifier"
{
}

CENXP::CENXP(CENXP const& other)
: TypeBase(other.GetNode())
, value2(*this)	// "@value"
, code(*this)	// "@code"
, codeSystem(*this)	// "@codeSystem"
, codeSystemVersion(*this)	// "@codeSystemVersion"
, type(*this)	// "@type"
, qualifier(*this)	// "@qualifier"
{
}

void CENXP::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ENXP"), _T("uri:iso.org:21090"));
}

CEntityNamePartQualifier::CEntityNamePartQualifier(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CEntityNamePartQualifier::CEntityNamePartQualifier(CEntityNamePartQualifier const& other)
: TypeBase(other.GetNode())
{
}


CEntityNamePartType::CEntityNamePartType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CEntityNamePartType::CEntityNamePartType(CEntityNamePartType const& other)
: TypeBase(other.GetNode())
{
}


CEntityNameUse::CEntityNameUse(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CEntityNameUse::CEntityNameUse(CEntityNameUse const& other)
: TypeBase(other.GetNode())
{
}


CGLIST_CO::CGLIST_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_CO::CGLIST_CO(CGLIST_CO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_CO"), _T("uri:iso.org:21090"));
}

CGLIST_INT::CGLIST_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_INT::CGLIST_INT(CGLIST_INT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_INT"), _T("uri:iso.org:21090"));
}

CGLIST_INT_NonNeg::CGLIST_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_INT_NonNeg::CGLIST_INT_NonNeg(CGLIST_INT_NonNeg const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CGLIST_INT_Positive::CGLIST_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_INT_Positive::CGLIST_INT_Positive(CGLIST_INT_Positive const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_INT.Positive"), _T("uri:iso.org:21090"));
}

CGLIST_MO::CGLIST_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_MO::CGLIST_MO(CGLIST_MO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_MO"), _T("uri:iso.org:21090"));
}

CGLIST_PQ::CGLIST_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_PQ::CGLIST_PQ(CGLIST_PQ const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_PQ"), _T("uri:iso.org:21090"));
}

CGLIST_PQ_Time::CGLIST_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_PQ_Time::CGLIST_PQ_Time(CGLIST_PQ_Time const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_PQ.Time"), _T("uri:iso.org:21090"));
}

CGLIST_REAL::CGLIST_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_REAL::CGLIST_REAL(CGLIST_REAL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_REAL"), _T("uri:iso.org:21090"));
}

CGLIST_RTO::CGLIST_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_RTO::CGLIST_RTO(CGLIST_RTO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_RTO"), _T("uri:iso.org:21090"));
}

CGLIST_TS::CGLIST_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_TS::CGLIST_TS(CGLIST_TS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_TS"), _T("uri:iso.org:21090"));
}

CGLIST_TS_Birth::CGLIST_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_TS_Birth::CGLIST_TS_Birth(CGLIST_TS_Birth const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_TS.Birth"), _T("uri:iso.org:21090"));
}

CGLIST_TS_Date::CGLIST_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_TS_Date::CGLIST_TS_Date(CGLIST_TS_Date const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_TS.Date"), _T("uri:iso.org:21090"));
}

CGLIST_TS_Date_Full::CGLIST_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_TS_Date_Full::CGLIST_TS_Date_Full(CGLIST_TS_Date_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CGLIST_TS_DateTime::CGLIST_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_TS_DateTime::CGLIST_TS_DateTime(CGLIST_TS_DateTime const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_TS.DateTime"), _T("uri:iso.org:21090"));
}

CGLIST_TS_DateTime_Full::CGLIST_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

CGLIST_TS_DateTime_Full::CGLIST_TS_DateTime_Full(CGLIST_TS_DateTime_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, denominator(*this)	// "@denominator"
, period(*this)	// "@period"
, head(*this)	// "head"
, increment(*this)	// "increment"
{
}

void CGLIST_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("GLIST_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CHIST_AD::CHIST_AD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_AD(node)
{
}

CHIST_AD::CHIST_AD(CHIST_AD const& other)
: ::AIMXML::iso::CLIST_AD(other.GetNode())
{
}

void CHIST_AD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_AD"), _T("uri:iso.org:21090"));
}

CHIST_BL::CHIST_BL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_BL(node)
{
}

CHIST_BL::CHIST_BL(CHIST_BL const& other)
: ::AIMXML::iso::CLIST_BL(other.GetNode())
{
}

void CHIST_BL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_BL"), _T("uri:iso.org:21090"));
}

CHIST_BL_NonNull::CHIST_BL_NonNull(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_BL_NonNull(node)
{
}

CHIST_BL_NonNull::CHIST_BL_NonNull(CHIST_BL_NonNull const& other)
: ::AIMXML::iso::CLIST_BL_NonNull(other.GetNode())
{
}

void CHIST_BL_NonNull::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_BL.NonNull"), _T("uri:iso.org:21090"));
}

CHIST_CD::CHIST_CD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_CD(node)
{
}

CHIST_CD::CHIST_CD(CHIST_CD const& other)
: ::AIMXML::iso::CLIST_CD(other.GetNode())
{
}

void CHIST_CD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_CD"), _T("uri:iso.org:21090"));
}

CHIST_CD_CE::CHIST_CD_CE(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_CD_CE(node)
{
}

CHIST_CD_CE::CHIST_CD_CE(CHIST_CD_CE const& other)
: ::AIMXML::iso::CLIST_CD_CE(other.GetNode())
{
}

void CHIST_CD_CE::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_CD.CE"), _T("uri:iso.org:21090"));
}

CHIST_CD_CE_None::CHIST_CD_CE_None(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_CD_CE_None(node)
{
}

CHIST_CD_CE_None::CHIST_CD_CE_None(CHIST_CD_CE_None const& other)
: ::AIMXML::iso::CLIST_CD_CE_None(other.GetNode())
{
}

void CHIST_CD_CE_None::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_CD.CE.None"), _T("uri:iso.org:21090"));
}

CHIST_CD_CV::CHIST_CD_CV(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_CD_CV(node)
{
}

CHIST_CD_CV::CHIST_CD_CV(CHIST_CD_CV const& other)
: ::AIMXML::iso::CLIST_CD_CV(other.GetNode())
{
}

void CHIST_CD_CV::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_CD.CV"), _T("uri:iso.org:21090"));
}

CHIST_CO::CHIST_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_CO(node)
{
}

CHIST_CO::CHIST_CO(CHIST_CO const& other)
: ::AIMXML::iso::CLIST_CO(other.GetNode())
{
}

void CHIST_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_CO"), _T("uri:iso.org:21090"));
}

CHIST_CS::CHIST_CS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_CS(node)
{
}

CHIST_CS::CHIST_CS(CHIST_CS const& other)
: ::AIMXML::iso::CLIST_CS(other.GetNode())
{
}

void CHIST_CS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_CS"), _T("uri:iso.org:21090"));
}

CHIST_ED::CHIST_ED(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ED(node)
{
}

CHIST_ED::CHIST_ED(CHIST_ED const& other)
: ::AIMXML::iso::CLIST_ED(other.GetNode())
{
}

void CHIST_ED::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ED"), _T("uri:iso.org:21090"));
}

CHIST_ED_Doc::CHIST_ED_Doc(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ED_Doc(node)
{
}

CHIST_ED_Doc::CHIST_ED_Doc(CHIST_ED_Doc const& other)
: ::AIMXML::iso::CLIST_ED_Doc(other.GetNode())
{
}

void CHIST_ED_Doc::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ED.Doc"), _T("uri:iso.org:21090"));
}

CHIST_ED_Doc_Inline::CHIST_ED_Doc_Inline(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ED_Doc_Inline(node)
{
}

CHIST_ED_Doc_Inline::CHIST_ED_Doc_Inline(CHIST_ED_Doc_Inline const& other)
: ::AIMXML::iso::CLIST_ED_Doc_Inline(other.GetNode())
{
}

void CHIST_ED_Doc_Inline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ED.Doc.Inline"), _T("uri:iso.org:21090"));
}

CHIST_ED_Doc_Ref::CHIST_ED_Doc_Ref(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ED_Doc_Ref(node)
{
}

CHIST_ED_Doc_Ref::CHIST_ED_Doc_Ref(CHIST_ED_Doc_Ref const& other)
: ::AIMXML::iso::CLIST_ED_Doc_Ref(other.GetNode())
{
}

void CHIST_ED_Doc_Ref::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ED.Doc.Ref"), _T("uri:iso.org:21090"));
}

CHIST_ED_Image::CHIST_ED_Image(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ED_Image(node)
{
}

CHIST_ED_Image::CHIST_ED_Image(CHIST_ED_Image const& other)
: ::AIMXML::iso::CLIST_ED_Image(other.GetNode())
{
}

void CHIST_ED_Image::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ED.Image"), _T("uri:iso.org:21090"));
}

CHIST_ED_Narrative::CHIST_ED_Narrative(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ED_Narrative(node)
{
}

CHIST_ED_Narrative::CHIST_ED_Narrative(CHIST_ED_Narrative const& other)
: ::AIMXML::iso::CLIST_ED_Narrative(other.GetNode())
{
}

void CHIST_ED_Narrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ED.Narrative"), _T("uri:iso.org:21090"));
}

CHIST_ED_Signature::CHIST_ED_Signature(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ED_Signature(node)
{
}

CHIST_ED_Signature::CHIST_ED_Signature(CHIST_ED_Signature const& other)
: ::AIMXML::iso::CLIST_ED_Signature(other.GetNode())
{
}

void CHIST_ED_Signature::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ED.Signature"), _T("uri:iso.org:21090"));
}

CHIST_ED_Text::CHIST_ED_Text(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ED_Text(node)
{
}

CHIST_ED_Text::CHIST_ED_Text(CHIST_ED_Text const& other)
: ::AIMXML::iso::CLIST_ED_Text(other.GetNode())
{
}

void CHIST_ED_Text::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ED.Text"), _T("uri:iso.org:21090"));
}

CHIST_EN::CHIST_EN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_EN(node)
{
}

CHIST_EN::CHIST_EN(CHIST_EN const& other)
: ::AIMXML::iso::CLIST_EN(other.GetNode())
{
}

void CHIST_EN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_EN"), _T("uri:iso.org:21090"));
}

CHIST_EN_ON::CHIST_EN_ON(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_EN_ON(node)
{
}

CHIST_EN_ON::CHIST_EN_ON(CHIST_EN_ON const& other)
: ::AIMXML::iso::CLIST_EN_ON(other.GetNode())
{
}

void CHIST_EN_ON::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_EN.ON"), _T("uri:iso.org:21090"));
}

CHIST_EN_PN::CHIST_EN_PN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_EN_PN(node)
{
}

CHIST_EN_PN::CHIST_EN_PN(CHIST_EN_PN const& other)
: ::AIMXML::iso::CLIST_EN_PN(other.GetNode())
{
}

void CHIST_EN_PN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_EN.PN"), _T("uri:iso.org:21090"));
}

CHIST_EN_TN::CHIST_EN_TN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_EN_TN(node)
{
}

CHIST_EN_TN::CHIST_EN_TN(CHIST_EN_TN const& other)
: ::AIMXML::iso::CLIST_EN_TN(other.GetNode())
{
}

void CHIST_EN_TN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_EN.TN"), _T("uri:iso.org:21090"));
}

CHIST_II::CHIST_II(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_II(node)
{
}

CHIST_II::CHIST_II(CHIST_II const& other)
: ::AIMXML::iso::CLIST_II(other.GetNode())
{
}

void CHIST_II::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_II"), _T("uri:iso.org:21090"));
}

CHIST_INT::CHIST_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_INT(node)
{
}

CHIST_INT::CHIST_INT(CHIST_INT const& other)
: ::AIMXML::iso::CLIST_INT(other.GetNode())
{
}

void CHIST_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_INT"), _T("uri:iso.org:21090"));
}

CHIST_INT_NonNeg::CHIST_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_INT_NonNeg(node)
{
}

CHIST_INT_NonNeg::CHIST_INT_NonNeg(CHIST_INT_NonNeg const& other)
: ::AIMXML::iso::CLIST_INT_NonNeg(other.GetNode())
{
}

void CHIST_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CHIST_INT_Positive::CHIST_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_INT_Positive(node)
{
}

CHIST_INT_Positive::CHIST_INT_Positive(CHIST_INT_Positive const& other)
: ::AIMXML::iso::CLIST_INT_Positive(other.GetNode())
{
}

void CHIST_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_INT.Positive"), _T("uri:iso.org:21090"));
}

CHIST_MO::CHIST_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_MO(node)
{
}

CHIST_MO::CHIST_MO(CHIST_MO const& other)
: ::AIMXML::iso::CLIST_MO(other.GetNode())
{
}

void CHIST_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_MO"), _T("uri:iso.org:21090"));
}

CHIST_PQ::CHIST_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_PQ(node)
{
}

CHIST_PQ::CHIST_PQ(CHIST_PQ const& other)
: ::AIMXML::iso::CLIST_PQ(other.GetNode())
{
}

void CHIST_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_PQ"), _T("uri:iso.org:21090"));
}

CHIST_PQ_Time::CHIST_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_PQ_Time(node)
{
}

CHIST_PQ_Time::CHIST_PQ_Time(CHIST_PQ_Time const& other)
: ::AIMXML::iso::CLIST_PQ_Time(other.GetNode())
{
}

void CHIST_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_PQ.Time"), _T("uri:iso.org:21090"));
}

CHIST_REAL::CHIST_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_REAL(node)
{
}

CHIST_REAL::CHIST_REAL(CHIST_REAL const& other)
: ::AIMXML::iso::CLIST_REAL(other.GetNode())
{
}

void CHIST_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_REAL"), _T("uri:iso.org:21090"));
}

CHIST_RTO::CHIST_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_RTO(node)
{
}

CHIST_RTO::CHIST_RTO(CHIST_RTO const& other)
: ::AIMXML::iso::CLIST_RTO(other.GetNode())
{
}

void CHIST_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_RTO"), _T("uri:iso.org:21090"));
}

CHIST_SC::CHIST_SC(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_SC(node)
{
}

CHIST_SC::CHIST_SC(CHIST_SC const& other)
: ::AIMXML::iso::CLIST_SC(other.GetNode())
{
}

void CHIST_SC::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_SC"), _T("uri:iso.org:21090"));
}

CHIST_SC_NT::CHIST_SC_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_SC_NT(node)
{
}

CHIST_SC_NT::CHIST_SC_NT(CHIST_SC_NT const& other)
: ::AIMXML::iso::CLIST_SC_NT(other.GetNode())
{
}

void CHIST_SC_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_SC.NT"), _T("uri:iso.org:21090"));
}

CHIST_ST::CHIST_ST(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ST(node)
{
}

CHIST_ST::CHIST_ST(CHIST_ST const& other)
: ::AIMXML::iso::CLIST_ST(other.GetNode())
{
}

void CHIST_ST::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ST"), _T("uri:iso.org:21090"));
}

CHIST_ST_NT::CHIST_ST_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_ST_NT(node)
{
}

CHIST_ST_NT::CHIST_ST_NT(CHIST_ST_NT const& other)
: ::AIMXML::iso::CLIST_ST_NT(other.GetNode())
{
}

void CHIST_ST_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_ST.NT"), _T("uri:iso.org:21090"));
}

CHIST_TEL::CHIST_TEL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TEL(node)
{
}

CHIST_TEL::CHIST_TEL(CHIST_TEL const& other)
: ::AIMXML::iso::CLIST_TEL(other.GetNode())
{
}

void CHIST_TEL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TEL"), _T("uri:iso.org:21090"));
}

CHIST_TEL_Email::CHIST_TEL_Email(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TEL_Email(node)
{
}

CHIST_TEL_Email::CHIST_TEL_Email(CHIST_TEL_Email const& other)
: ::AIMXML::iso::CLIST_TEL_Email(other.GetNode())
{
}

void CHIST_TEL_Email::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TEL.Email"), _T("uri:iso.org:21090"));
}

CHIST_TEL_Person::CHIST_TEL_Person(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TEL_Person(node)
{
}

CHIST_TEL_Person::CHIST_TEL_Person(CHIST_TEL_Person const& other)
: ::AIMXML::iso::CLIST_TEL_Person(other.GetNode())
{
}

void CHIST_TEL_Person::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TEL.Person"), _T("uri:iso.org:21090"));
}

CHIST_TEL_Phone::CHIST_TEL_Phone(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TEL_Phone(node)
{
}

CHIST_TEL_Phone::CHIST_TEL_Phone(CHIST_TEL_Phone const& other)
: ::AIMXML::iso::CLIST_TEL_Phone(other.GetNode())
{
}

void CHIST_TEL_Phone::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TEL.Phone"), _T("uri:iso.org:21090"));
}

CHIST_TEL_Url::CHIST_TEL_Url(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TEL_Url(node)
{
}

CHIST_TEL_Url::CHIST_TEL_Url(CHIST_TEL_Url const& other)
: ::AIMXML::iso::CLIST_TEL_Url(other.GetNode())
{
}

void CHIST_TEL_Url::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TEL.Url"), _T("uri:iso.org:21090"));
}

CHIST_TS::CHIST_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TS(node)
{
}

CHIST_TS::CHIST_TS(CHIST_TS const& other)
: ::AIMXML::iso::CLIST_TS(other.GetNode())
{
}

void CHIST_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TS"), _T("uri:iso.org:21090"));
}

CHIST_TS_Birth::CHIST_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TS_Birth(node)
{
}

CHIST_TS_Birth::CHIST_TS_Birth(CHIST_TS_Birth const& other)
: ::AIMXML::iso::CLIST_TS_Birth(other.GetNode())
{
}

void CHIST_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TS.Birth"), _T("uri:iso.org:21090"));
}

CHIST_TS_Date::CHIST_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TS_Date(node)
{
}

CHIST_TS_Date::CHIST_TS_Date(CHIST_TS_Date const& other)
: ::AIMXML::iso::CLIST_TS_Date(other.GetNode())
{
}

void CHIST_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TS.Date"), _T("uri:iso.org:21090"));
}

CHIST_TS_Date_Full::CHIST_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TS_Date_Full(node)
{
}

CHIST_TS_Date_Full::CHIST_TS_Date_Full(CHIST_TS_Date_Full const& other)
: ::AIMXML::iso::CLIST_TS_Date_Full(other.GetNode())
{
}

void CHIST_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CHIST_TS_DateTime::CHIST_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TS_DateTime(node)
{
}

CHIST_TS_DateTime::CHIST_TS_DateTime(CHIST_TS_DateTime const& other)
: ::AIMXML::iso::CLIST_TS_DateTime(other.GetNode())
{
}

void CHIST_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TS.DateTime"), _T("uri:iso.org:21090"));
}

CHIST_TS_DateTime_Full::CHIST_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CLIST_TS_DateTime_Full(node)
{
}

CHIST_TS_DateTime_Full::CHIST_TS_DateTime_Full(CHIST_TS_DateTime_Full const& other)
: ::AIMXML::iso::CLIST_TS_DateTime_Full(other.GetNode())
{
}

void CHIST_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HIST_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CHXIT::CHXIT(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
{
}

CHXIT::CHXIT(CHXIT const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
{
}

void CHXIT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("HXIT"), _T("uri:iso.org:21090"));
}

CII::CII(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, root(*this)	// "@root"
, extension(*this)	// "@extension"
, identifierName(*this)	// "@identifierName"
, displayable(*this)	// "@displayable"
, scope(*this)	// "@scope"
, reliability(*this)	// "@reliability"
{
}

CII::CII(CII const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, root(*this)	// "@root"
, extension(*this)	// "@extension"
, identifierName(*this)	// "@identifierName"
, displayable(*this)	// "@displayable"
, scope(*this)	// "@scope"
, reliability(*this)	// "@reliability"
{
}

void CII::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("II"), _T("uri:iso.org:21090"));
}

CINT::CINT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQTY(node)
, value2(*this)	// "@value"
{
}

CINT::CINT(CINT const& other)
: ::AIMXML::iso::CQTY(other.GetNode())
, value2(*this)	// "@value"
{
}

void CINT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("INT"), _T("uri:iso.org:21090"));
}

CINT_NonNeg::CINT_NonNeg(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

CINT_NonNeg::CINT_NonNeg(CINT_NonNeg const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

void CINT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("INT.NonNeg"), _T("uri:iso.org:21090"));
}

CINT_Positive::CINT_Positive(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

CINT_Positive::CINT_Positive(CINT_Positive const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

void CINT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("INT.Positive"), _T("uri:iso.org:21090"));
}

CIVL_High_CO::CIVL_High_CO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_CO::CIVL_High_CO(CIVL_High_CO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_CO"), _T("uri:iso.org:21090"));
}

CIVL_High_INT::CIVL_High_INT(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_INT::CIVL_High_INT(CIVL_High_INT const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_INT"), _T("uri:iso.org:21090"));
}

CIVL_High_INT_NonNeg::CIVL_High_INT_NonNeg(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_INT_NonNeg::CIVL_High_INT_NonNeg(CIVL_High_INT_NonNeg const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CIVL_High_INT_Positive::CIVL_High_INT_Positive(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_INT_Positive::CIVL_High_INT_Positive(CIVL_High_INT_Positive const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_INT.Positive"), _T("uri:iso.org:21090"));
}

CIVL_High_MO::CIVL_High_MO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_MO::CIVL_High_MO(CIVL_High_MO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_MO"), _T("uri:iso.org:21090"));
}

CIVL_High_PQ::CIVL_High_PQ(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_PQ::CIVL_High_PQ(CIVL_High_PQ const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_PQ"), _T("uri:iso.org:21090"));
}

CIVL_High_PQ_Time::CIVL_High_PQ_Time(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_PQ_Time::CIVL_High_PQ_Time(CIVL_High_PQ_Time const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_PQ.Time"), _T("uri:iso.org:21090"));
}

CIVL_High_REAL::CIVL_High_REAL(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_REAL::CIVL_High_REAL(CIVL_High_REAL const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_REAL"), _T("uri:iso.org:21090"));
}

CIVL_High_RTO::CIVL_High_RTO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_RTO::CIVL_High_RTO(CIVL_High_RTO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_RTO"), _T("uri:iso.org:21090"));
}

CIVL_High_TS::CIVL_High_TS(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_TS::CIVL_High_TS(CIVL_High_TS const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_TS"), _T("uri:iso.org:21090"));
}

CIVL_High_TS_Birth::CIVL_High_TS_Birth(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_TS_Birth::CIVL_High_TS_Birth(CIVL_High_TS_Birth const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_TS.Birth"), _T("uri:iso.org:21090"));
}

CIVL_High_TS_Date::CIVL_High_TS_Date(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_TS_Date::CIVL_High_TS_Date(CIVL_High_TS_Date const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_TS.Date"), _T("uri:iso.org:21090"));
}

CIVL_High_TS_Date_Full::CIVL_High_TS_Date_Full(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_TS_Date_Full::CIVL_High_TS_Date_Full(CIVL_High_TS_Date_Full const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CIVL_High_TS_DateTime::CIVL_High_TS_DateTime(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_TS_DateTime::CIVL_High_TS_DateTime(CIVL_High_TS_DateTime const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_TS.DateTime"), _T("uri:iso.org:21090"));
}

CIVL_High_TS_DateTime_Full::CIVL_High_TS_DateTime_Full(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_High_TS_DateTime_Full::CIVL_High_TS_DateTime_Full(CIVL_High_TS_DateTime_Full const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_High_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.High_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CIVL_Low_CO::CIVL_Low_CO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_CO::CIVL_Low_CO(CIVL_Low_CO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_CO"), _T("uri:iso.org:21090"));
}

CIVL_Low_INT::CIVL_Low_INT(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_INT::CIVL_Low_INT(CIVL_Low_INT const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_INT"), _T("uri:iso.org:21090"));
}

CIVL_Low_INT_NonNeg::CIVL_Low_INT_NonNeg(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_INT_NonNeg::CIVL_Low_INT_NonNeg(CIVL_Low_INT_NonNeg const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CIVL_Low_INT_Positive::CIVL_Low_INT_Positive(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_INT_Positive::CIVL_Low_INT_Positive(CIVL_Low_INT_Positive const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_INT.Positive"), _T("uri:iso.org:21090"));
}

CIVL_Low_MO::CIVL_Low_MO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_MO::CIVL_Low_MO(CIVL_Low_MO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_MO"), _T("uri:iso.org:21090"));
}

CIVL_Low_PQ::CIVL_Low_PQ(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_PQ::CIVL_Low_PQ(CIVL_Low_PQ const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_PQ"), _T("uri:iso.org:21090"));
}

CIVL_Low_PQ_Time::CIVL_Low_PQ_Time(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_PQ_Time::CIVL_Low_PQ_Time(CIVL_Low_PQ_Time const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_PQ.Time"), _T("uri:iso.org:21090"));
}

CIVL_Low_REAL::CIVL_Low_REAL(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_REAL::CIVL_Low_REAL(CIVL_Low_REAL const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_REAL"), _T("uri:iso.org:21090"));
}

CIVL_Low_RTO::CIVL_Low_RTO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_RTO::CIVL_Low_RTO(CIVL_Low_RTO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_RTO"), _T("uri:iso.org:21090"));
}

CIVL_Low_TS::CIVL_Low_TS(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_TS::CIVL_Low_TS(CIVL_Low_TS const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_TS"), _T("uri:iso.org:21090"));
}

CIVL_Low_TS_Birth::CIVL_Low_TS_Birth(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_TS_Birth::CIVL_Low_TS_Birth(CIVL_Low_TS_Birth const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_TS.Birth"), _T("uri:iso.org:21090"));
}

CIVL_Low_TS_Date::CIVL_Low_TS_Date(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_TS_Date::CIVL_Low_TS_Date(CIVL_Low_TS_Date const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_TS.Date"), _T("uri:iso.org:21090"));
}

CIVL_Low_TS_Date_Full::CIVL_Low_TS_Date_Full(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_TS_Date_Full::CIVL_Low_TS_Date_Full(CIVL_Low_TS_Date_Full const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CIVL_Low_TS_DateTime::CIVL_Low_TS_DateTime(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_TS_DateTime::CIVL_Low_TS_DateTime(CIVL_Low_TS_DateTime const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_TS.DateTime"), _T("uri:iso.org:21090"));
}

CIVL_Low_TS_DateTime_Full::CIVL_Low_TS_DateTime_Full(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Low_TS_DateTime_Full::CIVL_Low_TS_DateTime_Full(CIVL_Low_TS_DateTime_Full const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Low_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Low_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CIVL_Width_CO::CIVL_Width_CO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_CO::CIVL_Width_CO(CIVL_Width_CO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_CO"), _T("uri:iso.org:21090"));
}

CIVL_Width_INT::CIVL_Width_INT(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_INT::CIVL_Width_INT(CIVL_Width_INT const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_INT"), _T("uri:iso.org:21090"));
}

CIVL_Width_INT_NonNeg::CIVL_Width_INT_NonNeg(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_INT_NonNeg::CIVL_Width_INT_NonNeg(CIVL_Width_INT_NonNeg const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CIVL_Width_INT_Positive::CIVL_Width_INT_Positive(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_INT_Positive::CIVL_Width_INT_Positive(CIVL_Width_INT_Positive const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_INT.Positive"), _T("uri:iso.org:21090"));
}

CIVL_Width_MO::CIVL_Width_MO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_MO::CIVL_Width_MO(CIVL_Width_MO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_MO"), _T("uri:iso.org:21090"));
}

CIVL_Width_PQ::CIVL_Width_PQ(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_PQ::CIVL_Width_PQ(CIVL_Width_PQ const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_PQ"), _T("uri:iso.org:21090"));
}

CIVL_Width_PQ_Time::CIVL_Width_PQ_Time(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_PQ_Time::CIVL_Width_PQ_Time(CIVL_Width_PQ_Time const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_PQ.Time"), _T("uri:iso.org:21090"));
}

CIVL_Width_REAL::CIVL_Width_REAL(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_REAL::CIVL_Width_REAL(CIVL_Width_REAL const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_REAL"), _T("uri:iso.org:21090"));
}

CIVL_Width_RTO::CIVL_Width_RTO(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_RTO::CIVL_Width_RTO(CIVL_Width_RTO const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_RTO"), _T("uri:iso.org:21090"));
}

CIVL_Width_TS::CIVL_Width_TS(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_TS::CIVL_Width_TS(CIVL_Width_TS const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_TS"), _T("uri:iso.org:21090"));
}

CIVL_Width_TS_Birth::CIVL_Width_TS_Birth(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_TS_Birth::CIVL_Width_TS_Birth(CIVL_Width_TS_Birth const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_TS.Birth"), _T("uri:iso.org:21090"));
}

CIVL_Width_TS_Date::CIVL_Width_TS_Date(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_TS_Date::CIVL_Width_TS_Date(CIVL_Width_TS_Date const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_TS.Date"), _T("uri:iso.org:21090"));
}

CIVL_Width_TS_Date_Full::CIVL_Width_TS_Date_Full(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_TS_Date_Full::CIVL_Width_TS_Date_Full(CIVL_Width_TS_Date_Full const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CIVL_Width_TS_DateTime::CIVL_Width_TS_DateTime(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_TS_DateTime::CIVL_Width_TS_DateTime(CIVL_Width_TS_DateTime const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_TS.DateTime"), _T("uri:iso.org:21090"));
}

CIVL_Width_TS_DateTime_Full::CIVL_Width_TS_DateTime_Full(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_Width_TS_DateTime_Full::CIVL_Width_TS_DateTime_Full(CIVL_Width_TS_DateTime_Full const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, originalText(*this)	// "originalText"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_Width_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL.Width_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CIVL_CO::CIVL_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_CO(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_CO::CIVL_CO(CIVL_CO const& other)
: ::AIMXML::iso::CQSET_CO(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_CO"), _T("uri:iso.org:21090"));
}

CIVL_INT::CIVL_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_INT::CIVL_INT(CIVL_INT const& other)
: ::AIMXML::iso::CQSET_INT(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_INT"), _T("uri:iso.org:21090"));
}

CIVL_INT_NonNeg::CIVL_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_NonNeg(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_INT_NonNeg::CIVL_INT_NonNeg(CIVL_INT_NonNeg const& other)
: ::AIMXML::iso::CQSET_INT_NonNeg(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CIVL_INT_Positive::CIVL_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_Positive(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_INT_Positive::CIVL_INT_Positive(CIVL_INT_Positive const& other)
: ::AIMXML::iso::CQSET_INT_Positive(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_INT.Positive"), _T("uri:iso.org:21090"));
}

CIVL_MO::CIVL_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_MO(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_MO::CIVL_MO(CIVL_MO const& other)
: ::AIMXML::iso::CQSET_MO(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_MO"), _T("uri:iso.org:21090"));
}

CIVL_PQ::CIVL_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_PQ::CIVL_PQ(CIVL_PQ const& other)
: ::AIMXML::iso::CQSET_PQ(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_PQ"), _T("uri:iso.org:21090"));
}

CIVL_PQ_Time::CIVL_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ_Time(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_PQ_Time::CIVL_PQ_Time(CIVL_PQ_Time const& other)
: ::AIMXML::iso::CQSET_PQ_Time(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_PQ.Time"), _T("uri:iso.org:21090"));
}

CIVL_REAL::CIVL_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_REAL(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_REAL::CIVL_REAL(CIVL_REAL const& other)
: ::AIMXML::iso::CQSET_REAL(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_REAL"), _T("uri:iso.org:21090"));
}

CIVL_RTO::CIVL_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_RTO(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_RTO::CIVL_RTO(CIVL_RTO const& other)
: ::AIMXML::iso::CQSET_RTO(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_RTO"), _T("uri:iso.org:21090"));
}

CIVL_TS::CIVL_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_TS::CIVL_TS(CIVL_TS const& other)
: ::AIMXML::iso::CQSET_TS(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_TS"), _T("uri:iso.org:21090"));
}

CIVL_TS_Birth::CIVL_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Birth(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_TS_Birth::CIVL_TS_Birth(CIVL_TS_Birth const& other)
: ::AIMXML::iso::CQSET_TS_Birth(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_TS.Birth"), _T("uri:iso.org:21090"));
}

CIVL_TS_Date::CIVL_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_TS_Date::CIVL_TS_Date(CIVL_TS_Date const& other)
: ::AIMXML::iso::CQSET_TS_Date(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_TS.Date"), _T("uri:iso.org:21090"));
}

CIVL_TS_Date_Full::CIVL_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date_Full(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_TS_Date_Full::CIVL_TS_Date_Full(CIVL_TS_Date_Full const& other)
: ::AIMXML::iso::CQSET_TS_Date_Full(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CIVL_TS_DateTime::CIVL_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_TS_DateTime::CIVL_TS_DateTime(CIVL_TS_DateTime const& other)
: ::AIMXML::iso::CQSET_TS_DateTime(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_TS.DateTime"), _T("uri:iso.org:21090"));
}

CIVL_TS_DateTime_Full::CIVL_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(node)
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

CIVL_TS_DateTime_Full::CIVL_TS_DateTime_Full(CIVL_TS_DateTime_Full const& other)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(other.GetNode())
, lowClosed(*this)	// "@lowClosed"
, highClosed(*this)	// "@highClosed"
, low(*this)	// "low"
, high(*this)	// "high"
, width(*this)	// "width"
{
}

void CIVL_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("IVL_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CIdentifierReliability::CIdentifierReliability(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CIdentifierReliability::CIdentifierReliability(CIdentifierReliability const& other)
: TypeBase(other.GetNode())
{
}


CIdentifierScope::CIdentifierScope(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CIdentifierScope::CIdentifierScope(CIdentifierScope const& other)
: TypeBase(other.GetNode())
{
}


CIntegrityCheckAlgorithm::CIntegrityCheckAlgorithm(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CIntegrityCheckAlgorithm::CIntegrityCheckAlgorithm(CIntegrityCheckAlgorithm const& other)
: TypeBase(other.GetNode())
{
}


CLIST_AD::CLIST_AD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_AD::CLIST_AD(CLIST_AD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_AD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_AD"), _T("uri:iso.org:21090"));
}

CLIST_BL::CLIST_BL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_BL::CLIST_BL(CLIST_BL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_BL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_BL"), _T("uri:iso.org:21090"));
}

CLIST_BL_NonNull::CLIST_BL_NonNull(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_BL_NonNull::CLIST_BL_NonNull(CLIST_BL_NonNull const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_BL_NonNull::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_BL.NonNull"), _T("uri:iso.org:21090"));
}

CLIST_CD::CLIST_CD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_CD::CLIST_CD(CLIST_CD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_CD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_CD"), _T("uri:iso.org:21090"));
}

CLIST_CD_CE::CLIST_CD_CE(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_CD_CE::CLIST_CD_CE(CLIST_CD_CE const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_CD_CE::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_CD.CE"), _T("uri:iso.org:21090"));
}

CLIST_CD_CE_None::CLIST_CD_CE_None(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_CD_CE_None::CLIST_CD_CE_None(CLIST_CD_CE_None const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_CD_CE_None::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_CD.CE.None"), _T("uri:iso.org:21090"));
}

CLIST_CD_CV::CLIST_CD_CV(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_CD_CV::CLIST_CD_CV(CLIST_CD_CV const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_CD_CV::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_CD.CV"), _T("uri:iso.org:21090"));
}

CLIST_CO::CLIST_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_CO::CLIST_CO(CLIST_CO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_CO"), _T("uri:iso.org:21090"));
}

CLIST_CS::CLIST_CS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_CS::CLIST_CS(CLIST_CS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_CS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_CS"), _T("uri:iso.org:21090"));
}

CLIST_ED::CLIST_ED(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ED::CLIST_ED(CLIST_ED const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ED::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ED"), _T("uri:iso.org:21090"));
}

CLIST_ED_Doc::CLIST_ED_Doc(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ED_Doc::CLIST_ED_Doc(CLIST_ED_Doc const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ED_Doc::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ED.Doc"), _T("uri:iso.org:21090"));
}

CLIST_ED_Doc_Inline::CLIST_ED_Doc_Inline(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ED_Doc_Inline::CLIST_ED_Doc_Inline(CLIST_ED_Doc_Inline const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ED_Doc_Inline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ED.Doc.Inline"), _T("uri:iso.org:21090"));
}

CLIST_ED_Doc_Ref::CLIST_ED_Doc_Ref(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ED_Doc_Ref::CLIST_ED_Doc_Ref(CLIST_ED_Doc_Ref const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ED_Doc_Ref::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ED.Doc.Ref"), _T("uri:iso.org:21090"));
}

CLIST_ED_Image::CLIST_ED_Image(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ED_Image::CLIST_ED_Image(CLIST_ED_Image const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ED_Image::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ED.Image"), _T("uri:iso.org:21090"));
}

CLIST_ED_Narrative::CLIST_ED_Narrative(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ED_Narrative::CLIST_ED_Narrative(CLIST_ED_Narrative const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ED_Narrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ED.Narrative"), _T("uri:iso.org:21090"));
}

CLIST_ED_Signature::CLIST_ED_Signature(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ED_Signature::CLIST_ED_Signature(CLIST_ED_Signature const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ED_Signature::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ED.Signature"), _T("uri:iso.org:21090"));
}

CLIST_ED_Text::CLIST_ED_Text(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ED_Text::CLIST_ED_Text(CLIST_ED_Text const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ED_Text::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ED.Text"), _T("uri:iso.org:21090"));
}

CLIST_EN::CLIST_EN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_EN::CLIST_EN(CLIST_EN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_EN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_EN"), _T("uri:iso.org:21090"));
}

CLIST_EN_ON::CLIST_EN_ON(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_EN_ON::CLIST_EN_ON(CLIST_EN_ON const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_EN_ON::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_EN.ON"), _T("uri:iso.org:21090"));
}

CLIST_EN_PN::CLIST_EN_PN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_EN_PN::CLIST_EN_PN(CLIST_EN_PN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_EN_PN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_EN.PN"), _T("uri:iso.org:21090"));
}

CLIST_EN_TN::CLIST_EN_TN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_EN_TN::CLIST_EN_TN(CLIST_EN_TN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_EN_TN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_EN.TN"), _T("uri:iso.org:21090"));
}

CLIST_II::CLIST_II(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_II::CLIST_II(CLIST_II const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_II::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_II"), _T("uri:iso.org:21090"));
}

CLIST_INT::CLIST_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_INT::CLIST_INT(CLIST_INT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_INT"), _T("uri:iso.org:21090"));
}

CLIST_INT_NonNeg::CLIST_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_INT_NonNeg::CLIST_INT_NonNeg(CLIST_INT_NonNeg const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CLIST_INT_Positive::CLIST_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_INT_Positive::CLIST_INT_Positive(CLIST_INT_Positive const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_INT.Positive"), _T("uri:iso.org:21090"));
}

CLIST_MO::CLIST_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_MO::CLIST_MO(CLIST_MO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_MO"), _T("uri:iso.org:21090"));
}

CLIST_PQ::CLIST_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_PQ::CLIST_PQ(CLIST_PQ const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_PQ"), _T("uri:iso.org:21090"));
}

CLIST_PQ_Time::CLIST_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_PQ_Time::CLIST_PQ_Time(CLIST_PQ_Time const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_PQ.Time"), _T("uri:iso.org:21090"));
}

CLIST_REAL::CLIST_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_REAL::CLIST_REAL(CLIST_REAL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_REAL"), _T("uri:iso.org:21090"));
}

CLIST_RTO::CLIST_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_RTO::CLIST_RTO(CLIST_RTO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_RTO"), _T("uri:iso.org:21090"));
}

CLIST_SC::CLIST_SC(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_SC::CLIST_SC(CLIST_SC const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_SC::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_SC"), _T("uri:iso.org:21090"));
}

CLIST_SC_NT::CLIST_SC_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_SC_NT::CLIST_SC_NT(CLIST_SC_NT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_SC_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_SC.NT"), _T("uri:iso.org:21090"));
}

CLIST_ST::CLIST_ST(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ST::CLIST_ST(CLIST_ST const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ST::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ST"), _T("uri:iso.org:21090"));
}

CLIST_ST_NT::CLIST_ST_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_ST_NT::CLIST_ST_NT(CLIST_ST_NT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_ST_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_ST.NT"), _T("uri:iso.org:21090"));
}

CLIST_TEL::CLIST_TEL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TEL::CLIST_TEL(CLIST_TEL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TEL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TEL"), _T("uri:iso.org:21090"));
}

CLIST_TEL_Email::CLIST_TEL_Email(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TEL_Email::CLIST_TEL_Email(CLIST_TEL_Email const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TEL_Email::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TEL.Email"), _T("uri:iso.org:21090"));
}

CLIST_TEL_Person::CLIST_TEL_Person(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TEL_Person::CLIST_TEL_Person(CLIST_TEL_Person const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TEL_Person::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TEL.Person"), _T("uri:iso.org:21090"));
}

CLIST_TEL_Phone::CLIST_TEL_Phone(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TEL_Phone::CLIST_TEL_Phone(CLIST_TEL_Phone const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TEL_Phone::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TEL.Phone"), _T("uri:iso.org:21090"));
}

CLIST_TEL_Url::CLIST_TEL_Url(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TEL_Url::CLIST_TEL_Url(CLIST_TEL_Url const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TEL_Url::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TEL.Url"), _T("uri:iso.org:21090"));
}

CLIST_TS::CLIST_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TS::CLIST_TS(CLIST_TS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TS"), _T("uri:iso.org:21090"));
}

CLIST_TS_Birth::CLIST_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TS_Birth::CLIST_TS_Birth(CLIST_TS_Birth const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TS.Birth"), _T("uri:iso.org:21090"));
}

CLIST_TS_Date::CLIST_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TS_Date::CLIST_TS_Date(CLIST_TS_Date const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TS.Date"), _T("uri:iso.org:21090"));
}

CLIST_TS_Date_Full::CLIST_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TS_Date_Full::CLIST_TS_Date_Full(CLIST_TS_Date_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CLIST_TS_DateTime::CLIST_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TS_DateTime::CLIST_TS_DateTime(CLIST_TS_DateTime const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TS.DateTime"), _T("uri:iso.org:21090"));
}

CLIST_TS_DateTime_Full::CLIST_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CLIST_TS_DateTime_Full::CLIST_TS_DateTime_Full(CLIST_TS_DateTime_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CLIST_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("LIST_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CMO::CMO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQTY(node)
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
, currency(*this)	// "@currency"
{
}

CMO::CMO(CMO const& other)
: ::AIMXML::iso::CQTY(other.GetNode())
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
, currency(*this)	// "@currency"
{
}

void CMO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("MO"), _T("uri:iso.org:21090"));
}

CNPPD_AD::CNPPD_AD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_AD::CNPPD_AD(CNPPD_AD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_AD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_AD"), _T("uri:iso.org:21090"));
}

CNPPD_BL::CNPPD_BL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_BL::CNPPD_BL(CNPPD_BL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_BL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_BL"), _T("uri:iso.org:21090"));
}

CNPPD_BL_NonNull::CNPPD_BL_NonNull(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_BL_NonNull::CNPPD_BL_NonNull(CNPPD_BL_NonNull const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_BL_NonNull::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_BL.NonNull"), _T("uri:iso.org:21090"));
}

CNPPD_CD::CNPPD_CD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_CD::CNPPD_CD(CNPPD_CD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_CD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_CD"), _T("uri:iso.org:21090"));
}

CNPPD_CD_CE::CNPPD_CD_CE(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_CD_CE::CNPPD_CD_CE(CNPPD_CD_CE const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_CD_CE::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_CD.CE"), _T("uri:iso.org:21090"));
}

CNPPD_CD_CE_None::CNPPD_CD_CE_None(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_CD_CE_None::CNPPD_CD_CE_None(CNPPD_CD_CE_None const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_CD_CE_None::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_CD.CE.None"), _T("uri:iso.org:21090"));
}

CNPPD_CD_CV::CNPPD_CD_CV(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_CD_CV::CNPPD_CD_CV(CNPPD_CD_CV const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_CD_CV::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_CD.CV"), _T("uri:iso.org:21090"));
}

CNPPD_CO::CNPPD_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_CO::CNPPD_CO(CNPPD_CO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_CO"), _T("uri:iso.org:21090"));
}

CNPPD_CS::CNPPD_CS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_CS::CNPPD_CS(CNPPD_CS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_CS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_CS"), _T("uri:iso.org:21090"));
}

CNPPD_ED::CNPPD_ED(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ED::CNPPD_ED(CNPPD_ED const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ED::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ED"), _T("uri:iso.org:21090"));
}

CNPPD_ED_Doc::CNPPD_ED_Doc(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ED_Doc::CNPPD_ED_Doc(CNPPD_ED_Doc const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ED_Doc::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ED.Doc"), _T("uri:iso.org:21090"));
}

CNPPD_ED_Doc_Inline::CNPPD_ED_Doc_Inline(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ED_Doc_Inline::CNPPD_ED_Doc_Inline(CNPPD_ED_Doc_Inline const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ED_Doc_Inline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ED.Doc.Inline"), _T("uri:iso.org:21090"));
}

CNPPD_ED_Doc_Ref::CNPPD_ED_Doc_Ref(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ED_Doc_Ref::CNPPD_ED_Doc_Ref(CNPPD_ED_Doc_Ref const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ED_Doc_Ref::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ED.Doc.Ref"), _T("uri:iso.org:21090"));
}

CNPPD_ED_Image::CNPPD_ED_Image(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ED_Image::CNPPD_ED_Image(CNPPD_ED_Image const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ED_Image::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ED.Image"), _T("uri:iso.org:21090"));
}

CNPPD_ED_Narrative::CNPPD_ED_Narrative(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ED_Narrative::CNPPD_ED_Narrative(CNPPD_ED_Narrative const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ED_Narrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ED.Narrative"), _T("uri:iso.org:21090"));
}

CNPPD_ED_Signature::CNPPD_ED_Signature(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ED_Signature::CNPPD_ED_Signature(CNPPD_ED_Signature const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ED_Signature::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ED.Signature"), _T("uri:iso.org:21090"));
}

CNPPD_ED_Text::CNPPD_ED_Text(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ED_Text::CNPPD_ED_Text(CNPPD_ED_Text const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ED_Text::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ED.Text"), _T("uri:iso.org:21090"));
}

CNPPD_EN::CNPPD_EN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_EN::CNPPD_EN(CNPPD_EN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_EN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_EN"), _T("uri:iso.org:21090"));
}

CNPPD_EN_ON::CNPPD_EN_ON(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_EN_ON::CNPPD_EN_ON(CNPPD_EN_ON const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_EN_ON::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_EN.ON"), _T("uri:iso.org:21090"));
}

CNPPD_EN_PN::CNPPD_EN_PN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_EN_PN::CNPPD_EN_PN(CNPPD_EN_PN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_EN_PN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_EN.PN"), _T("uri:iso.org:21090"));
}

CNPPD_EN_TN::CNPPD_EN_TN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_EN_TN::CNPPD_EN_TN(CNPPD_EN_TN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_EN_TN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_EN.TN"), _T("uri:iso.org:21090"));
}

CNPPD_II::CNPPD_II(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_II::CNPPD_II(CNPPD_II const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_II::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_II"), _T("uri:iso.org:21090"));
}

CNPPD_INT::CNPPD_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_INT::CNPPD_INT(CNPPD_INT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_INT"), _T("uri:iso.org:21090"));
}

CNPPD_INT_NonNeg::CNPPD_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_INT_NonNeg::CNPPD_INT_NonNeg(CNPPD_INT_NonNeg const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CNPPD_INT_Positive::CNPPD_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_INT_Positive::CNPPD_INT_Positive(CNPPD_INT_Positive const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_INT.Positive"), _T("uri:iso.org:21090"));
}

CNPPD_MO::CNPPD_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_MO::CNPPD_MO(CNPPD_MO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_MO"), _T("uri:iso.org:21090"));
}

CNPPD_PQ::CNPPD_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_PQ::CNPPD_PQ(CNPPD_PQ const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_PQ"), _T("uri:iso.org:21090"));
}

CNPPD_PQ_Time::CNPPD_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_PQ_Time::CNPPD_PQ_Time(CNPPD_PQ_Time const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_PQ.Time"), _T("uri:iso.org:21090"));
}

CNPPD_REAL::CNPPD_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_REAL::CNPPD_REAL(CNPPD_REAL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_REAL"), _T("uri:iso.org:21090"));
}

CNPPD_RTO::CNPPD_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_RTO::CNPPD_RTO(CNPPD_RTO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_RTO"), _T("uri:iso.org:21090"));
}

CNPPD_SC::CNPPD_SC(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_SC::CNPPD_SC(CNPPD_SC const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_SC::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_SC"), _T("uri:iso.org:21090"));
}

CNPPD_SC_NT::CNPPD_SC_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_SC_NT::CNPPD_SC_NT(CNPPD_SC_NT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_SC_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_SC.NT"), _T("uri:iso.org:21090"));
}

CNPPD_ST::CNPPD_ST(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ST::CNPPD_ST(CNPPD_ST const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ST::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ST"), _T("uri:iso.org:21090"));
}

CNPPD_ST_NT::CNPPD_ST_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_ST_NT::CNPPD_ST_NT(CNPPD_ST_NT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_ST_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_ST.NT"), _T("uri:iso.org:21090"));
}

CNPPD_TEL::CNPPD_TEL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TEL::CNPPD_TEL(CNPPD_TEL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TEL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TEL"), _T("uri:iso.org:21090"));
}

CNPPD_TEL_Email::CNPPD_TEL_Email(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TEL_Email::CNPPD_TEL_Email(CNPPD_TEL_Email const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TEL_Email::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TEL.Email"), _T("uri:iso.org:21090"));
}

CNPPD_TEL_Person::CNPPD_TEL_Person(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TEL_Person::CNPPD_TEL_Person(CNPPD_TEL_Person const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TEL_Person::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TEL.Person"), _T("uri:iso.org:21090"));
}

CNPPD_TEL_Phone::CNPPD_TEL_Phone(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TEL_Phone::CNPPD_TEL_Phone(CNPPD_TEL_Phone const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TEL_Phone::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TEL.Phone"), _T("uri:iso.org:21090"));
}

CNPPD_TEL_Url::CNPPD_TEL_Url(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TEL_Url::CNPPD_TEL_Url(CNPPD_TEL_Url const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TEL_Url::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TEL.Url"), _T("uri:iso.org:21090"));
}

CNPPD_TS::CNPPD_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TS::CNPPD_TS(CNPPD_TS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TS"), _T("uri:iso.org:21090"));
}

CNPPD_TS_Birth::CNPPD_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TS_Birth::CNPPD_TS_Birth(CNPPD_TS_Birth const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TS.Birth"), _T("uri:iso.org:21090"));
}

CNPPD_TS_Date::CNPPD_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TS_Date::CNPPD_TS_Date(CNPPD_TS_Date const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TS.Date"), _T("uri:iso.org:21090"));
}

CNPPD_TS_Date_Full::CNPPD_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TS_Date_Full::CNPPD_TS_Date_Full(CNPPD_TS_Date_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CNPPD_TS_DateTime::CNPPD_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TS_DateTime::CNPPD_TS_DateTime(CNPPD_TS_DateTime const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TS.DateTime"), _T("uri:iso.org:21090"));
}

CNPPD_TS_DateTime_Full::CNPPD_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, item(*this)	// "item"
{
}

CNPPD_TS_DateTime_Full::CNPPD_TS_DateTime_Full(CNPPD_TS_DateTime_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, item(*this)	// "item"
{
}

void CNPPD_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("NPPD_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CNarrative::CNarrative(xercesc::DOMNode* const& node)
: TypeBase(node)
, ID(*this)	// "@ID"
, styleCode(*this)	// "@styleCode"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
, paragraph(*this)	// "paragraph"
, list(*this)	// "list"
, table(*this)	// "table"
{
}

CNarrative::CNarrative(CNarrative const& other)
: TypeBase(other.GetNode())
, ID(*this)	// "@ID"
, styleCode(*this)	// "@styleCode"
, content(*this)	// "content"
, linkHtml(*this)	// "linkHtml"
, sub(*this)	// "sub"
, sup(*this)	// "sup"
, br(*this)	// "br"
, footnote(*this)	// "footnote"
, footnoteRef(*this)	// "footnoteRef"
, renderMultiMedia(*this)	// "renderMultiMedia"
, paragraph(*this)	// "paragraph"
, list(*this)	// "list"
, table(*this)	// "table"
{
}

void CNarrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("Narrative"), _T("uri:iso.org:21090"));
}

CNullFlavor::CNullFlavor(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CNullFlavor::CNullFlavor(CNullFlavor const& other)
: TypeBase(other.GetNode())
{
}


CPIVL_TS::CPIVL_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS(node)
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

CPIVL_TS::CPIVL_TS(CPIVL_TS const& other)
: ::AIMXML::iso::CQSET_TS(other.GetNode())
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

void CPIVL_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PIVL_TS"), _T("uri:iso.org:21090"));
}

CPIVL_TS_Birth::CPIVL_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Birth(node)
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

CPIVL_TS_Birth::CPIVL_TS_Birth(CPIVL_TS_Birth const& other)
: ::AIMXML::iso::CQSET_TS_Birth(other.GetNode())
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

void CPIVL_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PIVL_TS.Birth"), _T("uri:iso.org:21090"));
}

CPIVL_TS_Date::CPIVL_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date(node)
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

CPIVL_TS_Date::CPIVL_TS_Date(CPIVL_TS_Date const& other)
: ::AIMXML::iso::CQSET_TS_Date(other.GetNode())
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

void CPIVL_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PIVL_TS.Date"), _T("uri:iso.org:21090"));
}

CPIVL_TS_Date_Full::CPIVL_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date_Full(node)
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

CPIVL_TS_Date_Full::CPIVL_TS_Date_Full(CPIVL_TS_Date_Full const& other)
: ::AIMXML::iso::CQSET_TS_Date_Full(other.GetNode())
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

void CPIVL_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PIVL_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CPIVL_TS_DateTime::CPIVL_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime(node)
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

CPIVL_TS_DateTime::CPIVL_TS_DateTime(CPIVL_TS_DateTime const& other)
: ::AIMXML::iso::CQSET_TS_DateTime(other.GetNode())
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

void CPIVL_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PIVL_TS.DateTime"), _T("uri:iso.org:21090"));
}

CPIVL_TS_DateTime_Full::CPIVL_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(node)
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

CPIVL_TS_DateTime_Full::CPIVL_TS_DateTime_Full(CPIVL_TS_DateTime_Full const& other)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(other.GetNode())
, alignment(*this)	// "@alignment"
, institutionSpecified(*this)	// "@institutionSpecified"
, phase(*this)	// "phase"
, period(*this)	// "period"
{
}

void CPIVL_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PIVL_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CPQ::CPQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQTY(node)
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
, unit(*this)	// "@unit"
, codingRationale(*this)	// "@codingRationale"
, translation(*this)	// "translation"
{
}

CPQ::CPQ(CPQ const& other)
: ::AIMXML::iso::CQTY(other.GetNode())
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
, unit(*this)	// "@unit"
, codingRationale(*this)	// "@codingRationale"
, translation(*this)	// "translation"
{
}

void CPQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PQ"), _T("uri:iso.org:21090"));
}

CPQ_Time::CPQ_Time(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
, unit(*this)	// "@unit"
, codingRationale(*this)	// "@codingRationale"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
, translation(*this)	// "translation"
{
}

CPQ_Time::CPQ_Time(CPQ_Time const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
, unit(*this)	// "@unit"
, codingRationale(*this)	// "@codingRationale"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
, translation(*this)	// "translation"
{
}

void CPQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PQ.Time"), _T("uri:iso.org:21090"));
}

CPQR::CPQR(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CCD(node)
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
{
}

CPQR::CPQR(CPQR const& other)
: ::AIMXML::iso::CCD(other.GetNode())
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
{
}

void CPQR::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("PQR"), _T("uri:iso.org:21090"));
}

CPostalAddressUse::CPostalAddressUse(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CPostalAddressUse::CPostalAddressUse(CPostalAddressUse const& other)
: TypeBase(other.GetNode())
{
}


CQSD_CO::CQSD_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_CO(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_CO::CQSD_CO(CQSD_CO const& other)
: ::AIMXML::iso::CQSET_CO(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_CO"), _T("uri:iso.org:21090"));
}

CQSD_INT::CQSD_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_INT::CQSD_INT(CQSD_INT const& other)
: ::AIMXML::iso::CQSET_INT(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_INT"), _T("uri:iso.org:21090"));
}

CQSD_INT_NonNeg::CQSD_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_NonNeg(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_INT_NonNeg::CQSD_INT_NonNeg(CQSD_INT_NonNeg const& other)
: ::AIMXML::iso::CQSET_INT_NonNeg(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CQSD_INT_Positive::CQSD_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_Positive(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_INT_Positive::CQSD_INT_Positive(CQSD_INT_Positive const& other)
: ::AIMXML::iso::CQSET_INT_Positive(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_INT.Positive"), _T("uri:iso.org:21090"));
}

CQSD_MO::CQSD_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_MO(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_MO::CQSD_MO(CQSD_MO const& other)
: ::AIMXML::iso::CQSET_MO(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_MO"), _T("uri:iso.org:21090"));
}

CQSD_PQ::CQSD_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_PQ::CQSD_PQ(CQSD_PQ const& other)
: ::AIMXML::iso::CQSET_PQ(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_PQ"), _T("uri:iso.org:21090"));
}

CQSD_PQ_Time::CQSD_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ_Time(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_PQ_Time::CQSD_PQ_Time(CQSD_PQ_Time const& other)
: ::AIMXML::iso::CQSET_PQ_Time(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_PQ.Time"), _T("uri:iso.org:21090"));
}

CQSD_REAL::CQSD_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_REAL(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_REAL::CQSD_REAL(CQSD_REAL const& other)
: ::AIMXML::iso::CQSET_REAL(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_REAL"), _T("uri:iso.org:21090"));
}

CQSD_RTO::CQSD_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_RTO(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_RTO::CQSD_RTO(CQSD_RTO const& other)
: ::AIMXML::iso::CQSET_RTO(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_RTO"), _T("uri:iso.org:21090"));
}

CQSD_TS::CQSD_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_TS::CQSD_TS(CQSD_TS const& other)
: ::AIMXML::iso::CQSET_TS(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_TS"), _T("uri:iso.org:21090"));
}

CQSD_TS_Birth::CQSD_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Birth(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_TS_Birth::CQSD_TS_Birth(CQSD_TS_Birth const& other)
: ::AIMXML::iso::CQSET_TS_Birth(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_TS.Birth"), _T("uri:iso.org:21090"));
}

CQSD_TS_Date::CQSD_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_TS_Date::CQSD_TS_Date(CQSD_TS_Date const& other)
: ::AIMXML::iso::CQSET_TS_Date(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_TS.Date"), _T("uri:iso.org:21090"));
}

CQSD_TS_Date_Full::CQSD_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date_Full(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_TS_Date_Full::CQSD_TS_Date_Full(CQSD_TS_Date_Full const& other)
: ::AIMXML::iso::CQSET_TS_Date_Full(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CQSD_TS_DateTime::CQSD_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_TS_DateTime::CQSD_TS_DateTime(CQSD_TS_DateTime const& other)
: ::AIMXML::iso::CQSET_TS_DateTime(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_TS.DateTime"), _T("uri:iso.org:21090"));
}

CQSD_TS_DateTime_Full::CQSD_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSD_TS_DateTime_Full::CQSD_TS_DateTime_Full(CQSD_TS_DateTime_Full const& other)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSD_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSD_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CQSET_BoundedPIVL::CQSET_BoundedPIVL(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, originalText(*this)	// "originalText"
, term(*this)	// "term"
{
}

CQSET_BoundedPIVL::CQSET_BoundedPIVL(CQSET_BoundedPIVL const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, originalText(*this)	// "originalText"
, term(*this)	// "term"
{
}

void CQSET_BoundedPIVL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET.BoundedPIVL"), _T("uri:iso.org:21090"));
}

CQSET_CO::CQSET_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_CO::CQSET_CO(CQSET_CO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_CO"), _T("uri:iso.org:21090"));
}

CQSET_INT::CQSET_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_INT::CQSET_INT(CQSET_INT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_INT"), _T("uri:iso.org:21090"));
}

CQSET_INT_NonNeg::CQSET_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_INT_NonNeg::CQSET_INT_NonNeg(CQSET_INT_NonNeg const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CQSET_INT_Positive::CQSET_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_INT_Positive::CQSET_INT_Positive(CQSET_INT_Positive const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_INT.Positive"), _T("uri:iso.org:21090"));
}

CQSET_MO::CQSET_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_MO::CQSET_MO(CQSET_MO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_MO"), _T("uri:iso.org:21090"));
}

CQSET_PQ::CQSET_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_PQ::CQSET_PQ(CQSET_PQ const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_PQ"), _T("uri:iso.org:21090"));
}

CQSET_PQ_Time::CQSET_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_PQ_Time::CQSET_PQ_Time(CQSET_PQ_Time const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_PQ.Time"), _T("uri:iso.org:21090"));
}

CQSET_REAL::CQSET_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_REAL::CQSET_REAL(CQSET_REAL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_REAL"), _T("uri:iso.org:21090"));
}

CQSET_RTO::CQSET_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_RTO::CQSET_RTO(CQSET_RTO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_RTO"), _T("uri:iso.org:21090"));
}

CQSET_TS::CQSET_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_TS::CQSET_TS(CQSET_TS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_TS"), _T("uri:iso.org:21090"));
}

CQSET_TS_Birth::CQSET_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_TS_Birth::CQSET_TS_Birth(CQSET_TS_Birth const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_TS.Birth"), _T("uri:iso.org:21090"));
}

CQSET_TS_Date::CQSET_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_TS_Date::CQSET_TS_Date(CQSET_TS_Date const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_TS.Date"), _T("uri:iso.org:21090"));
}

CQSET_TS_Date_Full::CQSET_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_TS_Date_Full::CQSET_TS_Date_Full(CQSET_TS_Date_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CQSET_TS_DateTime::CQSET_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_TS_DateTime::CQSET_TS_DateTime(CQSET_TS_DateTime const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_TS.DateTime"), _T("uri:iso.org:21090"));
}

CQSET_TS_DateTime_Full::CQSET_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, originalText(*this)	// "originalText"
{
}

CQSET_TS_DateTime_Full::CQSET_TS_DateTime_Full(CQSET_TS_DateTime_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, originalText(*this)	// "originalText"
{
}

void CQSET_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSET_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CQSI_CO::CQSI_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_CO(node)
, term(*this)	// "term"
{
}

CQSI_CO::CQSI_CO(CQSI_CO const& other)
: ::AIMXML::iso::CQSET_CO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_CO"), _T("uri:iso.org:21090"));
}

CQSI_INT::CQSI_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT(node)
, term(*this)	// "term"
{
}

CQSI_INT::CQSI_INT(CQSI_INT const& other)
: ::AIMXML::iso::CQSET_INT(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_INT"), _T("uri:iso.org:21090"));
}

CQSI_INT_NonNeg::CQSI_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_NonNeg(node)
, term(*this)	// "term"
{
}

CQSI_INT_NonNeg::CQSI_INT_NonNeg(CQSI_INT_NonNeg const& other)
: ::AIMXML::iso::CQSET_INT_NonNeg(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CQSI_INT_Positive::CQSI_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_Positive(node)
, term(*this)	// "term"
{
}

CQSI_INT_Positive::CQSI_INT_Positive(CQSI_INT_Positive const& other)
: ::AIMXML::iso::CQSET_INT_Positive(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_INT.Positive"), _T("uri:iso.org:21090"));
}

CQSI_MO::CQSI_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_MO(node)
, term(*this)	// "term"
{
}

CQSI_MO::CQSI_MO(CQSI_MO const& other)
: ::AIMXML::iso::CQSET_MO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_MO"), _T("uri:iso.org:21090"));
}

CQSI_PQ::CQSI_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ(node)
, term(*this)	// "term"
{
}

CQSI_PQ::CQSI_PQ(CQSI_PQ const& other)
: ::AIMXML::iso::CQSET_PQ(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_PQ"), _T("uri:iso.org:21090"));
}

CQSI_PQ_Time::CQSI_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ_Time(node)
, term(*this)	// "term"
{
}

CQSI_PQ_Time::CQSI_PQ_Time(CQSI_PQ_Time const& other)
: ::AIMXML::iso::CQSET_PQ_Time(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_PQ.Time"), _T("uri:iso.org:21090"));
}

CQSI_REAL::CQSI_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_REAL(node)
, term(*this)	// "term"
{
}

CQSI_REAL::CQSI_REAL(CQSI_REAL const& other)
: ::AIMXML::iso::CQSET_REAL(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_REAL"), _T("uri:iso.org:21090"));
}

CQSI_RTO::CQSI_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_RTO(node)
, term(*this)	// "term"
{
}

CQSI_RTO::CQSI_RTO(CQSI_RTO const& other)
: ::AIMXML::iso::CQSET_RTO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_RTO"), _T("uri:iso.org:21090"));
}

CQSI_TS::CQSI_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS(node)
, term(*this)	// "term"
{
}

CQSI_TS::CQSI_TS(CQSI_TS const& other)
: ::AIMXML::iso::CQSET_TS(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_TS"), _T("uri:iso.org:21090"));
}

CQSI_TS_Birth::CQSI_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Birth(node)
, term(*this)	// "term"
{
}

CQSI_TS_Birth::CQSI_TS_Birth(CQSI_TS_Birth const& other)
: ::AIMXML::iso::CQSET_TS_Birth(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_TS.Birth"), _T("uri:iso.org:21090"));
}

CQSI_TS_Date::CQSI_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date(node)
, term(*this)	// "term"
{
}

CQSI_TS_Date::CQSI_TS_Date(CQSI_TS_Date const& other)
: ::AIMXML::iso::CQSET_TS_Date(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_TS.Date"), _T("uri:iso.org:21090"));
}

CQSI_TS_Date_Full::CQSI_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date_Full(node)
, term(*this)	// "term"
{
}

CQSI_TS_Date_Full::CQSI_TS_Date_Full(CQSI_TS_Date_Full const& other)
: ::AIMXML::iso::CQSET_TS_Date_Full(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CQSI_TS_DateTime::CQSI_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime(node)
, term(*this)	// "term"
{
}

CQSI_TS_DateTime::CQSI_TS_DateTime(CQSI_TS_DateTime const& other)
: ::AIMXML::iso::CQSET_TS_DateTime(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_TS.DateTime"), _T("uri:iso.org:21090"));
}

CQSI_TS_DateTime_Full::CQSI_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(node)
, term(*this)	// "term"
{
}

CQSI_TS_DateTime_Full::CQSI_TS_DateTime_Full(CQSI_TS_DateTime_Full const& other)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(other.GetNode())
, term(*this)	// "term"
{
}

void CQSI_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSI_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CQSP_CO::CQSP_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_CO(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_CO::CQSP_CO(CQSP_CO const& other)
: ::AIMXML::iso::CQSET_CO(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_CO"), _T("uri:iso.org:21090"));
}

CQSP_INT::CQSP_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_INT::CQSP_INT(CQSP_INT const& other)
: ::AIMXML::iso::CQSET_INT(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_INT"), _T("uri:iso.org:21090"));
}

CQSP_INT_NonNeg::CQSP_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_NonNeg(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_INT_NonNeg::CQSP_INT_NonNeg(CQSP_INT_NonNeg const& other)
: ::AIMXML::iso::CQSET_INT_NonNeg(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CQSP_INT_Positive::CQSP_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_Positive(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_INT_Positive::CQSP_INT_Positive(CQSP_INT_Positive const& other)
: ::AIMXML::iso::CQSET_INT_Positive(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_INT.Positive"), _T("uri:iso.org:21090"));
}

CQSP_MO::CQSP_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_MO(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_MO::CQSP_MO(CQSP_MO const& other)
: ::AIMXML::iso::CQSET_MO(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_MO"), _T("uri:iso.org:21090"));
}

CQSP_PQ::CQSP_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_PQ::CQSP_PQ(CQSP_PQ const& other)
: ::AIMXML::iso::CQSET_PQ(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_PQ"), _T("uri:iso.org:21090"));
}

CQSP_PQ_Time::CQSP_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ_Time(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_PQ_Time::CQSP_PQ_Time(CQSP_PQ_Time const& other)
: ::AIMXML::iso::CQSET_PQ_Time(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_PQ.Time"), _T("uri:iso.org:21090"));
}

CQSP_REAL::CQSP_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_REAL(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_REAL::CQSP_REAL(CQSP_REAL const& other)
: ::AIMXML::iso::CQSET_REAL(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_REAL"), _T("uri:iso.org:21090"));
}

CQSP_RTO::CQSP_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_RTO(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_RTO::CQSP_RTO(CQSP_RTO const& other)
: ::AIMXML::iso::CQSET_RTO(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_RTO"), _T("uri:iso.org:21090"));
}

CQSP_TS::CQSP_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_TS::CQSP_TS(CQSP_TS const& other)
: ::AIMXML::iso::CQSET_TS(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_TS"), _T("uri:iso.org:21090"));
}

CQSP_TS_Birth::CQSP_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Birth(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_TS_Birth::CQSP_TS_Birth(CQSP_TS_Birth const& other)
: ::AIMXML::iso::CQSET_TS_Birth(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_TS.Birth"), _T("uri:iso.org:21090"));
}

CQSP_TS_Date::CQSP_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_TS_Date::CQSP_TS_Date(CQSP_TS_Date const& other)
: ::AIMXML::iso::CQSET_TS_Date(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_TS.Date"), _T("uri:iso.org:21090"));
}

CQSP_TS_Date_Full::CQSP_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date_Full(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_TS_Date_Full::CQSP_TS_Date_Full(CQSP_TS_Date_Full const& other)
: ::AIMXML::iso::CQSET_TS_Date_Full(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CQSP_TS_DateTime::CQSP_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_TS_DateTime::CQSP_TS_DateTime(CQSP_TS_DateTime const& other)
: ::AIMXML::iso::CQSET_TS_DateTime(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_TS.DateTime"), _T("uri:iso.org:21090"));
}

CQSP_TS_DateTime_Full::CQSP_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(node)
, first(*this)	// "first"
, second(*this)	// "second"
{
}

CQSP_TS_DateTime_Full::CQSP_TS_DateTime_Full(CQSP_TS_DateTime_Full const& other)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(other.GetNode())
, first(*this)	// "first"
, second(*this)	// "second"
{
}

void CQSP_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSP_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CQSS_CO::CQSS_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_CO(node)
, term(*this)	// "term"
{
}

CQSS_CO::CQSS_CO(CQSS_CO const& other)
: ::AIMXML::iso::CQSET_CO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_CO"), _T("uri:iso.org:21090"));
}

CQSS_INT::CQSS_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT(node)
, term(*this)	// "term"
{
}

CQSS_INT::CQSS_INT(CQSS_INT const& other)
: ::AIMXML::iso::CQSET_INT(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_INT"), _T("uri:iso.org:21090"));
}

CQSS_INT_NonNeg::CQSS_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_NonNeg(node)
, term(*this)	// "term"
{
}

CQSS_INT_NonNeg::CQSS_INT_NonNeg(CQSS_INT_NonNeg const& other)
: ::AIMXML::iso::CQSET_INT_NonNeg(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CQSS_INT_Positive::CQSS_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_Positive(node)
, term(*this)	// "term"
{
}

CQSS_INT_Positive::CQSS_INT_Positive(CQSS_INT_Positive const& other)
: ::AIMXML::iso::CQSET_INT_Positive(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_INT.Positive"), _T("uri:iso.org:21090"));
}

CQSS_MO::CQSS_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_MO(node)
, term(*this)	// "term"
{
}

CQSS_MO::CQSS_MO(CQSS_MO const& other)
: ::AIMXML::iso::CQSET_MO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_MO"), _T("uri:iso.org:21090"));
}

CQSS_PQ::CQSS_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ(node)
, term(*this)	// "term"
{
}

CQSS_PQ::CQSS_PQ(CQSS_PQ const& other)
: ::AIMXML::iso::CQSET_PQ(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_PQ"), _T("uri:iso.org:21090"));
}

CQSS_PQ_Time::CQSS_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ_Time(node)
, term(*this)	// "term"
{
}

CQSS_PQ_Time::CQSS_PQ_Time(CQSS_PQ_Time const& other)
: ::AIMXML::iso::CQSET_PQ_Time(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_PQ.Time"), _T("uri:iso.org:21090"));
}

CQSS_REAL::CQSS_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_REAL(node)
, term(*this)	// "term"
{
}

CQSS_REAL::CQSS_REAL(CQSS_REAL const& other)
: ::AIMXML::iso::CQSET_REAL(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_REAL"), _T("uri:iso.org:21090"));
}

CQSS_RTO::CQSS_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_RTO(node)
, term(*this)	// "term"
{
}

CQSS_RTO::CQSS_RTO(CQSS_RTO const& other)
: ::AIMXML::iso::CQSET_RTO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_RTO"), _T("uri:iso.org:21090"));
}

CQSS_TS::CQSS_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS(node)
, term(*this)	// "term"
{
}

CQSS_TS::CQSS_TS(CQSS_TS const& other)
: ::AIMXML::iso::CQSET_TS(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_TS"), _T("uri:iso.org:21090"));
}

CQSS_TS_Birth::CQSS_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Birth(node)
, term(*this)	// "term"
{
}

CQSS_TS_Birth::CQSS_TS_Birth(CQSS_TS_Birth const& other)
: ::AIMXML::iso::CQSET_TS_Birth(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_TS.Birth"), _T("uri:iso.org:21090"));
}

CQSS_TS_Date::CQSS_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date(node)
, term(*this)	// "term"
{
}

CQSS_TS_Date::CQSS_TS_Date(CQSS_TS_Date const& other)
: ::AIMXML::iso::CQSET_TS_Date(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_TS.Date"), _T("uri:iso.org:21090"));
}

CQSS_TS_Date_Full::CQSS_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date_Full(node)
, term(*this)	// "term"
{
}

CQSS_TS_Date_Full::CQSS_TS_Date_Full(CQSS_TS_Date_Full const& other)
: ::AIMXML::iso::CQSET_TS_Date_Full(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CQSS_TS_DateTime::CQSS_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime(node)
, term(*this)	// "term"
{
}

CQSS_TS_DateTime::CQSS_TS_DateTime(CQSS_TS_DateTime const& other)
: ::AIMXML::iso::CQSET_TS_DateTime(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_TS.DateTime"), _T("uri:iso.org:21090"));
}

CQSS_TS_DateTime_Full::CQSS_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(node)
, term(*this)	// "term"
{
}

CQSS_TS_DateTime_Full::CQSS_TS_DateTime_Full(CQSS_TS_DateTime_Full const& other)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(other.GetNode())
, term(*this)	// "term"
{
}

void CQSS_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSS_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CQSU_CO::CQSU_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_CO(node)
, term(*this)	// "term"
{
}

CQSU_CO::CQSU_CO(CQSU_CO const& other)
: ::AIMXML::iso::CQSET_CO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_CO"), _T("uri:iso.org:21090"));
}

CQSU_INT::CQSU_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT(node)
, term(*this)	// "term"
{
}

CQSU_INT::CQSU_INT(CQSU_INT const& other)
: ::AIMXML::iso::CQSET_INT(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_INT"), _T("uri:iso.org:21090"));
}

CQSU_INT_NonNeg::CQSU_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_NonNeg(node)
, term(*this)	// "term"
{
}

CQSU_INT_NonNeg::CQSU_INT_NonNeg(CQSU_INT_NonNeg const& other)
: ::AIMXML::iso::CQSET_INT_NonNeg(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CQSU_INT_Positive::CQSU_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_INT_Positive(node)
, term(*this)	// "term"
{
}

CQSU_INT_Positive::CQSU_INT_Positive(CQSU_INT_Positive const& other)
: ::AIMXML::iso::CQSET_INT_Positive(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_INT.Positive"), _T("uri:iso.org:21090"));
}

CQSU_MO::CQSU_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_MO(node)
, term(*this)	// "term"
{
}

CQSU_MO::CQSU_MO(CQSU_MO const& other)
: ::AIMXML::iso::CQSET_MO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_MO"), _T("uri:iso.org:21090"));
}

CQSU_PQ::CQSU_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ(node)
, term(*this)	// "term"
{
}

CQSU_PQ::CQSU_PQ(CQSU_PQ const& other)
: ::AIMXML::iso::CQSET_PQ(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_PQ"), _T("uri:iso.org:21090"));
}

CQSU_PQ_Time::CQSU_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_PQ_Time(node)
, term(*this)	// "term"
{
}

CQSU_PQ_Time::CQSU_PQ_Time(CQSU_PQ_Time const& other)
: ::AIMXML::iso::CQSET_PQ_Time(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_PQ.Time"), _T("uri:iso.org:21090"));
}

CQSU_REAL::CQSU_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_REAL(node)
, term(*this)	// "term"
{
}

CQSU_REAL::CQSU_REAL(CQSU_REAL const& other)
: ::AIMXML::iso::CQSET_REAL(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_REAL"), _T("uri:iso.org:21090"));
}

CQSU_RTO::CQSU_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_RTO(node)
, term(*this)	// "term"
{
}

CQSU_RTO::CQSU_RTO(CQSU_RTO const& other)
: ::AIMXML::iso::CQSET_RTO(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_RTO"), _T("uri:iso.org:21090"));
}

CQSU_TS::CQSU_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS(node)
, term(*this)	// "term"
{
}

CQSU_TS::CQSU_TS(CQSU_TS const& other)
: ::AIMXML::iso::CQSET_TS(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_TS"), _T("uri:iso.org:21090"));
}

CQSU_TS_Birth::CQSU_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Birth(node)
, term(*this)	// "term"
{
}

CQSU_TS_Birth::CQSU_TS_Birth(CQSU_TS_Birth const& other)
: ::AIMXML::iso::CQSET_TS_Birth(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_TS.Birth"), _T("uri:iso.org:21090"));
}

CQSU_TS_Date::CQSU_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date(node)
, term(*this)	// "term"
{
}

CQSU_TS_Date::CQSU_TS_Date(CQSU_TS_Date const& other)
: ::AIMXML::iso::CQSET_TS_Date(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_TS.Date"), _T("uri:iso.org:21090"));
}

CQSU_TS_Date_Full::CQSU_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_Date_Full(node)
, term(*this)	// "term"
{
}

CQSU_TS_Date_Full::CQSU_TS_Date_Full(CQSU_TS_Date_Full const& other)
: ::AIMXML::iso::CQSET_TS_Date_Full(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CQSU_TS_DateTime::CQSU_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime(node)
, term(*this)	// "term"
{
}

CQSU_TS_DateTime::CQSU_TS_DateTime(CQSU_TS_DateTime const& other)
: ::AIMXML::iso::CQSET_TS_DateTime(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_TS.DateTime"), _T("uri:iso.org:21090"));
}

CQSU_TS_DateTime_Full::CQSU_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(node)
, term(*this)	// "term"
{
}

CQSU_TS_DateTime_Full::CQSU_TS_DateTime_Full(CQSU_TS_DateTime_Full const& other)
: ::AIMXML::iso::CQSET_TS_DateTime_Full(other.GetNode())
, term(*this)	// "term"
{
}

void CQSU_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QSU_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CQTY::CQTY(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

CQTY::CQTY(CQTY const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

void CQTY::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("QTY"), _T("uri:iso.org:21090"));
}

CREAL::CREAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQTY(node)
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
{
}

CREAL::CREAL(CREAL const& other)
: ::AIMXML::iso::CQTY(other.GetNode())
, value2(*this)	// "@value"
, precision(*this)	// "@precision"
{
}

void CREAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("REAL"), _T("uri:iso.org:21090"));
}

CRTO::CRTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQTY(node)
, numerator(*this)	// "numerator"
, denominator(*this)	// "denominator"
{
}

CRTO::CRTO(CRTO const& other)
: ::AIMXML::iso::CQTY(other.GetNode())
, numerator(*this)	// "numerator"
, denominator(*this)	// "denominator"
{
}

void CRTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("RTO"), _T("uri:iso.org:21090"));
}

CSC::CSC(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CST(node)
, code(*this)	// "code"
{
}

CSC::CSC(CSC const& other)
: ::AIMXML::iso::CST(other.GetNode())
, code(*this)	// "code"
{
}

void CSC::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SC"), _T("uri:iso.org:21090"));
}

CSC_NT::CSC_NT(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, language(*this)	// "@language"
, translation(*this)	// "translation"
, code(*this)	// "code"
{
}

CSC_NT::CSC_NT(CSC_NT const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, language(*this)	// "@language"
, translation(*this)	// "translation"
, code(*this)	// "code"
{
}

void CSC_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SC.NT"), _T("uri:iso.org:21090"));
}

CSLIST_CO::CSLIST_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_CO::CSLIST_CO(CSLIST_CO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_CO"), _T("uri:iso.org:21090"));
}

CSLIST_INT::CSLIST_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_INT::CSLIST_INT(CSLIST_INT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_INT"), _T("uri:iso.org:21090"));
}

CSLIST_INT_NonNeg::CSLIST_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_INT_NonNeg::CSLIST_INT_NonNeg(CSLIST_INT_NonNeg const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CSLIST_INT_Positive::CSLIST_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_INT_Positive::CSLIST_INT_Positive(CSLIST_INT_Positive const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_INT.Positive"), _T("uri:iso.org:21090"));
}

CSLIST_MO::CSLIST_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_MO::CSLIST_MO(CSLIST_MO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_MO"), _T("uri:iso.org:21090"));
}

CSLIST_PQ::CSLIST_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_PQ::CSLIST_PQ(CSLIST_PQ const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_PQ"), _T("uri:iso.org:21090"));
}

CSLIST_PQ_Time::CSLIST_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_PQ_Time::CSLIST_PQ_Time(CSLIST_PQ_Time const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_PQ.Time"), _T("uri:iso.org:21090"));
}

CSLIST_REAL::CSLIST_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_REAL::CSLIST_REAL(CSLIST_REAL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_REAL"), _T("uri:iso.org:21090"));
}

CSLIST_RTO::CSLIST_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_RTO::CSLIST_RTO(CSLIST_RTO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_RTO"), _T("uri:iso.org:21090"));
}

CSLIST_TS::CSLIST_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_TS::CSLIST_TS(CSLIST_TS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_TS"), _T("uri:iso.org:21090"));
}

CSLIST_TS_Birth::CSLIST_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_TS_Birth::CSLIST_TS_Birth(CSLIST_TS_Birth const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_TS.Birth"), _T("uri:iso.org:21090"));
}

CSLIST_TS_Date::CSLIST_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_TS_Date::CSLIST_TS_Date(CSLIST_TS_Date const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_TS.Date"), _T("uri:iso.org:21090"));
}

CSLIST_TS_Date_Full::CSLIST_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_TS_Date_Full::CSLIST_TS_Date_Full(CSLIST_TS_Date_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CSLIST_TS_DateTime::CSLIST_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_TS_DateTime::CSLIST_TS_DateTime(CSLIST_TS_DateTime const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_TS.DateTime"), _T("uri:iso.org:21090"));
}

CSLIST_TS_DateTime_Full::CSLIST_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

CSLIST_TS_DateTime_Full::CSLIST_TS_DateTime_Full(CSLIST_TS_DateTime_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, origin(*this)	// "origin"
, scale(*this)	// "scale"
, digit(*this)	// "digit"
{
}

void CSLIST_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("SLIST_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CST::CST(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, value2(*this)	// "@value"
, language(*this)	// "@language"
, translation(*this)	// "translation"
{
}

CST::CST(CST const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, value2(*this)	// "@value"
, language(*this)	// "@language"
, translation(*this)	// "translation"
{
}

void CST::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ST"), _T("uri:iso.org:21090"));
}

CST_NT::CST_NT(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, language(*this)	// "@language"
, translation(*this)	// "translation"
{
}

CST_NT::CST_NT(CST_NT const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, language(*this)	// "@language"
, translation(*this)	// "translation"
{
}

void CST_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("ST.NT"), _T("uri:iso.org:21090"));
}

CTEL::CTEL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CURL(node)
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

CTEL::CTEL(CTEL const& other)
: ::AIMXML::iso::CURL(other.GetNode())
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

void CTEL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TEL"), _T("uri:iso.org:21090"));
}

CTEL_Email::CTEL_Email(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

CTEL_Email::CTEL_Email(CTEL_Email const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

void CTEL_Email::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TEL.Email"), _T("uri:iso.org:21090"));
}

CTEL_Person::CTEL_Person(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

CTEL_Person::CTEL_Person(CTEL_Person const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

void CTEL_Person::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TEL.Person"), _T("uri:iso.org:21090"));
}

CTEL_Phone::CTEL_Phone(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

CTEL_Phone::CTEL_Phone(CTEL_Phone const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

void CTEL_Phone::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TEL.Phone"), _T("uri:iso.org:21090"));
}

CTEL_Url::CTEL_Url(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

CTEL_Url::CTEL_Url(CTEL_Url const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, value2(*this)	// "@value"
, use(*this)	// "@use"
, useablePeriod(*this)	// "useablePeriod"
{
}

void CTEL_Url::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TEL.Url"), _T("uri:iso.org:21090"));
}

CTS::CTS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CQTY(node)
, value2(*this)	// "@value"
{
}

CTS::CTS(CTS const& other)
: ::AIMXML::iso::CQTY(other.GetNode())
, value2(*this)	// "@value"
{
}

void CTS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TS"), _T("uri:iso.org:21090"));
}

CTS_Birth::CTS_Birth(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

CTS_Birth::CTS_Birth(CTS_Birth const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

void CTS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TS.Birth"), _T("uri:iso.org:21090"));
}

CTS_Date::CTS_Date(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

CTS_Date::CTS_Date(CTS_Date const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

void CTS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TS.Date"), _T("uri:iso.org:21090"));
}

CTS_Date_Full::CTS_Date_Full(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

CTS_Date_Full::CTS_Date_Full(CTS_Date_Full const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

void CTS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TS.Date.Full"), _T("uri:iso.org:21090"));
}

CTS_DateTime::CTS_DateTime(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

CTS_DateTime::CTS_DateTime(CTS_DateTime const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

void CTS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TS.DateTime"), _T("uri:iso.org:21090"));
}

CTS_DateTime_Full::CTS_DateTime_Full(xercesc::DOMNode* const& node)
: TypeBase(node)
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

CTS_DateTime_Full::CTS_DateTime_Full(CTS_DateTime_Full const& other)
: TypeBase(other.GetNode())
, validTimeLow(*this)	// "@validTimeLow"
, validTimeHigh(*this)	// "@validTimeHigh"
, controlActRoot(*this)	// "@controlActRoot"
, controlActExtension(*this)	// "@controlActExtension"
, nullFlavor(*this)	// "@nullFlavor"
, flavorId(*this)	// "@flavorId"
, updateMode(*this)	// "@updateMode"
, expressionLanguage(*this)	// "@expressionLanguage"
, uncertaintyType(*this)	// "@uncertaintyType"
, value2(*this)	// "@value"
, expression(*this)	// "expression"
, originalText(*this)	// "originalText"
, uncertainty(*this)	// "uncertainty"
{
}

void CTS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CTelecommunicationAddressUse::CTelecommunicationAddressUse(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CTelecommunicationAddressUse::CTelecommunicationAddressUse(CTelecommunicationAddressUse const& other)
: TypeBase(other.GetNode())
{
}


CTimingEvent::CTimingEvent(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CTimingEvent::CTimingEvent(CTimingEvent const& other)
: TypeBase(other.GetNode())
{
}


CURL::CURL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, value2(*this)	// "@value"
{
}

CURL::CURL(CURL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, value2(*this)	// "@value"
{
}

void CURL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("URL"), _T("uri:iso.org:21090"));
}

CUVP_AD::CUVP_AD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_AD::CUVP_AD(CUVP_AD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_AD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_AD"), _T("uri:iso.org:21090"));
}

CUVP_BL::CUVP_BL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_BL::CUVP_BL(CUVP_BL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_BL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_BL"), _T("uri:iso.org:21090"));
}

CUVP_BL_NonNull::CUVP_BL_NonNull(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_BL_NonNull::CUVP_BL_NonNull(CUVP_BL_NonNull const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_BL_NonNull::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_BL.NonNull"), _T("uri:iso.org:21090"));
}

CUVP_CD::CUVP_CD(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_CD::CUVP_CD(CUVP_CD const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_CD::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_CD"), _T("uri:iso.org:21090"));
}

CUVP_CD_CE::CUVP_CD_CE(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_CD_CE::CUVP_CD_CE(CUVP_CD_CE const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_CD_CE::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_CD.CE"), _T("uri:iso.org:21090"));
}

CUVP_CD_CE_None::CUVP_CD_CE_None(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_CD_CE_None::CUVP_CD_CE_None(CUVP_CD_CE_None const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_CD_CE_None::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_CD.CE.None"), _T("uri:iso.org:21090"));
}

CUVP_CD_CV::CUVP_CD_CV(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_CD_CV::CUVP_CD_CV(CUVP_CD_CV const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_CD_CV::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_CD.CV"), _T("uri:iso.org:21090"));
}

CUVP_CO::CUVP_CO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_CO::CUVP_CO(CUVP_CO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_CO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_CO"), _T("uri:iso.org:21090"));
}

CUVP_CS::CUVP_CS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_CS::CUVP_CS(CUVP_CS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_CS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_CS"), _T("uri:iso.org:21090"));
}

CUVP_ED::CUVP_ED(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ED::CUVP_ED(CUVP_ED const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ED::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ED"), _T("uri:iso.org:21090"));
}

CUVP_ED_Doc::CUVP_ED_Doc(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ED_Doc::CUVP_ED_Doc(CUVP_ED_Doc const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ED_Doc::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ED.Doc"), _T("uri:iso.org:21090"));
}

CUVP_ED_Doc_Inline::CUVP_ED_Doc_Inline(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ED_Doc_Inline::CUVP_ED_Doc_Inline(CUVP_ED_Doc_Inline const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ED_Doc_Inline::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ED.Doc.Inline"), _T("uri:iso.org:21090"));
}

CUVP_ED_Doc_Ref::CUVP_ED_Doc_Ref(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ED_Doc_Ref::CUVP_ED_Doc_Ref(CUVP_ED_Doc_Ref const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ED_Doc_Ref::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ED.Doc.Ref"), _T("uri:iso.org:21090"));
}

CUVP_ED_Image::CUVP_ED_Image(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ED_Image::CUVP_ED_Image(CUVP_ED_Image const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ED_Image::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ED.Image"), _T("uri:iso.org:21090"));
}

CUVP_ED_Narrative::CUVP_ED_Narrative(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ED_Narrative::CUVP_ED_Narrative(CUVP_ED_Narrative const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ED_Narrative::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ED.Narrative"), _T("uri:iso.org:21090"));
}

CUVP_ED_Signature::CUVP_ED_Signature(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ED_Signature::CUVP_ED_Signature(CUVP_ED_Signature const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ED_Signature::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ED.Signature"), _T("uri:iso.org:21090"));
}

CUVP_ED_Text::CUVP_ED_Text(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ED_Text::CUVP_ED_Text(CUVP_ED_Text const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ED_Text::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ED.Text"), _T("uri:iso.org:21090"));
}

CUVP_EN::CUVP_EN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_EN::CUVP_EN(CUVP_EN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_EN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_EN"), _T("uri:iso.org:21090"));
}

CUVP_EN_ON::CUVP_EN_ON(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_EN_ON::CUVP_EN_ON(CUVP_EN_ON const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_EN_ON::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_EN.ON"), _T("uri:iso.org:21090"));
}

CUVP_EN_PN::CUVP_EN_PN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_EN_PN::CUVP_EN_PN(CUVP_EN_PN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_EN_PN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_EN.PN"), _T("uri:iso.org:21090"));
}

CUVP_EN_TN::CUVP_EN_TN(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_EN_TN::CUVP_EN_TN(CUVP_EN_TN const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_EN_TN::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_EN.TN"), _T("uri:iso.org:21090"));
}

CUVP_II::CUVP_II(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_II::CUVP_II(CUVP_II const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_II::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_II"), _T("uri:iso.org:21090"));
}

CUVP_INT::CUVP_INT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_INT::CUVP_INT(CUVP_INT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_INT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_INT"), _T("uri:iso.org:21090"));
}

CUVP_INT_NonNeg::CUVP_INT_NonNeg(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_INT_NonNeg::CUVP_INT_NonNeg(CUVP_INT_NonNeg const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_INT_NonNeg::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_INT.NonNeg"), _T("uri:iso.org:21090"));
}

CUVP_INT_Positive::CUVP_INT_Positive(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_INT_Positive::CUVP_INT_Positive(CUVP_INT_Positive const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_INT_Positive::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_INT.Positive"), _T("uri:iso.org:21090"));
}

CUVP_MO::CUVP_MO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_MO::CUVP_MO(CUVP_MO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_MO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_MO"), _T("uri:iso.org:21090"));
}

CUVP_PQ::CUVP_PQ(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_PQ::CUVP_PQ(CUVP_PQ const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_PQ::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_PQ"), _T("uri:iso.org:21090"));
}

CUVP_PQ_Time::CUVP_PQ_Time(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_PQ_Time::CUVP_PQ_Time(CUVP_PQ_Time const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_PQ_Time::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_PQ.Time"), _T("uri:iso.org:21090"));
}

CUVP_REAL::CUVP_REAL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_REAL::CUVP_REAL(CUVP_REAL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_REAL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_REAL"), _T("uri:iso.org:21090"));
}

CUVP_RTO::CUVP_RTO(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_RTO::CUVP_RTO(CUVP_RTO const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_RTO::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_RTO"), _T("uri:iso.org:21090"));
}

CUVP_SC::CUVP_SC(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_SC::CUVP_SC(CUVP_SC const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_SC::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_SC"), _T("uri:iso.org:21090"));
}

CUVP_SC_NT::CUVP_SC_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_SC_NT::CUVP_SC_NT(CUVP_SC_NT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_SC_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_SC.NT"), _T("uri:iso.org:21090"));
}

CUVP_ST::CUVP_ST(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ST::CUVP_ST(CUVP_ST const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ST::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ST"), _T("uri:iso.org:21090"));
}

CUVP_ST_NT::CUVP_ST_NT(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_ST_NT::CUVP_ST_NT(CUVP_ST_NT const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_ST_NT::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_ST.NT"), _T("uri:iso.org:21090"));
}

CUVP_TEL::CUVP_TEL(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TEL::CUVP_TEL(CUVP_TEL const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TEL::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TEL"), _T("uri:iso.org:21090"));
}

CUVP_TEL_Email::CUVP_TEL_Email(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TEL_Email::CUVP_TEL_Email(CUVP_TEL_Email const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TEL_Email::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TEL.Email"), _T("uri:iso.org:21090"));
}

CUVP_TEL_Person::CUVP_TEL_Person(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TEL_Person::CUVP_TEL_Person(CUVP_TEL_Person const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TEL_Person::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TEL.Person"), _T("uri:iso.org:21090"));
}

CUVP_TEL_Phone::CUVP_TEL_Phone(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TEL_Phone::CUVP_TEL_Phone(CUVP_TEL_Phone const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TEL_Phone::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TEL.Phone"), _T("uri:iso.org:21090"));
}

CUVP_TEL_Url::CUVP_TEL_Url(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TEL_Url::CUVP_TEL_Url(CUVP_TEL_Url const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TEL_Url::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TEL.Url"), _T("uri:iso.org:21090"));
}

CUVP_TS::CUVP_TS(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TS::CUVP_TS(CUVP_TS const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TS::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TS"), _T("uri:iso.org:21090"));
}

CUVP_TS_Birth::CUVP_TS_Birth(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TS_Birth::CUVP_TS_Birth(CUVP_TS_Birth const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TS_Birth::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TS.Birth"), _T("uri:iso.org:21090"));
}

CUVP_TS_Date::CUVP_TS_Date(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TS_Date::CUVP_TS_Date(CUVP_TS_Date const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TS_Date::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TS.Date"), _T("uri:iso.org:21090"));
}

CUVP_TS_Date_Full::CUVP_TS_Date_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TS_Date_Full::CUVP_TS_Date_Full(CUVP_TS_Date_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TS_Date_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TS.Date.Full"), _T("uri:iso.org:21090"));
}

CUVP_TS_DateTime::CUVP_TS_DateTime(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TS_DateTime::CUVP_TS_DateTime(CUVP_TS_DateTime const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TS_DateTime::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TS.DateTime"), _T("uri:iso.org:21090"));
}

CUVP_TS_DateTime_Full::CUVP_TS_DateTime_Full(xercesc::DOMNode* const& node)
: ::AIMXML::iso::CANY(node)
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

CUVP_TS_DateTime_Full::CUVP_TS_DateTime_Full(CUVP_TS_DateTime_Full const& other)
: ::AIMXML::iso::CANY(other.GetNode())
, probability(*this)	// "@probability"
, value2(*this)	// "value"
{
}

void CUVP_TS_DateTime_Full::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("UVP_TS.DateTime.Full"), _T("uri:iso.org:21090"));
}

CUid::CUid(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CUid::CUid(CUid const& other)
: TypeBase(other.GetNode())
{
}


CUncertaintyType::CUncertaintyType(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CUncertaintyType::CUncertaintyType(CUncertaintyType const& other)
: TypeBase(other.GetNode())
{
}


CUpdateMode::CUpdateMode(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CUpdateMode::CUpdateMode(CUpdateMode const& other)
: TypeBase(other.GetNode())
{
}


CUri::CUri(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

CUri::CUri(CUri const& other)
: TypeBase(other.GetNode())
{
}


CXReference::CXReference(xercesc::DOMNode* const& node)
: TypeBase(node)
, xref(*this)	// "@xref"
{
}

CXReference::CXReference(CXReference const& other)
: TypeBase(other.GetNode())
, xref(*this)	// "@xref"
{
}

void CXReference::SetXsiType()
{
	XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"), 
		_T("XReference"), _T("uri:iso.org:21090"));
}

Cset_CodingRationale::Cset_CodingRationale(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cset_CodingRationale::Cset_CodingRationale(Cset_CodingRationale const& other)
: TypeBase(other.GetNode())
{
}


Cset_EntityNamePartQualifier::Cset_EntityNamePartQualifier(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cset_EntityNamePartQualifier::Cset_EntityNamePartQualifier(Cset_EntityNamePartQualifier const& other)
: TypeBase(other.GetNode())
{
}


Cset_EntityNameUse::Cset_EntityNameUse(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cset_EntityNameUse::Cset_EntityNameUse(Cset_EntityNameUse const& other)
: TypeBase(other.GetNode())
{
}


Cset_PostalAddressUse::Cset_PostalAddressUse(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cset_PostalAddressUse::Cset_PostalAddressUse(Cset_PostalAddressUse const& other)
: TypeBase(other.GetNode())
{
}


Cset_TelecommunicationAddressUse::Cset_TelecommunicationAddressUse(xercesc::DOMNode* const& node)
: TypeBase(node)
{
}

Cset_TelecommunicationAddressUse::Cset_TelecommunicationAddressUse(Cset_TelecommunicationAddressUse const& other)
: TypeBase(other.GetNode())
{
}


} // namespace iso


void CcaptionType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_altova_CcaptionType_altova_unnamed, value);
}

CcaptionType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_altova_CcaptionType_altova_unnamed);
}

void ClinkHtmlType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_altova_ClinkHtmlType_altova_unnamed, value);
}

ClinkHtmlType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_altova_ClinkHtmlType_altova_unnamed);
}

void CfootnoteType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_altova_CfootnoteType_altova_unnamed, value);
}

CfootnoteType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_altova_CfootnoteType_altova_unnamed);
}

void CcontentType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_altova_CcontentType_altova_unnamed, value);
}

CcontentType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_altova_CcontentType_altova_unnamed);
}

void CitemType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_altova_CitemType_altova_unnamed, value);
}

CitemType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_altova_CitemType_altova_unnamed);
}

void CparagraphType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_altova_CparagraphType_altova_unnamed, value);
}

CparagraphType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_altova_CparagraphType_altova_unnamed);
}

void CtdType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_altova_CtdType_altova_unnamed, value);
}

CtdType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_altova_CtdType_altova_unnamed);
}

void CthType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_altova_CthType_altova_unnamed, value);
}

CthType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_altova_CthType_altova_unnamed);
}

namespace xs
{	

void CanyType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_xs_altova_CanyType_altova_unnamed, value);
}

CanyType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_xs_altova_CanyType_altova_unnamed);
}

void CstringType::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_xs_altova_CstringType_altova_unnamed, value);
}

CstringType::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_xs_altova_CstringType_altova_unnamed);
}

void Cbase64BinaryType::operator=(const std::vector<unsigned char>& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_xs_altova_Cbase64BinaryType_altova_unnamed, value);
}

Cbase64BinaryType::operator std::vector<unsigned char>() {
	return CastAs<std::vector<unsigned char> >::Do(GetNode(), members + _altova_mi_xs_altova_Cbase64BinaryType_altova_unnamed);
}

} // namespace xs


namespace iso
{	

void CNarrative::operator=(const string_type& value) { 
	XercesTreeOperations::SetValue(GetNode(), members + _altova_mi_iso_altova_CNarrative_altova_unnamed, value);
}

CNarrative::operator string_type() {
	return CastAs<string_type >::Do(GetNode(), members + _altova_mi_iso_altova_CNarrative_altova_unnamed);
}

} // namespace iso


}
