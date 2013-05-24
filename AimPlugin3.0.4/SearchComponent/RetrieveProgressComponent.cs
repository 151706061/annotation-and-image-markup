﻿#region License

// Copyright Notice. Copyright 2008-2012 Northwestern University
// ("caBIG® Participant"). AIM Plugin for ClearCanvas conforms
// to caBIG® technical specifications and is part of the caBIG® initiative. The
// software subject to this notice and license includes human readable source
// code form, machine readable, binary, object code form and related
// documentation (the "caBIG® Software").
//
// This caBIG® Software License (the "License") is between the National Cancer
// Institute (NCI) and You. "You (or "Your") shall mean a person or an entity,
// and all other entities that control, are controlled by, or are under common
// control with the entity. "Control" for purposes of this definition means (i)
// the direct or indirect power to cause the direction or management of such
// entity, whether by contract or otherwise, or (ii) ownership of fifty percent
// (50%) or more of the outstanding shares, or (iii) beneficial ownership of
// such entity.
//
// Provided that You agree to the conditions described below, NCI grants You a
// non-exclusive, worldwide, perpetual, fully-paid-up, no-charge, irrevocable,
// transferable and royalty-free right and license in its rights in the caBIG®
// Software, including any copyright or patent rights therein, to (i) use,
// install, disclose, access, operate, execute, reproduce, copy, modify,
// translate, market, publicly display, publicly perform, and prepare
// derivative works of the caBIG® Software in any manner and for any purpose,
// and to have or permit others to do so; (ii) make, have made, use, practice,
// sell, and offer for sale, import, and/or otherwise dispose of caBIG®
// Software (or portions thereof); (iii) distribute and have distributed to and
// by third parties the caBIG® Software and any modifications and derivative
// works thereof; and (iv) sublicense the foregoing rights set out in (i), (ii)
// and (iii) to third parties, including the right to license such rights to
// further third parties. For sake of clarity, and not by way of limitation,
// NCI shall have no right of accounting or right of payment from You or Your
// sublicensees for the rights granted under this License. This License is
// granted at no charge to You. Your downloading, copying, modifying,
// displaying, distributing or use of caBIG® Software constitutes acceptance of
// all of the terms and conditions of this Agreement. If you do not agree to
// such terms and conditions, you have no right to download, copy, modify,
// display, distribute or use the caBIG® Software.
//
// 1. Your redistributions of the source code for the caBIG® Software must retain
// the above copyright notice, this list of conditions and the disclaimer and
// limitation of liability of Article 6 below. Your redistributions in object
// code form must reproduce the above copyright notice, this list of conditions
// and the disclaimer of Article 6 in the documentation and/or other materials
// provided with the distribution, if any.
//
// 2. Your end-user documentation included with the redistribution, if any, must
// include the following acknowledgment: "This product includes software
// developed by Vladimir Kleper, Skip Talbot and Pattanasak Mongkolwat,
// Northwestern University."
// If You do not include such end-user documentation, You shall include this
// acknowledgment in the caBIG® Software itself, wherever such third-party
// acknowledgments normally appear.
//
// 3. You may not use the names "Northwestern University",
// "The National Cancer Institute", "NCI", "Cancer Bioinformatics Grid" or
// "caBIG®" to endorse or promote products derived from this caBIG® Software.
// This License does not authorize You to use any trademarks, service marks,
// trade names, logos or product names of either caBIG® Participant, NCI or
// caBIG®, except as required to comply with the terms of this License.
//
// 4. For sake of clarity, and not by way of limitation, You are not prohibited by
// this License from incorporating this caBIG® Software into Your proprietary
// programs and into any third party proprietary programs. However, if You
// incorporate the caBIG® Software into third party proprietary programs, You
// agree that You are solely responsible for obtaining any permission from such
// third parties required to incorporate the caBIG® Software into such third
// party proprietary programs and for informing Your sublicensees, including
// without limitation Your end-users, of their obligation to secure any
// required permissions from such third parties before incorporating the caBIG®
// Software into such third party proprietary software programs. In the event
// that You fail to obtain such permissions, You agree to indemnify NCI for any
// claims against NCI by such third parties, except to the extent prohibited by
// law, resulting from Your failure to obtain such permissions.
//
// 5. For sake of clarity, and not by way of limitation, You may add Your own
// copyright statement to Your modifications and to the derivative works, and
// You may provide additional or different license terms and conditions in
// Your sublicenses of modifications of the caBIG® Software, or any derivative
// works of the caBIG® Software as a whole, provided Your use, reproduction,
// and distribution of the Work otherwise complies with the conditions stated
// in this License.
//
// 6. THIS caBIG® SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
// WARRANTIES (INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE) ARE
// DISCLAIMED. IN NO EVENT SHALL NCI OR THE NORTHWESTERN UNIVERSITY OR ITS
// AFFILIATES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS caBIG® SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#endregion

using System;

using ClearCanvas.Common;
using ClearCanvas.Common.Utilities;
using ClearCanvas.Desktop;
using ClearCanvas.Desktop.Actions;
using ClearCanvas.Desktop.Tables;
using ClearCanvas.Desktop.Tools;

namespace SearchComponent
{
	/// <summary>
	/// Extension point for views onto <see cref="RetrieveProgressComponent"/>.
	/// </summary>
	[ExtensionPoint]
	public sealed class RetrieveProgressComponentViewExtensionPoint : ExtensionPoint<IApplicationComponentView>
	{
	}

