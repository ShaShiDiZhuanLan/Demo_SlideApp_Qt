#ifndef SINGLETON_H
#define SINGLETON_H
#include <stdio.h>
#include <QDebug>

/****************
 * by QtCreator Create 2018年4月10日 10:49:23
 * Author：fulin
 * 单例模式，两种方式使用
 * 可以class继承Singleton<T>方式
 * 可以Singleton<T>::Instance
 * 先初始化Instance，后面取值GetInstance，如果中途销毁单例的话，
 * 需要重新取值。如果没有初始化就取值则会抛出一个异常。
 *
*****************/

using namespace std;

template <typename T>

class Singleton
{
public:
    template<typename... Args>

    static T* Instance(Args&&... args)
    {
        Q_ASSERT(nullptr == m_pInstance);

        if(nullptr == m_pInstance)
            m_pInstance = new T(std::forward<Args>(args)...);
        else
        {
            qFatal("This instance has been initialized.");
        }

        return m_pInstance;
    }

    static T* GetInstance()
    {
        if (nullptr == m_pInstance)
            qFatal("the instance is not init, please initialize the instance first");
        return m_pInstance;
    }

    static void DestroyInstance()
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }

private:
    Singleton(void){}
    virtual ~Singleton(void){DestroyInstance();}
    Singleton(const Singleton&){}
    Singleton& operator = (const Singleton&){}
private:
    static T* m_pInstance;
};

template <class T> T*  Singleton<T>::m_pInstance = nullptr;

#endif // SINGLETON_H
