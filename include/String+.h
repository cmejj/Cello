/*
** == String ==
**
**  Basic string wrapper
*/

#ifndef StringPlus_h
#define StringPlus_h

#include "Prelude+.h"
#include "Type+.h"

module String;

data {
  var type;
  char* value;
} StringData;

/** String_New(var self, char* value); */
var String_New(var self, va_list* args);
var String_Delete(var self);
void String_Assign(var self, var obj);
var String_Copy(var self);

bool String_Eq(var self, var obj);

int String_Len(var self);
bool String_IsEmpty(var self);
void String_Clear(var self);
bool String_Contains(var self, var sub);
void String_Discard(var self, var sub);

long String_Hash(var self);

const char* String_AsStr(var self);

instance(String, New) = { sizeof(StringData), String_New, String_Delete };
instance(String, Assign) = { String_Assign };
instance(String, Copy) = { String_Copy };
instance(String, Eq) = { String_Eq };
instance(String, Collection) = { String_Len, String_IsEmpty, String_Clear, String_Contains, String_Discard };
instance(String, Hash) = { String_Hash  };
instance(String, AsStr) = { String_AsStr  };


#endif