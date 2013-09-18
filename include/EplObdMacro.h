/****************************************************************************

  (c) SYSTEC electronic GmbH, D-07973 Greiz, August-Bebel-Str. 29
      www.systec-electronic.com

  Project:      openPOWERLINK

  Description:  include file for macros of EplOBD-Module

  License:

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

    3. Neither the name of SYSTEC electronic GmbH nor the names of its
       contributors may be used to endorse or promote products derived
       from this software without prior written permission. For written
       permission, please contact info@systec-electronic.com.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    Severability Clause:

        If a provision of this License is or becomes illegal, invalid or
        unenforceable in any jurisdiction, that shall not affect:
        1. the validity or enforceability in that jurisdiction of any other
           provision of this License; or
        2. the validity or enforceability in other jurisdictions of that or
           any other provision of this License.

  -------------------------------------------------------------------------

                $RCSfile$

                $Author$

                $Revision$  $Date$

                $State$

                Build Environment:
                    GCC V3.4

  -------------------------------------------------------------------------

  Revision History:

  2006/06/05 k.t.:   start of the implementation
                    -> based on CANopen ObdMacro.h



****************************************************************************/


//---------------------------------------------------------------------------
// const defines
//---------------------------------------------------------------------------

#if defined (EPL_OBD_DEFINE_MACRO)

    //-------------------------------------------------------------------------------------------
    #if defined (EPL_OBD_CREATE_ROM_DATA)

//        #pragma message ("EPL_OBD_CREATE_ROM_DATA")

        #define EPL_OBD_BEGIN()                                                         static CONST DWORD  dwObd_OBK_g = 0x0000;
        #define EPL_OBD_END()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_PART_GENERIC()
        #define EPL_OBD_BEGIN_PART_MANUFACTURER()
        #define EPL_OBD_BEGIN_PART_DEVICE()
        #define EPL_OBD_END_PART()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_INDEX_RAM(ind,cnt,call)
        #define EPL_OBD_END_INDEX(ind)
        #define EPL_OBD_RAM_INDEX_RAM_ARRAY(ind,cnt,call,typ,acc,dtyp,name,def)         static CONST tObdUnsigned8 ROM xDef##ind##_0x00_g = (cnt); \
                                                                                        static CONST dtyp ROM xDef##ind##_0x01_g = (def);
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY(ind,cnt,call,typ,acc,dtyp,name,def)      static CONST tObdUnsigned8 ROM xDef##ind##_0x00_g = (cnt); \
                                                                                        static CONST dtyp ROM xDef##ind##_0x01_g = (def);
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY_NOINIT(ind,cnt,call,typ,acc,dtyp,name)   static CONST tObdUnsigned8 ROM xDef##ind##_0x00_g = (cnt);
        #define EPL_OBD_RAM_INDEX_RAM_PDO_MAPPING(ind,cnt,call,acc,name,def)            static CONST tObdUnsigned8 ROM xDef##ind##_0x00_g = 0; \
                                                                                        static CONST tObdUnsigned64 ROM xDef##ind##_0x01_g = (def);

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_SUBINDEX_RAM_VAR(ind,sub,typ,acc,dtyp,name,val)                 static CONST dtyp ROM xDef##ind##_##sub##_g        = val;
        #define EPL_OBD_SUBINDEX_RAM_VAR_RG(ind,sub,typ,acc,dtyp,name,val,low,high)     static CONST dtyp ROM xDef##ind##_##sub##_g[3]     = {val,low,high};
        #define EPL_OBD_SUBINDEX_RAM_VAR_NOINIT(ind,sub,typ,acc,dtyp,name)
        #define EPL_OBD_SUBINDEX_RAM_VSTRING(ind,sub,acc,name,size,val)                 static char  MEM szCur##ind##_##sub##_g[size+1]; \
                                                                                        static CONST tObdVStringDef ROM xDef##ind##_##sub##_g = {size, val, szCur##ind##_##sub##_g};

        #define EPL_OBD_SUBINDEX_RAM_OSTRING(ind,sub,acc,name,size)                     static BYTE  MEM bCur##ind##_##sub##_g[size]; \
                                                                                        static CONST tObdOStringDef ROM xDef##ind##_##sub##_g = {size, ((BYTE*)""), bCur##ind##_##sub##_g};
        #define EPL_OBD_SUBINDEX_RAM_DOMAIN(ind,sub,acc,name)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF(ind,sub,typ,acc,dtyp,name,val)             static CONST dtyp ROM xDef##ind##_##sub##_g        = val;
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_RG(ind,sub,typ,acc,dtyp,name,val,low,high) static CONST dtyp ROM xDef##ind##_##sub##_g[3]     = {val,low,high};
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_NOINIT(ind,sub,typ,acc,dtyp,name)

