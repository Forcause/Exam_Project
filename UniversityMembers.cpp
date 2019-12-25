#include "UniversityMembers.h"
#include <algorithm>

template class UniversityMembers<Student>;
template class UniversityMembers<Lecturer>;

template <class T>
inline void UniversityMembers<T>::add(T const& person) {
    base_.push_back(person);
}

template <class T>
inline void UniversityMembers<T>::remove(T const& person) {
    base_.erase(std::find(base_.begin(), base_.end(), person));
}

template <class T>
inline typename std::vector<T>::iterator UniversityMembers<T>::find(
    string const& name, string const& surname, string const& patronymic) {
    return std::find(base_.begin(), base_.end(), Person(name, surname, patronymic));
}

template <class T>
inline typename std::vector<T>::iterator UniversityMembers<T>::find(T const& person) {
    return std::find(base_.begin(), base_.end(), person);
}

template <class T>
inline typename std::vector<T>::iterator UniversityMembers<T>::end() {
    return base_.end();
}

template <class T>
template <class Pred>
inline typename std::vector<T>::iterator UniversityMembers<T>::find(Pred p) {
    return std::find_if(base_.begin(), base_.end(), p);
}