/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/


#ifndef DSRIODCC_H
#define DSRIODCC_H

#include "dcmtk/config/osconfig.h"   /* make sure OS specific configuration is included first */

#include "dcmtk/dcmsr/dsrtypes.h"


/*---------------------*
 *  class declaration  *
 *---------------------*/

/** Class for checking the content relationship constraints of an SR IOD (abstract)
 */
class DCMTK_DCMSR_EXPORT DSRIODConstraintChecker
  : public DSRTypes
{

  public:

    /** default constructor
     */
    DSRIODConstraintChecker();

    /** destructor
     */
    virtual ~DSRIODConstraintChecker();

    /** check whether by-reference relationships are allowed for this SR IOD (abstract)
     ** @return OFTrue if by-reference relationships are allowed, OFFalse otherwise
     */
    virtual OFBool isByReferenceAllowed() const = 0;

    /** check whether this SR IOD requires template support (abstract)
     ** @return OFTrue if template support is required, OFFalse otherwise
     */
    virtual OFBool isTemplateSupportRequired() const = 0;

    /** get identifier of the root template
     ** @return root template identifier (TID) if required, NULL otherwise
     */
    virtual const char *getRootTemplateIdentifier() const = 0;

    /** get the associated document type of the SR IOD (abstract)
     ** @return document type (see DSRTypes::E_DocumentType)
     */
    virtual E_DocumentType getDocumentType() const = 0;

    /** check whether specified content relationship is allowed for this IOD (abstract)
     ** @param  sourceValueType   value type of the source content item to be checked
     *  @param  relationshipType  type of relationship between source and target item
     *  @param  targetValueType   value type of the target content item to be checked
     *  @param  byReference       optional flag indicating whether the node/relationship
     *                            should be added by-value (default) or by-reference
     ** @return OFTrue if content relationship is allowed, OFFalse otherwise
     */
    virtual OFBool checkContentRelationship(const E_ValueType sourceValueType,
                                            const E_RelationshipType relationshipType,
                                            const E_ValueType targetValueType,
                                            const OFBool byReference = OFFalse) const = 0;
};


#endif
