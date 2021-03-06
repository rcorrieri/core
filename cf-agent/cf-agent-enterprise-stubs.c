/*
   Copyright (C) CFEngine AS

   This file is part of CFEngine 3 - written and maintained by CFEngine AS.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; version 3.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA

  To the extent this program is licensed as part of the Enterprise
  versions of CFEngine, the applicable Commercial Open Source License
  (COSL) may apply to this file if you as a licensee so wish it. See
  included file COSL.txt.
*/

#include <cf-agent-enterprise-stubs.h>

ENTERPRISE_FUNC_3ARG_DEFINE_STUB(PromiseResult, VerifyWindowsService,
                                 ARG_UNUSED EvalContext *, ctx,
                                 ARG_UNUSED Attributes, a,
                                 ARG_UNUSED const Promise *, pp)
{
    Log(LOG_LEVEL_ERR, "Windows service management is only supported in CFEngine Enterprise");
    return PROMISE_RESULT_FAIL;
}

ENTERPRISE_VOID_FUNC_2ARG_DEFINE_STUB(void, LastSawBundle, ARG_UNUSED const Bundle *, bundle, ARG_UNUSED double, comp)
{
}

ENTERPRISE_FUNC_8ARG_DEFINE_STUB(PromiseResult, LogFileChange,
                                 ARG_UNUSED EvalContext *, ctx,
                                 ARG_UNUSED const char *, file,
                                 ARG_UNUSED int, change,
                                 ARG_UNUSED Attributes, a,
                                 ARG_UNUSED const Promise *, pp,
                                 ARG_UNUSED CopyRegularFileFunction, CopyRegularFilePtr,
                                 ARG_UNUSED const char *, destination,
                                 ARG_UNUSED DeleteCompressedArrayFunction, DeleteCompressedArrayPtr)
{
    Log(LOG_LEVEL_VERBOSE, "Logging file differences requires version Nova or above");
    return PROMISE_RESULT_NOOP;
}

ENTERPRISE_FUNC_5ARG_DEFINE_STUB(PromiseResult, Nova_CheckNtACL,
                                 ARG_UNUSED EvalContext *, ctx,
                                 ARG_UNUSED const char *, file_path,
                                 ARG_UNUSED Acl, acl,
                                 ARG_UNUSED Attributes, a,
                                 ARG_UNUSED const Promise *, pp)
{
    Log(LOG_LEVEL_INFO, "NTFS ACLs are only supported in CFEngine Enterprise");
    return PROMISE_RESULT_NOOP;
}

ENTERPRISE_VOID_FUNC_1ARG_DEFINE_STUB(void, Nova_NoteVarUsageDB, ARG_UNUSED EvalContext *, ctx)
{
}

ENTERPRISE_VOID_FUNC_1ARG_DEFINE_STUB(void, Nova_NoteClassUsage, ARG_UNUSED EvalContext *, ctx)
{
}

ENTERPRISE_VOID_FUNC_1ARG_DEFINE_STUB(void, Nova_TrackExecution, ARG_UNUSED const char *, input_file)
{
}

ENTERPRISE_VOID_FUNC_1ARG_DEFINE_STUB(void, GenerateDiffReports, ARG_UNUSED const char *, input_file)
{
}
