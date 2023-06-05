#include <cstring>
#include <iostream>

template <typename T>
class Vector {
   private:
    T* m_data;         // 元素
    size_t m_size;     // 元素个数
    size_t m_memSize;  // 内存大小

    // 递归赋值，自定义元素
    template <typename... ARGS>
    void RecFun(T first, ARGS... args) {
        m_data[m_size++] = first;
    }
    void RecFun() {}  // 结束递归

   public:
    // 构造函数
    Vector()
        : m_data(operator new(10)), m_size(10), m_memSize(sizeof(T) * 10) {
        new (m_data) T(0);
    }
    Vector(size_t size)
        : m_data(operator new(size)), m_size(size), m_memSize(sizeof(T) * size) {
        new (m_data) T(0);
    }
    Vector(size_t count, T data)
        : m_data(operator new(count)), m_size(count), m_memSize(sizeof(T) * count) {
        new (m_data) T(0);
        while (count-- > 0) {
            m_data[count] = data;
        }
    }
    Vector(const Vector& source)
        : m_data(operator new(source.m_size)), m_size(source.m_size), m_memSize(source.m_memSize) {
        new (m_data) T(0);
        memcpy(m_data, source.m_data, source.m_size);
        /* int len = m_size;
        while (len != 0) {
            m_data[len--] = source.m_data[len];
        } */
    }
    Vector(std::initializer_list<T> list)
        : m_data(operator new(list.size())), m_size(list.size()), m_memSize(sizeof(T) * list.size()) {
        new (m_data) T(0);
        memcpy(m_data, list.begin(), m_memSize);
    }
    template <typename... ARGS>
    Vector(ARGS... args)
        : m_data(new T[sizeof...(args)]{}), m_size(0) {
        RecFun(args...);
        m_memSize = m_size * sizeof(T);
    }

    // 重载运算符
    T operator[](size_t index) {
        return m_data[index];
    }
    T operator[](size_t index) const {
        return m_data[index];
    }

    // 析构函数
    virtual ~Vector() {
        if (m_data) {
            m_data->~T();
            operator delete[];
            m_data = nullptr;
        }
    }

    // 功能函数
    // sf
};

/* Vector::Vector() {
}

Vector::~Vector() {
}
 */