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

#include "wshapes.h"

WINDOW_ARRAY wcreate_win_array(
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLenghtX ,
		const size_t cellN
	)
	{
		WINDOW_ARRAY array = malloc( sizeof( WINDOW_ARRAY ) * cellN ) ;

		for( size_t cell = 0 ; cell < cellN ; ++ cell )
			array[ cell ] = newwin(
					cLengthY , cLenghtX , startY , startX + cLenghtX * cell
				) ;

		return array ;
	}

WINDOW_MATRIX wcreate_win_matrix(
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLengthX ,
		const size_t rows     , const size_t cols
	)
	{
		WINDOW_MATRIX matrix = malloc( sizeof( WINDOW_MATRIX ) * rows ) ;

		for( size_t row = 0 ; row < rows ; ++ row )
			matrix[ row ] = wcreate_win_array(
					startY + cLengthY * cols , startX , cLengthY , cLengthX , cols
				) ;

		return matrix ;
	}

WINDOW_MATRIX_2 wcreate_win_matrix_2(
		const size_t drawingAreaStartY , const size_t drawingAreaStartX ,
		const size_t cLengthY          , const size_t cLengthX ,
		const size_t elementRows       , const size_t elementCol ,
		const size_t rows              , const size_t cols ,
		const size_t innerSpacingY     , const size_t innerSpacingX
	)
	{
		WINDOW_MATRIX_2 matrix2 = malloc( sizeof( WINDOW_MATRIX_2 ) * rows ) ;

		for( size_t row = 0 ; row < rows ; ++ row )
			{
				matrix2[ row ] = malloc( sizeof( WINDOW_MATRIX * ) * cols ) ;

				for( size_t col = 0 ; col < cols ; ++ col )
					{
						size_t startY = drawingAreaStartY + ( cLengthY * elementRows + innerSpacingY ) * row ;
						size_t startX = drawingAreaStartX + ( cLengthX * elementCol  + innerSpacingX ) * col ;

						matrix2[ row ][ col ] = wcreate_win_matrix(
								startY , startX , cLengthY , cLengthX , elementRows , elementCol
							) ;
					}
			}

		return matrix2 ;
	}
