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

#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

typedef WINDOW ** WINDOW_ARRAY ;
typedef WINDOW_ARRAY * WINDOW_MATRIX ;
typedef WINDOW_MATRIX ** WINDOW_MATRIX_2 ;

WINDOW_ARRAY wcreate_win_array(
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLenghtX ,
		const size_t cellN
	) ;

WINDOW_MATRIX wcreate_win_matrix(
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLenghtX ,
		const size_t rows     , const size_t columns
	) ;

WINDOW_MATRIX_2 wcreate_win_matrix_2(
		const size_t drawingAreaStartY , const size_t drawingAreaStartX ,
		const size_t cLengthY          , const size_t cLengthX ,
		const size_t elementRows       , const size_t elementCol ,
		const size_t rows              , const size_t columns ,
		const size_t innerSpacingY     , const size_t innerSpacingX
	) ;
