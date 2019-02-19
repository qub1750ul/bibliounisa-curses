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
#include <string.h>

#include <ncurses.h>
#include <curl/curl.h>

#include "functions.h"
#include "resources.h"
#include "ui/ui.h"

int main()
	{
		// Initialization section
		curl_global_init( CURL_GLOBAL_ALL ) ;

		CURL * curlEasySock_ptr = curl_easy_init() ;

		curl_easy_setopt( curlEasySock_ptr , CURLOPT_WRITEFUNCTION , curl_fetch_callback ) ;
		curl_easy_setopt( curlEasySock_ptr , CURLOPT_WRITEDATA     , curlFetchBuf        ) ;

		ui_init() ;

		// Start main loop
		bool run = true ;

		while( run )
			{
				//ui_display_home() ;
				ui_display_seatTable_sciLib() ;

				// GET seat list from the server
				//u_curl_get( curlEasySock_ptr , seatListPageUrl ) ;

				addch( '\n' ) ;
				refresh() ;
				getch() ;

				run = false ;

				// Parse it with myHTML
				// .....
				// Extract relevant data
				// ...
			}

		// Cleanup and exit

		endwin() ;
		curl_easy_cleanup( curlEasySock_ptr ) ;

		return EXIT_SUCCESS ;
	}
