#ifndef UNIQUE_HPP_
#define UNIQUE_HPP_ 

#include <algorithm>
#include <stddef.h>
#include <utility>

template <typename T>
class UniquePtr
{
    public:
        typedef T element_type ;
        typedef T *pointer;
        typedef T &reference ;

        explicit UniquePtr(T *ptr = NULL) throw() ;
        UniquePtr(UniquePtr &&other) throw() 
            :ptr_(other.ptr_)
        {
            other.ptr_ = NULL ;   //让传入的临时变量的指针指向 NULL 避免bug。
        }
        UniquePtr &operator=(UniquePtr &&other) throw() 
        {
            if(this != &other)
            {
                delete ptr_ ;
                ptr_ = other.ptr_ ;
                other.ptr_ = NULL ;
            }
            return *this ;
        }
        ~UniquePtr() 
        {
            delete ptr_ ; 
        }

        reference operator*() const throw() 
        {
            return *ptr_ ;
        }

        pointer operator->() const throw()
        {
            return ptr_ ; 
        }
        
        pointer get() const throw() 
        {
           return ptr_ ;
        }

        pointer relese() 
        {
            pointer temp(ptr_) ;
            ptr_ = NULL ;
            return temp ;
        }

        void reset(T *ptr = NULL) 
        {
            if(ptr != ptr_)
            {
                delete ptr_ ;
                ptr_ = ptr;
            }
        }

        swap(UniquePtr &other)
        {
            std::swap(ptr_, other.ptr_) ;
        }
        

    private:

        void operator=(const UniquePtr &) ;
        UniquePtr(const UniquePtr &) ;
        pointer ptr_ ;
}

#endif  /*UNIQUE_HPP_*/
