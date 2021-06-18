#ifndef TESTFUNCS_H
#define TESTFUNCS_H
#include <napi.h>
#include <iostream>


namespace testf{ // namespace is required?
int doMath(int a, int b);

// Can I use v8::Number or something like that?
Napi::Number addWrapped(const Napi::CallbackInfo& info);

Napi::Object Init(Napi::Env env, Napi::Object exports);
NODE_API_MODULE(addon, Init) // no semicolon... freaking macros

}




#endif// TESTFUNCS_H
