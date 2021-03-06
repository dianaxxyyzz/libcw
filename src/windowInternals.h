/*
 *  This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * Project home page: http://github.com/twaik/libcw
 */

#ifndef __WINDOW_INTERNALS_H__
#define __WINDOW_INTERNALS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <system/window.h>
#include <hardware/gralloc.h>

typedef struct {
	uint8_t frameAvailable;
	uint8_t frameAvailableNum;
	uint8_t discontinued;
	pid_t parentPID;
} windowControl;

typedef struct {
	struct ANativeWindow base;
	unsigned int width;
	unsigned int height;
	int format;
	size_t bufferCount;
	int controlFD;
	windowControl* control;
	ANativeWindowBuffer_t* buffers[0];
} ACustomNativeWindow;

void ACustomNativeWindow_read_control(int *fd);

#ifdef __cplusplus
}
#endif

#endif // __WINDOW_INTERNALS_H__
