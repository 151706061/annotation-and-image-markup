/*
*  Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/


#include "../stdafx.h"
#include "Entity.h"
#include "MarkupEntity.h"

#include "../memdebug.h"

using namespace aim_lib;

MarkupEntity::MarkupEntity(void){
}

MarkupEntity::MarkupEntity(const MarkupEntity& markupEntity) : Entity(markupEntity){
}

MarkupEntity::~MarkupEntity(void){
}
