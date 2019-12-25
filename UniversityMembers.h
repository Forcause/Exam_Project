#pragma once
#include "Student.h"
#include "Lecturer.h"

using std::string;

template <class T>
class UniversityMembers {
    static_assert(std::is_convertible<T, Person>::value, "Throw error");
    std::vector<T> base_;
public:
    void add(T const& human);
    void remove(T const& human);
    inline typename std::vector<T>::iterator find(string const& name, string const& surname, string const& patronymic);
    template<class Pred>  
    inline typename std::vector<T>::iterator find(Pred p);
    inline typename std::vector<T>::iterator find(T const& human);
    inline typename std::vector<T>::iterator end();
};
