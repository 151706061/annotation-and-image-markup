//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

using System.Collections.Generic;

namespace SearchComponent
{
	internal class AIMSearchResult
	{
		public Patient Patient = new Patient();
		public Study Study = new Study();
		public Series Series = new Series();
		public List<AnatomicEntity> AnatomicEntities = new List<AnatomicEntity>();
		public List<AnatomicEntityCharacteristic> AnatomicEntityCharacteristics = new List<AnatomicEntityCharacteristic>();
		public List<ImagingObservation> ImagingObservations = new List<ImagingObservation>();
		public List<ImagingObservationCharacteristic> ImagingObservationCharacteristics = new List<ImagingObservationCharacteristic>();
		public User User = new User();
	    public aim_dotnet.Annotation RetrievedAnnotation;
	}
}