//-------------------------------------------------------------------------------------------
    #elif defined (EPL_OBD_CREATE_RAM_DATA)

//        #pragma message ("EPL_OBD_CREATE_RAM_DATA")

        #define EPL_OBD_BEGIN()
        #define EPL_OBD_END()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_PART_GENERIC()
        #define EPL_OBD_BEGIN_PART_MANUFACTURER()
        #define EPL_OBD_BEGIN_PART_DEVICE()
        #define EPL_OBD_END_PART()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_INDEX_RAM(ind,cnt,call)
        #define EPL_OBD_END_INDEX(ind)
        #define EPL_OBD_RAM_INDEX_RAM_ARRAY(ind,cnt,call,typ,acc,dtyp,name,def)         static dtyp         MEM axCur##ind##_g[cnt];
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY(ind,cnt,call,typ,acc,dtyp,name,def)      static tObdVarEntry MEM aVarEntry##ind##_g[cnt];
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY_NOINIT(ind,cnt,call,typ,acc,dtyp,name)   static tObdVarEntry MEM aVarEntry##ind##_g[cnt];
        #define EPL_OBD_RAM_INDEX_RAM_PDO_MAPPING(ind,cnt,call,acc,name,def)            static tObdUnsigned8 MEM xCur##ind##_0x00_g; \
                                                                                        static tObdUnsigned64 MEM axCur##ind##_g[cnt];

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_SUBINDEX_RAM_VAR(ind,sub,typ,acc,dtyp,name,val)                 static dtyp         MEM xCur##ind##_##sub##_g;
        #define EPL_OBD_SUBINDEX_RAM_VAR_RG(ind,sub,typ,acc,dtyp,name,val,low,high)     static dtyp         MEM xCur##ind##_##sub##_g;
        #define EPL_OBD_SUBINDEX_RAM_VSTRING(ind,sub,acc,name,size,val)                 static tObdVString  MEM xCur##ind##_##sub##_g;
        #define EPL_OBD_SUBINDEX_RAM_OSTRING(ind,sub,acc,name,size)                     static tObdOString  MEM xCur##ind##_##sub##_g;
        #define EPL_OBD_SUBINDEX_RAM_VAR_NOINIT(ind,sub,typ,acc,dtyp,name)              static dtyp         MEM xCur##ind##_##sub##_g;
        #define EPL_OBD_SUBINDEX_RAM_DOMAIN(ind,sub,acc,name)                           static tObdVarEntry MEM VarEntry##ind##_##sub##_g;
        #define EPL_OBD_SUBINDEX_RAM_USERDEF(ind,sub,typ,acc,dtyp,name,val)             static tObdVarEntry MEM VarEntry##ind##_##sub##_g;
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_RG(ind,sub,typ,acc,dtyp,name,val,low,high) static tObdVarEntry MEM VarEntry##ind##_##sub##_g;
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_NOINIT(ind,sub,typ,acc,dtyp,name)          static tObdVarEntry MEM VarEntry##ind##_##sub##_g;

    //-------------------------------------------------------------------------------------------
    #elif defined (EPL_OBD_CREATE_SUBINDEX_TAB)

