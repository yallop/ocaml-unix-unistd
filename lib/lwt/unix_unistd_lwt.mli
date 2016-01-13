(*
 * Copyright (c) 2016 Jeremy Yallop <jeremy.yallop@unikernel.com>
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
 *)

module type S =
sig
  (** Can raise Unix.Unix_error *)
  val write_lwt : ?blocking:bool ->
    Unix.file_descr -> unit Ctypes.ptr -> int -> int Lwt.t

  (** Can raise Unix.Unix_error *)
  val pwrite_lwt : ?blocking:bool ->
    Unix.file_descr -> unit Ctypes.ptr -> int -> int64 -> int Lwt.t

  (** Can raise Unix.Unix_error *)
  val read_lwt : ?blocking:bool ->
    Unix.file_descr -> unit Ctypes.ptr -> int -> int Lwt.t

  (** Can raise Unix.Unix_error *)
  val pread_lwt : ?blocking:bool ->
    Unix.file_descr -> unit Ctypes.ptr -> int -> int64 -> int Lwt.t
end

module Make
    (X:
     sig
       val pwrite : Unix.file_descr -> unit Ctypes.ptr -> int -> int64 -> int
       val pread : Unix.file_descr -> unit Ctypes.ptr -> int -> int64 -> int
     end) : S
