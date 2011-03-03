/*
 * Copyright 2008 Stefan Dösinger
 * Copyright 2009 Matteo Bruni
 * Copyright 2008-2009 Henri Verbeet for CodeWeavers
 * Copyright 2010 Rico Schüller
 *
 * This library is free software; you can redistribute it and/or
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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 */

#include "config.h"
#include "wine/port.h"

#include "d3dcompiler_private.h"

WINE_DEFAULT_DEBUG_CHANNEL(d3dcompiler);

#define WINE_D3DCOMPILER_TO_STR(x) case x: return #x

const char *debug_d3dcompiler_shader_variable_class(D3D_SHADER_VARIABLE_CLASS c)
{
    switch (c)
    {
        WINE_D3DCOMPILER_TO_STR(D3D_SVC_SCALAR);
        WINE_D3DCOMPILER_TO_STR(D3D_SVC_VECTOR);
        WINE_D3DCOMPILER_TO_STR(D3D_SVC_MATRIX_ROWS);
        WINE_D3DCOMPILER_TO_STR(D3D_SVC_MATRIX_COLUMNS);
        WINE_D3DCOMPILER_TO_STR(D3D_SVC_OBJECT);
        WINE_D3DCOMPILER_TO_STR(D3D_SVC_STRUCT);
        WINE_D3DCOMPILER_TO_STR(D3D_SVC_INTERFACE_CLASS);
        WINE_D3DCOMPILER_TO_STR(D3D_SVC_INTERFACE_POINTER);
        default:
            FIXME("Unrecognized D3D_SHADER_VARIABLE_CLASS %#x.\n", c);
            return "unrecognized";
    }
}

const char *debug_d3dcompiler_shader_variable_type(D3D_SHADER_VARIABLE_TYPE t)
{
    switch (t)
    {
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_VOID);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_BOOL);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_INT);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_FLOAT);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_STRING);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURE);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURE1D);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURE2D);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURE3D);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURECUBE);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_SAMPLER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_PIXELSHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_VERTEXSHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_UINT);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_UINT8);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_GEOMETRYSHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RASTERIZER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_DEPTHSTENCIL);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_BLEND);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_BUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_CBUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TBUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURE1DARRAY);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURE2DARRAY);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RENDERTARGETVIEW);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_DEPTHSTENCILVIEW);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURE2DMS);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURE2DMSARRAY);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_TEXTURECUBEARRAY);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_HULLSHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_DOMAINSHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_INTERFACE_POINTER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_COMPUTESHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_DOUBLE);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RWTEXTURE1D);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RWTEXTURE1DARRAY);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RWTEXTURE2D);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RWTEXTURE2DARRAY);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RWTEXTURE3D);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RWBUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_BYTEADDRESS_BUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RWBYTEADDRESS_BUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_STRUCTURED_BUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_RWSTRUCTURED_BUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_APPEND_STRUCTURED_BUFFER);
        WINE_D3DCOMPILER_TO_STR(D3D_SVT_CONSUME_STRUCTURED_BUFFER);
        default:
            FIXME("Unrecognized D3D_SHADER_VARIABLE_TYPE %#x.\n", t);
            return "unrecognized";
    }
}

const char *debug_d3dcompiler_d3d_blob_part(D3D_BLOB_PART part)
{
    switch(part)
    {
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_INPUT_SIGNATURE_BLOB);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_OUTPUT_SIGNATURE_BLOB);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_INPUT_AND_OUTPUT_SIGNATURE_BLOB);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_PATCH_CONSTANT_SIGNATURE_BLOB);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_ALL_SIGNATURE_BLOB);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_DEBUG_INFO);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_LEGACY_SHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_XNA_PREPASS_SHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_XNA_SHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_TEST_ALTERNATE_SHADER);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_TEST_COMPILE_DETAILS);
        WINE_D3DCOMPILER_TO_STR(D3D_BLOB_TEST_COMPILE_PERF);
        default:
            FIXME("Unrecognized D3D_BLOB_PART %#x\n", part);
            return "unrecognized";
    }
}

