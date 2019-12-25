#include "UniversityMembers.h"

template <class T>
inline void UniversityMembers<T>::add(T const& human) {
    base_.push_back(human);
}

template <class T>
inline void UniversityMembers<T>::remove(T const& human) {
    base_.erase(std::find(base_.begin(), base_.end(), human));
}

template <class T>
inline auto UniversityMembers<T>::find(
    string const& name, string const& surname, string const& patronymic) {
    return std::find(base_.begin(), base_.end(), Person(name, surname, patronymic));
}

template <class T>
inline auto UniversityMembers<T>::find(T const& human) {
    return std::find(base_.begin(), base_.end(), human);
}

template <class T>
inline auto UniversityMembers<T>::end() const {
    return base_.cend();
}

template <class T>
template <class Pred>
inline auto UniversityMembers<T>::find(Pred p) {
    return std::find_if(base_.begin(), base_.end(), p);
}