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
#include "zapi/vm/ClassMagicMethodInvoker.h"

namespace zapi
{
namespace lang
{

using zapi::vm::AbstractClass;
using zapi::vm::ClassMagicMethodInvoker;

template <typename T>
class ZAPI_DECL_EXPORT Class : public AbstractClass
{
public:
   Class(const char *name, ClassType classType = ClassType::Regular);
   Class(const Class<T> &other);
   Class(Class<T> &&other) ZAPI_DECL_NOEXCEPT;
   virtual ~Class();
   Class<T> &operator=(const Class<T> &other);
   Class<T> &operator=(Class<T> &&other);
public:
   void registerConstant();
   void registerMethod();
   void registerProperty();
   void registerInterface();
private:
   std::unique_ptr<ClassMagicMethodInvoker<T>> m_magicInvoker;
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
Class<T>::~Class()
{}

} // lang
} // zapi

#endif //ZAPI_LANG_CLASS_H