const char *debug_print_srcmod(DWORD mod)
{
    switch (mod)
    {
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_NEG);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_BIAS);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_BIASNEG);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_SIGN);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_SIGNNEG);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_COMP);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_X2);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_X2NEG);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_DZ);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_DW);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_ABS);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_ABSNEG);
        WINE_D3DCOMPILER_TO_STR(BWRITERSPSM_NOT);
        default:
            FIXME("Unrecognized source modifier %#x.\n", mod);
            return "unrecognized_src_mod";
    }
}

#undef WINE_D3DCOMPILER_TO_STR

const char *debug_print_dstmod(DWORD mod)
{
    switch (mod)
    {
        case 0:
            return "";
        case BWRITERSPDM_SATURATE:
            return "_sat";
        case BWRITERSPDM_PARTIALPRECISION:
            return "_pp";
        case BWRITERSPDM_MSAMPCENTROID:
            return "_centroid";
        case BWRITERSPDM_SATURATE | BWRITERSPDM_PARTIALPRECISION:
            return "_sat_pp";
        case BWRITERSPDM_SATURATE | BWRITERSPDM_MSAMPCENTROID:
            return "_sat_centroid";
        case BWRITERSPDM_PARTIALPRECISION | BWRITERSPDM_MSAMPCENTROID:
            return "_pp_centroid";
        case BWRITERSPDM_SATURATE | BWRITERSPDM_PARTIALPRECISION | BWRITERSPDM_MSAMPCENTROID:
            return "_sat_pp_centroid";
        default:
            return "Unexpected modifier\n";
    }
}

const char *debug_print_shift(DWORD shift)
{
    static const char * const shiftstrings[] =
    {
        "",
        "_x2",
        "_x4",
        "_x8",
        "_x16",
        "_x32",
        "",
        "",
        "",
        "",
        "",
        "",
        "_d16",
        "_d8",
        "_d4",
        "_d2",
    };
    return shiftstrings[shift];
}

static const char *get_regname(const struct shader_reg *reg)
{
    switch (reg->type)
    {
        case BWRITERSPR_TEMP:
            return wine_dbg_sprintf("r%u", reg->regnum);
        case BWRITERSPR_INPUT:
            return wine_dbg_sprintf("v%u", reg->regnum);
        case BWRITERSPR_CONST:
            return wine_dbg_sprintf("c%u", reg->regnum);
        case BWRITERSPR_ADDR:
            return wine_dbg_sprintf("a%u", reg->regnum);
        case BWRITERSPR_TEXTURE:
            return wine_dbg_sprintf("t%u", reg->regnum);
        case BWRITERSPR_RASTOUT:
            switch (reg->regnum)
            {
                case BWRITERSRO_POSITION:   return "oPos";
                case BWRITERSRO_FOG:        return "oFog";
                case BWRITERSRO_POINT_SIZE: return "oPts";
                default: return "Unexpected RASTOUT";
            }
        case BWRITERSPR_ATTROUT:
            return wine_dbg_sprintf("oD%u", reg->regnum);
        case BWRITERSPR_TEXCRDOUT:
            return wine_dbg_sprintf("oT%u", reg->regnum);
        case BWRITERSPR_OUTPUT:
            return wine_dbg_sprintf("o%u", reg->regnum);
        case BWRITERSPR_CONSTINT:
            return wine_dbg_sprintf("i%u", reg->regnum);
        case BWRITERSPR_COLOROUT:
            return wine_dbg_sprintf("oC%u", reg->regnum);
        case BWRITERSPR_DEPTHOUT:
            return "oDepth";
        case BWRITERSPR_SAMPLER:
            return wine_dbg_sprintf("s%u", reg->regnum);
        case BWRITERSPR_CONSTBOOL:
            return wine_dbg_sprintf("b%u", reg->regnum);
        case BWRITERSPR_LOOP:
            return "aL";
        case BWRITERSPR_MISCTYPE:
            switch (reg->regnum)
            {
                case 0: return "vPos";
                case 1: return "vFace";
                default: return "unexpected misctype";
            }
        case BWRITERSPR_LABEL:
            return wine_dbg_sprintf("l%u", reg->regnum);
        case BWRITERSPR_PREDICATE:
            return wine_dbg_sprintf("p%u", reg->regnum);
        default:
            return wine_dbg_sprintf("unknown regname %#x", reg->type);
    }
}

