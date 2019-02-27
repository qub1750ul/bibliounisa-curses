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

/// Check if memory allocation has succeded
void checkalloc( void * ptr )
	{
		if( ptr != NULL ) return ;

		fputs( "CRITICAL ERROR: Cannot allocate memory" , stderr ) ;
		exit( EXIT_FAILURE ) ;
	}

/// Create a WINDOW array structure
struct WindowArray * wcreate_win_array(
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLenghtX ,
		const size_t cellN
	)
	{
		struct WindowArray * array = malloc( sizeof( struct WindowArray ) ) ;
		checkalloc( array ) ;

		array -> data = malloc( sizeof( WINDOW * ) * cellN ) ;
		checkalloc( array -> data ) ;

		for( size_t cell = 0 ; cell < cellN ; ++ cell )
			array -> data[ cell ] = newwin(
					cLengthY , cLenghtX , startY , startX + cLenghtX * cell
				) ;

		return array ;
	}

/// Create a WINDOW matrix
struct WindowMatrix * wcreate_win_matrix(
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLengthX ,
		const size_t rows     , const size_t cols
	)
	{
		struct WindowMatrix * matrix = malloc( sizeof( struct WindowMatrix ) ) ;
		checkalloc( matrix ) ;

		matrix -> data = malloc( sizeof( struct WindowArray * ) * rows ) ;
		checkalloc( matrix -> data ) ;

		for( size_t row = 0 ; row < rows ; ++ row )
			matrix -> data [ row ] = wcreate_win_array(
					startY + cLengthY * cols , startX , cLengthY , cLengthX , cols
				) ;

		return matrix ;
	}

/** Create a WINDOW matrix matrix,
 * that is a group of WINDOW matrixes with spacing among them
 */
struct WindowMatrix2 * wcreate_win_matrix_2(
		const size_t drawingAreaStartY , const size_t drawingAreaStartX ,
		const size_t cLengthY          , const size_t cLengthX ,
		const size_t elementRows       , const size_t elementCol ,
		const size_t rows              , const size_t cols ,
		const size_t innerSpacingY     , const size_t innerSpacingX
	)
	{
		struct WindowMatrix2 * matrix2 = malloc( sizeof( struct WindowMatrix2 ) ) ;
		checkalloc( matrix2 ) ;

		matrix2 -> data = malloc( sizeof( struct WindowMatrix ** ) * rows ) ;
		checkalloc( matrix2 -> data ) ;

		#define MATRIX2_CURRENT_ROW  matrix2 -> data[ row ]
		#define MATRIX2_CURRENT_CELL MATRIX2_CURRENT_ROW [ col ]

		for( size_t row = 0 ; row < rows ; ++ row )
			{
				MATRIX2_CURRENT_ROW = malloc( sizeof( struct WindowMatrix * ) * cols ) ;
				checkalloc( MATRIX2_CURRENT_ROW ) ;

				for( size_t col = 0 ; col < cols ; ++ col )
					{
						size_t startY = drawingAreaStartY + ( cLengthY * elementRows + innerSpacingY ) * row ;
						size_t startX = drawingAreaStartX + ( cLengthX * elementCol  + innerSpacingX ) * col ;

						MATRIX2_CURRENT_CELL = wcreate_win_matrix(
								startY , startX , cLengthY , cLengthX , elementRows , elementCol
							) ;
					}
			}

		#undef MATRIX2_CURRENT_ROW
		#undef MATRIX2_CURRENT_CELL

		return matrix2 ;
	}
