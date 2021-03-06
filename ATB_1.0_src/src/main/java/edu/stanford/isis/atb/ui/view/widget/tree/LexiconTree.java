/*
*  2010 � 2012 Copyright Northwestern University and Stanford University 
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.view.widget.tree;

import edu.stanford.isis.atb.ui.model.tree.LexiconNodeValue;
import edu.stanford.isis.atb.ui.view.widget.tree.renderer.lexicon.LexiconTreeNodeRenderer;

/**
 * @author Vitaliy Semeshko
 */
public class LexiconTree extends AbstractTree<LexiconNodeValue> {

	public LexiconTree() {
		super(new LexiconTreeNodeRenderer());
	}
	
}
