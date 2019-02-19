/* Copyright (C) 2019  Giuseppe Masino ( qub1750ul ) <dev.giuseppemasino@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "ui.h"
#include "draw/draw.h"
#include "draw/wdraw.h"
#include "draw/settings.h"
#include "helper.h"

struct cursesUiProp uiProp ;

void ui_init()
	{
		initscr() ;
		cbreak() ;

		getmaxyx( stdscr , uiProp.maxy , uiProp.maxx ) ;

		if( has_colors() ) start_color() ;
			else
				{
					endwin() ;
					puts( "Your terminal does not support color" ) ;
					exit( EXIT_FAILURE ) ;
				}

	} ;

void ui_display_home()
	{
		caddstr( 0 , "= UNISA CBA =" ) ;
		caddstr( 1 , "== Unofficial curses client ==" ) ;
		addstr(
				"\n"
				"Select what to do:\n"
				"1. View seat map\n"
				"2. Request seat\n"
			) ;

		refresh() ;
	}

void ui_display_seatTable_sciLib()
	{
		caddstr( 0 , "= UNISA CBA =\n" ) ;
		caddstr( 1 , "== BIBLIOTECA SCIENTIFICA - SALA A ==\n" ) ;

		draw_sciLib_seatTable( & sciLibSeatTableSettings ) ;
		wcreate_sciLib_seatTable( & sciLibSeatTableSettings ) ;

		refresh() ;
	}

void ui_display_seatTable_mainLib()
	{
		//
	}
