/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

package edu.stanford.isis.ats.xmldb.data;

import com.sleepycat.dbxml.XmlValue;

/**
 * @author Vladimir Kleper
 * @param <T>
 */
public interface QueryResultAdapter<T> {

    public T adaptResult(XmlValue value);
}
