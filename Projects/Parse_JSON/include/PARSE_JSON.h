#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#ifndef PARSE_JSON_H
#define PARSE_JSON_H

typedef enum //enumeration
{
    JSON_NULL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_BOOLEAN,
    JSON_ARRAY,
    JSON_OBJECT,
}JsonType;

typedef struct JSONValue //value
{
    JsonType type;
    union
    {
        double number;
        char *string;
        int boolean_value;
        struct JSONArray *array;
        struct JSONObject *object;

    }data;
}JSONValue;

typedef struct JSONPair //Key-value
{
    char *key; //ex: name
    JSONValue *value; // ex: Matteo 
}JSONPair;

typedef struct JSONObject //object
{
    JSONPair *pairs; //A pair = a key-value pair
    int count;
}JSONObject;

typedef struct JSONArray //Array
{
    JSONValue **items;
    int count;
}JSONArray;

JSONArray* parse_array(char **json);
JSONObject* parse_object(char **json);
JSONValue* parse_value(char **json);
JSONValue* parse_null(char **json);
void free_value(JSONValue *value);
void skip_whitespace(char **json);
char *parse_string(char **json);
double parse_number(char **json);
int parse_boolean(char **json);
void print_value(JSONValue *value, int indent, int in_array);

#endif