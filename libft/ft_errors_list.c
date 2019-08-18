/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/15 17:41:54 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_errors_0_21(int error)
{
	char *list[22];

	list[0] = "Undefined error: 0";
	list[1] = "Operation not permitted";
	list[2] = "No such file or directory";
	list[3] = "No such process";
	list[4] = "Interrupted system call";
	list[5] = "Input/output error";
	list[6] = "Device not configured";
	list[7] = "Argument list too long";
	list[8] = "Exec format error";
	list[9] = "Bad file descriptor";
	list[10] = "No child processes";
	list[11] = "Resource deadlock avoided";
	list[12] = "Cannot allocate memory";
	list[13] = "Permission denied";
	list[14] = "Bad address";
	list[15] = "Block device required";
	list[16] = "Resource busy";
	list[17] = "File exists";
	list[18] = "Cross-device link";
	list[19] = "Operation not supported by device";
	list[20] = "Not a directory";
	list[21] = "Is a directory";
	return (list[error]);
}

char	*ft_errors_22_43(int error)
{
	char *list[22];

	list[0] = "Invalid argument";
	list[1] = "Too many open files in system";
	list[2] = "Too many open files";
	list[3] = "Inappropriate ioctl for device";
	list[4] = "Text file busy";
	list[5] = "File too large";
	list[6] = "No space left on device";
	list[7] = "Illegal seek";
	list[8] = "Read-only file system";
	list[9] = "Too many links";
	list[10] = "Broken pipe";
	list[11] = "Numerical argument out of domain";
	list[12] = "Result too large";
	list[13] = "Resource temporarily unavailable";
	list[14] = "Operation now in progress";
	list[15] = "Operation already in progress";
	list[16] = "Socket operation on non-socket";
	list[17] = "Destination address required";
	list[18] = "Message too long";
	list[19] = "Protocol wrong type for socket";
	list[20] = "Protocol not available";
	list[21] = "Protocol not supported";
	return (list[error - 22]);
}

char	*ft_errors_44_65(int error)
{
	char *list[22];

	list[0] = "Socket type not supported";
	list[1] = "Operation not supported";
	list[2] = "Protocol family not supported";
	list[3] = "Address family not supported by protocol family";
	list[4] = "Address already in use";
	list[5] = "Can't assign requested address";
	list[6] = "Network is down";
	list[7] = "Network is unreachable";
	list[8] = "Network dropped connection on reset";
	list[9] = "Software caused connection abort";
	list[10] = "Connection reset by peer";
	list[11] = "No buffer space available";
	list[12] = "Socket is already connected";
	list[13] = "Socket is not connected";
	list[14] = "Can't send after socket shutdown";
	list[15] = "Too many references: can't splice";
	list[16] = "Operation timed out";
	list[17] = "Connection refused";
	list[18] = "Too many levels of symbolic links";
	list[19] = "File name too long";
	list[20] = "Host is down";
	list[21] = "No route to host";
	return (list[error - 44]);
}

char	*ft_errors_66_87(int error)
{
	char *list[22];

	list[0] = "Directory not empty";
	list[1] = "Too many processes";
	list[2] = "Too many users";
	list[3] = "Disc quota exceeded";
	list[4] = "Stale NFS file handle";
	list[5] = "Too many levels of remote in path";
	list[6] = "RPC struct is bad";
	list[7] = "RPC version wrong";
	list[8] = "RPC prog. not avail";
	list[9] = "Program version wrong";
	list[10] = "Bad procedure for program";
	list[11] = "No locks available";
	list[12] = "Function not implemented";
	list[13] = "Inappropriate file type or format";
	list[14] = "Authentication error";
	list[15] = "Need authenticator";
	list[16] = "Device power is off";
	list[17] = "Device error";
	list[18] = "Value too large to be stored in data type";
	list[19] = "Bad executable (or shared library)";
	list[20] = "Bad CPU type in executable";
	list[21] = "Shared library version mismatch";
	return (list[error - 66]);
}

char	*ft_errors_88_106(int error)
{
	char *list[22];

	list[0] = "Malformed Mach-o file";
	list[1] = "Operation canceled";
	list[2] = "Identifier removed";
	list[3] = "No message of desired type";
	list[4] = "Illegal byte sequence";
	list[5] = "Attribute not found";
	list[6] = "Bad message";
	list[7] = "EMULTIHOP (Reserved)";
	list[8] = "No message available on STREAM";
	list[9] = "ENOLINK (Reserved)";
	list[10] = "No STREAM resources";
	list[11] = "Not a STREAM";
	list[12] = "Protocol error";
	list[13] = "STREAM ioctl timeout";
	list[14] = "Operation not supported on socket";
	list[15] = "Policy not found";
	list[16] = "State not recoverable";
	list[17] = "Previous owner died";
	list[18] = "Interface output queue is full";
	return (list[error - 88]);
}
