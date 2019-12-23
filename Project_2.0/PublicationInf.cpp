#include "PublicationInf.h"

PublicationInf::PublicationInf(string title, string date,
                               vector<string> authors, vector<string> key_words)
    : title_(title), date_(date), authors_(authors), key_words_(key_words) {}
