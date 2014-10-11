#ifndef UNIQUE_HPP_
#define UNIQUE_HPP_ 

template <typename T>
class UniquePtr
{
    public:
        typedef T element_type ;
        typedef T *pointer;
        typedef T &reference ;

        explicit UniquePtr(T *ptr = NULL) throw() ;
        UniquePtr(UniquePtr &&) throw() ;
        UniquePtr &operator=(UniquePtr &&) throw() ;
        ~UniquePtr() ;

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
            
        }


    private:
        pointer ptr_ ;
}

#endif  /*UNIQUE_HPP_*/
