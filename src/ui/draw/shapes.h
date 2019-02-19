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

void ui_draw_box(
		const size_t starty , const size_t startx ,
		const size_t leny   , const size_t lenx
	) ;

void ui_draw_array(
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLenghtX ,
		const size_t cellN
	) ;

void ui_draw_matrix(
		const size_t startY   , const size_t startX   ,
		const size_t cLengthY , const size_t cLenghtX ,
		const size_t rows     , const size_t columns
	) ;

void ui_draw_matrix_group(
		const size_t drawingAreaStartY , const size_t drawingAreaStartX ,
		const size_t cLengthY          , const size_t cLengthX ,
		const size_t elementRows       , const size_t elementCol ,
		const size_t rows              , const size_t columns ,
		const size_t innerSpacingY     , const size_t innerSpacingX
	) ;
