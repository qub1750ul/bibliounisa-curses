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

#include <stdint.h>

#include "settings.h"
#include "shapes.h"

void draw_sciLib_seatTable( const DrawingSettings * const settings )
	{
		const uint8_t tableOffset = settings -> seatLenX * settings -> tableCols + settings -> spacingX ;
		const uint8_t centerGroupOffset = settings -> offsetX + tableOffset * 2 ;
		const uint8_t rightGroupOffset = centerGroupOffset + tableOffset * 2 + settings -> seatLenX * 5 ;

		uint8_t offsetX = settings -> offsetX ;
		uint8_t offsetY = settings -> offsetY ;

		#define UI_DRAW_TABLE( rows , cols ) \
			ui_draw_matrix( offsetY , offsetX , settings -> seatLenY , settings -> seatLenX , rows , cols )

		#define UI_DRAW_TABLE_WOFF( rows , cols ) \
			{ UI_DRAW_TABLE( rows , cols ) ; offsetX += tableOffset ; }

		// Draw 1st table row

		offsetX = centerGroupOffset ;
		UI_DRAW_TABLE( 3 , 1 ) ;

		offsetX += settings -> seatLenX * 2 ;
		UI_DRAW_TABLE_WOFF( 1 , 3 ) ;
		UI_DRAW_TABLE_WOFF( 1 , 3 ) ;

		offsetX += settings -> seatLenX ;
		UI_DRAW_TABLE( 3 , 1 ) ;

		// Draw 2nd table row

		offsetX = settings -> offsetX ;
		offsetY += settings -> seatLenY * 3 + settings -> spacingY ;

		UI_DRAW_TABLE_WOFF( 1 , 3 ) ;
		UI_DRAW_TABLE( 2 , 3 ) ;

		offsetX = centerGroupOffset + settings -> seatLenX * 2 ;

		UI_DRAW_TABLE_WOFF( 2 , 3 ) ;
		UI_DRAW_TABLE( 2 , 3 ) ;

		offsetX = rightGroupOffset ;

		UI_DRAW_TABLE_WOFF( 2 , 3 ) ;
		UI_DRAW_TABLE( 1 , 3 ) ;

		// Draw the rest of the structure from 3rd row

		offsetY += settings -> seatLenY * 2 + settings -> spacingY ;
		offsetX = settings -> offsetX ;

		// Draw Left group
		ui_draw_matrix_group(
				offsetY , offsetX ,
				settings -> seatLenY  , settings -> seatLenX ,
				settings -> tableRows , settings -> tableCols ,
				3 , 2 ,
				settings -> spacingY  , settings -> spacingX
			) ;

		// Draw Right group

		offsetX = rightGroupOffset ;

		ui_draw_matrix_group(
				offsetY   , offsetX      ,
				settings -> seatLenY  , settings -> seatLenX     ,
				settings -> tableRows , settings -> tableCols ,
				4         , 2            ,
				settings -> spacingY  , settings -> spacingX
			) ;

		// Draw Lower group

		offsetY += ( settings -> seatLenY * 2 + settings -> spacingY ) * 3 ;
		offsetX = centerGroupOffset + settings -> seatLenX * 2 ;

		UI_DRAW_TABLE_WOFF( 2 , 3 ) ;
		UI_DRAW_TABLE( 2 , 3 ) ;

		offsetY += settings -> seatLenY * 2 + settings -> spacingY ;
		offsetX = centerGroupOffset + settings -> seatLenX * 2 ;

		ui_draw_matrix_group(
				offsetY   , offsetX  ,
				settings -> seatLenY  , settings -> seatLenX ,
				1         , 3        ,
				2         , 2        ,
				settings -> spacingY  , settings -> spacingX
			) ;
	}
