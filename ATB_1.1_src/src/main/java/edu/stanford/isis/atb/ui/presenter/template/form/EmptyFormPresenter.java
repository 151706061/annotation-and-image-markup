/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.ui.presenter.template.form;

import edu.stanford.isis.atb.ui.presenter.form.AbstractFormPresenter;
import edu.stanford.isis.atb.ui.view.form.EmptyFormView;

/**
 * @author Vitaliy Semeshko
 */
public class EmptyFormPresenter extends AbstractFormPresenter<Void, EmptyFormView> {

	public EmptyFormPresenter(EmptyFormView view) {
		super(view);
	}

	@Override
	protected boolean validate() {
		return false;
	}

	@Override
	public void setValue(Void value) {}

}
