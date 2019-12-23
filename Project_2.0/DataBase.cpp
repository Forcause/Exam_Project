#include "DataBase.h"

void DataBase::AddStudent(Student student) {
  return students_.push_back(student);
}

void DataBase::AddLecturer(Lecturer lecturer) {
  return lecturers_.push_back(lecturer);
}

void DataBase::RemoveStudent(Student student) {
  students_.erase(std::find_if(students_.begin(), students_.end(),
                               [student](Student h) -> bool {
                                 return static_cast<Human> (h) ==
                                        static_cast<Human>(student);
                               }));
}

void DataBase::RemoveLecturer(Lecturer lecturer) {
  lecturers_.erase(std::find_if(lecturers_.begin(), lecturers_.end(),
                                [lecturer](Lecturer h) -> bool {
        return static_cast<Human>(h) == static_cast<Human>(lecturer);
      }));
}

vector<Student> const& DataBase::students() {
  return students_;
}

vector<Lecturer> const& DataBase::lecturers() {
  return lecturers_;
}
