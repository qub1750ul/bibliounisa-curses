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

#include <string.h>
#include <ncurses.h>

#include "definitions.h"
#include "functions.h"

void pdebug( const char * const s )
	{
		#ifdef DEBUG
			fprintf( stderr , "DEBUG: "  ) ;
			fprintf( stderr , "%s\n" , s ) ;
		#endif
	}

size_t curl_fetch_callback( void * buf_ptr , size_t size, size_t bufSize, void * externalBuf_ptr )
	{
		if( bufSize >= CURL_FETCH_BUF_CAPACITY - strlen( externalBuf_ptr ) )
			{
				addstr( "ERROR: LOW MEMORY\n" ) ;
				exit( EXIT_LOW_MEMORY ) ;
			}

		strncat( externalBuf_ptr , buf_ptr , bufSize ) ;
		return bufSize ;
	}

void u_curl_get( CURL * const socket , const char * const url )
	{
		curl_easy_setopt( socket , CURLOPT_URL , url ) ;
		curl_easy_perform( socket ) ;
	}
