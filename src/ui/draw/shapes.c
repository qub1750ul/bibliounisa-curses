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

#include <ncurses.h>

#include "shapes.h"

void ui_draw_box(
		WINDOW * const win  ,
		const size_t starty , const size_t startx ,
		const size_t leny   , const size_t lenx
	)
	{
		const size_t endx = startx + lenx ;
		const size_t endy = starty + leny ;

		// Draw horizontal lines
		for( size_t x = startx ; x < endx ; ++ x )
			{
				mvwaddch( win , starty , x , ACS_HLINE ) ;
				mvwaddch( win , endy   , x , ACS_HLINE ) ;
			}

		// Draw vertical lines
		for( size_t y = starty ; y < endy ; ++ y )
			{
				mvwaddch( win , y , startx , ACS_VLINE ) ;
				mvwaddch( win , y , endx   , ACS_VLINE ) ;
			}

		// Add corners
		mvwaddch( win , starty , startx , ACS_ULCORNER ) ;
		mvwaddch( win , starty , endx   , ACS_URCORNER ) ;
		mvwaddch( win , endy   , startx , ACS_LLCORNER ) ;
		mvwaddch( win , endy   , endx   , ACS_LRCORNER ) ;
	}

void ui_draw_array(
		WINDOW * const win    ,
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLenghtX ,
		const size_t cellN
	)
	{
		for( size_t drawnCells = 0 ; drawnCells < cellN ; ++ drawnCells )
			ui_draw_box(
					win ,
					startY ,
					startX + cLenghtX * drawnCells ,
					cLengthY ,
					cLenghtX
				) ;

		// Correct intersections
		for( size_t x = startX + cLenghtX ; x < startX + cLenghtX * cellN ; x += cLenghtX )
			{
				mvwaddch( win , startY            , x , ACS_TTEE ) ;
				mvwaddch( win , startY + cLengthY , x , ACS_BTEE ) ;
			}

		// Move the cursor past the drawing to allow correct rendering
		wmove( win , startY + cLengthY , startX + cLenghtX * cellN + 1 ) ;
	}

void ui_draw_matrix(
		WINDOW * const win    ,
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLengthX ,
		const size_t rows     , const size_t columns
	)
	{
		for( size_t row = 0 ; row < rows ; ++ row )
			ui_draw_array( win , startY + cLengthY * row , startX , cLengthY , cLengthX , columns ) ;

		// Fix intesections
		for( size_t y = startY + cLengthY ; y < startY + cLengthY * rows ; y += cLengthY )
			{
				mvwaddch( win , y , startX , ACS_LTEE ) ;

				for( size_t x = startX + cLengthX ; x < startX + cLengthX * columns ; x += cLengthX )
					mvwaddch( win , y , x , ACS_PLUS ) ;

				mvwaddch( win , y , startX + cLengthX * columns , ACS_RTEE ) ;
			}

		// Move the cursor past the drawing to allow correct rendering
		wmove( win , startY + cLengthY * rows , startX + cLengthX * columns + 1 ) ;
	}

void ui_draw_matrix_group(
		WINDOW * const win ,
		const size_t drawingAreaStartY , const size_t drawingAreaStartX ,
		const size_t cLengthY          , const size_t cLengthX ,
		const size_t elementRows       , const size_t elementCol ,
		const size_t rows              , const size_t columns ,
		const size_t innerSpacingY     , const size_t innerSpacingX
	)
	{
		for( size_t row = 0 ; row < rows ; ++ row )
			for( size_t col = 0 ; col < columns ; ++ col )
				{
					size_t startY = drawingAreaStartY + ( cLengthY * elementRows + innerSpacingY ) * row ;
					size_t startX = drawingAreaStartX + ( cLengthX * elementCol  + innerSpacingX ) * col ;

					ui_draw_matrix( win , startY , startX , cLengthY , cLengthX , elementRows , elementCol ) ;
				}
	}