//        #pragma message ("EPL_OBD_CREATE_SUBINDEX_TAB")

        #define EPL_OBD_BEGIN()
        #define EPL_OBD_END()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_PART_GENERIC()
        #define EPL_OBD_BEGIN_PART_MANUFACTURER()
        #define EPL_OBD_BEGIN_PART_DEVICE()
        #define EPL_OBD_END_PART()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_INDEX_RAM(ind,cnt,call)                                   static tObdSubEntry MEM aObdSubEntry##ind##Ram_g[cnt]= {
        #define EPL_OBD_END_INDEX(ind)                                                  EPL_OBD_END_SUBINDEX()};
        #define EPL_OBD_RAM_INDEX_RAM_ARRAY(ind,cnt,call,typ,acc,dtyp,name,def)         static tObdSubEntry MEM aObdSubEntry##ind##Ram_g[]= { \
                                                                                        {0, kObdTypeUInt8, kObdAccCR,          &xDef##ind##_0x00_g,   NULL}, \
                                                                                        {1, typ,          (acc)|kObdAccArray, &xDef##ind##_0x01_g,   &axCur##ind##_g[0]}, \
                                                                                        EPL_OBD_END_SUBINDEX()};
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY(ind,cnt,call,typ,acc,dtyp,name,def)      static tObdSubEntry MEM aObdSubEntry##ind##Ram_g[]= { \
                                                                                        {0, kObdTypeUInt8, kObdAccCR,                     &xDef##ind##_0x00_g,   NULL}, \
                                                                                        {1, typ,          (acc)|kObdAccArray|kObdAccVar, &xDef##ind##_0x01_g,   &aVarEntry##ind##_g[0]}, \
                                                                                        EPL_OBD_END_SUBINDEX()};
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY_NOINIT(ind,cnt,call,typ,acc,dtyp,name)   static tObdSubEntry MEM aObdSubEntry##ind##Ram_g[]= { \
                                                                                        {0, kObdTypeUInt8, kObdAccCR,                     &xDef##ind##_0x00_g,   NULL}, \
                                                                                        {1, typ,          (acc)|kObdAccArray|kObdAccVar, NULL,                  &aVarEntry##ind##_g[0]}, \
                                                                                        EPL_OBD_END_SUBINDEX()};
        #define EPL_OBD_RAM_INDEX_RAM_PDO_MAPPING(ind,cnt,call,acc,name,def)            static tObdSubEntry MEM aObdSubEntry##ind##Ram_g[]= { \
                                                                                        {0, kObdTypeUInt8, kObdAccRW,          &xDef##ind##_0x00_g,   &xCur##ind##_0x00_g}, \
                                                                                        {1, kObdTypeUInt64, (acc)|kObdAccArray, &xDef##ind##_0x01_g,   &axCur##ind##_g[0]}, \
                                                                                        EPL_OBD_END_SUBINDEX()};

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_SUBINDEX_RAM_VAR(ind,sub,typ,acc,dtyp,name,val)                 {sub,typ,            (acc),                        &xDef##ind##_##sub##_g,   &xCur##ind##_##sub##_g},
        #define EPL_OBD_SUBINDEX_RAM_VAR_RG(ind,sub,typ,acc,dtyp,name,val,low,high)     {sub,typ,            (acc)|kObdAccRange,           &xDef##ind##_##sub##_g[0],&xCur##ind##_##sub##_g},
        #define EPL_OBD_SUBINDEX_RAM_VAR_NOINIT(ind,sub,typ,acc,dtyp,name)              {sub,typ,            (acc),                        NULL,   &xCur##ind##_##sub##_g},
        #define EPL_OBD_SUBINDEX_RAM_VSTRING(ind,sub,acc,name,size,val)                 {sub,kObdTypeVString,(acc)/*|kObdAccVar*/,         &xDef##ind##_##sub##_g,   &xCur##ind##_##sub##_g},
        #define EPL_OBD_SUBINDEX_RAM_OSTRING(ind,sub,acc,name,size)                     {sub,kObdTypeOString,(acc)/*|kObdAccVar*/,         &xDef##ind##_##sub##_g,   &xCur##ind##_##sub##_g},
        #define EPL_OBD_SUBINDEX_RAM_DOMAIN(ind,sub,acc,name)                           {sub,kObdTypeDomain, (acc)|kObdAccVar,             NULL,                     &VarEntry##ind##_##sub##_g},
        #define EPL_OBD_SUBINDEX_RAM_USERDEF(ind,sub,typ,acc,dtyp,name,val)             {sub,typ,           (acc)|kObdAccVar,             &xDef##ind##_##sub##_g,   &VarEntry##ind##_##sub##_g},
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_RG(ind,sub,typ,acc,dtyp,name,val,low,high) {sub,typ,           (acc)|kObdAccVar|kObdAccRange,&xDef##ind##_##sub##_g[0],&VarEntry##ind##_##sub##_g},
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_NOINIT(ind,sub,typ,acc,dtyp,name)          {sub,typ,           (acc)|kObdAccVar,             NULL,    &VarEntry##ind##_##sub##_g},


    //-------------------------------------------------------------------------------------------
    #elif defined (EPL_OBD_CREATE_INDEX_TAB)

//        #pragma message ("EPL_OBD_CREATE_INDEX_TAB")

        #define EPL_OBD_BEGIN()
        #define EPL_OBD_END()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_PART_GENERIC()                                            static  tObdEntry  aObdTabGeneric_g[]      = {
        #define EPL_OBD_BEGIN_PART_MANUFACTURER()                                       static  tObdEntry  aObdTabManufacturer_g[] = {
        #define EPL_OBD_BEGIN_PART_DEVICE()                                             static  tObdEntry  aObdTabDevice_g[]       = {
        #define EPL_OBD_END_PART()                                                      {EPL_OBD_TABLE_INDEX_END,(tObdSubEntryPtr)(void*)&dwObd_OBK_g,0,NULL}};

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_INDEX_RAM(ind,cnt,call)                                   {ind,(tObdSubEntryPtr)&aObdSubEntry##ind##Ram_g[0],cnt,(tObdCallback)call},
        #define EPL_OBD_END_INDEX(ind)
        #define EPL_OBD_RAM_INDEX_RAM_ARRAY(ind,cnt,call,typ,acc,dtyp,name,def)         {ind,(tObdSubEntryPtr)&aObdSubEntry##ind##Ram_g[0],(cnt)+1,(tObdCallback)call},
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY(ind,cnt,call,typ,acc,dtyp,name,def)      {ind,(tObdSubEntryPtr)&aObdSubEntry##ind##Ram_g[0],(cnt)+1,(tObdCallback)call},
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY_NOINIT(ind,cnt,call,typ,acc,dtyp,name)   {ind,(tObdSubEntryPtr)&aObdSubEntry##ind##Ram_g[0],(cnt)+1,(tObdCallback)call},
        #define EPL_OBD_RAM_INDEX_RAM_PDO_MAPPING(ind,cnt,call,acc,name,def)            {ind,(tObdSubEntryPtr)&aObdSubEntry##ind##Ram_g[0],(cnt)+1,(tObdCallback)call},

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_SUBINDEX_RAM_VAR(ind,sub,typ,acc,dtyp,name,val)
        #define EPL_OBD_SUBINDEX_RAM_VAR_RG(ind,sub,typ,acc,dtyp,name,val,low,high)
        #define EPL_OBD_SUBINDEX_RAM_VSTRING(ind,sub,acc,name,size,val)
        #define EPL_OBD_SUBINDEX_RAM_OSTRING(ind,sub,acc,name,size)
        #define EPL_OBD_SUBINDEX_RAM_VAR_NOINIT(ind,sub,typ,acc,dtyp,name)
        #define EPL_OBD_SUBINDEX_RAM_DOMAIN(ind,sub,acc,name)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF(ind,sub,typ,acc,dtyp,name,val)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_RG(ind,sub,typ,acc,dtyp,name,val,low,high)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_NOINIT(ind,sub,typ,acc,dtyp,name)

            //-------------------------------------------------------------------------------------------
    #elif defined (EPL_OBD_CREATE_INIT_FUNCTION)

//        #pragma message ("EPL_OBD_CREATE_INIT_FUNCTION")

        #define EPL_OBD_BEGIN()
        #define EPL_OBD_END()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_PART_GENERIC()                                            pInitParam->m_pGenericPart      = (tObdEntryPtr) &aObdTabGeneric_g[0];
        #define EPL_OBD_BEGIN_PART_MANUFACTURER()                                       pInitParam->m_pManufacturerPart = (tObdEntryPtr) &aObdTabManufacturer_g[0];
        #define EPL_OBD_BEGIN_PART_DEVICE()                                             pInitParam->m_pDevicePart       = (tObdEntryPtr) &aObdTabDevice_g[0];
        #define EPL_OBD_END_PART()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_INDEX_RAM(ind,cnt,call)
        #define EPL_OBD_END_INDEX(ind)
        #define EPL_OBD_RAM_INDEX_RAM_ARRAY(ind,cnt,call,typ,acc,dtyp,name,def)
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY(ind,cnt,call,typ,acc,dtyp,name,def)
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY_NOINIT(ind,cnt,call,typ,acc,dtyp,name)
        #define EPL_OBD_RAM_INDEX_RAM_PDO_MAPPING(ind,cnt,call,acc,name,def)

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_SUBINDEX_RAM_VAR(ind,sub,typ,acc,dtyp,name,val)
        #define EPL_OBD_SUBINDEX_RAM_VAR_RG(ind,sub,typ,acc,dtyp,name,val,low,high)
        #define EPL_OBD_SUBINDEX_RAM_VSTRING(ind,sub,acc,name,size,val)
        #define EPL_OBD_SUBINDEX_RAM_OSTRING(ind,sub,acc,name,size)
        #define EPL_OBD_SUBINDEX_RAM_VAR_NOINIT(ind,sub,typ,acc,dtyp,name)
        #define EPL_OBD_SUBINDEX_RAM_DOMAIN(ind,sub,acc,name)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF(ind,sub,typ,acc,dtyp,name,val)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_RG(ind,sub,typ,acc,dtyp,name,val,low,high)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_NOINIT(ind,sub,typ,acc,dtyp,name)


    //-------------------------------------------------------------------------------------------
    #elif defined (EPL_OBD_CREATE_INIT_SUBINDEX)

//        #pragma message ("EPL_OBD_CREATE_INIT_SUBINDEX")

        #define EPL_OBD_BEGIN()
        #define EPL_OBD_END()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_PART_GENERIC()
        #define EPL_OBD_BEGIN_PART_MANUFACTURER()
        #define EPL_OBD_BEGIN_PART_DEVICE()
        #define EPL_OBD_END_PART()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_INDEX_RAM(ind,cnt,call)
        #define EPL_OBD_END_INDEX(ind)
        #define EPL_OBD_RAM_INDEX_RAM_ARRAY(ind,cnt,call,typ,acc,dtyp,name,def)
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY(ind,cnt,call,typ,acc,dtyp,name,def)
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY_NOINIT(ind,cnt,call,typ,acc,dtyp,name)
        #define EPL_OBD_RAM_INDEX_RAM_PDO_MAPPING(ind,cnt,call,acc,name,def)

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_SUBINDEX_RAM_VAR(ind,sub,typ,acc,dtyp,name,val)
        #define EPL_OBD_SUBINDEX_RAM_VAR_RG(ind,sub,typ,acc,dtyp,name,val,low,high)
        #define EPL_OBD_SUBINDEX_RAM_VSTRING(ind,sub,acc,name,size,val)
        #define EPL_OBD_SUBINDEX_RAM_OSTRING(ind,sub,acc,name,size)
        #define EPL_OBD_SUBINDEX_RAM_VAR_NOINIT(ind,sub,typ,acc,dtyp,name)
        #define EPL_OBD_SUBINDEX_RAM_DOMAIN(ind,sub,acc,name)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF(ind,sub,typ,acc,dtyp,name,val)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_RG(ind,sub,typ,acc,dtyp,name,val,low,high)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_NOINIT(ind,sub,typ,acc,dtyp,name)

    //-------------------------------------------------------------------------------------------
    #else

//        #pragma message ("ELSE OF DEFINE")

        #define EPL_OBD_BEGIN()
        #define EPL_OBD_END()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_PART_GENERIC()
        #define EPL_OBD_BEGIN_PART_MANUFACTURER()
        #define EPL_OBD_BEGIN_PART_DEVICE()
        #define EPL_OBD_END_PART()

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_BEGIN_INDEX_RAM(ind,cnt,call)
        #define EPL_OBD_END_INDEX(ind)
        #define EPL_OBD_RAM_INDEX_RAM_ARRAY(ind,cnt,call,typ,acc,dtyp,name,def)
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY(ind,cnt,call,typ,acc,dtyp,name,def)
        #define EPL_OBD_RAM_INDEX_RAM_VARARRAY_NOINIT(ind,cnt,call,typ,acc,dtyp,name)
        #define EPL_OBD_RAM_INDEX_RAM_PDO_MAPPING(ind,cnt,call,acc,name,def)

        //---------------------------------------------------------------------------------------
        #define EPL_OBD_SUBINDEX_RAM_VAR(ind,sub,typ,acc,dtyp,name,val)
        #define EPL_OBD_SUBINDEX_RAM_VAR_RG(ind,sub,typ,acc,dtyp,name,val,low,high)
        #define EPL_OBD_SUBINDEX_RAM_VSTRING(ind,sub,acc,name,sizes,val)
        #define EPL_OBD_SUBINDEX_RAM_OSTRING(ind,sub,acc,name,size)
        #define EPL_OBD_SUBINDEX_RAM_VAR_NOINIT(ind,sub,typ,acc,dtyp,name)
        #define EPL_OBD_SUBINDEX_RAM_DOMAIN(ind,sub,acc,name)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF(ind,sub,typ,acc,dtyp,name,val)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_RG(ind,sub,typ,acc,dtyp,name,val,low,high)
        #define EPL_OBD_SUBINDEX_RAM_USERDEF_NOINIT(ind,sub,typ,acc,dtyp,name)

    #endif

    //-------------------------------------------------------------------------------------------
#elif defined (EPL_OBD_UNDEFINE_MACRO)

//    #pragma message ("EPL_OBD_UNDEFINE_MACRO")

    #undef EPL_OBD_BEGIN
    #undef EPL_OBD_END

    //---------------------------------------------------------------------------------------
    #undef EPL_OBD_BEGIN_PART_GENERIC
    #undef EPL_OBD_BEGIN_PART_MANUFACTURER
    #undef EPL_OBD_BEGIN_PART_DEVICE
    #undef EPL_OBD_END_PART

    //---------------------------------------------------------------------------------------
    #undef EPL_OBD_BEGIN_INDEX_RAM
    #undef EPL_OBD_END_INDEX
    #undef EPL_OBD_RAM_INDEX_RAM_ARRAY
    #undef EPL_OBD_RAM_INDEX_RAM_VARARRAY
    #undef EPL_OBD_RAM_INDEX_RAM_VARARRAY_NOINIT
    #undef EPL_OBD_RAM_INDEX_RAM_PDO_MAPPING

    //---------------------------------------------------------------------------------------
    #undef EPL_OBD_SUBINDEX_RAM_VAR
    #undef EPL_OBD_SUBINDEX_RAM_VAR_RG
    #undef EPL_OBD_SUBINDEX_RAM_VSTRING
    #undef EPL_OBD_SUBINDEX_RAM_OSTRING
    #undef EPL_OBD_SUBINDEX_RAM_VAR_NOINIT
    #undef EPL_OBD_SUBINDEX_RAM_DOMAIN
    #undef EPL_OBD_SUBINDEX_RAM_USERDEF
    #undef EPL_OBD_SUBINDEX_RAM_USERDEF_RG
    #undef EPL_OBD_SUBINDEX_RAM_USERDEF_NOINIT

#else

    #error "nothing defined"


#endif


