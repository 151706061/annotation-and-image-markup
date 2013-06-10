#region License

//L
// 2007 - 2013 Copyright Northwestern University
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
//L

#endregion

using System;
using System.ServiceModel;
using DataServiceUtil;

namespace AIMTCGAService
{
    public class AIMTCGASubmit
    {
        static public void sendAIMTCGAAnnotation(string[] inXML)
        {
            var uri = AIMDataServiceSettings.Default.AIMDataServiceUrl; 
            try
            {
                var proxy = new AIM3DataServicePortTypeClient();
                proxy.Endpoint.Address = new EndpointAddress(uri);
                proxy.submit(inXML);         
            }
            catch (System.Net.WebException ex)
            {
                Console.WriteLine(ex.Message);
                throw new GridServicerException("Error writting to AIM data service", ex);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                throw new GridServicerException("Error writting to AIM data service", e);
            }
        }

    	static public string ServiceUrl
    	{
			get { return AIMDataServiceSettings.Default.AIMDataServiceUrl; }
    	}
    }
}
