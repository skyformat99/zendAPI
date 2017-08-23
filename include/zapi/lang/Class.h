// Copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2017/08/01.

#ifndef ZAPI_LANG_CLASS_H
#define ZAPI_LANG_CLASS_H

#include "zapi/vm/AbstractClass.h"
#include "zapi/vm/InvokeBridge.h"
#include "zapi/ds/StringVariant.h"
#include "zapi/ds/BoolVariant.h"
#include "zapi/ds/DoubleVariant.h"
#include "zapi/ds/NumericVariant.h"

namespace zapi
{
namespace lang
{

using zapi::vm::AbstractClass;
using zapi::vm::InvokeBridge;

class Constant;
class Interface;

template <typename T>
class ZAPI_DECL_EXPORT Class final : public AbstractClass
{
public:
   Class(const char *name, ClassType classType = ClassType::Regular);
   Class(const Class<T> &other);
   Class(Class<T> &&other) ZAPI_DECL_NOEXCEPT;
   virtual ~Class();
   Class<T> &operator=(const Class<T> &other);
   Class<T> &operator=(Class<T> &&other);
public:
   template <void (T::*method)()>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <void (T::*method)(Parameters &params)>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <Variant (T::*method)()>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <Variant (T::*method)(Parameters &params)>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <void (T::*method)()>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <void (T::*method)(Parameters &params)>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <Variant (T::*method)()>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <Variant (T::*method)(Parameters &params)>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   
   template <void (T::*method)() const>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <void (T::*method)(Parameters &params) const>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <Variant (T::*method)() const>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <Variant (T::*method)(Parameters &params) const>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <void (T::*method)() const>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <void (T::*method)(Parameters &params) const>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <Variant (T::*method)() const>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <Variant (T::*method)(Parameters &params) const>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   
   // static methods register
   template <void (*method)()>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <void (*method)(Parameters &params)>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <Variant (*method)()>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <Variant (*method)(Parameters &params)>
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   template <void (*method)()>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <void (*method)(Parameters &params)>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <Variant (*method)()>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   template <Variant (*method)(Parameters &params)>
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   
   Class<T> &registerMethod(const char *name, Modifier flags, const Arguments &args = {});
   Class<T> &registerMethod(const char *name, const Arguments &args = {});
   
   Class<T> &registerProperty(const char *name, std::nullptr_t value, Modifier flags = Modifier::Public);
   Class<T> &registerProperty(const char *name, int16_t value, Modifier flags = Modifier::Public);
   Class<T> &registerProperty(const char *name, int32_t value, Modifier flags = Modifier::Public);
   Class<T> &registerProperty(const char *name, int64_t value, Modifier flags = Modifier::Public);
   Class<T> &registerProperty(const char *name, char value, Modifier flags = Modifier::Public);
   Class<T> &registerProperty(const char *name, const char *value, Modifier flags = Modifier::Public);
   Class<T> &registerProperty(const char *name, const std::string &value, Modifier flags = Modifier::Public);
   Class<T> &registerProperty(const char *name, bool value, Modifier flags = Modifier::Public);
   Class<T> &registerProperty(const char *name, double value, Modifier flags = Modifier::Public);
   
   Class<T> &registerConstant(const char *name, std::nullptr_t value);
   Class<T> &registerConstant(const char *name, int16_t value);
   Class<T> &registerConstant(const char *name, int32_t value);
   Class<T> &registerConstant(const char *name, int64_t value);
   Class<T> &registerConstant(const char *name, char value);
   Class<T> &registerConstant(const char *name, const char *value);
   Class<T> &registerConstant(const char *name, const std::string &value);
   Class<T> &registerConstant(const char *name, bool value);
   Class<T> &registerConstant(const char *name, double value);
   Class<T> &registerConstant(const Constant &constant);
   
   Class<T> &registerInterface(const Interface &interface);
   Class<T> &registerInterface(Interface &&interface);
private:
   virtual StdClass *construct() const override;
   virtual StdClass *clone(StdClass *orig) const override;
   virtual int callCompare(StdClass *left, StdClass *right) const override;
   virtual void callDestruct(StdClass *nativeObject) const override;
   virtual Variant callMagicCall(StdClass *nativeObject, const char *name, Parameters &params) const override;
   virtual Variant callMagicStaticCall(const char *name, Parameters &params) const override;
   virtual Variant callMagicInvoke(StdClass *nativeObject, Parameters &params) const override;
   
   virtual Variant callGet(StdClass *nativeObject, const std::string &name) const override;
   virtual void callSet(StdClass *nativeObject, const std::string &name, const Variant &value) const override;
   virtual bool callIsset(StdClass *nativeObject, const std::string &name) const override;
   virtual void callUnset(StdClass *nativeObject, const std::string &name) const override;
   
   virtual Variant castToString(StdClass *nativeObject) const override;
   virtual Variant castToInteger(StdClass *nativeObject) const override;
   virtual Variant castToDouble(StdClass *nativeObject) const override;
   virtual Variant castToBool(StdClass *nativeObject) const override;
   
