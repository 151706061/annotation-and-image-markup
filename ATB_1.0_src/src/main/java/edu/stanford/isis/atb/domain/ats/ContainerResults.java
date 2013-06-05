/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.domain.ats;

import java.util.List;

import org.simpleframework.xml.ElementList;
import org.simpleframework.xml.Root;

/**
 * @author Vitaliy Semeshko
 */

@Root(name="results", strict=false)
public class ContainerResults {

	@ElementList(name="result", inline=true, required=false)
	private List<ContainerSingleResult> containers;

	public List<ContainerSingleResult> getContainers() {
		return containers;
	}
	
}