static const char *debug_print_writemask(DWORD mask)
{
    char ret[6];
    unsigned char pos = 1;

    if(mask == BWRITERSP_WRITEMASK_ALL) return "";
    ret[0] = '.';
    if(mask & BWRITERSP_WRITEMASK_0) ret[pos++] = 'x';
    if(mask & BWRITERSP_WRITEMASK_1) ret[pos++] = 'y';
    if(mask & BWRITERSP_WRITEMASK_2) ret[pos++] = 'z';
    if(mask & BWRITERSP_WRITEMASK_3) ret[pos++] = 'w';
    ret[pos] = 0;

    return wine_dbg_sprintf("%s", ret);
}

static const char *debug_print_swizzle(DWORD arg)
{
    char ret[6];
    unsigned int i;
    DWORD swizzle[4];

    switch (arg)
    {
        case BWRITERVS_NOSWIZZLE:
            return "";
        case BWRITERVS_SWIZZLE_X:
            return ".x";
        case BWRITERVS_SWIZZLE_Y:
            return ".y";
        case BWRITERVS_SWIZZLE_Z:
            return ".z";
        case BWRITERVS_SWIZZLE_W:
            return ".w";
    }

    swizzle[0] = (arg >> (BWRITERVS_SWIZZLE_SHIFT + 0)) & 0x03;
    swizzle[1] = (arg >> (BWRITERVS_SWIZZLE_SHIFT + 2)) & 0x03;
    swizzle[2] = (arg >> (BWRITERVS_SWIZZLE_SHIFT + 4)) & 0x03;
    swizzle[3] = (arg >> (BWRITERVS_SWIZZLE_SHIFT + 6)) & 0x03;

    ret[0] = '.';
    for (i = 0; i < 4; ++i)
    {
        switch (swizzle[i])
        {
            case 0: ret[1 + i] = 'x'; break;
            case 1: ret[1 + i] = 'y'; break;
            case 2: ret[1 + i] = 'z'; break;
            case 3: ret[1 + i] = 'w'; break;
        }
    }
    ret[5] = '\0';

    return wine_dbg_sprintf("%s", ret);
}

static const char *debug_print_relarg(const struct shader_reg *reg)
{
    const char *short_swizzle;
    if (!reg->rel_reg) return "";

    short_swizzle = debug_print_swizzle(reg->rel_reg->u.swizzle);

    if (reg->rel_reg->type == BWRITERSPR_ADDR)
        return wine_dbg_sprintf("[a%u%s]", reg->rel_reg->regnum, short_swizzle);
    else if(reg->rel_reg->type == BWRITERSPR_LOOP && reg->rel_reg->regnum == 0)
        return wine_dbg_sprintf("[aL%s]", short_swizzle);
    else
        return "Unexpected relative addressing argument";
}

const char *debug_print_dstreg(const struct shader_reg *reg)
{
    return wine_dbg_sprintf("%s%s%s", get_regname(reg),
            debug_print_relarg(reg),
            debug_print_writemask(reg->u.writemask));
}

