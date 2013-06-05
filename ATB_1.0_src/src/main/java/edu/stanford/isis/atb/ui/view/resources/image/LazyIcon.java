/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.view.resources.image;

import java.net.URL;

import javax.swing.Icon;

/**
 * Maintains {@link URL} of the image resource.
 * Initializes image on demand.
 * 
 * @author Vitaliy Semeshko
 */
public interface LazyIcon {

	public Icon loadIcon();
	
	public URL getLocation();
	
}
