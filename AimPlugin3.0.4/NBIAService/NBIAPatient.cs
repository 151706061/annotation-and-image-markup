//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

using System;
using System.Collections;
using System.Data;
using DataServiceUtil;

namespace NBIAService
{
	public class NBIAPatient : NBIAQueryBase
	{
		public DataTable getPatientInfo(NBIAQueryParameters queryParameters, string endPointUrl)
		{
			_queryParameters = queryParameters;
			DataTable dataTable = null;
			var result = getPatientCQLInfo(endPointUrl);
			if (result != null && result.Items != null && result.Items.Length > 0)
				dataTable = processCQLObjectResult(result);
			return dataTable;
		}

		private CQLQueryResults getPatientCQLInfo(string endPointUrl)
		{
			object[] obj;
			CQLQueryResults result = null;
			Association assoClinicalTrialSite = null;
			Association assoClinicalTrialProtocol = null;
			Association assoClinicalTrialSubject = null;
			Association assoImage = null;
			Association assoTrialDataProvenance = null;
			Association assoSeries = null;
			Association assoStudy = null;
			var results = new ArrayList();
			var proxy = new NCIACoreServicePortTypeClient();
			proxy.Endpoint.Address = new System.ServiceModel.EndpointAddress(endPointUrl);
			var items = new[] { "ethnicGroup", "patientBirthDate", "patientId", "patientName", "patientSex" };
			var itemsChoiceType1 = new[] {
                ItemsChoiceType.AttributeNames, ItemsChoiceType.AttributeNames, ItemsChoiceType.AttributeNames, 
                ItemsChoiceType.AttributeNames, ItemsChoiceType.AttributeNames };

			assoTrialDataProvenance = null;
			if (!_queryParameters.ProjectName.IsEmpty)
			{
				var attrTrialDataProvenance = CreateAttribute("project", _queryParameters.ProjectName);
				var grpTrialDataProvenance = CreateQRAttrAssoGroup.createGroup(attrTrialDataProvenance, LogicalOperator.AND);
				assoTrialDataProvenance = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.TrialDataProvenance", "dataProvenance", grpTrialDataProvenance);
			}
			assoClinicalTrialSite = null;
			obj = null;
			results = new ArrayList();
			if (!_queryParameters.SiteId.IsEmpty)
				results.Add(CreateAttribute("siteId", _queryParameters.SiteId));
			if (!_queryParameters.SiteName.IsEmpty)
				results.Add(CreateAttribute("siteName", _queryParameters.SiteName));
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var grpClinicalTrialSite = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoClinicalTrialSite = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.ClinicalTrialSite", "site", grpClinicalTrialSite);
			}
			assoClinicalTrialProtocol = null;
			obj = null;
			results = new ArrayList();
			if (!_queryParameters.ProtocolId.IsEmpty)
				results.Add(CreateAttribute("protocolId", _queryParameters.ProtocolId));
			if (!_queryParameters.ProtocolName.IsEmpty)
				results.Add(CreateAttribute("protocolName", _queryParameters.ProtocolName));
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var grpClinicalTrialProtocol = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoClinicalTrialProtocol = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.ClinicalTrialProtocol",
																							"protocol", grpClinicalTrialProtocol);
			}
			obj = null;
			results = new ArrayList();
			assoClinicalTrialSubject = null;
			if (assoClinicalTrialSite != null)
				results.Add(assoClinicalTrialSite);
			if (assoClinicalTrialProtocol != null)
				results.Add(assoClinicalTrialProtocol);
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var grpClinicalTrialSubject = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoClinicalTrialSubject = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.ClinicalTrialSubject",
																							   "subjectCollection", grpClinicalTrialSubject);
			}
			assoImage = null;
			if (!_queryParameters.SliceThickness.IsEmpty)
			{
				var attrPatient = CreateAttribute("sliceThickness", _queryParameters.SliceThickness);
				var grpPatient = CreateQRAttrAssoGroup.createGroup(attrPatient, LogicalOperator.AND);
				assoImage = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.Image", "imageCollection", grpPatient);
			}
			assoSeries = null;
			obj = null;
			results = new ArrayList();
			Attribute attrSeries = null;
			if (assoImage != null)
				results.Add(assoImage);
			if (!_queryParameters.Modality.IsEmpty)
				attrSeries = CreateAttribute("modality", _queryParameters.Modality);
			if (attrSeries != null)
				results.Add(attrSeries);
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var grpSeries = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoSeries = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.Series", "seriesCollection", grpSeries);
			}
			obj = null;
			assoStudy = null;
			results = new ArrayList();
			if (assoSeries != null)
				results.Add(assoSeries);
			if (!_queryParameters.StudyInstanceUID.IsEmpty)
				results.Add(CreateAttribute("studyInstanceUID", _queryParameters.StudyInstanceUID));
			assoStudy = null;
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var groupStudy = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoStudy = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.Study", "studyCollection", groupStudy);
			}
			obj = null;
			results = new ArrayList();
			if (assoClinicalTrialSubject != null)
				results.Add(assoClinicalTrialSubject);
			if (assoTrialDataProvenance != null)
				results.Add(assoTrialDataProvenance);
			if (assoStudy != null)
				results.Add(assoStudy);
			if (!_queryParameters.PatientBirthDate.IsEmpty)
				results.Add(CreateAttribute("patientBirthDate", _queryParameters.PatientBirthDate));
			if (!_queryParameters.PatientId.IsEmpty)
				results.Add(CreateAttribute("patientId", _queryParameters.PatientId));
			if (!_queryParameters.PatientName.IsEmpty)
				results.Add(CreateAttribute("patientName", _queryParameters.PatientName));
			if (!_queryParameters.PatientSex.IsEmpty)
				results.Add(CreateAttribute("patientSex", _queryParameters.PatientSex));

			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));

			var groupPatient = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
			var arg = CreateQRAttrAssoGroup.createQueryRequestCqlQuery("gov.nih.nci.ncia.domain.Patient", items, itemsChoiceType1, null, groupPatient);
			try
			{
				result = proxy.query(arg);
			}
			catch (System.Net.WebException ex)
			{
				Console.WriteLine(ex.Message);
				result = null;
			}
			catch (Exception e)
			{
				Console.WriteLine(e.Message);
				result = null;
				throw new GridServicerException("Error querying NCIA Grid", e);
			}
			return result;
		}
	}
}
