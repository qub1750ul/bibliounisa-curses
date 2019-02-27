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

#include "wshapes.h"

WINDOW_ARRAY linearizeWMatrix( const WINDOW_MATRIX , const size_t rows , const size_t cols ) ;
WINDOW_ARRAY linearizeWMatrix2( const WINDOW_MATRIX_2 , const size_t rows , const size_t cols ) ;

/// Check if memory allocation has succeded
void checkalloc( void * ptr ) ;
