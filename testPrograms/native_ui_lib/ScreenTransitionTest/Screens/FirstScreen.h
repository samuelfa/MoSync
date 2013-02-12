/*
 Copyright (C) 2013 MoSync AB

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License,
 version 2, as published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 MA 02110-1301, USA.
 */

/**
 * @file FirstScreen.h
 * @author Bogdan Iusco & Mircea Vasiliniuc
 * @date 20 Nov 2012
 *
 * @brief First screen shown.
 */

#ifndef FIRST_SCREEN_H_
#define FIRST_SCREEN_H_

#include <NativeUI/ButtonListener.h>
#include <NativeUI/Screen.h>
#include <NativeUI/ListViewListener.h>

#include "../Observers/FirstScreenObserver.h"

namespace NativeUI
{
	class Button;
	class Label;
	class VerticalLayout;
	class HorizontalLayout;
	class ListView;
	class ListViewItem;
}

namespace ScreenTransitionTest
{

	class FirstScreen:
		public NativeUI::Screen,
		public NativeUI::ButtonListener,
		public NativeUI::ListViewListener
	{
	public:
		/**
		 * Constructor.
		 * @param observer Observer for this screen.
		 */
		FirstScreen(FirstScreenObserver& observer);

		/**
		 * Destructor.
		 */
		virtual ~FirstScreen();

	private:
		/**
		 * This method is called if the touch-up event was inside the
		 * bounds of the button.
		 * Platform: iOS, Android, Windows Phone.
		 * @param button The button object that generated the event.
		 */
		virtual void buttonClicked(NativeUI::Widget* button);

	    /**
	     * This method is called when a list view item is clicked.
	     * @param listView The list view object that generated the event.
	     * @param listViewItem The ListViewItem object that was clicked.
	     */
	    virtual void listViewItemClicked(
	        NativeUI::ListView* listView,
	        NativeUI::ListViewItem* listViewItem);

	    /**
		 * This method is called when a list view item is clicked.
		 * @param listView The list view object that generated the event.
		 * @param index The index on which the list view item is positioned.
		 */
		virtual void listViewItemClicked(
			NativeUI::ListView* listView,
			int index);

		/**
		 * Create screen's UI.
		 */
		void createUI();

		/**
		 * Fills the screen transition container.
		 */
		void fillScreenTransitionContainer();

		/**
		 * Populates the screen transition list.
		 */
		void populateTransitionList();

		/**
		 * Obtain the screen transition type from the list index for iOS screen
		 * transitions.
		 *
		 * @param selectedIndex Selected item from list of screen transitions.
		 * @return the Transition type corresponding to the selected screen transition.
		 */
		MAWScreenTransitionType getTransitionTypeForiOS(int selectedIndex);

		/**
		 * Obtain the screen transition type from the list index for Android screen
		 * transitions.
		 *
		 * @param selectedIndex Selected item from list of screen transitions.
		 * @return the Transition type corresponding to the selected screen transition.
		 */
		MAWScreenTransitionType getTransitionTypeForAndroid(int selectedIndex);

		/**
		 * Obtain the screen transition type from the list index for Windows Phone screen
		 * transitions.
		 *
		 * @param selectedIndex Selected item from list of screen transitions.
		 * @return the Transition type corresponding to the selected screen transition.
		 */
		MAWScreenTransitionType getTransitionTypeForWindows(int selectedIndex);


	private:
		/**
		 * Observer for this screen.
		 */
		FirstScreenObserver& mObserver;

		/**
		 * Screen's layout.
		 */
		NativeUI::VerticalLayout* mMainLayout;

		/**
		 * List's layout.
		 */
		NativeUI::HorizontalLayout* mListLayout;

		/**
		 * Footer layout.
		 */
		NativeUI::HorizontalLayout* mFooterLayout;

		/**
		 * Start screen transition button
		 */
		NativeUI::Button* mShowSecondScreenButton;

		/**
		 * Screen Title
		 */
		NativeUI::Label* mTitleLabel;

		/**
		 * Screen transitions list
		 */
		NativeUI::ListView* mScreenTransitionListView;

		/**
		 * Previous item selected. Used in list management.
		 */
		NativeUI::ListViewItem* mPreviousItem;

		/**
		 * Previous list item
		 */
		int mSelectedListItem;

		/**
		 * Vector of screen transitions available on the current platform.
		 */
		MAUtil::Vector<int> mPlatformTransitions;
	};
}


#endif /* FIRST_SCREEN_H_ */
