/*
    ChibiOS - Copyright (C) 2006,2007,2008,2009,2010,2011,2012,2013,2014,
              2015,2016,2017,2018,2019,2020,2021 Giovanni Di Sirio.

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation version 3 of the License.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    vfs/include/vfsdrivers.h
 * @brief   VFS drivers header file.
 *
 * @addtogroup VFS_DRIVERS
 * @{
 */

#ifndef VFSDRIVERS_H
#define VFSDRIVERS_H

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    File open modes.
 * @{
 */
#define MODE_READ                   0x01U
#define MODE_WRITE                  0x02U
#define MODE_RDWR                   (MODE_READ | MODE_WRITE)
#define MODE_OPEN                   0x00U
#define MODE_CREATE_EXCL            0x04U
#define MODE_CREATE_TRUNCATE        0x08U
#define MODE_CREATE_OPEN            0x10U
#define MODE_APPEND                 0x20U
#define MODE_OPEN_APPEND            (MODE_CREATE_OPEN | MODE_APPEND)
/** @} */

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   @p vfs_driver_t specific methods.
 */
#define __vfs_driver_methods                                                \
  _base_object_methods                                                      \
  msg_t (*open_dir)(void *instance,                                         \
                    const char *path,                                       \
                    vfs_directory_node_t **vdnpp);                          \
  msg_t (*open_file)(void *instance,                                        \
                     const char *path,                                      \
                     unsigned mode,                                         \
                     vfs_file_node_t **vfnpp);

/**
 * @brief   @p vfs_driver_t specific data.
 */
#define __vfs_driver_data                                                   \
  _base_object_data                                                         \
  const char *rootname;

/**
 * @brief   @p vfs_driver_t virtual methods table.
 */
struct vfs_driver_vmt {
  __vfs_driver_methods
};

/**
 * @brief   Type of a structure representing a VFS driver.
 */
typedef struct vfs_driver {
  /**
   * @brief   Virtual Methods Table.
   */
  const struct vfs_driver_vmt   *vmt;
  __vfs_driver_data
} vfs_driver_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

#endif /* VFSDRIVERS_H */

/** @} */