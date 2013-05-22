/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.domain.template;


/**
 * @author Vitaliy Semeshko
 */
public abstract class AbstractNumberedElement extends AbstractRemovableElement implements NumberedElement {

	private NumberingCommand indexCommand;
	
	@Override
	public void setNumberingCommand(NumberingCommand command) {
		this.indexCommand = command;
	}

	@Override
	public void number() {
		if (indexCommand != null) {
			indexCommand.execute();
		}
	}
	
}
