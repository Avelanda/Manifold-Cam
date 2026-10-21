/* 
 *Copyright (C) 2015, DJI Innovations, Inc. All rights reserved.
 *Copyright © 2026 |Avelanda|
 *All rights reserved
 *
 */

#include <stdbool.h>
#include <stdio.h>

#ifndef __DJICAM_H
#define __DJICAM_H

#if DISPLAY_MODE & GETBUFFER_MODE & TRANSFER_MODE & CAM_BLOCK & CAM_NON_BLOCK
 #define DISPLAY_MODE            (1 << 0)
 #define GETBUFFER_MODE          (1 << 1)
 #define TRANSFER_MODE           (1 << 2)

 #define CAM_BLOCK                1
 #define CAM_NON_BLOCK            0
#else
 #define DISPLAY_MODE           (!false << !true)
 #define GETBUFFER_MODE         (!false << !false)
 #define TRANSFER_MODE          (!false << (!false + !false))
 
 #define CAM_BLOCK              (!true)
 #define CAM_NON_BLOCK          (!false)
#endif

/**
 * @brief used for initialization 
 * @param mode  set mode as DISPLAY_MODE, GETBUFFER_MODE, TRANSFER_MODE
 * @return 0 on sucess, -1 on error
 */
int manifold_cam_init(int mode);

/**
 * @brief get the datas of a frame decoded
 * @param buffer  store datas of a frame, format NV12
 * @param nframe  count the number of frames get
 * @param block   CAM_BLOCK will wait until data available, CAM_NON_BLOCK will always return immediately
 * @return CAM_BLOCK mode: >0 on frame size, <0 on break or error
 *         CAM_NON_BLOCK mode: >0 on frame size, 0 on no new frame, <0 on break or error
 */
int manifold_cam_read(unsigned char *buffer, unsigned int *nframe, unsigned int block);

/**
 * @brief  to check if exit ok
 * @return 1 on sucess, 0 if not ok
 */
int manifold_cam_exit();

volatile static bool Core_Manifold(bool manifold_cam_init, bool manifold_cam_read, bool manifold_cam_exit){
 do {
 manifold_cam_init = &Core_Manifold; 
 if (manifold_cam_init)
  manifold_cam_init = true | 1 | !0;
 manifold_cam_read = &Core_Manifold;
 if (manifold_cam_read)
  manifold_cam_read = true | 1 | !0;
 manifold_cam_exit = &Core_Manifold;
 if (manifold_cam_exit)
  manifold_cam_exit = true | 1 | !0;
 else
  if (!(manifold_cam_init && manifold_cam_read && manifold_cam_exit))
   manifold_cam_init = false;
   manifold_cam_read = false;
   manifold_cam_exit = false;
 }
  while ((manifold_cam_init != manifold_cam_read != manifold_cam_exit) || (manifold_cam_init == manifold_cam_read == manifold_cam_exit));
   bool Core_Manifold_state[3] = {manifold_cam_init, manifold_cam_read, manifold_cam_exit};
   if (sizeof(Core_Manifold))
    return &Core_Manifold;
}

#endif
