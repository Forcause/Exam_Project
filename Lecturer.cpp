#include "Lecturer.h"


void Lecturer::addPublication(Publication publication) {
    publications_.push_back(publication);
}

vector<Publication> const& Lecturer::publications() const {
    return publications_;
}

string Lecturer::to_s(Lecturer lect) {
    string info =
        lect.surname() + " " + lect.name() + " " + lect.patronymic() + '\n';
    if (lect.role().size() != 0) {
        for (auto it : lect.role()) info += it;
        info += ' ';
    }
    //info += '\n';
    //if (lect.publication().size() != 0) {
    //    string tmp;
    //    for (auto it : lect.publication()) {
    //        info += it.title() + it.date() + ' ';
    //        for (int i = 0; i < it.authors().size(); i++)
    //            tmp += it.authors()[i] + ' ';
    //        info += tmp + '\n';
    //        tmp = "";
    //        for (int i = 0; i < it.key_words().size(); i++) {
    //            tmp += it.authors()[i] + ' ';
    //        }
    //        info += tmp;
    //    }
    //}
    return info;

}