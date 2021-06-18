#include "testfuncs.h"

int testf::doMath(int a, int b){
    return a + b; // math has been done
}

// this looks like it can be simplified
Napi::Number testf::addWrapped(const Napi::CallbackInfo& info){
 Napi::Env env = info.Env();
 //check if arguments are integer only.
 if(info.Length()<2 || !info[0].IsNumber() || !info[1].IsNumber()){
    Napi::TypeError::New(env, "arg1::Number, arg2::Number expected").ThrowAsJavaScriptException();
 }
 //convert javascripts datatype to c++
 Napi::Number first = info[0].As<Napi::Number>();
 Napi::Number second = info[1].As<Napi::Number>();

//run c++ function return value and return it in javascript
 Napi::Number returnValue = Napi::Number::New(env, testf::doMath(first.Int32Value(), second.Int32Value()));

 return returnValue;
}

Napi::Object testf::Init(Napi::Env env, Napi::Object exports)
{
  //export Napi function
  exports.Set("doMath", Napi::Function::New(env, testf::addWrapped));
  return exports;
}
