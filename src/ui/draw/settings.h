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

#include <stdint.h>

typedef struct DrawingSettings
	{
		uint8_t offsetX ;
		uint8_t offsetY ;

		uint8_t spacingY ;
		uint8_t spacingX ;

		uint8_t tableCols ;
		uint8_t tableRows ;

		uint8_t seatLenY ;
		uint8_t seatLenX ;

	} DrawingSettings ;

#define EXTERN_SETTINGS extern const DrawingSettings

EXTERN_SETTINGS sciLibSeatTableSettings ;

#undef EXTERN_SETTINGS