const char *debug_print_srcreg(const struct shader_reg *reg)
{
    switch (reg->srcmod)
    {
        case BWRITERSPSM_NONE:
            return wine_dbg_sprintf("%s%s%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_NEG:
            return wine_dbg_sprintf("-%s%s%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_BIAS:
            return wine_dbg_sprintf("%s%s_bias%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_BIASNEG:
            return wine_dbg_sprintf("-%s%s_bias%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_SIGN:
            return wine_dbg_sprintf("%s%s_bx2%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_SIGNNEG:
            return wine_dbg_sprintf("-%s%s_bx2%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_COMP:
            return wine_dbg_sprintf("1 - %s%s%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_X2:
            return wine_dbg_sprintf("%s%s_x2%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_X2NEG:
            return wine_dbg_sprintf("-%s%s_x2%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_DZ:
            return wine_dbg_sprintf("%s%s_dz%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_DW:
            return wine_dbg_sprintf("%s%s_dw%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_ABS:
            return wine_dbg_sprintf("%s%s_abs%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_ABSNEG:
            return wine_dbg_sprintf("-%s%s_abs%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
        case BWRITERSPSM_NOT:
            return wine_dbg_sprintf("!%s%s%s", get_regname(reg),
                    debug_print_relarg(reg),
                    debug_print_swizzle(reg->u.swizzle));
    }
    return "Unknown modifier";
}

const char *debug_print_comp(DWORD comp)
{
    switch (comp)
    {
        case BWRITER_COMPARISON_NONE: return "";
        case BWRITER_COMPARISON_GT:   return "_gt";
        case BWRITER_COMPARISON_EQ:   return "_eq";
        case BWRITER_COMPARISON_GE:   return "_ge";
        case BWRITER_COMPARISON_LT:   return "_lt";
        case BWRITER_COMPARISON_NE:   return "_ne";
        case BWRITER_COMPARISON_LE:   return "_le";
        default: return "_unknown";
    }
}

const char *debug_print_opcode(DWORD opcode)
{
    switch (opcode)
    {
        case BWRITERSIO_NOP:          return "nop";
        case BWRITERSIO_MOV:          return "mov";
        case BWRITERSIO_ADD:          return "add";
        case BWRITERSIO_SUB:          return "sub";
        case BWRITERSIO_MAD:          return "mad";
        case BWRITERSIO_MUL:          return "mul";
        case BWRITERSIO_RCP:          return "rcp";
        case BWRITERSIO_RSQ:          return "rsq";
        case BWRITERSIO_DP3:          return "dp3";
        case BWRITERSIO_DP4:          return "dp4";
        case BWRITERSIO_MIN:          return "min";
        case BWRITERSIO_MAX:          return "max";
        case BWRITERSIO_SLT:          return "slt";
        case BWRITERSIO_SGE:          return "sge";
        case BWRITERSIO_EXP:          return "exp";
        case BWRITERSIO_LOG:          return "log";
        case BWRITERSIO_LIT:          return "lit";
        case BWRITERSIO_DST:          return "dst";
        case BWRITERSIO_LRP:          return "lrp";
        case BWRITERSIO_FRC:          return "frc";
        case BWRITERSIO_M4x4:         return "m4x4";
        case BWRITERSIO_M4x3:         return "m4x3";
        case BWRITERSIO_M3x4:         return "m3x4";
        case BWRITERSIO_M3x3:         return "m3x3";
        case BWRITERSIO_M3x2:         return "m3x2";
        case BWRITERSIO_CALL:         return "call";
        case BWRITERSIO_CALLNZ:       return "callnz";
        case BWRITERSIO_LOOP:         return "loop";
        case BWRITERSIO_RET:          return "ret";
        case BWRITERSIO_ENDLOOP:      return "endloop";
        case BWRITERSIO_LABEL:        return "label";
        case BWRITERSIO_DCL:          return "dcl";
        case BWRITERSIO_POW:          return "pow";
        case BWRITERSIO_CRS:          return "crs";
        case BWRITERSIO_SGN:          return "sgn";
        case BWRITERSIO_ABS:          return "abs";
        case BWRITERSIO_NRM:          return "nrm";
        case BWRITERSIO_SINCOS:       return "sincos";
        case BWRITERSIO_REP:          return "rep";
        case BWRITERSIO_ENDREP:       return "endrep";
        case BWRITERSIO_IF:           return "if";
        case BWRITERSIO_IFC:          return "ifc";
        case BWRITERSIO_ELSE:         return "else";
        case BWRITERSIO_ENDIF:        return "endif";
        case BWRITERSIO_BREAK:        return "break";
        case BWRITERSIO_BREAKC:       return "breakc";
        case BWRITERSIO_MOVA:         return "mova";
        case BWRITERSIO_DEFB:         return "defb";
        case BWRITERSIO_DEFI:         return "defi";
        case BWRITERSIO_TEXCOORD:     return "texcoord";
        case BWRITERSIO_TEXKILL:      return "texkill";
        case BWRITERSIO_TEX:          return "tex";
        case BWRITERSIO_TEXBEM:       return "texbem";
        case BWRITERSIO_TEXBEML:      return "texbeml";
        case BWRITERSIO_TEXREG2AR:    return "texreg2ar";
        case BWRITERSIO_TEXREG2GB:    return "texreg2gb";
        case BWRITERSIO_TEXM3x2PAD:   return "texm3x2pad";
        case BWRITERSIO_TEXM3x2TEX:   return "texm3x2tex";
        case BWRITERSIO_TEXM3x3PAD:   return "texm3x3pad";
        case BWRITERSIO_TEXM3x3TEX:   return "texm3x3tex";
        case BWRITERSIO_TEXM3x3SPEC:  return "texm3x3vspec";
        case BWRITERSIO_TEXM3x3VSPEC: return "texm3x3vspec";
        case BWRITERSIO_EXPP:         return "expp";
        case BWRITERSIO_LOGP:         return "logp";
        case BWRITERSIO_CND:          return "cnd";
        case BWRITERSIO_DEF:          return "def";
        case BWRITERSIO_TEXREG2RGB:   return "texreg2rgb";
        case BWRITERSIO_TEXDP3TEX:    return "texdp3tex";
        case BWRITERSIO_TEXM3x2DEPTH: return "texm3x2depth";
        case BWRITERSIO_TEXDP3:       return "texdp3";
        case BWRITERSIO_TEXM3x3:      return "texm3x3";
        case BWRITERSIO_TEXDEPTH:     return "texdepth";
        case BWRITERSIO_CMP:          return "cmp";
        case BWRITERSIO_BEM:          return "bem";
        case BWRITERSIO_DP2ADD:       return "dp2add";
        case BWRITERSIO_DSX:          return "dsx";
        case BWRITERSIO_DSY:          return "dsy";
        case BWRITERSIO_TEXLDD:       return "texldd";
        case BWRITERSIO_SETP:         return "setp";
        case BWRITERSIO_TEXLDL:       return "texldl";
        case BWRITERSIO_BREAKP:       return "breakp";
        case BWRITERSIO_PHASE:        return "phase";

        case BWRITERSIO_TEXLDP:       return "texldp";
        case BWRITERSIO_TEXLDB:       return "texldb";

        default:                      return "unknown";
    }
}

void skip_dword_unknown(const char **ptr, unsigned int count)
{
    unsigned int i;
    DWORD d;

    FIXME("Skipping %u unknown DWORDs:\n", count);
    for (i = 0; i < count; ++i)
    {
        read_dword(ptr, &d);
        FIXME("\t0x%08x\n", d);
    }
}

void write_dword_unknown(char **ptr, DWORD d)
{
    FIXME("Writing unknown DWORD 0x%08x\n", d);
    write_dword(ptr, d);
}

HRESULT dxbc_add_section(struct dxbc *dxbc, DWORD tag, const char *data, DWORD data_size)
{
    TRACE("dxbc %p, tag %s, size %#x.\n", dxbc, debugstr_an((const char *)&tag, 4), data_size);

    if (dxbc->count >= dxbc->size)
    {
        struct dxbc_section *new_sections;
        DWORD new_size = dxbc->size << 1;

        new_sections = HeapReAlloc(GetProcessHeap(), 0, dxbc->sections, new_size * sizeof(*dxbc->sections));
        if (!new_sections)
        {
            ERR("Failed to allocate dxbc section memory\n");
            return E_OUTOFMEMORY;
        }

        dxbc->sections = new_sections;
        dxbc->size = new_size;
    }

    dxbc->sections[dxbc->count].tag = tag;
    dxbc->sections[dxbc->count].data_size = data_size;
    dxbc->sections[dxbc->count].data = data;
    ++dxbc->count;

    return S_OK;
}

HRESULT dxbc_init(struct dxbc *dxbc, UINT size)
{
    TRACE("dxbc %p, size %u.\n", dxbc, size);

    /* use a good starting value for the size if none specified */
    if (!size) size = 2;

    dxbc->sections = HeapAlloc(GetProcessHeap(), 0, size * sizeof(*dxbc->sections));
    if (!dxbc->sections)
    {
        ERR("Failed to allocate dxbc section memory\n");
        return E_OUTOFMEMORY;
    }

    dxbc->size = size;
    dxbc->count = 0;

    return S_OK;
}

HRESULT dxbc_parse(const char *data, SIZE_T data_size, struct dxbc *dxbc)
{
    const char *ptr = data;
    HRESULT hr;
    unsigned int i;
    DWORD tag, total_size, chunk_count;

    if (!data)
    {
        WARN("No data supplied.\n");
        return E_FAIL;
    }

    read_dword(&ptr, &tag);
    TRACE("tag: %s.\n", debugstr_an((const char *)&tag, 4));

    if (tag != TAG_DXBC)
    {
        WARN("Wrong tag.\n");
        return E_FAIL;
    }

    /* checksum? */
    skip_dword_unknown(&ptr, 4);

    skip_dword_unknown(&ptr, 1);

    read_dword(&ptr, &total_size);
    TRACE("total size: %#x\n", total_size);

    if (data_size != total_size)
    {
        WARN("Wrong size supplied.\n");
        return D3DERR_INVALIDCALL;
    }

    read_dword(&ptr, &chunk_count);
    TRACE("chunk count: %#x\n", chunk_count);

    hr = dxbc_init(dxbc, chunk_count);
    if (FAILED(hr))
    {
        WARN("Failed to init dxbc\n");
        return hr;
    }

    for (i = 0; i < chunk_count; ++i)
    {
        DWORD chunk_tag, chunk_size;
        const char *chunk_ptr;
        DWORD chunk_offset;

        read_dword(&ptr, &chunk_offset);
        TRACE("chunk %u at offset %#x\n", i, chunk_offset);

        chunk_ptr = data + chunk_offset;

        read_dword(&chunk_ptr, &chunk_tag);
        read_dword(&chunk_ptr, &chunk_size);

        hr = dxbc_add_section(dxbc, chunk_tag, chunk_ptr, chunk_size);
        if (FAILED(hr))
        {
            WARN("Failed to add section to dxbc\n");
            return hr;
        }
    }

    return hr;
}

void dxbc_destroy(struct dxbc *dxbc)
{
    TRACE("dxbc %p.\n", dxbc);

    HeapFree(GetProcessHeap(), 0, dxbc->sections);
}

HRESULT dxbc_write_blob(struct dxbc *dxbc, ID3DBlob **blob)
{
    DWORD size = 32, offset = size + 4 * dxbc->count;
    ID3DBlob *object;
    HRESULT hr;
    char *ptr;
    unsigned int i;

    TRACE("dxbc %p, blob %p.\n", dxbc, blob);

    for (i = 0; i < dxbc->count; ++i)
    {
        size += 12 + dxbc->sections[i].data_size;
    }

    hr = D3DCreateBlob(size, &object);
    if (FAILED(hr))
    {
        WARN("Failed to create blob\n");
        return hr;
    }

    ptr = ID3D10Blob_GetBufferPointer(object);

    write_dword(&ptr, TAG_DXBC);

    /* signature(?) */
    write_dword_unknown(&ptr, 0);
    write_dword_unknown(&ptr, 0);
    write_dword_unknown(&ptr, 0);
    write_dword_unknown(&ptr, 0);

    /* seems to be always 1 */
    write_dword_unknown(&ptr, 1);

    /* DXBC size */
    write_dword(&ptr, size);

    /* chunk count */
    write_dword(&ptr, dxbc->count);

    /* write the chunk offsets */
    for (i = 0; i < dxbc->count; ++i)
    {
        write_dword(&ptr, offset);
        offset += 8 + dxbc->sections[i].data_size;
    }

    /* write the chunks */
    for (i = 0; i < dxbc->count; ++i)
    {
        write_dword(&ptr, dxbc->sections[i].tag);
        write_dword(&ptr, dxbc->sections[i].data_size);
        memcpy(ptr, dxbc->sections[i].data, dxbc->sections[i].data_size);
        ptr += dxbc->sections[i].data_size;
    }

    TRACE("Created ID3DBlob %p\n", object);

    *blob = object;

    return S_OK;
}
