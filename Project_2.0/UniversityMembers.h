#pragma once
#include "Person.h"

using std::string;

template <class T>
class UniversityMembers {
    static_assert(std::is_convertible<T, Person>::value, "Throw error");
    std::vector<T> base_;
public:
    void add(T const& human);
    void remove(T const& human);
    auto find(string const& name, string const& surname, string const& patronymic);
    template<class Pred>  
    auto find(Pred p);
    auto find(T const& human);
    auto end() const;
};