	public class RetrieveProgressToolExtensionPoint : ExtensionPoint<ITool>
	{
	}

	public interface IRetrieveProgressToolContext : IToolContext
	{
		ISelection Selection { get; }
		event EventHandler SelectionChanged;

		event EventHandler<ItemChangedEventArgs> ItemsChanged;
		IItemCollection Items { get; }

		IDesktopWindow DesktopWindow { get; }
		ClickHandlerDelegate DefaultActionHandler { get; set; }
	}

	/// <summary>
	/// RetrieveProgressComponent class.
	/// </summary>
	[AssociateView(typeof(RetrieveProgressComponentViewExtensionPoint))]
	public class RetrieveProgressComponent : ApplicationComponent
	{
		public const string MenuSite = "cagrid-retrieve-contextmenu";
		public const string ToolbarSite = "cagrid-retrieve-toolbar";
		internal static readonly string ToolNamespace = typeof(RetrieveProgressComponent).FullName;

		private class ToolContext : IRetrieveProgressToolContext
		{
			private readonly RetrieveProgressComponent _parent;

			public ToolContext(RetrieveProgressComponent parent)
			{
				_parent = parent;
			}

			public ISelection Selection
			{
				get { return _parent.Selection; }
			}

			public event EventHandler SelectionChanged
			{
				add { _parent.SelectionChanged += value; }
				remove { _parent.SelectionChanged -= value; }
			}

			public event EventHandler<ItemChangedEventArgs> ItemsChanged
			{
				add { _parent.ItemsChanged += value; }
				remove { _parent.ItemsChanged -= value; }
			}

			public IItemCollection Items
			{
				get { return _parent.Table.Items; }
			}

			public IDesktopWindow DesktopWindow
			{
				get { return _parent.Host.DesktopWindow; }
			}

			public ClickHandlerDelegate DefaultActionHandler
			{
				get { return _parent.DefaultActionHandler; }
				set { _parent.DefaultActionHandler = value; }
			}
		}

		private ToolSet _toolSet;
		private readonly IExtensionPoint _toolExtensionPoint;
		private readonly string _menuSite;
		private readonly string _toolbarSite;
		private readonly string _toolsNamespace;

		private ActionModelRoot _toolbarModel;
		private ActionModelRoot _menuModel;

		private string _title = "Study Retrieve Progress";
		private ISelection _selection;
		private event EventHandler _selectionChanged;

	    private ClickHandlerDelegate _defaultActionHandler;

		internal RetrieveProgressComponent(string toolbarSite, string menuSite, string toolsNamespace, IExtensionPoint toolExtensionPoint, ITable table)
		{
			_toolbarSite = toolbarSite;
			_menuSite = menuSite;
			_toolsNamespace = toolsNamespace;
			_toolExtensionPoint = toolExtensionPoint;
		}

		public ActionModelNode ToolbarModel
		{
			get { return _toolbarModel;}
		}

		public ActionModelNode MenuModel
		{
			get { return _menuModel;}
		}

		public string Title
		{
			get { return _title; }	
			set
			{
				if (_title != value)
				{
					_title = value;
					NotifyPropertyChanged("Title");
				}
			}
		}

		public ISelection Selection
		{
			get { return _selection; }
		}

		public event EventHandler SelectionChanged
		{
			add { _selectionChanged += value; }
			remove { _selectionChanged -= value; }
		}

		public event EventHandler<ItemChangedEventArgs> ItemsChanged
		{
			add { Table.Items.ItemsChanged += value; }
			remove { Table.Items.ItemsChanged -= value; }
		}

		public override void Start()
		{
			_toolSet = new ToolSet(_toolExtensionPoint, new ToolContext(this));
			_toolbarModel = ActionModelRoot.CreateModel(_toolsNamespace, _toolbarSite, _toolSet.Actions);
			_menuModel = ActionModelRoot.CreateModel(_toolsNamespace, _menuSite, _toolSet.Actions);

			base.Start();
		}

		public ITable Table
		{
			get { return RetrieveCoordinator.Coordinator.Table; }
		}

        internal ClickHandlerDelegate DefaultActionHandler
        {
            get { return _defaultActionHandler; }
            set { _defaultActionHandler += value; }
        }

		public void SetSelection(ISelection selection)
		{
			if (selection == null)
				selection = new Selection();

			if (!Equals(_selection, selection))
			{
				_selection = selection;
				EventsHelper.Fire(_selectionChanged, this, EventArgs.Empty);
			}
		}

		public void ItemDoubleClick()
		{
			if (DefaultActionHandler != null)
				DefaultActionHandler();
		}

		public override bool CanExit()
		{
			if (!base.CanExit())
				return false;

			bool retrieveInProgress = CollectionUtils.Contains<RetrieveProgressResult>
				(RetrieveCoordinator.Coordinator.Table.Items, delegate(RetrieveProgressResult result)
               	{
               		return result.Status == RetrieveStatus.InProgress ||
               		       result.Status == RetrieveStatus.Queued;
               	});

			return retrieveInProgress
			       	? this.Host.DesktopWindow.ShowMessageBox("You are retrieving one or more studies from the caGrid. Abandon retrieve and exist?",
			       	                                         MessageBoxActions.YesNo) == DialogBoxAction.Yes
			       	: true;
		}
	}
}
