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

#include <stdlib.h>

#include <curl/curl.h>

/// Print debug mode
void pdebug( const char * const ) ;

/// Curl fetch handler
size_t curl_fetch_callback( void * buf , size_t size, size_t bufSize, void * userdata ) ;

/// Curl GET shorthand
void u_curl_get( CURL * const socket , const char * const url ) ;
