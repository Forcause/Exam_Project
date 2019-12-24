#pragma once
#include "Human.h"

using std::string;

template <class T>
class UniversityWorkers {
  static_assert(std::is_convertible<T, Human>::value, "Ты пидорас");
  std::vector<T> base_;

 public:
  void Add(T const &human);
  void Remove(T const &human);
  auto Find(string const &name, string const &surname, string const &patronymic);
  template<class Pred>
  auto Find(Pred p);
  auto Find(T const &human);
  auto end() const;
};

template <class T>
inline void UniversityWorkers<T>::Add(T const &human) {
  base_.push_back(human);
}

template <class T>
inline void UniversityWorkers<T>::Remove(T const &human) {
  base_.erase(std::find(base_.begin(), base_.end(), human));
}

template <class T>
inline auto UniversityWorkers<T>::Find(
    string const &name, string const &surname, string const &patronymic) {
  return std::find(base_.begin(), base_.end(), Human(name, surname, patronymic));
}

template <class T>
inline auto UniversityWorkers<T>::Find(T const &human) {
  return std::find(base_.begin(), base_.end(), human);
}

template <class T>
inline auto UniversityWorkers<T>::end() const {
  return base_.cend();
}

template <class T>
template <class Pred>
inline auto UniversityWorkers<T>::Find(Pred p) {
  return std::find_if(base_.begin(), base_.end(), p);
}
