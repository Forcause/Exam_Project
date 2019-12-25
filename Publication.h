#pragma once
#include "Research.h"

class Publication : public Research {
    int h_index_;
public:
    using Research::Research;
    int h_index();
    void setHindex(int);
};