   template <typename X = T>
   typename std::enable_if<std::is_default_constructible<X>::value, StdClass *>::type
   static doConstructObject();
   
   template <typename X = T>
   typename std::enable_if<!std::is_default_constructible<X>::value, StdClass *>::type
   static doConstructObject();
   
   template <typename X = T>
   typename std::enable_if<std::is_copy_constructible<X>::value, StdClass *>::type
   static doCloneObject(X *orig);
   
   template <typename X = T>
   typename std::enable_if<!std::is_copy_constructible<X>::value, StdClass *>::type
   static doCloneObject(X *orig);
   
   template <typename X>
   class HasCallStatic
   {
      typedef char one;
      typedef long two;
      template <typename C> 
      static one test(decltype(&C::__callStatic));
      template <typename C> 
      static two test(...);
   public:
      static const bool value = sizeof(test<X>(0)) == sizeof(char);
   };
   
   template <typename X>
   typename std::enable_if<HasCallStatic<X>::value, Variant>::type
   static doCallStatic(const char *name, Parameters &params);
   
   template <typename X>
   typename std::enable_if<!HasCallStatic<X>::value, Variant>::type
   static doCallStatic(const char *name, Parameters &params);
};

template <typename T>
Class<T>::Class(const char *name, ClassType classType)
   : AbstractClass(name, classType)
{}

template <typename T>
Class<T>::Class(const Class<T> &other)
   : AbstractClass(other)
{}

template <typename T>
Class<T>::Class(Class<T> &&other) ZAPI_DECL_NOEXCEPT
   : AbstractClass(std::move(other))
{}

template <typename T>
Class<T> &Class<T>::registerInterface(const Interface &interface)
{
   AbstractClass::registerInterface(interface);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerInterface(Interface &&interface)
{
   AbstractClass::registerInterface(std::move(interface));
   return *this;
}

template <typename T>
template <void (T::*method)()>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, flags, args);
   return *this;
}

template <typename T>
template <void (T::*method)(Parameters &params)>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, flags, args);
   return *this;
}

template <typename T>
template <Variant (T::*method)()>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, flags, args);
   return *this;
}

template <typename T>
template <Variant (T::*method)(Parameters &params)>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, flags, args);
   return *this;
}

template <typename T>
template <void (T::*method)()>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, Modifier::Public, args);
   return *this;
}

template <typename T>
template <void (T::*method)(Parameters &params)>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, Modifier::Public, args);
   return *this;
}

template <typename T>
template <Variant (T::*method)()>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, Modifier::Public, args);
   return *this;
}

template <typename T>
template <Variant (T::*method)(Parameters &params)>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, Modifier::Public, args);
   return *this;
}

template <typename T>
template <void (T::*method)() const>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, flags, args);
   return *this;
}

template <typename T>
template <void (T::*method)(Parameters &params) const>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, flags, args);
   return *this;
}

template <typename T>
template <Variant (T::*method)() const>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, flags, args);
   return *this;
}

template <typename T>
template <Variant (T::*method)(Parameters &params) const>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, flags, args);
   return *this;
}

template <typename T>
template <void (T::*method)() const>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, Modifier::Public, args);
   return *this;
}

template <typename T>
template <void (T::*method)(Parameters &params) const>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, Modifier::Public, args);
   return *this;
}

template <typename T>
template <Variant (T::*method)() const>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, Modifier::Public, args);
   return *this;
}

template <typename T>
template <Variant (T::*method)(Parameters &params) const>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<T, method>, Modifier::Public, args);
   return *this;
}

// static methods register
template <typename T>
template <void (*method)()>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<method>, flags | Modifier::Static, args);
   return *this;
}

template <typename T>
template <void (*method)(Parameters &params)>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<method>, flags | Modifier::Static, args);
   return *this;
}

template <typename T>
template <Variant (*method)()>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<method>, flags | Modifier::Static, args);
   return *this;
}

template <typename T>
template <Variant (*method)(Parameters &params)>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<method>, flags | Modifier::Static, args);
   return *this;
}

template <typename T>
template <void (*method)()>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<method>, Modifier::Public | Modifier::Static, args);
   return *this;
}

template <typename T>
template <void (*method)(Parameters &params)>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<method>, Modifier::Public | Modifier::Static, args);
   return *this;
}

template <typename T>
template <Variant (*method)()>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<method>, Modifier::Public | Modifier::Static, args);
   return *this;
}

