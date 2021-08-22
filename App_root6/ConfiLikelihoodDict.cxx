// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ConfiLikelihoodDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "ConfiLikelihood.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_ConfidenceLikelihood(void *p);
   static void deleteArray_ConfidenceLikelihood(void *p);
   static void destruct_ConfidenceLikelihood(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ConfidenceLikelihood*)
   {
      ::ConfidenceLikelihood *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ConfidenceLikelihood >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ConfidenceLikelihood", ::ConfidenceLikelihood::Class_Version(), "ConfiLikelihood.h", 78,
                  typeid(::ConfidenceLikelihood), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::ConfidenceLikelihood::Dictionary, isa_proxy, 4,
                  sizeof(::ConfidenceLikelihood) );
      instance.SetDelete(&delete_ConfidenceLikelihood);
      instance.SetDeleteArray(&deleteArray_ConfidenceLikelihood);
      instance.SetDestructor(&destruct_ConfidenceLikelihood);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ConfidenceLikelihood*)
   {
      return GenerateInitInstanceLocal((::ConfidenceLikelihood*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ConfidenceLikelihood*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr ConfidenceLikelihood::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ConfidenceLikelihood::Class_Name()
{
   return "ConfidenceLikelihood";
}

//______________________________________________________________________________
const char *ConfidenceLikelihood::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ConfidenceLikelihood*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ConfidenceLikelihood::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ConfidenceLikelihood*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ConfidenceLikelihood::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ConfidenceLikelihood*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ConfidenceLikelihood::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ConfidenceLikelihood*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void ConfidenceLikelihood::Streamer(TBuffer &R__b)
{
   // Stream an object of class ConfidenceLikelihood.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ConfidenceLikelihood::Class(),this);
   } else {
      R__b.WriteClassBuffer(ConfidenceLikelihood::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ConfidenceLikelihood(void *p) {
      delete ((::ConfidenceLikelihood*)p);
   }
   static void deleteArray_ConfidenceLikelihood(void *p) {
      delete [] ((::ConfidenceLikelihood*)p);
   }
   static void destruct_ConfidenceLikelihood(void *p) {
      typedef ::ConfidenceLikelihood current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ConfidenceLikelihood

namespace {
  void TriggerDictionaryInitialization_ConfiLikelihoodDict_Impl() {
    static const char* headers[] = {
"ConfiLikelihood.h",
0
    };
    static const char* includePaths[] = {
"/home/builinh/Program/root6/include",
"/home/builinh/Dropbox/SEASTAR2017/Linh_code_DTCB2021/ConfiLikelihood/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ConfiLikelihoodDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$ConfiLikelihood.h")))  ConfidenceLikelihood;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ConfiLikelihoodDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "ConfiLikelihood.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"ConfidenceLikelihood", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ConfiLikelihoodDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ConfiLikelihoodDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ConfiLikelihoodDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ConfiLikelihoodDict() {
  TriggerDictionaryInitialization_ConfiLikelihoodDict_Impl();
}
