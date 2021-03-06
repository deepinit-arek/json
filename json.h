/*
    Copyright (c) 2014
    vurtun <polygone@gmx.net>
    MIT license
*/
#ifndef JSON_H_
#define JSON_H_

#define JSON_NAME 0
#define JSON_VALUE 1

typedef unsigned char json_char;
typedef unsigned int json_size;

enum json_typ {
    JSON_NONE,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_NUMBER,
    JSON_STRING,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
};

typedef struct json_token {
    const json_char *str;
    json_size len;
} json_pair[2];

struct json_iter {
    int depth;
    int err;
    const void **go;
    const json_char *src;
    json_size len;
};

struct json_iter json_begin(const json_char*, json_size);
struct json_iter json_read(const struct json_iter*, struct json_token*);
struct json_iter json_parse(const struct json_iter*, json_pair);
json_char *json_dup(struct json_token*, void*(*alloc)(size_t));
int json_cpy(json_char *dst, json_size max, struct json_token*);
int json_cmp(const struct json_token* tok, const json_char* str);
enum json_typ json_type(const struct json_token *tok);

#endif