template <typename T>
template <Variant (*method)(Parameters &params)>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, &InvokeBridge::invoke<method>, Modifier::Public | Modifier::Static, args);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerMethod(const char *name, Modifier flags, const Arguments &args)
{
   AbstractClass::registerMethod(name, flags | Modifier::Abstract, args);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerMethod(const char *name, const Arguments &args)
{
   AbstractClass::registerMethod(name, Modifier::Public | Modifier::Abstract, args);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, std::nullptr_t value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}
template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, int16_t value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, int32_t value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, int64_t value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, char value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, const char *value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, const std::string &value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, bool value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerProperty(const char *name, double value, Modifier flags)
{
   AbstractClass::registerProperty(name, value, flags);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, std::nullptr_t value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, int16_t value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, int32_t value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, int64_t value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, char value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, const char *value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, const std::string &value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, bool value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const char *name, double value)
{
   AbstractClass::registerProperty(name, value, Modifier::Const);
   return *this;
}

template <typename T>
Class<T> &Class<T>::registerConstant(const Constant &constant)
{
   AbstractClass::registerConstant(constant);
   return *this;
}

template <typename T>
StdClass *Class<T>::construct() const
{
   return doConstructObject<T>();
}

template <typename T>
void Class<T>::callDestruct(StdClass *nativeObject) const
{
   T *object = dynamic_cast<T *>(nativeObject);
   return object->__destruct();
}

template <typename T>
Variant Class<T>::callMagicCall(StdClass *nativeObject, const char *name, Parameters &params) const
{
   T *object = static_cast<T *>(nativeObject);
   return object->__call(name, params);
}

template <typename T>
Variant Class<T>::callMagicStaticCall(const char *name, Parameters &params) const
{
   return doCallStatic<T>(name, params);
}

template <typename T>
Variant Class<T>::callMagicInvoke(StdClass *nativeObject, Parameters &params) const
{
   T *object = dynamic_cast<T *>(nativeObject);
   return object->__invoke(params);
}

template <typename T>
Variant Class<T>::callGet(StdClass *nativeObject, const std::string &name) const
{
   T *object = dynamic_cast<T *>(nativeObject);
   return object->__get(name);
}

template <typename T>
void Class<T>::callSet(StdClass *nativeObject, const std::string &name, const Variant &value) const
{
   T *object = dynamic_cast<T *>(nativeObject);
   object->__set(name, value);
}

template <typename T>
bool Class<T>::callIsset(StdClass *nativeObject, const std::string &name) const
{
   T *object = dynamic_cast<T *>(nativeObject);
   return object->__isset(name);
}

template <typename T>
void Class<T>::callUnset(StdClass *nativeObject, const std::string &name) const
{
   T *object = dynamic_cast<T *>(nativeObject);
   object->__unset(name);
}

template <typename T>
Variant Class<T>::castToString(StdClass *nativeObject) const
{
   T *object = static_cast<T *>(nativeObject);
   return zapi::ds::StringVariant(object->__toString());
}

template <typename T>
Variant Class<T>::castToInteger(StdClass *nativeObject) const
{
   T *object = static_cast<T *>(nativeObject);
   return zapi::ds::NumericVariant(object->__toInteger());
}

template <typename T>
Variant Class<T>::castToDouble(StdClass *nativeObject) const
{
   T *object = static_cast<T *>(nativeObject);
   return zapi::ds::DoubleVariant(object->__toDouble());
}

template <typename T>
Variant Class<T>::castToBool(StdClass *nativeObject) const
{
   T *object = static_cast<T *>(nativeObject);
   return zapi::ds::BoolVariant(object->__toBool());
}

template <typename T>
template <typename X>
typename std::enable_if<std::is_default_constructible<X>::value, StdClass *>::type
Class<T>::doConstructObject()
{
   return new X();
}

template <typename T>
template <typename X>
typename std::enable_if<!std::is_default_constructible<X>::value, StdClass *>::type
Class<T>::doConstructObject()
{
   return nullptr;
}

template <typename T>
template <typename X>
typename std::enable_if<std::is_copy_constructible<X>::value, StdClass *>::type
Class<T>::doCloneObject(X *orig)
{
   return new X(*orig);
}

template <typename T>
template <typename X>
typename std::enable_if<!std::is_copy_constructible<X>::value, StdClass *>::type
Class<T>::doCloneObject(X *orig)
{
   return nullptr;
}

template <typename T>
template <typename X>
typename std::enable_if<Class<T>::template HasCallStatic<X>::value, Variant>::type
Class<T>::doCallStatic(const char *name, Parameters &params)
{
   return X::__callStatic(name, params);
}

template <typename T>
template <typename X>
typename std::enable_if<!Class<T>::template HasCallStatic<X>::value, Variant>::type
Class<T>::doCallStatic(const char *name, Parameters &params)
{
   notImplemented();
   // prevent some compiler warnning
   return nullptr;
}

template <typename T>
StdClass *Class<T>::clone(StdClass *orig) const
{
   return doCloneObject<T>(static_cast<T *>(orig));
}

template <typename T>
int Class<T>::callCompare(StdClass *left, StdClass *right) const
{
   T *leftNativeObject = static_cast<T *>(left);
   T *rightNativeObject = static_cast<T *>(right);
   return leftNativeObject->__compare(*rightNativeObject);
}

template <typename T>
Class<T>::~Class()
{}

} // lang
} // zapi

#endif //ZAPI_LANG_CLASS_H
