/*
 * Copyright (c) 2014 David Sheets <sheets@alum.mit.edu>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _XOPEN_SOURCE 600
#define _GNU_SOURCE // includes the previous feature macros on Linux

#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/threads.h>

#define UNUSED(x) (void)(x)

int unix_unistd_lseek(int fd, off_t offset, int whence) {
  int retval;
  caml_release_runtime_system();
  retval = lseek(fd, offset, whence);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_lseek_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_lseek);
}

int unix_unistd_rmdir(const char *pathname) {
  int retval;
  caml_release_runtime_system();
  retval = rmdir(pathname);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_rmdir_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_rmdir);
}

int unix_unistd_unlink(const char *pathname) {
  int retval;
  caml_release_runtime_system();
  retval = unlink(pathname);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_unlink_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_unlink);
}

ssize_t unix_unistd_write(int fd, void *buf, size_t count) {
  ssize_t retval;
  caml_release_runtime_system();
  retval = write(fd, buf, count);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_write_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_write);
}

ssize_t unix_unistd_pwrite(int fd, void *buf, size_t count, off_t offset) {
  ssize_t retval;
  caml_release_runtime_system();
  retval = pwrite(fd, buf, count, offset);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_pwrite_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_pwrite);
}

ssize_t unix_unistd_read(int fd, void *buf, size_t count) {
  ssize_t retval;
  caml_release_runtime_system();
  retval = read(fd, buf, count);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_read_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_read);
}

ssize_t unix_unistd_pread(int fd, void *buf, size_t count, off_t offset) {
  ssize_t retval;
  caml_release_runtime_system();
  retval = pread(fd, buf, count, offset);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_pread_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_pread);
}

int unix_unistd_close(int fd) {
  int retval;
  caml_release_runtime_system();
  retval = close(fd);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_close_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_close);
}

int unix_unistd_access(const char *pathname, int mode) {
  int retval;
  caml_release_runtime_system();
  retval = access(pathname, mode);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_access_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_access);
}

ssize_t unix_unistd_readlink(const char *path, char *buf, size_t bufsiz) {
  ssize_t retval;
  caml_release_runtime_system();
  retval = readlink(path, buf, bufsiz);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_readlink_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_readlink);
}

int unix_unistd_symlink(const char *target, const char *linkpath) {
  int retval;
  caml_release_runtime_system();
  retval = symlink(target, linkpath);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_symlink_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_symlink);
}

int unix_unistd_truncate(const char *path, off_t length) {
  int retval;
  caml_release_runtime_system();
  retval = truncate(path, length);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_truncate_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_truncate);
}

int unix_unistd_ftruncate(int fd, off_t length) {
  int retval;
  caml_release_runtime_system();
  retval = ftruncate(fd, length);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_ftruncate_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_ftruncate);
}

int unix_unistd_chown(const char *path, uid_t owner, gid_t group) {
  int retval;
  caml_release_runtime_system();
  retval = chown(path, owner, group);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_chown_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_chown);
}

int unix_unistd_fchown(int fd, uid_t owner, gid_t group) {
  int retval;
  caml_release_runtime_system();
  retval = fchown(fd, owner, group);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_fchown_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_fchown);
}

int unix_unistd_seteuid(uid_t uid) {
  int retval;
  caml_release_runtime_system();
  retval = seteuid(uid);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_seteuid_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_seteuid);
}

int unix_unistd_setegid(gid_t gid) {
  int retval;
  caml_release_runtime_system();
  retval = setegid(gid);
  caml_acquire_runtime_system();
  return retval;
}

value unix_unistd_setegid_ptr(value _) {
  UNUSED(_);
  return caml_copy_nativeint((intptr_t)(void *)unix_unistd_setegid);
}
